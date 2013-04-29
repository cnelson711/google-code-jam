#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <vector>
#include <cstring>

using namespace std;

void usage() 
{
	cout << "usage: cat testset.txt | ./main > output.txt \n";
	cout << "\ttestset - testset filename\n";
	cout << "\tResults are written to stdout\n";
}

typedef struct 
{
	bool open;
	int keyhole;
	int numkeys;
	vector<int> keys;
} chest_t;

int maxkeysize;
int numkeysininventory;
int keys[250];
vector<int> order;
chest_t chests[250];
int numchests;
int numchestsopened;
int nettotalkeys;


bool openChests() {
	int i, c, k, key;

	if (numchestsopened == numchests) {
		return true;
	}

	if (numkeysininventory == 0) {
		return false;
	}

	// Find first unopened chest that we have a key to
	for (c=0; c<numchests; c++) {
		if (!chests[c].open && keys[chests[c].keyhole]) {
			// Open the chest
			chests[c].open = true;
			keys[chests[c].keyhole]--;
			for (i=0; i<chests[c].numkeys; i++) { // add keys from chest to inventory
				keys[chests[c].keys[i]]++;
			}
			numkeysininventory += chests[c].numkeys - 1;
			numchestsopened++;
			order.push_back(c+1);

			for (i=0; i<order.size(); i++) {
				cout << order[i] << " ";
			}
			cout << "\n";

			if (openChests()) { // try to open other chests
				return true;
			} else {
				// undo opening this chest; try again
				order.pop_back();
				numchestsopened--;
				numkeysininventory -= chests[c].numkeys - 1;
				for (i=0; i<chests[c].numkeys; i++) { // put keys back in chest
					keys[chests[c].keys[i]]--;
				}
				keys[chests[c].keyhole]++;
				chests[c].open = false;
			}
		}
	}

	return false; // we don't have a key to open a chest :(
}


int main(int argc, char *argv[])
{
	int i, c, k, key, numcases;
	int numstartkeys;
	int keycheck[250];

	if (argc != 1) {
		usage();
		return -1;
	}

	cin >> numcases;
	for (i=1; i<=numcases; i++) {
		cin >> numstartkeys >> numchests;
		
		// Get starting keys
		memset(keys, 0, 250);
		memset(keycheck, 0, 250);
		maxkeysize = 0;
		nettotalkeys = numstartkeys;
		numkeysininventory = numstartkeys;
		for (k=0; k<numstartkeys; k++) {
			cin >> key;
			keys[key]++;
			keycheck[key]++;
		}

		// Get chests
		for (c=0; c<numchests; c++) {
			chests[c].open = false;
			chests[c].keys.clear();
			cin >> chests[c].keyhole >> chests[c].numkeys;
			keycheck[chests[c].keyhole]--;
			nettotalkeys += chests[c].numkeys;
			for (k=0; k<chests[c].numkeys; k++) {
				cin >> key;
				keycheck[key]++;
				chests[c].keys.push_back(key);
			}
		}

		// Quick test of impossibility
		if (nettotalkeys < numchests) {
			cout << "Case #" << i << ": IMPOSSIBLE\n";
			continue;
		}

		// Another quick test of impossibility
		/*for (k=0; k<=maxkeysize; k++) {
			if (keycheck[k] < 0) {
				cout << "Case #" << i << ": IMPOSSIBLE";
				break; continue;		
			}
		}*/

		numchestsopened = 0;
		order.clear();
		if (!openChests()) {
			cout << "Case #" << i << ": IMPOSSIBLE\n";
		} else {
			cout << "Case #" << i << ": "; 
			for (c=0; c<numchests; c++) {
				cout << order[c] << " ";
			}
			cout << "\n";
		}

	}

	return 0;
}
