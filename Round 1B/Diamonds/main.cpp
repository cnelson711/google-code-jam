#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "gmpxx.h"
typedef mpz_class bignumber;

using namespace std;

void calc(int n, int &numblocks, int &coretowernum) {
	numblocks = 0;
	coretowernum = 0;
	do {
		numblocks += coretowernum*4 + 1;
		coretowernum++;
	} while (n >= numblocks);
	coretowernum--;
	numblocks -= coretowernum*4 + 1;
	coretowernum--;
}

long choose(int n, int k)
{
	if (k > n)
		return 0;
	long r = 1;
	for (int d=1; d<=k; d++) {
		r *= n--;
		r /= d;
	}
	return r;
}

double binomialcdf(int n, int k) {
	double p = 0.0;
	for (int i=k; i<=n; i++) {
		p += choose(n, i) * pow(0.5, i) * pow(0.5, n-i);
	}
	return p;
}



int main()
{
	int numcases;
	cin >> numcases;

	for (int i=1; i<=numcases; i++) {
		int n, x, y;
		cin >> n >> x >> y;
		if (x<0) x = -x;
		cout << "Case #" << i << ": ";

		int coretowernum, numblocks;
		calc(n, numblocks, coretowernum);

		if (x+y <= coretowernum*2) {
			// Are cordinates in the core part of the tower?
			cout << 1;
		} else if (x+y > coretowernum*2 + 2) {
			// Are cordinates outside the core tower & edge?
			cout << 0;
		} else {
			// Calculate number of blocks leaning on outside of core tower
			int numoutsideblocks = n-numblocks;
			int pos = (y + 1);

			if (numoutsideblocks == (coretowernum*4+4)) {
				// tower is almost complete; missing one block at very top
				cout << (pos <= coretowernum) ? 1 : 0;
			} else if (numoutsideblocks <= (coretowernum*4+4)/2) {
				// Not enough blocks to spill over to other side of tower yet
				// Binomial distribution: p(x>=pos) binomial (n=numoutsideblocks,p=.5)
				cout << binomialcdf(numoutsideblocks, pos);
			} else {
				// Spillage!  Calculate the minimum number of blocks on each side (spilled):
				int spilled = numoutsideblocks - (coretowernum*4+4)/2;

				if (pos <= spilled) {
					cout << 1;
				} else {
					// TODO: this isn't correct logic
					cout << binomialcdf(numoutsideblocks-spilled-spilled, pos-spilled) << " *";
				}
			}
		}
		cout << endl;
	}

	return 0;
}
