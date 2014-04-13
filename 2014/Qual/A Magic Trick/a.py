#!/usr/bin/python
# cat testset.in | ./main.py > testset.out
import sys


def main():
    n = int(sys.stdin.readline())
    for c in range(1, n + 1):
        sys.stdout.write("Case #" + str(c) + ": ")

        set1 = get_row()
        set2 = get_row()
        common = set1.intersection(set2)

        if len(common) == 0:
            print("Volunteer cheated!")
        elif len(common) > 1:
            print("Bad magician!")
        else:
            print(str(common.pop()))


def get_row():
    row_chosen = int(sys.stdin.readline())
    for r in range(1, 5):
        row = sys.stdin.readline()
        if r == row_chosen:
            return set(row.split())


if __name__ == "__main__":
    main()
