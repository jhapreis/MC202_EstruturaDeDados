#include <stdlib.h>
#include <stdio.h>

#include "heap.h"



void heapSort(int* array, int number_of_elements){

    int i = 0, buffer = 0;

    for(   i=(number_of_elements-1)/2;   i>=0;   i--   ){ // criar heap a partir dos dados

        criarHeap(array, i, number_of_elements-1);
    }

    /**
     * Encontra o maior elemento do heap e o coloca 
     * na sua posição correspondente no array. 
     */
    for(   i=number_of_elements-1;   i>=1; i--   ){ // reconstruir heap, de maneira ordenada

        buffer   = array[0];

        array[0] = array[i];

        array[i] = buffer;

        criarHeap(array, 0, i-1);
    }
}



void criarHeap(int* array, int element_index, int end){

    int buffer = array[element_index];

    int j = 2*element_index + 1;

    while(j <= end){ // the same as 2*element_index + 1 <= end

        if(j < end){
            if(array[j] < array[j+1]){ // se o pai tem dois filhos, encontrar qual deles é o maior
                j += 1; // se for o segundo, o índice do filho é somado 1, porque é o seguinte ao primeiro
            }
        }
        if(buffer < array[j]){ // se o filho é maior que o pai, o filho vai para a posição do pai; repetir

            array[element_index] = array[j];
            element_index = j;
            j = 2*element_index + 1;
        }
        else{
            j = end + 1;
        }
    }

    array[element_index] = buffer; // recoloca o pai no lugar do último filho que foi analisado
}



void printArray(int* array, int number_of_elements){

    for(int i=0; i<number_of_elements; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
}
