#!/usr/bin/python
# cat testset.in | ./main.py > testset.out
import sys


def main():
    n = int(sys.stdin.readline())
    for i in range(1, n + 1):
        sys.stdout.write("Case #" + str(i) + ": ")
        (c, f, x) = map(float, tuple(sys.stdin.readline().split()))
        t = 0.0
        rate = 2.0

        while True:
            ttx = x / rate
            ttf = c / rate
            rate += f
            ttxwf = ttf + (x / rate)
            t += ttf

            if (ttx < ttf) or (ttx < ttxwf):
                print(str(t + ttx))
                break


if __name__ == "__main__":
    main()
