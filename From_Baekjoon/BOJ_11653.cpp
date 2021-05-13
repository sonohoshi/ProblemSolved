#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= sqrt(n); i++) {
		while (!(n % i)) {
			cout << i << endl;
			n /= i;
		}
	}

	if (n != 1) cout << n;
	return 0;
}