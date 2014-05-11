#!/usr/bin/python
# < testset ./b.py

from __future__ import print_function
import sys
import itertools


def debug(*objs):
    print("DEBUG: ", *objs, file=sys.stderr)
    pass

def reduceCars(cars):
    new_cars = []
    for s in cars:
        new_s = ""
        previous_c = "~"
        for c in s:
            if previous_c != c:
                previous_c = c
                new_s += c
        new_cars.append(new_s)
    return new_cars


def isValidTrain(s):
    # debug(s)
    previous_c = "~"
    finished_letters = []
    for c in s:
        if c in finished_letters:
            return False
        if previous_c != c:
            finished_letters.append(previous_c)
            previous_c = c
    return True


def main():
    t = int(sys.stdin.readline())
    for c in range(1, t + 1):
        n = int(sys.stdin.readline())
        cars = sys.stdin.readline().split()
        cars.sort()
        new_cars = reduceCars(cars)

        valid = 0
        for p in itertools.permutations(new_cars):
            if isValidTrain("".join(p)):
                valid += 1
        
        print("Case #%i: %i" % (c, valid))


if __name__ == "__main__":
    main()
