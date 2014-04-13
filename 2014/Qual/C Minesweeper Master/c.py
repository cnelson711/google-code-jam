#!/usr/bin/python
# cat testset.in | ./main.py > testset.out
import sys


def main():
	n = int(sys.stdin.readline())
	for c in range(1, n + 1):
		print("Case #" + str(c) + ":")
		(h, w, m) = map(int, tuple(sys.stdin.readline().split()))
		a = w * h
		b = a - m

		if m == 0:
			printBlankBoard(w, h)
		elif b == 1:
			printFullBoard(w, h)
		elif w == 1 or h == 1:
			printMinesInLastRow(w, h, m)
		elif (b == 2 or b == 3):
			print "Impossible"
		elif (w == 2 or h == 2) and (m % 2 == 1):
			print "Impossible"
		elif b >= w * 2 and m % w != w - 1:
			printMinesInLastRow(w, h, m)
		elif b >= h * 2 and m % h != h - 1:
			printMinesInLastColumn(w, h, m)
		else:
			print "Unsolved" # unsolved


def printBlankBoard(w, h):
	printSimpleBoard(w, h, 0, lambda x, y: False)


def printFullBoard(w, h):
	printSimpleBoard(w, h, 0, lambda x, y: True)


def printMinesInLastRow(w, h, m):
	printSimpleBoard(w, h, m, lambda x, y: (y * w + x) >= (w * h - m) )


def printMinesInLastColumn(w, h, m):
	printSimpleBoard(w, h, m, lambda x, y: (x * h + y) >= (w * h - m) )


def printSimpleBoard(w, h, m, comp):
	for y in range(0, h):
		for x in range(0, w):
			if x == 0 and y == 0:
				sys.stdout.write('c')
			elif comp(x, y):
				sys.stdout.write('*')
			else:
				sys.stdout.write('.')
		sys.stdout.write('\n')


if __name__ == "__main__":
    main()
    