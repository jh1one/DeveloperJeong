#include <iostream>
using namespace std;

void MaxHeapify(int* arr, int parent, int child, int size)
{
	for (int p = parent, c = child; c <= size; p = c, c = p * 2) {
		if (c + 1 <= size && arr[c] < arr[c + 1]) c++;
		if (arr[p] < arr[c]) {
			int temp = arr[c];
			arr[c] = arr[p];
			arr[p] = temp;
		}
	}
}

void HeapSort(int* heap, int n) {
	//ÃÖ´ëÈü »ý¼º
	for (int i = n / 2; i > 0; i--) 
		MaxHeapify(heap, i, i * 2, n);
	
	//extract Max
	for (int i = 1, j = i * 2, heapSize = n; heapSize > 0; heapSize--) {
		int temp = heap[1];
		heap[1] = heap[heapSize];
		heap[heapSize] = temp;
		MaxHeapify(heap, i, j, heapSize);
	}
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	HeapSort(arr, n);

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";

	delete[] arr;
	return 0;
}