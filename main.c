#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int number = 1;
    int** result = malloc(sizeof(int*) * (n));
    *returnColumnSizes = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        result[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int top = 0, right = n - 1;
    int left = 0, bottom = n - 1;

    while (top <= bottom) {
        for (int i = left; i <= right; i++)
            result[top][i] = number++;
        top++;

        for (int i = top; i <= bottom; i++)
            result[i][right] = number++;
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[bottom][i] = number++;
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[i][left] = number++;
            left++;
        }
    }

    *returnSize = n;
    return result;
}

void printMatrix(int** matrix, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]");
}

int main() {
    int n = 3;
    int returnSize;
    int* returnColumnSizes;
    int** matrix = generateMatrix(n, &returnSize, &returnColumnSizes);
    printf("Input: n = %d\n", n);
    printf("Output: ");
    printMatrix(matrix, n);
    printf("\n");

    n = 1;
    matrix = generateMatrix(n, &returnSize, &returnColumnSizes);
    printf("Input: n = %d\n", n);
    printf("Output: ");
    printMatrix(matrix, n);
    printf("\n");

    // Don't forget to free the memory
    for (int i = 0; i < returnSize; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(returnColumnSizes);

    return 0;
}
