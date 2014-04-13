#!/usr/bin/python
# cat testset.in | ./main.py > testset.out
import sys


def main():
    t = int(sys.stdin.readline())
    for c in range(1, t + 1):
        sys.stdout.write("Case #" + str(c) + ": ")
        n = int(sys.stdin.readline())
        naomi = map(float, list(sys.stdin.readline().split()))
        ken = map(float, list(sys.stdin.readline().split()))
        naomi.sort()
        ken.sort()

        # deceitful war
        deceit_pts = deceit_war(naomi, ken)

        # normal war (play in ascending order)
        normal_pts = normal_war(naomi, ken)

        print(str(deceit_pts) + ' ' + str(normal_pts))
        # print(str(naomi))
        # print(str(ken))


def deceit_war(n, k):
    deceit_pts = 0
    deceits = 0
    j = len(k) - 1
    for i in range(0, len(n)):
        if n[i] < k[i - deceits]:  # deceive
            deceits += 1
            continue
        deceit_pts += 1

    return deceit_pts


def normal_war(n, k):
    normal_pts = 0
    j = 0
    for i in range(0, len(n)):
        if j >= len(k):
            normal_pts += 1
            continue
        while k[j] < n[i]:
            j += 1
            if j >= len(k):
                break
        j += 1
    return normal_pts


if __name__ == "__main__":
    main()
