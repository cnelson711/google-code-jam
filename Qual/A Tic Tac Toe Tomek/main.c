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


void gameState(char game[4][4], int gamenum) {
	int x, y;
	bool gameover = true;
	bool Ocanwincol, Xcanwincol;
	bool Ocanwinrow, Xcanwinrow;
	bool Ocanwindia1 = true;
	bool Xcanwindia1 = true;
	bool Ocanwindia2 = true;
	bool Xcanwindia2 = true;

	for (x=0; x<4; x++) {
		Ocanwincol = true;
		Xcanwincol = true;
		Ocanwinrow = true;
		Xcanwinrow = true;

		for (y=0; y<4; y++) {
			// Check columns
			switch (game[x][y]) {
				case 'X':
					Ocanwincol = false;
					break;
				case 'O':
					Xcanwincol = false;
					break;
				case '.':
					gameover = false;
					Xcanwincol = false;
					Ocanwincol = false;
					break;
				case 'T':
					break;
				default:
					printf("ERROR\n");
					return;
			}

			// Check rows
			switch (game[y][x]) {
				case 'X':
					Ocanwinrow = false;
					break;
				case 'O':
					Xcanwinrow = false;
					break;
				case '.':
					gameover = false;
					Xcanwinrow = false;
					Ocanwinrow = false;
			}
		}

		if (Ocanwinrow || Ocanwincol) {
			printf("Case #%d: O won\n", gamenum);
			return;
		}

		if (Xcanwinrow || Xcanwincol) {
			printf("Case #%d: X won\n", gamenum);
			return;
		}

		// Check diagonals
		switch (game[x][x]) {
			case 'X':
				Ocanwindia1 = false;
				break;
			case 'O':
				Xcanwindia1 = false;
				break;
			case '.':
				Xcanwindia1 = false;
				Ocanwindia1 = false;
		}

		// Check diagonals
		switch (game[4-x-1][x]) {
			case 'X':
				Ocanwindia2 = false;
				break;
			case 'O':
				Xcanwindia2 = false;
				break;
			case '.':
				Xcanwindia2 = false;
				Ocanwindia2 = false;
		}
	}

	if (Ocanwindia1 || Ocanwindia2) {
		printf("Case #%d: O won\n", gamenum);
		return;
	}

	if (Xcanwindia1 || Xcanwindia2) {
		printf("Case #%d: X won\n", gamenum);
		return;
	}

	if (gameover) {
		printf("Case #%d: Draw\n", gamenum);
	} else {
		printf("Case #%d: Game has not completed\n", gamenum);
	}
}


int main(int argc, char *argv[])
{
	int gamenum, gamecount;
	int i, x, y;
	char game[4][4];
	char buffer[1024];

	if (argc != 1) {
		usage();
		return -1;
	}

	gamecount = atoi(fgets(buffer, sizeof(buffer), stdin));

	for (gamenum=1; gamenum<=gamecount; gamenum++) {
		for (y=0; y<4; y++) {
			fgets(buffer, sizeof(buffer), stdin);
			for (x=0; x<4; x++) {
				game[x][y] = buffer[x];
			}
		}

		gameState(game, gamenum);

		fgets(buffer, sizeof(buffer), stdin); // get empty line
	}
}
