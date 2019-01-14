#include <cstdio>
#include <memory.h>


int w[100][100];
int d[100][100];
int p[100][100];

void Path(int i, int j) {
	if (p[i][j] != 0) {
		Path(i, p[i][j]);
		printf("%d ", p[i][j]);
		Path(p[i][j], j);
	}
}

int main() {

	int n;
	scanf_s("%d", &n);
	memset(w, 0, 10000);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &w[i][j]);
		}
	}
	
	memcpy(d + 1, w + 1, 10000);
	memset(p, 0, 10000);
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	int vi, vj;
	printf("Input the vertices to find path : ");
	scanf_s("%d%d", &vi, &vj);

	Path(vi, vj);

	return 0;
}