#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "gmpxx.h"
typedef mpz_class bignumber;

#include "Board.h"

using namespace std;

int main()
{
	int numcases;
	cin >> numcases;

	for (int i=1; i<=numcases; i++) {
		int n, k;
		cin >> n >> k;
		Board <char> b(n, n);

		// Read in board
		b.iterate2d(I2D_ROWS, [&] (char &element, int x, int y) {
			cin >> element;
		}, NULL, NULL);

		// Apply Gravity
		int lastx;
		b.iterate2d(I2D_ROWS | I2D_REVERSE_ORDER, [&] (char &element, int x, int y) {
			// for each element of a row/column/diag
			if (element != '.') {
				char temp = element;
				element = '.';
				b.setElement(temp, lastx--, y);
			}
		}, [&] {
			// before each row/column/diag
			lastx = n-1;
		}, NULL);
		
		// Check for K elements in a row/column/diagonal
		bool rwins = false;
		bool bwins = false;
		int rcnt, bcnt;
		char lastc;

		b.iterate2d(I2D_ALL, [&] (char &element, int x, int y) {
			// for each element of a row/column/diag
			if (element == lastc) {
				if (lastc == 'B') bcnt++;
				if (lastc == 'R') rcnt++;
				if (bcnt >= k) bwins = true;
				if (rcnt >= k) rwins = true;
			} else {
				lastc = element;
				rcnt = bcnt = 1;
			}
		}, [&] { 
			// before each row/column/diag
			rcnt = bcnt = 1;
			lastc = '.';
		}, NULL);

		cout << "Case #" << i << ": ";
		if (rwins && bwins)       cout << "Both";
		else if (rwins && !bwins) cout << "Red";
		else if (!rwins && bwins) cout << "Blue";
		else                      cout << "Neither";
		cout << endl;
	}

	return 0;
}
