#include <iostream>
#include <cstdio>
using namespace std;

int heap[100005] = { 0 };
int countOfHeap = 0;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(int item) {
	heap[++countOfHeap] = item;

	int child = countOfHeap;
	int parent = child / 2;
	
	// ���� �˻����� ��尡 �θ𺸴� ���� ���, ��ȯ�ϸ鼭 ��� ��Ʈ������ �ö󰡴� ����.
	while (child > 1 && heap[parent] > heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

int pop() {
	if (!countOfHeap) return 0;

	int res = heap[1];

	swap(&heap[1], &heap[countOfHeap]);
	countOfHeap--;

	int parent = 1;
	int child = parent * 2;

	// �ڽ� ��� �� ���� ���� ã�� ����.
	if (child + 1 <= countOfHeap) {
		child = heap[child] < heap[child + 1] ? child : child + 1;
	}

	// ���� �˻����� ��尡 �ڽĺ��� ���� ���, ��ȯ�ϸ鼭 ��� �� ���� �༮�� ã�� �������� ����.
	while (child <= countOfHeap && heap[parent] > heap[child]) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = parent * 2;
		if (child + 1 <= countOfHeap) {
			child = heap[child] < heap[child + 1] ? child : child + 1;
		}
	}

	return res;
}

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (!m) printf("%d\n", pop());
		else push(m);
	}

	return 0;
}