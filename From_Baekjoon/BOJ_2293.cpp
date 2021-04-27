#include <iostream>
using namespace std;

int coin[101];
int dp[10010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[k]);

	return 0;
}