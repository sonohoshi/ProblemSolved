#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	
	cout << (v - b - 1) / (a - b) + 1;

	return 0;	
}