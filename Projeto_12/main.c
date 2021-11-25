/**
 * @file main.c
 * @author Jorge Reis (jhapreis@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-26
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "heap.h"



int main(){

    int number_of_elements = 0;
    // int element = 0;

    // printf("Qual a quantidade de elementos?\n");

    scanf("%d", &number_of_elements); // get number of elements to sort

    int array[number_of_elements];

    // (%[^\n]%*c")

    for(int i=0; i<number_of_elements; i++){

        // printf("Insira um elemento: ");

        scanf("%d", &array[i]); // get element and insert on the array

        // array[i] = element;

        // printf("\n");

    }

    heapSort(array, number_of_elements);

    printArray(array, number_of_elements);

}
