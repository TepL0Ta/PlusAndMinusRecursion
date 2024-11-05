#include <stdio.h>

int N;
int arr[24];
char signs[24];
int sum;
int globalCheck;

int checkPlus(int i, int curr_sum) {
    curr_sum += arr[i];
    signs[i - 1] = '+';
    return curr_sum;
}

int checkMinus(int i, int curr_sum) {
    curr_sum -= arr[i];
    signs[i - 1] = '-';
    return curr_sum;
}

int doRecursion(int i, int curr_sum) {
    if (i >= N) {
        if (curr_sum == sum) {
            globalCheck = 1;
            return 1;
        }
        return 0;
    }

    // Попытка поставить знак '-'
    if (doRecursion(i + 1, checkMinus(i + 1, curr_sum))) {
        return 1;
    }

    // Попытка поставить знак '+'
    if (doRecursion(i + 1, checkPlus(i + 1, curr_sum))) {
        return 1;
    }

    return 0;
}

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &sum);

    doRecursion(0, arr[0]);

    if (globalCheck != 1) {
        printf("no solution\n");
    } else {
        for (int i = 0; i < N; ++i) {
            printf("%d", arr[i]);
            if (i != N - 1) {
                printf("%c", signs[i]);
            }
        }
        printf("=%d\n", sum);
    }

    return 0;
}
