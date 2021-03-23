#include <iostream>

using namespace std;

int main() {
	int n, m, mul, cnt = 0;
	cin >> n >> m;

	while (n != m) {
		auto temp = m - n;
		
		if (temp < 0) mul = -1;
		else mul = 1;

		auto modTemp = abs((m % 5) - (n % 5));
		if (abs(modTemp) != 0) {
			if (abs(modTemp) <= 2) {
				cnt += abs(modTemp);
				n += (m % 5) - (n % 5);
				continue;
			}

			if (abs(modTemp) >= 3) {
				cnt += 5 - abs(modTemp);
				n += modTemp;
				continue;
			}
		}

		if (abs(temp) >= 10) {
			n += 10 * mul;
		}
		else if (abs(temp) >= 5) {
			n += 5 * mul;
		}
		else n += mul;

		cnt++;
	}

	cout << cnt;
}