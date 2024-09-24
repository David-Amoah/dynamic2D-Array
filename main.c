#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

    int rows = 20;
    int columns = 30;


    printf("Hello world! I have created a dynamic 2D-arrray of 20x30 integers\n");

    int** array;
    array = (int**)malloc(rows * sizeof(int*));
    //everytime we do a malloc, it can fail
    if(array == NULL) {
        printf("Failed to allocate memory\n");
        exit(1);
    }



    //this allocates memory for each block in the array
    for(int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(sizeof(int) * columns);
        if (array[i] == NULL) {
            printf("Failed to allocate memory\n");
            exit(1);
        }
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = i + j;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }

    //free each of the blocks
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }

    free(array);


    return 0;
}