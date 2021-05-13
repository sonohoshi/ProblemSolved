#include <iostream>

using namespace std;

int main() {
	int c, r;
	cin >> r >> c;
	int** arr = new int* [r];
	for (int i = 0; i < r; i++) arr[i] = new int[c];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = 0;
		}
	}

	int dir[4][2] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}
	};

	int cnt = 1;
	int x = 0, y = 0;
	while (cnt <= c * r) {
		for (int i = 0; i < 4; i++) {
			if (cnt > c * r) break;
			while (true) {
				arr[y][x] = cnt++;

				y += dir[i][0];
				x += dir[i][1];

				if ((x >= c || x < 0) || (y >= r || y < 0) || arr[y][x]) {
					y -= dir[i][0];
					x -= dir[i][1];
					break;
				}
			}
			if (cnt <= c * r) cnt--;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%2d ", arr[i][j]);
		}
		cout << endl;
	}
}