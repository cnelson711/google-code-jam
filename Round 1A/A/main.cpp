/*

Theory:

Area of circle = [pi * r^2] cm^2 = [r^2] mL
Area of ring = [(r+1)^2 - r^2] mL = [2r + 1] mL
Area of multiple rings = Sum of arithmetic series
Sum of arithmetic series = number of terms * (first+last)/2
Let:
  n = number of rings
  r = smallest radius
  t = mL of paint required
  first = 2r + 1
  last  = 2(rlast) + 1 = 4n + 2r - 3
t = n*(first+last)/2
t = n*(4n + 4r - 2)/2
0 = 2n^2 + (2r-1)n - t
Solve for n using the quadratic formula in the form: 0 = ax^2 + bx + c

*/

#include <iostream>
#include "gmpxx.h"
typedef mpz_class bignumber;
using namespace std;

int main(int argc, char *argv[])
{
	int i, numcases;
	long r, t;

	cin >> numcases;
	for (i=1; i<=numcases; i++) {
		cin >> r >> t;
		
		bignumber a, b, c, n;
		a = 2;
		b = 2*r - 1;
		c = -t;
		n = (-b + sqrt(b*b - 4*a*c) ) / (2*a);

		cout << "Case #" << i << ": " << n << endl;
	}

	return 0;
}
