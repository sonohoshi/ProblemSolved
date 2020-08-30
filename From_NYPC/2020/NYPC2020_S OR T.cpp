#include <iostream>

using namespace std;

int jump(string str) {
	int sum = 0;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == 'S') {
			sum++;
		}
		else {
			sum += (4 - sum % 4);
		}
	}
	return sum;
}

int main() {
	string str;
	cin >> str;

	cout << jump(str);
	return 0;
}