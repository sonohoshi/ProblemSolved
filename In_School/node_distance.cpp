#include <iostream>
#include <algorithm>
using namespace std;

int CheckIsParent(int p, int c) {
	int cnt = 0;
	while (p != c) {
		if (!(c % 2))
			c /= 2;
		else
			c = (c - 1) / 2;
		cnt++;

		if (c == 1 && p != 1) return 0;
	}
	return cnt;
}

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;

	if (n > m) {
		n ^= m ^= n ^= m;
	}
	
	while (!CheckIsParent(n,m)) {
		if (!(n % 2)) {
			n /= 2;
			cnt++;
		}
		else {
			n = (n - 1) / 2;
			cnt++;
		}
	}
	
	cout << cnt + CheckIsParent(n, m);
}