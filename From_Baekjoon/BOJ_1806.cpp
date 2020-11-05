#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	int arr[100001];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int now = 0;
	int nowLen = 0;

	int minLen = n + 1;

	int start = 0, end = -1;
	while(end < n) {
		if (s > now) {
			now += arr[++end];
			nowLen++;
		}
		else if (s <= now) {
			if (nowLen < minLen) minLen = nowLen;
			now -= arr[start++];
			nowLen--;
		}
	}

	cout << (minLen <= n ? minLen : 0);

	return 0;
}