#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <vector>
#include <cstring>
#include "gmpxx.h"
typedef mpz_class bignumber;

using namespace std;

typedef struct 
{
	char word[16];
	bool eliminated;
} word;

int main(int argc, char *argv[])
{
	int i, j, k, w;
	int letters, numwords, numcases;
	word words[5000];
	char line[512];

	cin >> letters >> numwords >> numcases;
	
	// Get dictionary
	for (i=0; i<numwords; i++) {
		cin >> words[i].word;
		words[i].eliminated = false;
	}

	for (i=1; i<=numcases; i++) {

		cin >> line;
		
		// for each letter, use P.O.E.
		int ind = 0;
		for (j=0; j<letters; j++) {
			if (line[ind] != '(') {
				for(w=0; w<numwords; w++) {
					if (words[w].word[j] != line[ind]) {
						words[w].eliminated = true;
					}
				}
				ind++;
			} else {
				for(w=0; w<numwords; w++) {
					if (!words[w].eliminated) {
						bool match = false;
						for (k=ind+1; line[k] != ')'; k++) {
							if (line[k] == words[w].word[j]) {
								match = true;
								break;
							}
						}
						if (!match) words[w].eliminated = true;
					}
				}
				while (line[ind] != ')') ind++;
				ind++;
			}
		}
		
		int sum = 0;
		for (j=0; j<numwords; j++) {
			if (!words[j].eliminated) sum++;
			words[j].eliminated = false;
		}

		cout << "Case #" << i << ": " << sum << endl;
	}

	return 0;
}
