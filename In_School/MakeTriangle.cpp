#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int sum, cnt = 0;
	cin >> sum;
	for (a = 1; a <= sum / 3; a++) {
		for (b = (sum - a) / 2; b >= a; b--) {
			c = sum - (a + b);
			if (c < a + b) {
				printf("%d %d %d\n", a, b, c);
				cnt++;
			}
			else {
				break;
			}
		}
	}

	printf("count = %d", cnt);
}