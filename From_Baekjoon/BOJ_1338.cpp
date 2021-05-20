#include <iostream>

#define LLONG_MAX 9223372036854775807

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	long long min, max, x, y, res = LLONG_MAX;
	bool found = false;
	cin >> min >> max;
	cin >> x >> y;

	x = abs(x);

	if (min > max) swap(min, max);
	if (max - min >= 2 * x || !(0 <= y && y < x)) {
		return !(cout << "Unknwon Number");
	}

	long long start = min;

	if ((min % x + x) % x == y);
	else if ((min % x + x) % x <= y) start += y - (min % x + x) % x;
	else start += x - (min % x + x) % x + y;

	for (long long i = start; i <= max; i += x) {
		if ((i % x + x) % x == y) {
			if (found) return !(cout << "Unknwon Number");
			found = true, res = i;
		}
	}

	if (res == LLONG_MAX) return !(cout << "Unknwon Number");
	return !(cout << res);
}