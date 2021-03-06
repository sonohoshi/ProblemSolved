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

/*
카트라이더 러쉬플러스를 재밌게 즐기고 있는 월희는 최근 "커브 퀘스트"에 열심히 도전하고 있습니다.

커브 퀘스트에서는 정해진 트랙 구간을 완주하는 데 걸린 시간에 따라 별을 획득할 수 있습니다. 
별은 미리 정해져 있는 시간 T1, T2, T3 (T1 > T2 > T3) 에 대해서 다음과 같이 주어집니다.

 - T3 이내에 완주하면 별 3개
 - T3보단 늦지만 T2 이내에 완주하면 별 2개
 - T2보단 늦지만 T1 이내에 완주하면 별 1개
 - T1보다 늦은 시간 안에 완주하면 별 0개

월희는 이 커브 퀘스트를 총 N번 시도했습니다. 
각 시도에서 완주하는 데 걸린 시간이 주어졌을 때 각각 별을 몇 개 받을 수 있을지 계산하는 프로그램을 작성하시오.

입력 형식
세 줄에 걸쳐 i번째 줄에 별 i개를 받기 위해 필요한 시간 Ti가 주어진다. T1 > T2 > T3)
다음 줄에 월희의 시도 횟수를 나타내는 정수 N이 주어진다. (1 >= N <= 100,000)
다음 N개의 줄에 걸쳐 각 시도에서 완주하는 데 걸린 시간이 주어진다.
단, 모든 시간은 a:b:c의 형식으로 주어진다. (0 <= a,c <= 99; 0 <= b <= 50; a:b:c != 00:00:00)

이때 a, b, c는 항상 두 자릿수며 각각 분, 초, 백분의 일 초 단위를 의미한다.\

출력 형식
N개의 줄에 걸쳐 각 시도에 획득할 수 있는 별의 개수를 다음과 같은 형식으로 출력하시오.
 - 만약 별을 1개 이상 받을 수 있다면 받을 수 있는 별의 개수만큼 *을 출력
 - 만약 별을 받을 수 없다면 :( 출력
*/