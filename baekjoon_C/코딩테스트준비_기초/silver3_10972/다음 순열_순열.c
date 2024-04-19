#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* bucket, int m, int toPick, int *item);

int main() {
	int n;
	scanf("%d", &n);

	int* bucket = (int*)malloc(sizeof(int) * n);
	int* item = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &item[i]);
	}

	pick(bucket, n, n, item);

}
void pick(int* bucket, int m, int toPick, int* item) {
	int i, lastIdx;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			if (bucket[i] != item[i])
				return;
		}

		;
		return;
	}

	lastIdx = m - toPick - 1;

	for (i = 1; i <= m; i++) {
		int flag = 0;
		for (int j = 0; j <= lastIdx; j++) {
			if (bucket[j] == i) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {//bucket에 같은 수 없으면
			bucket[lastIdx+1] = i;
			pick(bucket, m, toPick - 1, item);
		}
	}

}