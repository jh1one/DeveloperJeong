#include <iostream>
using namespace std;

void InsertSort(int* arr, int size) {
	int key;
	for (int i = 1; i < size; i++) {
		key = arr[i];
		int j = i - 1;
		while (key < arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	
	for (int i = 0; i < n; i++) cin >> arr[i];

	InsertSort(arr, n);
	
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	delete[] arr;
	return 0;
}