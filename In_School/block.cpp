#include <iostream>

using namespace std;

int cnt = 0;
int ptr = 0;
int dp[30];

void rec(int n, int m) {
	if (!n) {
		for (int i = 0; i < ptr; i++) {
			printf("%d ", dp[i]);
		}
		printf("\n");
		cnt++;
		return;
	}

	int i = n > m ? m : n;
	for (; i >= 1; i--) {
		dp[ptr++] = i;
		rec(n - i, i);
		ptr--;
	}
}

int main() {
	int n;
	cin >> n;
	rec(n, n);
	printf("\ncount : %d", cnt);
}