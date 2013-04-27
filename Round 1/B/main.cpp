#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <vector>
#include <cstring>
#include "gmpxx.h"
typedef mpz_class bignumber;

using namespace std;

typedef struct {
	int value;
	int energy;
	int spent;
	bool locked;
} activity;

activity a[10000];

void usage() 
{
	cout << "usage: cat testset.txt | ./main > output.txt \n";
	cout << "\ttestset - testset filename\n";
}


long solve(int e, int r, int n) 
{
	int i, k, maxind, maxspent, diff, max;
	long sum = 0;

	if (e == r) {
		for (i=0; i<n; i++)
			sum += r*a[i].value;
		return sum;
	}

	for (i=0; i<n; i++) {
		// find max that's still unlocked
		max = 0;
		for (k=0; k<n; k++) {
			if (!a[k].locked && a[k].value > max) {
				maxind = k;
				max = a[k].value;
			}
		}

		// figure out the max we can spent here (max <= a[maxind].energy)
		// maxspent increases by r for each unlocked activity in front of maxind
		maxspent = 0;
		for (k=maxind+1; k<n && maxspent <= a[maxind].energy; k++) {
			if (!a[k].locked) {
				maxspent += r;
			} else {
				// needs to keep energy at a[k].energy since it's locked
				// diff
				// maxspent = a[maxind].energy + (r*diff) - a[k].energy
				diff = k - maxind;
				maxspent = (r*diff) - (a[k].energy - a[maxind].energy) ;
				break;
			}
		}
		if (k==n) {
			maxspent = a[maxind].energy;
		}
		if (maxspent > a[maxind].energy)
			maxspent = a[maxind].energy;

		//cout << maxspent << endl;

		// Barrow from future
		a[maxind].spent = maxspent;
		for (k=maxind+1; k<n && !a[k].locked; k++) {
			a[k].energy = a[k-1].energy - a[k-1].spent + r;
			if (a[k].energy > e)
				a[k].energy = e;
		}

		// lock
		a[maxind].locked = true;

	}

	for (i=0; i<n; i++) {
		sum += a[i].spent*a[i].value;

		//cout << a[i].spent << " "; 
	}
	//cout << endl;

	return sum;
}


int main(int argc, char *argv[])
{
	int i, k, numcases;
	int e, r, n, temp;

	if (argc != 1) {
		usage();
		return -1;
	}

	cin >> numcases;
	for (i=1; i<=numcases; i++) {
		cin >> e >> r >> n;
		for (k=0; k<n; k++) {
			cin >> temp;
			a[k].value = temp;
			a[k].spent = 0;
			a[k].energy = e;
			a[k].locked = false;
		}

		cout << "Case #" << i << ": " << solve(e, r, n) << endl;
	}

	return 0;
}
