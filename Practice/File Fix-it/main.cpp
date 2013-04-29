#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <set>
#include "gmpxx.h"
typedef mpz_class bignumber;

using namespace std;

set<string> dirs;

int addDir(string newdir) {
	if (dirs.find(newdir) != dirs.end() || newdir.length()==0) {
		return 0;
	} else {
		// parse parent
		string parent = newdir.substr(0, newdir.rfind("/"));
		// add this dir
		dirs.insert(newdir);
		return addDir(parent) + 1;
	}
}

int main(int argc, char *argv[])
{
	int numcases;

	cin >> numcases;
	for (int i=1; i<=numcases; i++) {

		int existdirs, newdirs;
		cin >> existdirs >> newdirs;

		dirs.clear();
		for (int j=0; j<existdirs; j++) {
			string d;
			cin >> d;
			dirs.insert(d);
		}

		int sum = 0;
		for (int j=0; j<newdirs; j++) {
			string newdir;
			cin >> newdir;
			sum += addDir(newdir);
		}

		cout << "Case #" << i << ": " << sum << endl;
	}

	return 0;
}
