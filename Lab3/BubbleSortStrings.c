#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char **strings, unsigned int n) {
    unsigned int i, j;
    char *temp;
    int opcount1 = 0;
    int opcount2 = 0;

    for (i = 0; i <= n - 2; i++) {
        for (j = 0; j <= n - 2 - i; j++) {
            ++opcount1;
            if (strcmp(strings[j], strings[j + 1]) > 0) { // Comparison is the basic operation
                ++opcount2;
                // Swap strings[j] and strings[j+1]
                temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }

    printf("\nComparison Count: %d\n", opcount1);
    printf("Swap Count: %d\n", opcount2);
}

int main() {
    char **strings;
    int n, i;

    printf("\nEnter number of strings: ");
    scanf("%d", &n);

    strings = (char **)malloc(sizeof(char *) * n);

    for (int k = 0; k < n; k++) {
        strings[k] = (char *)malloc(sizeof(char) * 100); // Assuming a maximum length of 100 characters
        scanf("%s", strings[k]);
    }

    printf("\nStrings are: ");
    for (i = 0; i < n; i++)
        printf("%s ", strings[i]);

    bubbleSort(strings, n);

    printf("Strings after bubble sort: ");
    for (i = 0; i < n; i++)
        printf("%s ", strings[i]);

    printf("\n");

    // Free allocated memory
    for (int k = 0; k < n; k++) {
        free(strings[k]);
    }
    free(strings);

    return 0;
}
