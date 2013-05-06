#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

// Combination
long choose(int n, int k)
{
	if (k > n)
		return 0;
	long r = 1;
	for (int d=1; d<=k; d++) {
		r *= n--;
		r /= d;
	}
	return r;
}

/*
 * Notice the pattern as more diamonds fall; there is always a core 
 * "perfect pyramid" and 0 or more diamonds that slide down either side of 
 * the perfect pyramid.
 * 
 * p = diamond in perfect pyramid
 * ? = possible diamond location on edge
 * d = known diamond location on edge
 * - = no diamond here
 *
 *        - - - - -            - - - - -            - - - - -          
 *       - - - - - -          - - - - - -          - - ? ? - -
 * n=1  - - - p - - -    n=2 - - ? p ? - -    n=3 - - ? p ? - - 
 *
 *                                                   - - - -
 *        - - - - -            - - - - -            - - p - - 
 *       - - ? ? - -          - - d d - -          - - p p - -
 * n=4  - - d p d - -    n=5 - - d p d - -    n=6 - - p p p - - 
 *
 *         - - - -              - - - -              - - - -
 *        - - p - -            - - p - -            - ? p ? - 
 *       - - p p - -          - ? p p ? -          - ? p p ? -
 * n=7  - ? p p p ? -    n=8 - ? p p p ? -    n=9 - ? p p p ? - 
 *
 *          - - -                - - -                - - -
 *         - ? ? -              - ? ? -              - ? ? -
 *        - ? p ? -            - ? p ? -            - ? p ? - 
 *       - ? p p ? -          - ? p p ? -          - d p p d -
 * n=7  - ? p p p ? -    n=8 - d p p p d -    n=9 - d p p p d - 
 */
int main()
{
	int numcases;
	cin >> numcases;

	for (int i=1; i<=numcases; i++) {
		int n, x, y;
		cin >> n >> x >> y;
		cout << "Case #" << i << ": ";

		float a, b, c;
		a = b = 1.0;
		c = (float) -2*n;
		
		// s = number of diamonds on side of perfect pyramid {1, 3, 5, 7...}
		int s = (int) floor((-b + sqrt(pow(b, 2.0) - 4.0*a*c)) / (2.0*a));
		s = (s%2 == 0) ? s-1 : s; // round down to nearest odd number
		// l = level of perfect pyramid {0, 1, 2...}
		int l = (s-1)/2;
		// np = number of diamonds in perfect pyramid {1, 6, 15, 28, 45, ...}
		int np = (s*s + s) / 2;
		// no = number of blocks left over
		int no = n - np; 
		// d = distance of property from origin
		int d = (abs(x) + y) / 2;

		// printf("\ns:%d\nl:%d\nnp:%d\nno:%d\nn:%d\nd:%d\nx:%d\ny:%d\n", s, l, np, no, n, d, x, y);

		if (d <= l) {
			// property is in the core part of the perfect pyramid
			cout << 1;
		} else if (d > l+1) {
			// property is outside the perfect pyramid and surrounding edge
			cout << 0;
		} else {
			// property is on the edge of the perfect pyramid

			// pos = position of the property on the side of the pyramid {1, 2, 3,... s+2}
			int pos = y+1;

			if (x == 0) {
				// property is at the top of the pyramid
				cout << 0;
			} else if (no > (s+1) && pos <= (no-s-1)) {
				// There are enough left over blocks (no) and the position of
				// the property (pos) is low enough that it will always have a diamond 
				cout << 1;
			} else {
				// We know the probability is not 0 or 1
				float favorable = 0;
				float possible = pow(2, no);
				for (int j=pos; j<=no; j++)
					favorable += choose(no, j);

				cout << favorable/possible;
			}
		}
		cout << endl;
	}

	return 0;
}
