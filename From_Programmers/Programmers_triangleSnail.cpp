#include <vector>

using namespace std;

int dir[3][2] = {
		{1,0},
		{0,1},
		{-1,-1}
};

vector<int> solution(int n) {    
    int** arr = new int* [n];
	for (int i = 0; i < n; i++) arr[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
    

	int sum = 0;
	for (int i = 1; i <= n; i++) sum += i;
    
    vector<int> answer;

	int cnt = 1;
	int x = 0, y = 0;
	while (cnt <= sum) {
		for (int i = 0; i < 3; i++) {
			if (cnt > sum) break;
			while (true) {
				arr[y][x] = cnt++;

				y += dir[i][0];
				x += dir[i][1];

				if ((x >= n || x < 0) || (y >= n || y < 0) || arr[y][x]) {
					y -= dir[i][0];
					x -= dir[i][1];
					break;
				}
			}
			if (cnt <= sum) cnt--;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(arr[i][j]);
		}
	}
    
    return answer;
}