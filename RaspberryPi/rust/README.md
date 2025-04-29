# #xxx Using rust on the RPi

Installing rust on a Raspberry Pi and using it for GPIO programming, also test cross-compilation from macOS to Raspberry Pi.

![Build](./assets/rust_build.jpg?raw=true)

## Notes

See also [Practical Rust Projects](https://codingkata.tardate.com/rust/practical-rust-projects/)

### Installing the Rust Toolchain

For the latest info, see <https://www.rust-lang.org/tools/install>

Using the remote self-installer:

```sh
pi@raspi1:~ $ curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
...

  stable-arm-unknown-linux-gnueabihf installed - rustc 1.86.0 (05f9846f8 2025-03-31)


Rust is installed now. Great!

To get started you may need to restart your current shell.
This would reload your PATH environment variable to include
Cargo's bin directory ($HOME/.cargo/bin).

To configure your current shell, you need to source
the corresponding env file under $HOME/.cargo.

This is usually done by running one of the following (note the leading DOT):
. "$HOME/.cargo/env"            # For sh/bash/zsh/ash/dash/pdksh
source "$HOME/.cargo/env.fish"  # For fish
source "$HOME/.cargo/env.nu"    # For nushell

```

So far so good - looks like we are good to go!

### Blinky Test Circuit Design

Let's do a simple blinky with an LED on GPIO23:

![bb](./assets/rust_bb.jpg?raw=true)

![schematic](./assets/rust_schematic.jpg?raw=true)

### Making a simple Blinky Circuit

Creating a new app the standard cargo way:

```sh
pi@raspi1:~ $ . "$HOME/.cargo/env"
pi@raspi1:~ $ cargo new blinky
    Creating binary (application) `blinky` package
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html
pi@raspi1:~ $ cd blinky
pi@raspi1:~/blinky $ cargo run
   Compiling blinky v0.1.0 (/home/pi/blinky)
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 18.31s
     Running `target/debug/blinky`
Hello, world!
```

For GPIO control, we need the
[rust_gpiozero](https://crates.io/crates/rust_gpiozero) crate.

```sh
pi@raspi1:~/blinky $ cargo add rust_gpiozero
```

I've added a simple blinky script in [main.rs](./blinky/src/main.rs)

```rust
extern crate rust_gpiozero;

use rust_gpiozero::*;
use std::thread::sleep;
use std::time::Duration;

fn main() {
    let led = LED::new(23);

    loop {
        println!("on");
        led.on();
        sleep(Duration::from_secs(1));
        println!("off");
        led.off();
        sleep(Duration::from_secs(1));
    }
}
```

### Testing

Running from the Raspberry Pi with `cargo run` and it is blinking at 1Hz:

![bb_build](./assets/rust_bb_build.jpg?raw=true)

### Cross-compiling on macOS

Its all very well being able to compile on the Raspberry Pi itself.
But since my prime machine is macOS, can I cross-compile on macOS for deployment on Raspberry Pi?

There's not a great deal of definitive information available,
but I finally got things going after finding
<https://t-shaped.nl/cross-compiling-rust-programs-for-a-raspberry-pi-from-macos>.

Install `arm-linux-gnueabihf-binutils` and add
the `armv7-unknown-linux-musleabihf` target:

```sh
cd blinky
brew install arm-linux-gnueabihf-binutils
rustup target add armv7-unknown-linux-musleabihf
```

Add linker hint to `~/.cargo/config.toml`

```sh
$ cat ~/.cargo/config.toml
[target.armv7-unknown-linux-musleabihf]
linker = "arm-linux-gnueabihf-ld"
```

Now can I build?

```sh
$ cargo build --target=arm-unknown-linux-musleabi
   Compiling libc v0.2.172
   Compiling lazy_static v1.5.0
   Compiling rppal v0.12.0
   Compiling rust_gpiozero v0.2.1
   Compiling blinky v0.1.0 (/Users/paulgallagher/MyGithub/tardate/LittleArduinoProjects/RaspberryPi/rust/blinky)
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 1.55s
```

Yes! Now copy to the Pi:

```sh
scp target/arm-unknown-linux-musleabi/debug/blinky pi@raspi1.local:blinky-xc
```

And execute on the Raspberry Pi:

```sh
pi@raspi1:~ $ ./blinky-xc
on
off
on
off
on
off
on
off
on
off
on
off
^C
pi@raspi1:~ $
```

Building a release version and copy to the Pi:

```sh
$ cargo build --release --target=arm-unknown-linux-musleabi
   Compiling libc v0.2.172
   Compiling lazy_static v1.5.0
   Compiling rppal v0.12.0
   Compiling rust_gpiozero v0.2.1
   Compiling blinky v0.1.0 (/Users/paulgallagher/MyGithub/tardate/LittleArduinoProjects/RaspberryPi/rust/blinky)
    Finished `release` profile [optimized] target(s) in 1.58s

$ scp target/arm-unknown-linux-musleabi/release/blinky pi@raspi1.local:blinky-xc-release
```

On the Pi:

```sh
pi@raspi1:~ $ ./blinky-xc-release
on
off
on
off
on
^C
pi@raspi1:~ $
```

Perfect!

## Credits and References

* [Practical Rust Projects](https://codingkata.tardate.com/rust/practical-rust-projects/)
* <https://www.rust-lang.org/tools/install>
* <https://t-shaped.nl/cross-compiling-rust-programs-for-a-raspberry-pi-from-macos>
