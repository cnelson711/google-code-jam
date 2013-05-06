#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <vector>
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
		int n, a, b;
		int left[1000];
		int right[1000];
		cin >> n;

		int sum = 0;
		for (int j=0; j<n; j++) {
			cin >> a >> b;
			for (int k=0; k<j; k++) {
				// count number of new intersections
				if ((left[k] < a && right[k] > b) ||
				    (left[k] > a && right[k] < b))
				    sum++;
			}
			left[j] = a;
			right[j] = b;
		}

		cout << "Case #" << i << ": " << sum << endl;
	}

	return 0;
}
