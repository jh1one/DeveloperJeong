#include <cstdio>

void Order(int p[][10], int col, int row) {
	if (col == row)
		printf("A%d", col);
	else {
		int k = p[col][row];
		printf("(");
		Order(p, col, k);
		Order(p, k + 1, row);
		printf(")");
	}
}

int main() {
	int n, diagonal;
	int m[10][10] = { 0, }, p[10][10] = { 0, };

	scanf_s("%d", &n);
	getchar();

	int *d = new int[n+1];
	scanf_s("%d", &d[0]);
	getchar();
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &d[i]);
		getchar();
	}

	for (diagonal = 1; diagonal < n; diagonal++) {
		for (int i = 1; i <= n - diagonal; i++) {
			int j = i + diagonal;
			for (int k = i; k <= j - 1; k++) {
				if (m[i][j] != 0) {
					if ((m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j]) < m[i][j]) {
						m[i][j] = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
						p[i][j] = k;
					}
				}
				else {
					m[i][j] = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
					p[i][j] = k;
				}
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%3d ", m[i][j]);
		}
		printf("\n");
	}

	Order(p, 1, n);
	return 0;
}