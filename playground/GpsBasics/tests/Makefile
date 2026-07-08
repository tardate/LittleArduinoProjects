# Makefile for DisplayController behavioural tests
# Run from this directory: make test
#
# Dependencies:
#   GoogleTest (libgtest-dev on Debian/Ubuntu, or googletest on Homebrew)
#
# Install on Debian/Ubuntu:
#   sudo apt-get install libgtest-dev
#   (may also need: sudo apt-get install cmake && cd /usr/src/gtest && sudo cmake . && sudo make && sudo cp lib/*.a /usr/lib/)
#
# Install on macOS with Homebrew:
#   brew install googletest

CXX      ?= g++
# -Istubs resolves stub headers (Arduino.h, TinyGPS++.h, etc.) before system paths.
# -I../GpsBasics resolves display_controller.h from the Arduino project directory.
CXXFLAGS  = -std=c++17 -Wall -Wextra -Istubs -I../GpsBasics

# Detect GoogleTest via pkg-config; fall back to conventional system paths.
GTEST_CFLAGS := $(shell pkg-config --cflags gtest 2>/dev/null)
GTEST_LIBS   := $(shell pkg-config --libs gtest_main 2>/dev/null || \
                        echo "-lgtest -lgtest_main -lpthread")

TEST_SRC = test_display_controller.cpp
TEST_BIN = test_display_controller

.PHONY: all test clean

all: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(GTEST_CFLAGS) -o $@ $< $(GTEST_LIBS)

test: $(TEST_BIN)
	cd $(dir $(abspath $(lastword $(MAKEFILE_LIST)))) && ./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN)
