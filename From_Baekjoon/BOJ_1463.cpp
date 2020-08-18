#include <iostream>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

int cache[10000000] = { 0,0,1,1 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			cache[i] = 0; continue;
		}
		int ans = 100000;
		if (i % 3 == 0) {
			ans = min(ans,cache[i/3]);
		}
		if (i % 2 == 0) {
			ans = min(ans, cache[i / 2]);
		}
		cache[i] = 1 + min(ans,cache[i-1]);
	}
	cout << cache[n];
	return 0;
}