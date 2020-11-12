#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	priority_queue<int> pq;

	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
	}

	do {
		if (priorities.front() < pq.top()) {
			int n = priorities.front();
			priorities.erase(priorities.begin());
			priorities.push_back(n);
			if (!location) {
				location = priorities.size();
			}
		}
		else {
			priorities.erase(priorities.begin());
			pq.pop();
			answer++;
		}
	} while (location--);

	return answer;
}

int main() {
	vector<int> v;
	
	v.push_back(1);
	v.push_back(1);
	v.push_back(9);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	
	
	cout << solution(v, 0);
	return 0;
}

// https://programmers.co.kr/learn/courses/30/lessons/42587

/*
풀 때 확인해야 하는 것

location이 0번째 인덱스에 있을 경우, while문을 do-while에서 처리해야할 수 있다.
location이 0일 때, 뒤로 보내면서 location 값을 다시 조정해줘야 한다.
*/