#include <iostream>
using namespace std;

int main() {
	int time[3];
	int sum[3];
	int tryCount, trySum;
	for (int i = 0; i < 3; i++) {
		scanf("%d:%d:%d", &time[0], &time[1], &time[2]);
		sum[i] = time[0] * 6000 + time[1] * 100 + time[2];
	}
	scanf("%d", &tryCount);
	for (int i = 0; i < tryCount; i++) {
		int j;
		scanf("%d:%d:%d", &time[0], &time[1], &time[2]);
		trySum = time[0] * 6000 + time[1] * 100 + time[2];
		for (j = 0; j < 3; j++) {
			if (sum[j] >= trySum) printf("*");
			else break;
		}
		if (!j) printf(":(");
		printf("\n");
	}
	return 0;
}