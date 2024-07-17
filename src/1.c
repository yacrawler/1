#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

int main() {
    int *array;
    int num, scan, size;
    char c;

    size = NMAX;

    array = (int *)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("n/a");
        free(array);
        return -1;
    }

    for(int i = 0; i < size; i++) array[i] = -1;

    int i = 0;

    do {

        scan = scanf("%10d%c", &num, &c);

        if ((scan == 2) && ((c == ' ') || (c == '\n')) && (num >= 0)) {
            array[i] = num;
            i++;
        } else {
            if (num != -1) printf("n/a");
            num = -1;
        }

        if (i == size) {
            size += NMAX;

            array = (int *)realloc(array, size * sizeof(int));

            if (array == NULL) {
                free(array);
                printf("n/a 2");
                return -1;
            }

            for(int k = i; k < size; k++) array[k] = -1;

            printf("realloc %d\n", size);
        }

    } while(num != -1);


    for(int i = 0; i < size; i++) {
        int rep = array[i];
        for(int j = i + 1; j < size; j++) {
            if (array[j] == rep) array[j] = -1;

        }
    }

    for(int i = 0; i < size; i++) {
        if (array[i] != -1) printf("%d ", array[i]);
    }

    free(array);
    printf("\nfree\n");

    return 0;

}
