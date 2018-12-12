//#include <iostream>
//#include <memory.h>
//using namespace std;
//
//int arr[1000000];
//int temp[1000000];
//void Merge(int start, int mid, int end) {
//	int i, j, k;
//	for (i = start, j = mid + 1, k = start; i <= mid && j <= end; k++) {
//		if (arr[i] < arr[j]) temp[k] = arr[i++];
//		else temp[k] = arr[j++];
//	}
//	if (i > mid)
//		memcpy(&temp[k], &arr[j], sizeof(int)*(end - j + 1));
//	else
//		memcpy(&temp[k], &arr[i], sizeof(int)*(mid - i + 1));
//
//	memcpy(&arr[start], &temp[start], sizeof(int)*(end - start + 1));
//}
//
//void MergeSort(int start, int end) {
//	if (start < end) {
//		int mid = (start + end) / 2;
//		MergeSort(start, mid);
//		MergeSort(mid + 1, end);
//		Merge(start, mid, end);
//	}
//}
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) cin >> arr[i];
//
//	MergeSort(0, n - 1);
//
//	for (int i = 0; i < n; i++) cout << arr[i] << " ";
//
//	return 0;
//}