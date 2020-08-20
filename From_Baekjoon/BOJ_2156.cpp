#include <iostream>
#include <algorithm>
using namespace std;

int dp[10000][3];

int DP(int* cup, int n) {
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][0]);
		dp[i][1] = dp[i-1][0] + cup[i];
		dp[i][2] = dp[i-1][1] + cup[i];
	}
	return max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}

int main() {
	int n;
	cin >> n;
	int* cup = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> cup[i];
	}
	dp[0][0] = 0;
	dp[0][1] = cup[0];
	dp[0][2] = 0;

	cout << DP(cup, n);

	delete cup;
	return 0;
}