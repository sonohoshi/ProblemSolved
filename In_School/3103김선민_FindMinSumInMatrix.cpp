#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = vector<int>(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	int* minList = new int[n];
	int* minIndex = new int[n];
	for (int i = 0; i < n; i++) {
		minList[i] = 9999;
		minIndex[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool isEqual = false;
			if (minList[i] > v[i][j]) {
				for (int k = 0; k < i; k++) {
					if (j == minIndex[k]) {
						isEqual = true;
					}
				}
				if (isEqual) continue;
				minList[i] = v[i][j];
				minIndex[i] = j;
			}
			if (minList[i] > v[j][i]) {
				for (int k = 0; k < i; k++) {
					if (j == k) {
						isEqual = true;
					}
				}
				if (isEqual) continue;
				minList[i] = v[j][i];
				minIndex[i] = i;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += minList[i];
	}
	cout << sum;

	delete[] minList;
	delete[] minIndex;

	return 0;
}