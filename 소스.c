#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char items[], int n, int bucket[], int m, int toPick) {
	int lastIdx, smallest;
	if (toPick == 0) {
		for (int i = 0; i < m; i++)
			printf("%c ", items[bucket[i]]);
		printf("\n");
		return;
	}
	lastIdx = m - toPick - 1;
	if (m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIdx] + 1;

	for (int i = smallest; i < n; i++) {
		bucket[lastIdx + 1] = i;
		pick(items, n, bucket, m, toPick - 1);
	}
}
int main(void) {
	char arr[] = { "ABCDEFG" };
	int n;
	scanf("%d", &n);
	int* bucket = malloc(sizeof(int) * n);
	pick(arr, 7, bucket, n, n);
	return 0;
}