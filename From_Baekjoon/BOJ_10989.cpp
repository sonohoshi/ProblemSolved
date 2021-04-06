#include <iostream>
#include <cstdio>

int main() {
	int count[10001] = { 0, };

	int n, m;
	std::cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        count[m]++;
    }

    for(int i=0;i<10001;i++){
        if(count[i]){
            for(int j=0;j<count[i];j++) printf("%d\n",i);
        }
    }

    return 0;
}
