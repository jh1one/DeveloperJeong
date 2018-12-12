#include <iostream>
using namespace std;

void SelectionSort(int* arr, int size)
{
	int i, j, min, temp, idx;
	for (i = 0; i < size; i++) {
		min = 999999;
		for (j = i; j < size; j++) {
			if (min > arr[j]) {
				min = arr[j];
				idx = j;
			}
		}
		temp = arr[idx];
		arr[idx] = arr[i];
		arr[i] = temp;
	}
}
int main() {

	int n;
	cin >> n;
	int *arr = new int[n];

	for (int k = 0; k < n; k++)	cin >> arr[k];

	SelectSort(arr, n);

	for (int k = 0; k < n; k++)
		cout << arr[k] << " ";

	delete[] arr;
	return 0;
}
