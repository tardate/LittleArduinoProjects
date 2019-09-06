# #494 Fomu Build Notifier

Using the Fomu's RGB-in-your-USB as a test results notifier in RISC-V C (demonstrated with Ruby, RSpec and Guard)

![Build](./assets/BuildNotifier_build.jpg?raw=true)

Here's a quick demo (click for the full video on Youtube)..

[![clip](./assets/BuildNotifier_demo.gif?raw=true)](https://www.youtube.com/watch?v=FSXaPQCYACY)

## Notes

The Fomu discretely slips an RGB LED into your USB port. I immediately starting thinking of the possibilities
for using at as a notification mechanism.

Since I spend most of my time programming on a laptop with no external monitor, I often have a sliver of
a console window showing beside my tools/editor. The console is showing the continuous builds running on the code I'm writing.
It's low-distraction, yet I can always know if the tests are running red or green.

Now if the Fomu could give me the red/green indicator, I could save that little bit of screen real-estate, only switching to the console window if things are red.

I'm often writing Ruby, so I'm using a Ruby project as an example, with two of my favourite tools for development:

* [RSpec](https://rspec.info/) for tests
* [Guard](https://guardgem.org/) for watching files and running the associated tests when changes are made

### The Proof-of-Concept

The [a_flakey_example](./a_flakey_example) folder contains a very simple Ruby project.
It has [a test in examples_spec.rb](./a_flakey_example/spec/examples_spec.rb) that randomly fails about 50% of the time.
Guard is setup to watch the files and run tests when things change (i.e. a file is saved or modified).

My first step to prove the point simply integrates `wishbone-tool` from the [Fomu Toolchain](https://github.com/im-tomu/fomu-toolchain) with Guard,
so that RGB control data is poked into the Fomu to control the LED corresponding to Guard events.

#### Using The Example Project

The project is setup such that rvm/rbenv will create a virtual environment with the usual ruby incantations:

    $ cd a_flakey_example
    $ gem install bundler
    Fetching bundler-2.0.2.gem
    ...
    1 gem installed
    $ bundle
    Fetching gem metadata from https://rubygems.org/............
    ...
    Bundle complete! 2 Gemfile dependencies, 25 gems now installed.
    Use `bundle info [gemname]` to see where a bundled gem is installed.

Invoke the tests directly to make sure things are working:

If you're "unlucky":

    $ rspec
    F

    Failures:

      1) 1 will sometimes fail!
         Failure/Error: expect(subject).to eql(2)

           expected: 2
                got: 1

           (compared using eql?)
         # ./spec/examples_spec.rb:6:in `block (2 levels) in <top (required)>'

    Finished in 0.02997 seconds (files took 0.17955 seconds to load)
    1 example, 1 failure

    Failed examples:

    rspec ./spec/examples_spec.rb:5 # 1 will sometimes fail!

If you're lucky:

    $ rspec
    .

    Finished in 0.00339 seconds (files took 0.1099 seconds to load)
    1 example, 0 failures

Running with Guard: saving one of the project files will trigger test, e.g.:

![running_guard](./assets/running_guard.png?raw=true)


#### Configuring Guard to Notify Fomu

The [Guardfile](./a_flakey_example/Guardfile) is setup to change the Fomu LED on the following events:

* when Guard starts, displays an 'idle' colour
* when a test starts, displays an 'running' colour (glowing blue)
* when a test fails, displays an 'fail' colour (glowing red)
* when a test succeeds, displays an 'pass' colour (glowing green)

It requires a few tricks to make Guard dance this way with out building a whole plugin, of rely on
some additional notification infrastructure like
[Growl](http://growl.info/)
or
[Libnotify](http://developer.gnome.org/libnotify/).

Firstly, a
[Guard Callback](https://github.com/guard/guard/wiki/Hooks-and-callbacks)
can easily be registered to call a method when a build starts (or other event), like this:

    # setup the callbacks so we know when things start
    callback(FomuNotifier.new, [
      :run_all_begin, :run_on_additions_begin, :run_on_modifications_begin, :run_on_removals_begin, :start_begin
    ])

Tht's great for knowing when a build starts, but unfortunately while we can hook a callback
when a build ends, the callback does **not** get the test result.

To get the test result, I had to resort to a little trick: send notiications to file, and use Guard to
monitor that file so the results can be read when they change!

[Guard notifications](https://github.com/guard/guard/wiki/System-notifications#file) are send to `.guard_result`:

    notification :file, path: '.guard_result'

Guard watches the results file and calls the FomuNotifier with the result of the test (a string like 'success', or 'failed')

    guard :shell do
      watch '.guard_result' do
        Guard::FomuNotifier.set_rbg File.read('.guard_result').lines.first.strip
      end
    end

Now for the ugly part! The `set_rbg` method takes the status string and sends a bunch of 'poke' commands to the Fomu
using the `wishbone-tool` to set the appropriate LED state. And that's  a minimum of six `wishbone-tool` calls (address and data for red, green and blue).

Note that it assumes `wishbone-tool` is on the PATH, so before running guard, set path to point to the bin
directory of the [Fomu Toolchain](https://github.com/im-tomu/fomu-toolchain). Location will depend on your installation:

    export PATH=../fomu-toolchain-macos-v1.3/bin:$PATH

The full Guardfile for this interim version:

    # Guardfile that demonstrates hooking RSpec results
    # and blinking notifyications on the Fomu RGB LED
    # using the wishbone-tool

    # The Fomu/wishbone-tool integration lives here
    class Guard::FomuNotifier
      LEDDPWRR = 1
      LEDDPWRG = 2
      LEDDPWRB = 3
      ADDR = [LEDDPWRR, LEDDPWRG, LEDDPWRB]
      CSR_RGB_DAT_ADDR = '0xe0006800'
      CSR_RGB_ADDR_ADDR = '0xe0006804'

      # Command: set the Fomu RGB LED state
      def self.set_rbg(status)
        case status
        when 'idle'
          puts "FomuNotifier ... #{status}!\n"
          rgb = [0, 20, 60]
        when 'running'
          puts "FomuNotifier ... #{status}!\n"
          rgb = [20, 20, 200]
        when 'success'
          puts "FomuNotifier √√√ #{status}!\n"
          rgb = [20, 150, 20]
        else
          puts "FomuNotifier XXX #{status}!\n"
          rgb = [200, 10, 10]
        end
        params = []
        rgb.each_with_index do |value, i|
          params << "#{CSR_RGB_ADDR_ADDR} #{ADDR[i]}"
          params << "#{CSR_RGB_DAT_ADDR} #{value}"
        end
        command = params.map do |args|
          "wishbone-tool #{args} 2> /dev/null"
        end.join('; ')
        system(command)
      end

      # callback target so we know when a build starts
      def call(guard_class, event, *args)
        case event
        when :start_begin
          self.class.set_rbg 'idle'
        else
          self.class.set_rbg 'running'
        end
      end
    end

    guard :rspec, cmd: "bundle exec rspec" do
      require "guard/rspec/dsl"
      dsl = Guard::RSpec::Dsl.new(self)

      # RSpec files
      rspec = dsl.rspec
      watch(rspec.spec_helper) { rspec.spec_dir }
      watch(rspec.spec_files)

      # Ruby files
      ruby = dsl.ruby
      dsl.watch_spec_files_for(ruby.lib_files)

      # rspec test results go to file (unfortunately cannot receive with callbacks)
      notification :file, path: '.guard_result'

      # setup the callbacks so we know when things start
      callback(FomuNotifier.new, [
        :run_all_begin, :run_on_additions_begin, :run_on_modifications_begin, :run_on_removals_begin, :start_begin
      ])
    end

    # watch the rspec results file so can trigger Fomu depending on the result
    guard :shell do
      watch '.guard_result' do
        Guard::FomuNotifier.set_rbg File.read('.guard_result').lines.first.strip
      end
    end


#### The Proof-of-Concept Results

It works! But it is pretty ugly because each change to the LED requires at least 6 separate wishbone poke commands.
Doing more complex effects like adjusting the glow rate just adds more commands.

What I really need is a program running on the Fomu that just requires a single write to set the build state!

### Version 2 - Using C for the RISC-V CPU

The [riscv-notifier](./riscv-notifier) folder contains a little C program to run on the Fomu.
This is based on the riscv-blink example from the Fomu workshop.

    $ cd riscv-notifier
    $ make
      CC       ./src/main.c main.o
      CC       ./src/rgb.c  rgb.o
      CC       ./src/time.c time.o
      CC       ./src/usb-dev.c  usb-dev.o
      CC       ./src/usb-epfifo.c usb-epfifo.o
      LD       riscv-notifier.elf
      OBJCOPY  riscv-notifier.bin
      IHEX     riscv-notifier.ihex
      DFU      riscv-notifier.dfu
    dfu-suffix (dfu-util) 0.9

    Copyright 2011-2012 Stefan Schmidt, 2013-2014 Tormod Volden
    This program is Free Software and has ABSOLUTELY NO WARRANTY
    Please report bugs to http://sourceforge.net/p/dfu-util/tickets/

    Suffix successfully added to file

    $ dfu-util -d 1209:5bf0 -D riscv-notifier.bin
    dfu-util 0.9

    Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
    Copyright 2010-2019 Tormod Volden and Stefan Schmidt
    This program is Free Software and has ABSOLUTELY NO WARRANTY
    Please report bugs to http://sourceforge.net/p/dfu-util/tickets/

    Invalid DFU suffix signature
    A valid DFU suffix will be required in a future dfu-util release!!!
    Deducing device DFU version from functional descriptor length
    Opening DFU capable USB device...
    ID 1209:5bf0
    Run-time device DFU version 0101
    Claiming USB DFU Interface...
    Setting Alternate Setting #0 ...
    Determining device status: state = dfuIDLE, status = 0
    dfuIDLE, continuing
    DFU mode device DFU version 0101
    Device returned transfer size 1024
    Copying data from PC to DFU device
    Download  [=========================] 100%         2728 bytes
    Download done.
    state(7) = dfuMANIFEST, status(0) = No error condition is present
    state(8) = dfuMANIFEST-WAIT-RESET, status(0) = No error condition is present
    Done!

Note: I had to resort to specifying the device ID `-d 1209:5bf0`, as there's more than one DFU capable USB device showing up on my system.

The Fomu can be reset (program cleared) with `wishbone-tool 0xe0006000 0xac`.

### LED Control

A summary of the specs from the [iCE40 LED Driver Usage Guide](https://workshop.fomu.im/reference/FPGA-TN-1288-ICE40LEDDriverUsageGuide.pdf),
Appendix D. RGB PWM IP - LED Control Bus Addressable Registers:

| LEDD_ADR[3:0] | Name     | Usage                                     | Access |
|---------------|----------|-------------------------------------------|--------|
| 1000          | LEDDCR0  | LED Driver Control Register 0             | W      |
| 1001          | LEDDBR   | LED Driver Pre-scale Register             | W      |
| 1010          | LEDDONR  | LED Driver ON Time Register               | W      |
| 1011          | LEDDOFR  | LED Driver OFF Time Register              | W      |
| 0101          | LEDDBCRR | LED Driver Breathe On Control Register    | W      |
| 0110          | LEDDBCFR | LED Driver Breathe Off Control Register   | W      |
| 0001          | LEDDPWRR | LED Driver Pulse Width Register for RED   | W      |
| 0010          | LEDDPWRG | LED Driver Pulse Width Register for GREEN | W      |
| 0011          | LEDDPWRB | LED Driver Pulse Width Register for BLUE  | W      |

A combination of breathe, blink and RGB settings are used to define four states (RUNNING, IDLE, SUCCESS, FAILED).

See the source, especially [main.c](./riscv-notifier/src/main.c) for how these are controlled.

### Controlling the Notifier over the Wishbone Bus

The riscv-notifier program sets the LED state to one of four possible states, determined by `volatile int desired_state`. This is declared volatile so it doesn't get optimized away.

The makefile is configured to generate a map file from which we can determin the memory address of `desired_state`:

    .sdata.desired_state
                    0x0000000010000230        0x4 .obj/main.o
                    0x0000000010000230                desired_state

Knowing that, we can control the notifier by poking a single value with the wishbone-tool e.g.

    wishbone-tool 0x0000000010000230 2  # sets SUCCESS state

### Final Revised Guardfile

So with the riscv-notifier program loaded on the Fomu, the Guardfile can be simplified considerably. Here it is in full:

    # Guardfile that demonstrates hooking RSpec results
    # and blinking notifyications on the Fomu RGB LED
    # using the wishbone-tool to control a RISC-V notification program running on the Fomu

    # The Fomu/wishbone-tool integration lives here
    class Guard::FomuNotifier
      NOTIFIER_ADDR = '0x0000000010000230'
      LED_STATES = ['running', 'idle', 'success', 'failed']

      # Command: set the Fomu RGB LED state
      def self.set_rbg(status)
        command = "wishbone-tool #{NOTIFIER_ADDR} #{LED_STATES.index(status) || 3} 2> /dev/null"
        system(command)
      end

      # callback target so we know when a build starts
      def call(guard_class, event, *args)
        status = if event == :start_begin
          'idle'
        else
          'running'
        end
        self.class.set_rbg status
      end
    end

    guard :rspec, cmd: "bundle exec rspec" do
      require "guard/rspec/dsl"
      dsl = Guard::RSpec::Dsl.new(self)

      # RSpec files
      rspec = dsl.rspec
      watch(rspec.spec_helper) { rspec.spec_dir }
      watch(rspec.spec_files)

      # Ruby files
      ruby = dsl.ruby
      dsl.watch_spec_files_for(ruby.lib_files)

      # rspec test results go to file (unfortunately cannot receive with callbacks)
      notification :file, path: '.guard_result'

      # setup the callbacks so we know when things start
      callback(FomuNotifier.new, [
        :run_all_begin, :run_on_additions_begin, :run_on_modifications_begin, :run_on_removals_begin, :start_begin
      ])
    end

    # watch the rspec results file so can trigger Fomu depending on the result
    guard :shell do
      watch '.guard_result' do
        Guard::FomuNotifier.set_rbg File.read('.guard_result').lines.first.strip
      end
    end


## Conclusions

I like it! Guard takes a bit of convincing to pipe the right results.

Programming the Fomu with RISC-V C was quite straight-forward and posed no curly issues.
The main downside is that the program is not permanently resident,
though it's no big deal to script the reflash so I can use this as a regular tool in my developer workflow.

![Build](./assets/BuildNotifier_build.jpg?raw=true)

## Credits and References

* [RSpec](https://rspec.info/)
* [Guard](https://guardgem.org/)
* [guard-rspec](https://github.com/guard/guard-rspec) - github
* [guard-shell](https://github.com/guard/guard-shell) - github
* [Fomu Toolchain](https://github.com/im-tomu/fomu-toolchain)
* [wishbone-utils](https://github.com/xobs/wishbone-utils) - github
* [Guard Notifications](https://github.com/guard/guard/wiki/System-notifications#file)
* [Guard Hooks and Callbacks](https://github.com/guard/guard/wiki/Hooks-and-callbacks)
* [iCE40 LED Driver Usage Guide](https://workshop.fomu.im/reference/FPGA-TN-1288-ICE40LEDDriverUsageGuide.pdf)
