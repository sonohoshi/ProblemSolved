#include <iostream>

using namespace std;

long DP[30] = { 1, 1, };

long dp(int n) {
	if (DP[n] == 0) {
		DP[n] = dp(n - 1) + 2 * dp(n - 2);

		return DP[n];
	}

	return DP[n];
}

int main() {
	int n;
	cin >> n;
	cout << dp(n);
}