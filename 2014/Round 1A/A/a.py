#!/usr/bin/python
# < testset ./a.py

from __future__ import print_function
import sys


def debug(*objs):
    print("DEBUG: ", *objs, file=sys.stderr)
    pass
    

def main():
    t = int(sys.stdin.readline())
    for c in range(1, t + 1):
        (n, l) = map(long, sys.stdin.readline().split())
        outlets = map(lambda x: long(x, 2), sys.stdin.readline().split())
        devices = map(lambda x: long(x, 2), sys.stdin.readline().split())
        outlets.sort()
        devices.sort()

        min_flips = l + 1
        for i in range(0, n):
            for j in range(0, n):
                candidate = outlets[i] ^ devices[j]
                num_ones = bin(candidate).count("1")
                if num_ones < min_flips:
                    temp_outlets = map(lambda x: x ^ candidate, outlets)
                    temp_outlets.sort()
                    if devices == temp_outlets:
                        min_flips = num_ones

        if min_flips <= l:
            print("Case #%i: %i" % (c, min_flips))
        else:
            print("Case #%i: NOT POSSIBLE" % c)


if __name__ == "__main__":
    main()
