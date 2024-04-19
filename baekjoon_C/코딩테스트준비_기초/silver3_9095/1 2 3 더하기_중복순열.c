#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int bucket[], int n, int toPick, int *cnt);
int main() {
	int T; //테스트 케이스
	int n;
	int* bucket;
	int* item;
	
	scanf("%d", &T);
	item = (int*)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++) {
		int* cnt = 0;
		scanf("%d", &n);
		bucket = (int*)malloc(sizeof(int) * n);

		pick(bucket, n, n, &cnt);

		item[i] = cnt;
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", item[i]);
	}
}
void pick(int bucket[], int n, int toPick, int* cnt) {
	int i, lastIdx, sum = 0;

	if (toPick == 0) {
		sum = 0;

		for (i = 0; i < n; i++) {
			sum += bucket[i];

			if (sum == n) {
				(*cnt)++;
				return;
			}
		}
		
		return;
	}

	lastIdx = n - toPick - 1;

	for (i = 0; i <= lastIdx; i++) {
		sum += bucket[i];
	}
	if (sum == n) {
		(*cnt)++; 
		return; //재귀함수 가지 못하게(더 뽑지 않게)막음
	}
	else if (sum > n) {
		return;
	}

	for (i = 1; i <= 3; i++) {//1,2,3만 넣을 수 있음
		bucket[lastIdx + 1] = i;
		pick(bucket, n, toPick - 1, cnt);
	}
}

