#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> pq;

int abs(int n) {
	if (n < 0) n *= -1;
	return n;
}

int main() {
	int n;
	int skill, m;
	cin >> n;
	cin >> skill >> m;
	for (int i = 0; i < n; i++) {
		int inputSkill;
		cin >> inputSkill;
		int input = skill - inputSkill;

		if (input > 0) pq.push_back(make_pair(input, -(i + 1)));
		else pq.push_back(make_pair(abs(input), i + 1));
	}
	sort(pq.begin(), pq.end());
	for (int i = 0; i < m; i++) {
		printf("%d ", abs(pq.at(i).second));
	}

	return 0;
}

/*
올해 한국에 출시된 카트라이더 러쉬플러스에 실력별 매칭이 도입되었다.
이 매칭 시스템에서는 모든 유저들에게 서로 다른 실력 점수를 매겨서 실력이 비슷한 사람들끼리 매칭시켜 준다.

매칭 대기열에는 현재 NN 명의 유저가 있다. 편의상 유저는 번호가 1부터 N까지 차례대로 매겨져 있다. 점수가 S인 새로운 유저가 매칭을 요청했다.
매칭 시스템을 구현하기 위해서 새로 들어온 유저와 실력 점수가 가장 가까운 K 명의 유저를 찾아보려고 한다.

실력 점수가 가깝다는 것은 실력 점수 차이가 작다는 것을 의미한다.
만약, 새로운 유저와 실력 점수 차이가 동일한 유저가 여러 명이라면 실력 점수가 낮은 유저가 더 가깝다고 생각하자.

입력 형식
첫 줄에 대기열에 있는 유저의 수를 나타내는 정수 N이 주어진다. (1 ≤ N ≤ 500,000)

둘째 줄에 새로 들어온 유저의 실력 점수를 나타내는 정수 S와 찾아야 하는 유저의 수를 나타내는 정수 K가 공백으로 구분되어 주어진다. (1 ≤ S ≤ 100,000,000; 1 ≤ K ≤ N)
셋째 줄에 대기열에 있는 유저들의 실력 점수를 나타내는 N 개의 정수가 공백으로 구분되어 주어진다.
i 번째로 주어지는 수는 i 번 유저의 실력 점수를 의미한다. 이때, 주어지는 점수는 S를 포함하여 모두 다르며, 1 이상 100,000,000 이하다.

출력 형식
첫 줄에 새로운 유저의 실력 점수와 가장 가까운 유저 K 명의 번호를 공백으로 구분하여 출력한다. 이때, 번호는 임의의 순서로 출력해도 된다.
*/