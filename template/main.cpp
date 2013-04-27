#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <vector>
#include <cstring>
#include "gmpxx.h"
typedef mpz_class bignumber;

using namespace std;

void usage() 
{
	cout << "usage: cat testset.txt | ./main > output.txt \n";
	cout << "\ttestset - testset filename\n";
}


bool solve() 
{

}


int main(int argc, char *argv[])
{
	int i, numcases;

	if (argc != 1) {
		usage();
		return -1;
	}

	cin >> numcases;
	for (i=1; i<=numcases; i++) {
		// cin >> param1 >> param2;
		solve();

		cout << "Case #" << i << ": Solved" << endl;
	}

	return 0;
}
