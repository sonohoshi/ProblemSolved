#include <iostream>
using namespace std;

int factorial(int n){
    if(n <= 1) return 1;
    return n * factorial(n-1);
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << factorial(n) / (factorial(r) * factorial(n-r));
    return 0;
}
