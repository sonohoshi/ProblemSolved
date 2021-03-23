#include <iostream>

using namespace std;

int cnt = 0;

void rec(int before, int total) {
	if (before == total) {
		cnt++;
		return;
	}

	if (before + 1 <= total) {
		rec(before + 1, total);
	}

	if (before + 2 <= total) {
		rec(before + 2, total);
	}

	if (before + 3 <= total) {
		rec(before + 3, total);
	}
}

int main() {
	int n;
	cin >> n;

	rec(1, n);
	rec(2, n);
	rec(3, n);

	cout << cnt;
}