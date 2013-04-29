
/*
Function for iterating over an mxn matrix:
m = # rows or height
n = # columns or width

a[0][0]  a[0][1]  a[0][2]
a[1][0]  a[1][1]  a[2][2]
*/
#include <functional>

#define I2D_REVERSE_ORDER 0x01 
// Regular order means x or y counts up from 0 to width or height.
// Reverse order means x or y counts down to 0 from width or height.

#define I2D_ROWS          0x02 
#define I2D_COLUMNS       0x04
#define I2D_DIAGONALS     0x08  // diags that lean left
#define I2D_ANTIDIAGONALS 0x10  // diags that lean right
#define I2D_ALL           0x1E

/*
 * array   = a 2D array; such as: char array[height][width]; access elements by array[y][x]
 * height  = number of rows
 * width   = number of columns
 * rcdmask = Row/Column/Diag mask; use 
 * f_element    = lambda function that runs per each element
 * f_rcd_before = lambda function that runs before each row/column/diagonal
 * f_rcd_after  = lambda function that runs after each row/column/diagonal
 */
void iterate2d(char *array, int height, int width, char rcdmask, 
	           std::function<void (char &, int, int)> f_element, 
	           std::function<void ()> f_rcd_before, 
	           std::function<void ()> f_rcd_after);