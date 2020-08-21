#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000] = { 0 };

int DP(int n) {
	int sum = 0;
	int tmp;
	cin >> dp[0];
	sum += dp[0];
	int max = dp[0];
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		dp[i] = tmp < sum ? sum : sum = tmp;
		max = std::max(max, dp[i]);
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	cout << DP(n);
	return 0;
}