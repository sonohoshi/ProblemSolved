#include <iostream>

using namespace std;

int tile[1001] = { 0,1,3 };

int dp(int n) {
	if (tile[n]) return tile[n];
	tile[n] = (dp(n - 1) + dp(n - 2) * 2) % 10007;
	return tile[n];
}

int main() {
	int n;
	cin >> n;
	cout << dp(n);
	return 0;
}