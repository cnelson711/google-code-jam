#!/usr/bin/python
# cat testset.in | ./main.py > testset.out
import sys


def main():
	n = int(sys.stdin.readline())
	for c in range(1, n + 1):
		sys.stdout.write("Case #" + str(c) + ": ")
		# print("Case #" + str(c) + ":")
	
		print "Unsolved"


if __name__ == "__main__":
    main()
    