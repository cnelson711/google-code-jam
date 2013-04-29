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
		string msg;
		cin >> msg;

		// Find the number of differing symbols (min base)
		string temp(msg);
		int base = 0;
		int translation[256];
		while (temp.length()) {
			base++;
			char c = temp[0];

			// Set the translation table such that the digits 
			// appearing first have the smallest value
			if (base == 1)
				translation[c] = 1;
			else if (base == 2)
				translation[c] = 0;
			else 
				translation[c] = base-1;

			// remove all instances of this digit from our temp string
			temp.erase(remove (temp.begin(), temp.end(), c), temp.end());
		}

		if (base == 1) base = 2;

		long secs = 0;
		long column = 1;
		for (int j=msg.length()-1; j>=0; j--) {
			secs += column * translation[msg[j]];
			column *= base;
		}

		cout << "Case #" << i << ": " << secs << endl;
	}

	return 0;
}
