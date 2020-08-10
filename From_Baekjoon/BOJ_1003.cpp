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
