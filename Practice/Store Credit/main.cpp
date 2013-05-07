#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include "gmpxx.h"
typedef mpz_class bignumber;

using namespace std;

int main()
{
	int numcases;
	cin >> numcases;

	for (int i=1; i<=numcases; i++) {
		int c, n, p[2001];
		cin >> c >> n;

		for (int j=0; j<n; j++)
			cin >> p[j];

		int j, k;
		for (j=0; j<n; j++)
			for (k=j+1; k<n; k++)
				if (p[j] + p[k] == c)
					cout << "Case #" << i << ": " << j+1 << " " << k+1 << endl;
	}

	return 0;
}
