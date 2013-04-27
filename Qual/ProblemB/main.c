#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>

void usage() 
{
	printf("usage: cat testset.txt | ./main > output.txt \n");
	printf("\ttestset - testset filename\n");
	printf("\tResults are written to stdout\n");
}

// Trick is that for each 1x1m square, either:
// 1) the row it is in has grass of the same height or less
// OR
// 2) the col it is in has grass of the same height or less
void lawnState(char lawn[100][100], int n, int m, int lawnnum) {
	int x, y, r, c, maxheight;
	bool rowvalid, colvalid;

	if (n==1 || m==1) {
		printf("Case #%d: YES\n", lawnnum);
		return;
	}

	for (x=0; x<m; x++) {
		for (y=0; y<n; y++) {
			maxheight = lawn[x][y];
			rowvalid = true;
			colvalid = true;

			// Check row
			for (r=0; r<m; r++) {
				if (lawn[r][y] > maxheight) {
					rowvalid = false;
					break;
				}
			}
			// Check col
			for (c=0; c<n; c++) {
				if (lawn[x][c] > maxheight) {
					colvalid = false;
					break;
				}
			}

			if (!rowvalid && !colvalid) {
				printf("Case #%d: NO\n", lawnnum);
				return;
			}
		}
	}

	printf("Case #%d: YES\n", lawnnum);
}


int main(int argc, char *argv[])
{
	int gamenum, gamecount;
	int i, n, m, x, y, temp;
	char game[100][100];

	if (argc != 1) {
		usage();
		return -1;
	}

	scanf("%d", &gamecount);

	for (gamenum=1; gamenum<=gamecount; gamenum++) {
		scanf("%d %d", &n, &m);

		for (y=0; y<n; y++) {
			for (x=0; x<m; x++) {
				scanf("%d", &temp);
				game[x][y] = (char) temp;
				//printf("%d", temp);
			}
			//printf("\n");
		}

		lawnState(game, n, m, gamenum);
	}
}
