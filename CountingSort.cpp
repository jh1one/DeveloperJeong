#include<iostream>
using namespace std;

int* CountingSort(int* arr, int n) {
	int *count = (int*)calloc(10, sizeof(int));

	for (int i = 0; i < n; i++)	count[arr[i]]++;

	/*for (int i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];*/

	int* sort = new int[n];

	int i = 0, j = 0; 
	while (i < n && j < 10) {
		while (count[j] > 0) {
			sort[i] = j;
			count[j]--;
			i++;
		}
		j++;
	}

	return sort;
}

int main() {
	
	int n;
	cin >> n;

	int *arr = new int[n];

	cout << "Input the values from 0 to 5" << endl;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		while (input > 9 || input < 0)
		{
			cout << "Input the other number. You must input the numbers from 0 to 5." << endl;
			cin >> input;
		}
		arr[i] = input;
	}

	int* result = CountingSort(arr, n);

	for (int i = 0; i < n; i++)
		cout << result[i] << " ";

	return 0;
}