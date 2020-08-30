#include <iostream>
using namespace std;

int Referee(int a, int b) {
	if (a > b) return 1;
	return 0;
}

int main() {
	int n;
	int skill[8];
	int myBest = 0, mySum = 0;
	int verBest = 0, verSum = 0;
	int sg, ig;
	cin >> n;
	for (int i = 0; i < n; i++) {
		myBest = mySum = verBest = verSum = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &skill[j]);
			if (skill[j] > myBest) myBest = skill[j];
			mySum += skill[j];
		}
		for (int j = 4; j < 8; j++) {
			scanf("%d", &skill[j]);
			if (skill[j] > verBest) verBest = skill[j];
			verSum += skill[j];
		}
		sg = Referee(mySum, verSum);
		ig = Referee(myBest, verBest);
		
		if (sg == ig) cout << 'R' << endl;
		else {
			if (sg > ig) cout << 'S' << endl;
			else cout << 'I' << endl;
		}
	}
	return 0;
}