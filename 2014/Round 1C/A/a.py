#!/usr/bin/python
# < testset ./a.py

from __future__ import print_function
import sys

from fractions import gcd

def pow2(n):
    return ((n & (n - 1)) == 0) and n != 0

def debug(*objs):
    print("DEBUG: ", *objs, file=sys.stderr)
    pass


def main():
    t = int(sys.stdin.readline())
    for c in range(1, t + 1):
        (n, d) = map(long, sys.stdin.readline().split('/'))
        
        divisor = gcd( n, d )
        n = n / divisor
        d = d / divisor

        if not pow2(d):
            print("Case #%i: impossible" % (c) )
            continue

        for g in range(1, 45):
            if n > d / 2:
                break
            d = d / 2
            if n / d == 1:
                break

        if g > 40:
            print("Case #%i: impossible" % (c) )
        else:
            print("Case #%i: %i" % (c, g) )


if __name__ == "__main__":
    main()
