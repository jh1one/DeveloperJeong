#include <cstdio>

int RecursiveLCS(char* str1, char* str2, int row, int col, char* cs) {
	if (col == 0 || row == 0)	return 0;
	if (str1[row] == str2[col])
	{
		int length = RecursiveLCS(str1, str2, row - 1, col - 1, cs) + 1;
		cs[length-1] = str1[row];
		return length;
	}
	else {
		int left = RecursiveLCS(str1, str2, row - 1, col, cs);
		int up = RecursiveLCS(str1, str2, row, col - 1, cs);
		if(left > up) return left;
		else return up;
	}
}
int main() {
	char str1[100] = { 0, }, str2[100] = { 0, }, cs[100] = { 0, };
	int l[100][100] = { 0, };
	int length = 0, m = 0, n = 0;
	
	scanf_s("%s", str1+1, 99);
	getchar();
	scanf_s("%s", str2+1, 99);
	getchar();

	for (int i = 1; str1[i] != '\0'; i++)
		m++;

	for (int i = 1l; str2[i] != '\0'; i++)
		n++;

	length = RecursiveLCS(str1, str2, m, n, cs);
	printf("%d\n", length);
	for (int k = 0; k <= length; k++)
			printf("%c", cs[k]);

	//printf("%d\n%d\n", m, n);

	//for (int i = 1; i <= m; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		if (str1[i] == str2[j]) {
	//			l[i][j] = l[i - 1][j - 1] + 1;
	//			//length++;
	//		}
	//		else {
	//			if (l[i][j - 1] > l[i - 1][j]) {
	//				l[i][j] = l[i][j - 1];
	//			}
	//			else //if (l[i][j - 1] < l[i - 1][j]) {
	//				l[i][j] = l[i - 1][j];
	//			//}
	//		}
	//	}
	//}

	//printf("%d\n", l[m][n]);
	///*for (int k = 0; k < length; k++)
	//	printf("%c", cs[k]);*/
	return 0;
}