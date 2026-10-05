#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 3;
    int allocated = 0;

    char **arr = malloc(n * sizeof(char *));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Allocate and read the first 3 strings
    printf("Enter 3 strings: ");
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(51 * sizeof(char));

        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");

            for (int j = 0; j < allocated; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
        allocated++;

        if (scanf("%50s", arr[i]) != 1) {
            printf("Invalid input.\n");

            for (int j = 0; j < allocated; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }

    printf("First 3 strings: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    // Resize the array of pointers to hold 5 strings
    char **temp = realloc(arr, 5 * sizeof(char *));

    if (temp == NULL) {
        printf("Memory reallocation failed!\n");

        for (int i = 0; i < allocated; i++) {
            free(arr[i]);
        }
        free(arr);
        return 1;
    }

    arr = temp;
    n = 5;

    // Allocate and read the additional 2 strings
    printf("Enter 2 more strings: ");
    for (int i = 3; i < n; i++) {
        arr[i] = malloc(51 * sizeof(char));

        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");

            for (int j = 0; j < allocated; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
        allocated++;

        if (scanf("%50s", arr[i]) != 1) {
            printf("Invalid input.\n");

            for (int j = 0; j < allocated; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }

    printf("All strings: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    // Free each string first, then the array of pointers
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;

    return 0;
}
