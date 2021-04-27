#include <iostream>

using namespace std;

int dp[1000][10];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) dp[0][i] = 1;

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j < 10; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j-1];
			dp[i][j] %= 10007;
		}
	}

	auto sum = 0;
	for (int i = 0; i < 10; i++) sum += dp[n - 1][i];
	
	printf("%d", sum % 10007);

	return 0;
}