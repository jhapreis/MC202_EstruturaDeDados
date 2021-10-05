#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "darray.h"


darray* da_alloc(int capacity){
    /* 
        It's not possible to initialize the value as darray array before cause, I think, it's going to initialize the
    data attribute with a given lenght. Therefore, you cannot resize without reallocating the memory. 
        It's easier to declare and fill the elements on the instance.
    */

    float *data = (float *) calloc( capacity, sizeof(float) ); // espaço para alocar os valores float
    
    darray array = {data, 0, 1, capacity, capacity};

    darray* ptr_array = &array;

    printf("first = %d, size = %d, capacity = %d, min_cap = %d\n\n", ptr_array->first, ptr_array->size, ptr_array->capacity, ptr_array->min_cap);
    printf("done\n");

    return ptr_array;
}



void da_free(darray *A){

    free(A);
}



float da_first(darray *A){

    return (*A).first;
}



float da_last(darray *A){

    int capacity = (*A).capacity, first_index = (*A).first, size = (*A).size;

    int last_index = (first_index + size - 1) % capacity;

    float last = (*A).data[last_index];

    return last;
}



int da_is_empty(darray *A){
    
    printf("\nsize = %d\n", A->size);

    int empty = 0; // supposedly NOT empty

    // int size = A->size;

    if ( A->size == 0 ){
        empty = 1;
    }
    
    printf("\nsize = %d, empty = %d\n", A->size, empty);

    return empty;
}



int da_push(darray *A, float x){

    int capacity = (*A).capacity;
    int first_index = (*A).first;
    int size = (*A).size;

    int last_index = (first_index + size - 1) % capacity;


    if (size == capacity || last_index == first_index - 1){ // if full capacity, create more space

        // printf("Address of pointer %p\n", (void *) (*A).data);

        float *data = (float *) realloc( (*A).data, 2*capacity*sizeof(float) ); // new array with double capacity

        if (data != NULL){ // in case of realocating successfully

            (*A).data = data;

            for (int i = 0; i < first_index; i++){ // move all the left part of the sequence to the right 
                (*A).data[i+size] = (*A).data[i];
                (*A).data[i] = 0;
            }

            // update variables; first, size and min_cap keep unchanged
            capacity      = 2*capacity;
            (*A).capacity = capacity;
        }

        else{ // in case of FAILURE
            return 0;
        }
    }
    

    if (last_index < capacity - 1){ // espaço na direita do último; colocar após o último
        (*A).data[last_index+1] = x;
    }

    else if (last_index == capacity - 1){ // espaço na esquerda da sequência; o último está na extrema direita, então coloque no primeiro
        (*A).data[0] = x;
    }


    (*A).size += 1; // register increment on size

    return 1;
}



int da_inject(darray *A, float x){

    int capacity = (*A).capacity;
    int first_index = (*A).first;
    int size = (*A).size;

    int last_index = (first_index + size - 1) % capacity;


    if (size == capacity || last_index == first_index - 1){ // if full capacity, create more space

        float *data = (float *) realloc( (*A).data, 2*capacity*sizeof(float) ); // new array with double capacity

        if (data != NULL){ // in case of realocating successfully

            (*A).data = data;

            for (int i = 0; i < first_index; i++){ // move all the left part of the sequence to the right 
                (*A).data[i+size] = (*A).data[i];
                (*A).data[i] = 0;
            }

            capacity      = 2*capacity;
            (*A).capacity = capacity;
        }

        else{ // in case of FAILURE
            return 0;
        }
    }

    
    if (first_index == 0){ // se o primeiro está na borda esquerda, adicione o elemento na outra borda
        (*A).data[capacity-1] = x;
    }

    else{ // se NÃO está na borda esquerda, adicione antes do primeiro (já existe espaço)
        (*A).data[first_index-1] = x;
    }


    (*A).size += 1; // register increment on size

    return 1;
}



float da_pop(darray *A){

    return 0;

}



float da_eject(darray *A){

    return 0;

}





