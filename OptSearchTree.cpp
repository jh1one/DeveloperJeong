#include <cstdio>
#include "BinarySearchTree.h"

float a[101][100] = { 0, };	//vi부터 vj까지의 평균 검색 횟수를 저장하는 배열
int r[100][100];	//vi부터 vj까지의 최적 트리의 루트가 될 원소의 키
float p[100];	//각 원소가 검색키가 될 확률
char data[100];	//원소의 데이터. 배열의 인덱스는 각 원소의 검색키가 된다.

				//트리 구축
template <class T>
void GetOptRoot(BSTree<T>& t, int i, int j) {
	int k = r[i][j];
	if (k) {
		t.Insert(k, data[k]);
		GetOptRoot(t, i, k - 1);
		GetOptRoot(t, k + 1, j);
	}
}

int main() {

/*//이분검색트리 테스트
	BSTree<char> tree(14, 'A');

	if (tree.IsEmpty()) printf("Your tree is NULL.\n");
	else printf("Your tree is not NULL.\n");

	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		char d;
		scanf_s("%d", &k);
		getchar();
		scanf_s("%c", &d);
		getchar();
		tree.Insert(k, d);
	}

	tree.PreOrder();*/
	
	BSTree<char> tree;

	int n, i, j, k, diagonal;
	scanf_s("%d", &n);

	//int** a = new int*[n + 1];
	//int** r = new int*[n];
	//int* p = new int[n];

	//데이터 입력
	for (int temp = 1; temp <= n; temp++) {
		printf("Input data & probability of element%d : ", temp);
		scanf_s("%f", &p[temp]);
		getchar();
	}

	//초기화
	for (int temp = 1; temp <= n; temp++) {
		a[temp][temp - 1] = 0;
		a[temp][temp] = p[temp];
		r[temp][temp - 1] = 0;
		r[temp][temp] = temp;
	}
	a[n + 1][n] = 0;
	r[n + 1][n] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			float temp = 1;
			for (k = i; k <= j; k++) {
				if (temp > a[i][k - 1] + a[k + 1][j]) {
					temp = a[i][k - 1] + a[k + 1][j];
					r[i][j] = k;
				}
			}
			a[i][j] = temp;
			for (int idx = i; idx <= j; idx++)
				a[i][j] += p[idx];
		}
	}
	
	for (int col = 1; col <= n; col++) {
		for (int row = 1; row <= n; row++) {
			printf("%.2f  ", a[col][row]);
		}
		printf("\n");
	}

	GetOptRoot(tree, 1, n);
	tree.PreOrder();

	return 0;
}