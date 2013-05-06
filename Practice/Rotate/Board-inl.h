
template <class T>
Board<T>::Board(int w, int h) 
{
	width = w;
	height = h;
	board = new T[w*h];
}


template <class T>
Board<T>::~Board() 
{
	delete(board);
}


template <class T>
void Board<T>::setElement(T val, int x, int y)
{
	board[y*width + x] = val;
}


template <class T>
void Board<T>::iterate2d(char rcdmask, 
                      std::function<void (T &, int, int)> f_element, 
                      std::function<void ()> f_rcd_before, 
                      std::function<void ()> f_rcd_after) 
{
	if (rcdmask & I2D_ROWS) {
		for (int y=0; y<height; y++) {
			if (f_rcd_before) f_rcd_before();
			for (int x=0; x<width; x++) {
				int xtmp = (rcdmask & I2D_REVERSE_ORDER) ? width - x - 1 : x;
				if (f_element) f_element(board[y*width + xtmp], xtmp, y);
			}
			if (f_rcd_after) f_rcd_after();
		}
	} 

	if (rcdmask & I2D_COLUMNS) {
		for (int x=0; x<width; x++) {
			if (f_rcd_before) f_rcd_before();
			for (int y=0; y<height; y++) {
				int ytmp = (rcdmask & I2D_REVERSE_ORDER) ? height - y - 1 : y;
				if (f_element) f_element(board[ytmp*width + x], x, ytmp);
			}
			if (f_rcd_after) f_rcd_after();
		}
	} 

	if (rcdmask & I2D_ANTIDIAGONALS) {
		for (int d=0; d<width+height-1; d++) {
			int starty = (d < height) ? d : height-1;
			int startx = (d < height) ? 0 : d - height + 1;
			if (f_rcd_before) f_rcd_before();
			for (int i=0; starty-i>=0 && startx+i<width; i++) {			
				int y = starty - i;
				int x = startx + i;
				if (f_element) f_element(board[y*width + x], x, y);
			}
			if (f_rcd_after) f_rcd_after();
		}
	}

	if (rcdmask & I2D_DIAGONALS) {
		for (int d=0; d<width+height-1; d++) {
			int starty = (d < height) ? height - d - 1 : 0;
			int startx = (d < height) ? 0 : d - height + 1;
			if (f_rcd_before) f_rcd_before();
			for (int i=0; starty+i<height && startx+i<width; i++) {			
				int y = starty + i;
				int x = startx + i;
				if (f_element) f_element(board[y*width + x], x, y);
			}		
			if (f_rcd_after) f_rcd_after();
		}
	}
}
