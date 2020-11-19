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
	
	// 현재 검사중인 노드가 부모보다 작은 경우, 교환하면서 계속 루트노드까지 올라가는 연산.
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

	// 자식 노드 중 작은 놈을 찾는 연산.
	if (child + 1 <= countOfHeap) {
		child = heap[child] < heap[child + 1] ? child : child + 1;
	}

	// 현재 검사중인 노드가 자식보다 작을 경우, 교환하면서 계속 더 작은 녀석을 찾아 내려가는 연산.
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