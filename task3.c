#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr;
    int n = 10;

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
    }

    int *temp = realloc(arr, 5 * sizeof(int));

    if (temp != NULL) {
        arr = temp;
        n = 5;
    } else {
        fprintf(stderr, "Memory reallocation failed!\n");
        free(arr);
        return 1;
    }

    printf("Array after resizing: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}
