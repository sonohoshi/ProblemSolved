#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>

using namespace std;

int dist[1001][1001] = { {0}, };

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i <= s1.length(); i++) dist[0][i] = i;
	for (int j = 0; j <= s2.length(); j++) dist[j][0] = j;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) dist[j][i] = dist[j - 1][i - 1];
			else dist[j][i] = min(min(dist[j - 1][i] + 1, dist[j][i - 1] + 1), dist[j - 1][i - 1] + 1);
		}
	}

	cout << dist[s2.length()][s1.length()];

	return 0;
}