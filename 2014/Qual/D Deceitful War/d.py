#!/usr/bin/python
# cat testset.in | ./main.py > testset.out
import sys


def main():
	t = int(sys.stdin.readline())
	for c in range(1, t + 1):
		sys.stdout.write("Case #" + str(c) + ": ")
		n = int(sys.stdin.readline())
		naomi = map(float, list(sys.stdin.readline().split()))
		ken   = map(float, list(sys.stdin.readline().split()))
		naomi.sort()
		ken.sort()

		# decietful war
		deceitpts = deceitwar(naomi, ken)

		# normal war (play in ascending order)
		normalpts = normalwar(naomi, ken)

		print str(deceitpts) + ' ' + str(normalpts)	
		# print str(naomi)
		# print str(ken)


def deceitwar(n, k):
	deceitpts = 0
	deceits = 0
	j = len(k) - 1
	for i in range(0, len(n)):
		if n[i] < k[i - deceits]: # deceive
			deceits += 1
			continue
		deceitpts += 1

	return deceitpts


def normalwar(n, k):
	normalpts = 0
	j = 0
	for i in range(0, len(n)):
		if j >= len(k):
			normalpts += 1
			continue
		while k[j] < n[i]:
			j += 1
			if j >= len(k):
				break 
		j += 1
	return normalpts


if __name__ == "__main__":
    main()
