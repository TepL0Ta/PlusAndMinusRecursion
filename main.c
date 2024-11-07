#include <stdio.h>

int N;
int arr[24];
char signs[23];
int target_sum;
int globalCheck = 0;

int doRecursion(int i, int curr_sum) {
    if (i == N) {
        if (curr_sum == target_sum) {
            globalCheck = 1;
            return 1;
        }
        return 0;
    }

    signs[i - 1] = '+';
    if (doRecursion(i + 1, curr_sum + arr[i])) {
        return 1;
    }

    signs[i - 1] = '-';
    if (doRecursion(i + 1, curr_sum - arr[i])) {
        return 1;
    }

    return 0;
}

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target_sum);

    if (doRecursion(1, arr[0])) {
        for (int i = 0; i < N; ++i) {
            printf("%d", arr[i]);
            if (i < N - 1) {
                printf("%c", signs[i]);
            }
        }
        printf("=%d\n", target_sum);
    } else {
        printf("no solution\n");
    }

    return 0;
}
