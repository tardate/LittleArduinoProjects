#!/usr/bin/env python
""" Simulate The Monarch's LFSR function.

The Monarch has taps at registers 8, 6, 5, 4
i.e. feedback polynomial: x^8 + x^6 + x^5 + x^4 + 1
"""
from sys import argv
import collections


def print_header(data):
    print '|  CLK | ', ' | '.join(['Q{}'.format(i + 1) for i in range(len(data))]), '|'
    print '|------|-----|----|----|----|----|----|----|----|'


def print_step(clock, data):
    print '| {:>4}'.format(clock), '|  ', ' |  '.join([str(x) for x in data]), '|'


def calculate_next_step(data):
    """ Command: calculates the next data frame.
    Hard-codes the specific taps as used by The Monarch
    """
    next_value = (data[7] ^ data[5] ^ data[4] ^ data[3]) & 1
    data.rotate(1)
    data[0] = next_value


def run(iterations):
    """ Command: runs the simulation.
    If iterations is > 0, runs for the specified number of steps.
    If iterations is < 1, runs until a full cycle complete.
    """
    initial_values = [1] * 8
    bits = collections.deque(initial_values)
    print_header(bits)
    if iterations > 0:
        for i in range(iterations):
            print_step(i, bits)
            calculate_next_step(bits)
    else:
        initial_bits = collections.deque(initial_values)
        i = 0
        while True:
            print_step(i, bits)
            calculate_next_step(bits)
            i += 1
            if bits == initial_bits:
                print_step(i, bits)
                break


if __name__ == '__main__':
    iterations = int(argv[1]) if len(argv) > 1 else 32
    run(iterations)
