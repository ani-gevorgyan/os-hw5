#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr;
    int n;
    int sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid integer.\n");
            free(arr);
            return 1;
        }

        sum += arr[i];
    }

    printf("Sum of the array: %d\n", sum);

    free(arr);
    arr = NULL;
    return 0;
}
