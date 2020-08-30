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

/*
배찌와 친구들은 카트라이더 게임을 즐겨한다. 
배찌와 친구들은 88명이 모여서 카트라이더 게임에서 44 대 44 경주를 하기로 하였다.

카트라이더는 대표적으로 아이템전과 스피드전 두 가지 모드가 존재한다. 
방장이 된 배찌는 방을 스피드전으로 만들지, 아이템전으로 만들지를 결정해야 한다.

배찌와 친구들은 각각 실력 지표를 가지고 있는데, 스피드전은 실력의 합이 높은 팀이 승리하고, 아이템전은 실력이 가장 높은 사람이 속한 팀이 승리한다. 
비기게 되는 경우도 존재하는데, 스피드전의 경우 두 팀의 실력의 합이 같으면 비기게 되고, 아이템전의 경우 두 팀의 가장 높은 실력이 같으면 비기게 된다.

승리에 목마른 배찌는 친구들의 실력에 따라 이길 수 있는 모드로 방을 만들려고 한다. 
자신을 포함한 모든 친구들의 실력을 알고 있을 때 배찌가 어떤 모드로 방을 만들어야 하는지 알려주는 프로그램을 만들어보자.

입력 형식
첫 줄에 테스트 케이스의 개수를 나타내는 정수 T가 주어진다. (1 <= T <= 1000)

다음 T 개의 줄에 대해서 8명의 실력을 나타내는 정수 8개가 공백으로 구분되어 주어지며, 
먼저 주어지는 4개의 수는 배찌가 속한 팀의 사람의 실력을 의미하고, 
나중에 주어지는 4개의 수는 상대 팀에 속한 사람의 실력을 의미한다. 
실력을 나타내는 정수는 1 이상 1 000 이하다.

출력 형식
각 테스트 케이스에 대해 각 줄에 아이템전으로 방을 만들면 이길 수 없고, 스피드전으로 방을 만들어야만 이길 수 있는 경우는 S를,
스피드전으로 방을 만들면 이길 수 없고 아이템전으로 방을 만들어야만 이길 수 있는 경우는 I를, 
그 외의 경우, 즉, 어떻게 방을 만들어도 모두 이기거나, 모두 이기지 못하는 경우는 R를 출력한다. 
여기서, 이기지 못한다는 것은 비기는 경우도 포함한다. 세 경우 모두 알파벳 대문자로 출력한다.
*/