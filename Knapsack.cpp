#include <cstdio>

int itemW[10], itemV[10];

int Opt(int i, int w) {
	if (i == 0)
		return 0;
	if (itemW[i] > w) {
		return Opt(i - 1, w);
	}
	else {
		int curr = Opt(i - 1, w - itemW[i]) + itemV[i];
		int prev = Opt(i - 1, w);
		if (curr > prev) {
			return curr;
		}
		else
			return prev;
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		scanf_s("%d%d", &itemV[i], &itemW[i]);
	
	printf("%d\n", Opt(9, 20));
	
	return 0;
}