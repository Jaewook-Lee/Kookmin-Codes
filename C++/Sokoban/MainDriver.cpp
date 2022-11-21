#include "MainDriver.h"

bool MainLogic::clear(int level, int** array)
{
    vector <vector<int> > c = Returnthree(level);
	bool count = true;
	for (int i = 0; i<c.size(); i++) {
		if (array[c[i][0]][c[i][1]] != 2) {
			count = false;
		}
	}
	return count;
}

void MainLogic::push(int v, int** array) {
	vector <vector<int> > c = Returnthree(level);
	int charX; int charY;
	charX = ReturnChar(array, charY);
    step+=1;
	if (v == 0403) {
		if (array[charX - 1][charY] == 1) {
		}
		else if (array[charX - 1][charY] == 0) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX - 1][charY] = 9;
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX - 1][charY] = 9;
			}
		}
		else if (array[charX - 1][charY] == 2) {
			if (array[charX - 2][charY] == 0 || array[charX - 2][charY] == 3) {
				bool count = false;
				for (int i = 0; i<c.size(); i++) {
					if (c[i][0] == charX && c[i][1] == charY) {
						array[charX][charY] = 3;
						array[charX - 1][charY] = 9;
						array[charX - 2][charY] = 2;
                        Count+=1;
						count= true;
						break;
					}
				}
				if (count == false) {
					array[charX][charY] = 0;
					array[charX - 1][charY] = 9;
					array[charX - 2][charY] = 2;
                    Count+=1;//박스 미는거
				}
			}
		}
		else if (array[charX - 1][charY] == 3) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX - 1][charY] = 9;
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX - 1][charY] = 9;
			}
		}
	}
	else if (v == 0402) {
		if (array[charX + 1][charY] == 1) {
		}
		else if (array[charX + 1][charY] == 0) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX + 1][charY] = 9;
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX + 1][charY] = 9;
			}
		}
		else if (array[charX + 1][charY] == 2) {
			if (array[charX + 2][charY] == 0 || array[charX + 2][charY] == 3) {
				bool count = false;
				for (int i = 0; i<c.size(); i++) {
					if (c[i][0] == charX && c[i][1] == charY) {
						array[charX][charY] = 3;
						array[charX + 1][charY] = 9;
						array[charX + 2][charY] = 2;
                        Count+=1;
						count= true;
						break;
					}
				}
				if (count == false) {
					array[charX][charY] = 0;
					array[charX + 1][charY] = 9;
					array[charX + 2][charY] = 2;
                    Count+=1;
				}
			}
		}
		else if (array[charX + 1][charY] == 3) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX + 1][charY] = 9;
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX + 1][charY] = 9;
			}
		}
	}
	else if (v ==0404) {
		if (array[charX][charY - 1] == 1) {
		}
		else if (array[charX][charY - 1] == 0) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX][charY - 1] = 9;
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX][charY - 1] = 9;
			}
		}
		else if (array[charX][charY - 1] == 2) {
			if (array[charX][charY - 2] == 0 || array[charX][charY - 2] == 3) {
				bool count = false;
				for (int i = 0; i<c.size(); i++) {
					if (c[i][0] == charX && c[i][1] == charY) {
						array[charX][charY] = 3;
						array[charX][charY - 1] = 9;
						array[charX][charY - 2] = 2;
                        count= true;
						Count+=1;
						break;
					}
				}
				if (count == false) {
					array[charX][charY] = 0;
					array[charX][charY - 1] = 9;
					array[charX][charY - 2] = 2;
                    Count+=1;
				}
			}
		}
		else if (array[charX][charY - 1] == 3) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX][charY - 1] = 9;
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX][charY - 1] = 9;
			}
		}
	}
	else if (v ==0405) {
		if (array[charX][charY + 1] == 1) {
		}
		else if (array[charX][charY + 1] == 0) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX][charY + 1] = 9;
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX][charY + 1] = 9;
			}
		}
		else if (array[charX][charY + 1] == 2) {
			if (array[charX][charY + 2] == 0 || array[charX][charY + 2] == 3) {
				bool count = false;
				for (int i = 0; i<c.size(); i++) {
					if (c[i][0] == charX && c[i][1] == charY) {
						array[charX][charY] = 3;
						array[charX][charY + 1] = 9;
						array[charX][charY + 2] = 2;
                        Count+=1;
						count= true;
						break;
					}
				}
				if (count == false) {
					array[charX][charY] = 0;
					array[charX][charY + 1] = 9;
					array[charX][charY + 2] = 2;
                    Count+=1;
				}
			}
		}
		else if (array[charX][charY + 1] == 3) {
			bool count = false;
			for (int i = 0; i<c.size(); i++) {
				if (c[i][0] == charX && c[i][1] == charY) {
					array[charX][charY] = 3;
					array[charX][charY + 1] = 9;    
					count = true;
					break;
				}
			}
			if (count == false) {
				array[charX][charY] = 0;
				array[charX][charY + 1] = 9;
			}
		}
	}
}