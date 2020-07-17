#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

bool cut(long long* arr, long long h, long long size, long long key) {
	long long sum = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] - h <= 0) continue;
		sum += arr[i] - h;
	}
	if (sum >= key) return true;
	return false;
}

int search(long long* arr, long long size, long long key) {
	int start = 0;
	int last = 2000000000;
	int mid;
	while (last - start >= 0) {
		mid = (start + last) / 2;
		if (cut(arr, mid, size, key))
			start = mid + 1;
		else
			last = mid - 1;
	}
	return last;
}

int main() {
	long long n;
	long long int m;
	long long int trees[1000005];
	int canCut;
	long long cut = -1;
	long long int h;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}
	qsort(trees, n, sizeof(long long), compare);
	cout << search(trees, n, m);

	return 0;
}

/*
https://www.acmicpc.net/problem/2805

����̴� ���� M���Ͱ� �ʿ��ϴ�. ��ó�� ������ ������ ���� ��� ���ع��ȱ� ������, ���ο� ���� �㰡�� ��û�ߴ�. 
���δ� ����̳� �� ��ó�� ���� �� �ٿ� ���� ���� �㰡�� ���־���, ����̴� ���� ������ �������ܱ⸦ �̿��ؼ� ������ ���Ұ��̴�.

�������ܱ�� ������ ���� �����Ѵ�. ����, ����̴� ���ܱ⿡ ���� H�� �����ؾ� �Ѵ�. 
���̸� �����ϸ� �鳯�� �����κ��� H���� ���� �ö󰣴�. �� ����, �� �ٿ� �������ִ� ������ ��� �����ع�����. 
����, ���̰� H���� ū ������ H ���� �κ��� �߸� ���̰�, ���� ������ �߸��� ���� ���̴�. 
���� ���, �� �ٿ� �������ִ� ������ ���̰� 20, 15, 10, 17�̶�� ����. ����̰� ���̸� 15�� �����ߴٸ�, 
������ �ڸ� ���� ���̴� 15, 15, 10, 15�� �� ���̰�, ����̴� ���̰� 5�� ������ 2�� ������ ��� ���� �� ���̴�. (�� 7���͸� ���� ��� ����)

����̴� ȯ�濡 �ſ� ������ ���� ������, ������ �ʿ��� ��ŭ�� ������ ���������� �Ѵ�. 
�̶�, ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� ������ �� N�� ����̰� ������ ���������� �ϴ� ������ ���� M�� �־�����. (1 �� N �� 1,000,000, 1 �� M �� 2,000,000,000)

��° �ٿ��� ������ ���̰� �־�����.
������ ������ ���� �׻� M�� �ѱ� ������, ����̴� ���� �ʿ��� ������ �׻� ������ �� �ִ�.
���̴� 1,000,000,000���� �۰ų� ���� ���� ���� �Ǵ� 0�̴�.

��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ����Ѵ�.
*/