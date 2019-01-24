#include <cstdio>
#include "BinarySearchTree.h"

float a[101][100] = { 0, };	//vi���� vj������ ��� �˻� Ƚ���� �����ϴ� �迭
int r[100][100];	//vi���� vj������ ���� Ʈ���� ��Ʈ�� �� ������ Ű
float p[100];	//�� ���Ұ� �˻�Ű�� �� Ȯ��
char data[100];	//������ ������. �迭�� �ε����� �� ������ �˻�Ű�� �ȴ�.

				//Ʈ�� ����
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

/*//�̺а˻�Ʈ�� �׽�Ʈ
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

	//������ �Է�
	for (int temp = 1; temp <= n; temp++) {
		printf("Input data & probability of element%d : ", temp);
		scanf_s("%f", &p[temp]);
		getchar();
	}

	//�ʱ�ȭ
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