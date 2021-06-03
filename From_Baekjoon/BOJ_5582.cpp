#include <iostream>

using namespace std;

int lcs(string str1, string str2) {
	int** matrix, maxLen = 0;
	matrix = new int* [str1.length()];
	for (int i = 0; i < str1.length(); i++) matrix[i] = new int[str2.length()];

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] != str2[j]) matrix[i][j] = 0;
			else {
				matrix[i][j] = ((i == 0) || (j == 0)) ? 1 : 1 + matrix[i - 1][j - 1];

				maxLen = matrix[i][j] > maxLen ? matrix[i][j] : maxLen;
			}
		}
	}

	cout << ' ';
	for (auto c : str2) cout << ' ' << c;
	cout << endl;

	for (int i = 0; i < str1.length(); i++) {
		cout << str1[i] << ' ';
		for (int j = 0; j < str2.length(); j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

	return maxLen;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	cout << lcs(str1, str2);
}