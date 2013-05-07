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

#include "Board.h"

using namespace std;

int main()
{
	int numcases;
	cin >> numcases;

	for (int i=1; i<=numcases; i++) {
		int r, c;
		cin >> r >> c;
		cout << "Case #" << i << ":" << endl;

		Board<char> b(r, c);
		b.iterate2d(I2D_ROWS, [&] (char &element, int x, int y) {
			cin >> element;
		}, NULL, NULL);

		bool possible = true;
		b.iterate2d(I2D_ROWS, [&] (char &element, int x, int y) {
			if (element == '#') {
				if (x == c-1 || y == r-1) {
					possible = false;
				} else if (b.getElement(x+1, y  ) != '#' ||
					       b.getElement(x  , y+1) != '#' ||
					       b.getElement(x+1, y+1) != '#') {
					possible = false;
				} else {
					b.setElement('/', x  , y);
					b.setElement('\\', x+1, y);
					b.setElement('\\', x  , y+1);
					b.setElement('/', x+1, y+1);	
				}
			}
		}, NULL, NULL);	

		if (possible) {
			b.iterate2d(I2D_ROWS, [&] (char &element, int x, int y) {
				cout << element;
			}, NULL, [&] { cout << endl; } );
		} else {
			cout << "Impossible" << endl;
		}
	}

	return 0;
}
