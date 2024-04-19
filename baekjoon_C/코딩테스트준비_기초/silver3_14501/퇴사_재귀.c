#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int calculateTotal(int* day, int* money, int index, int N) {
    int includeTotal, excludeTotal;

    if (index >= N) {
        return 0;
    }

    includeTotal = 0; //현재 포함
    if (index + day[index] <= N) {
        includeTotal = money[index] + calculateTotal(day, money, index + day[index], N);
    }

    excludeTotal = calculateTotal(day, money, index + 1, N); //현재 미포함

    if (includeTotal > excludeTotal)
        return includeTotal;
    else
        return excludeTotal;
    
}

int main() {
    int N, i, total;
    int* day;
    int* money;

    scanf("%d", &N);

    day = (int*)malloc(sizeof(int) * N);
    money = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &day[i], &money[i]);
    }

    total = calculateTotal(day, money, 0, N);
    printf("%d", total);

    free(day);
    free(money);

    return 0;
}