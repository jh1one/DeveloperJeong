#include <iostream>
using namespace std;

class MaxPQ {
public:
	MaxPQ(int theCapacity = 10) {
		heapSize = 0;
		heap = new int[theCapacity + 1];
	}
	~MaxPQ() {};
	bool IsEmpty() {
		if (heapSize <= 0) return true;
		else return false;
	}
	int Top() {
		return heap[1];
	}
	void Push(const int node) {
		heap[++heapSize] = node;

		if (heapSize > 1) {
			int curr = heapSize;
			int parent = curr / 2;
			while (heap[curr] > heap[parent] && curr >= 2)
			{
				int temp = heap[parent];
				heap[parent] = heap[curr];
				heap[curr] = temp;
				curr = parent;
				parent = curr / 2;
			}
		}
	}
	

	void Pop() {
		int temp = heap[heapSize];
		heap[heapSize] = heap[1];
		heap[1] = temp;
		heapSize--;

		if (heapSize > 1) {
			int curr = 1;
			int c = curr * 2;
			while (c <= heapSize) {
				if (c + 1 <= heapSize && heap[c] < heap[c + 1]) c++;
				if (heap[curr] < heap[c])
				{
					int temp = heap[curr];
					heap[curr] = heap[c];
					heap[c] = temp;
					curr = c;
					c = curr * 2;
				}
				else
					return;
			}
		}
	}
private :
	int* heap;
	int heapSize;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	MaxPQ maxHeap(n);

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		maxHeap.Push(input);
	}

	return 0;
}