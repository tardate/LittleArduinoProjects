#!/usr/bin/env python
""" Simulate The Monarch's LFSR function.

The Monarch has taps at bit position 3,5,6,7
i.e. feedback polynomial: x^8 + x^7 + x^6 + x^4 + 1
"""
from sys import argv
import collections


def print_header(data):
    print '|  CLK | ', ' | '.join(['Q{}'.format(i + 1) for i in range(len(data))]), '|'
    print '|------|-----|----|----|----|----|----|----|----|'


def print_step(clock, data):
    print '| {:>4}'.format(clock), '|  ', ' |  '.join([str(x) for x in data]), '|'


def calculate_next_step(data):
    """ Command: calculates the data frame.
    Hard-codes the specific taps as used by The Monarch
    """
    next_value = (data[7] ^ data[6] ^ data[5] ^ data[3]) & 1
    data.rotate(1)
    data[0] = next_value


def run(iterations):
    bits = collections.deque([1] * 8)
    print_header(bits)
    for i in range(iterations):
        print_step(i, bits)
        calculate_next_step(bits)


if __name__ == '__main__':
    iterations = int(argv[1]) if len(argv) > 1 else 32
    run(iterations)
