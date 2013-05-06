#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
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
		int n, temp;
		long y[810];
		long x[810];
		cin >> n;

		for (int j=0; j<n; j++)
			cin >> x[j];
		for (int j=0; j<n; j++)
			cin >> y[j];

		sort(x, x + n);
		sort(y, y + n);

		long sum = 0;

		for (int j=0; j<n; j++)
			sum += x[j] * y[n-j-1];

		cout << "Case #" << i << ": " << sum << endl;
	}

	return 0;
}
