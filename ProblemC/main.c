#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdint.h>

#define MAXDIGITS 14

void usage() 
{
	printf("usage: cat testset.txt | ./main > output.txt \n");
	printf("\ttestset - testset filename\n");
	printf("\tResults are written to stdout\n");
}

void makeOddPalindrome(char *num, int digits) {
	int i;
	
	for (i=0; i<digits - 1; i++) {
		num[2*digits-2-i] = num[i];
	}
	num[2*digits-1] = 0;
}

void makeEvenPalindrome(char *num, int digits) {
	int i;
	
	for (i=0; i<digits; i++) {
		num[2*digits-1-i] = num[i];
	}
	num[2*digits] = 0;
}

bool isPalindrome(char *num) {
	int i, len = strlen(num);
	for (i=0; i<=len/2; i++) {
		if (num[i] != num[len-i-1]) {
			return false;
		}
	}
	return true;
}

void square(char *input, char *output) {
	if (strlen(input) <= 7) {
		long unsigned temp = atol(input);
		sprintf(output, "%lu", temp*temp);
	} else {
		// ERROR! todo - multiply beyond long boundary
	}
}

// is a < b
bool isLessThan(char *a, char *b) {
	int lena = strlen(a);
	int lenb = strlen(b);
	int i;

	if (lena != lenb) {
		return lena < lenb;
	}

	for (i=0; i<lena; i++) {
		if (a[i] > b[i])
			return false;
		if (a[i] < b[i])
			return true;
	}

	return false; // they are equal
}



int main(int argc, char *argv[])
{
	long unsigned count, top = 10;
	int fsnum = 1;
	bool oddPal = true;
	char buffer[70];
	char bigbuffer[200];

	char *fairsquares[1024];
	int maxfairsquares = 1024;

	int numcases, startind, stopind, i;
	char start[200], stop[200];

	if (argc != 1) {
		usage();
		return -1;
	}

	// Calculate all fair squares
	fairsquares[0] = "0";
	while (1) {
		for (count=top/10; count<top; count++) {
				sprintf(buffer, "%lu", count);

				if (oddPal)
					makeOddPalindrome (buffer, strlen(buffer));
				else
					makeEvenPalindrome(buffer, strlen(buffer));

				square(buffer, bigbuffer);
				if (isPalindrome(bigbuffer)) {
					fairsquares[fsnum] = malloc(strlen(bigbuffer)+1);
					memcpy(fairsquares[fsnum], bigbuffer, strlen(bigbuffer)+1);
					printf("%d %s %s\n", fsnum, buffer, bigbuffer);
					fsnum++;
					if (fsnum >= maxfairsquares) break;
				}
		}

		if (strlen(bigbuffer) > MAXDIGITS || fsnum >= maxfairsquares) {
			break;
		}

		if (oddPal) {
			oddPal = false;
		} else {
			oddPal = true;
			top *= 10;
		}
	}

	// for (i=0; i<fsnum; i++) printf("%d: %s\n", i, fairsquares[i]);

	// Run through cases
	scanf("%d", &numcases);
	for (i=1; i<=numcases; i++) {
		scanf("%s %s", start, stop);
		startind = stopind = 0;

		for (stopind=0; stopind<fsnum; stopind++) {

			if (isLessThan(fairsquares[stopind], start)) {
				startind = stopind;
			}

			if (isLessThan(stop, fairsquares[stopind])) {
				break;
			}
		}

		printf("Case #%d: %d\n", i, stopind - startind - 1);
	}

	return 0;
}
