#include <iostream>
using namespace std;

int fibo[40][2] = {{1,0},{0,1}};

int* cnt(int n){
	if(!n || n == 1){
		return fibo[n];
	}
	if(fibo[n][0] && fibo[n][1]){
		return fibo[n];
	}
	fibo[n][0] = cnt(n - 1)[0] + cnt(n - 2)[0];
	fibo[n][1] = cnt(n - 1)[1] + cnt(n - 2)[1];
	return fibo[n];
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int m;
		cin >> m;
		cout << cnt(m)[0] << ' ' << cnt(m)[1] << endl;
	}
	return 0;
}

/*
https://www.acmicpc.net/problem/1003

fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
fibonacci(0)은 0을 출력하고, 0을 리턴한다.
fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
*/
