#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "num_complex.h"



// --------------------------------------------------

numero_complexo* criar_numero_complexo(float parte_real, float parte_imaginaria){

    numero_complexo* num_complex = (numero_complexo*) malloc( sizeof(numero_complexo) );

    num_complex->real       = parte_real;

    num_complex->imaginaria = parte_imaginaria;

    return num_complex;
}



// --------------------------------------------------

void deletar_numero_complexo(numero_complexo* num_complex){

    if(num_complex){
        free(num_complex);
    }
}



// --------------------------------------------------

int comparar_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2){

    /**
     * Compara utilizando criterio de maxima diferenca aceitavel. 
     */


    float diff_real = fabs(

        num_1->real - num_2->real
    );

    if(diff_real > MAX_ACCEPTABLE_DIFFERENCE) return 1;


    float diff_img  = fabs(

        num_1->imaginaria - num_2->imaginaria
    );

    if(diff_img > MAX_ACCEPTABLE_DIFFERENCE) return 1;


    return 0;
}



// --------------------------------------------------

numero_complexo* conjugado_numero_complexo(numero_complexo* num_complex){

    numero_complexo* conjugado = criar_numero_complexo(

        num_complex->real,

        -1*num_complex->imaginaria
    );

    return conjugado;
}



// --------------------------------------------------

numero_complexo* soma_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2){

    numero_complexo* soma = criar_numero_complexo(

        num_1->real       + num_2->real,

        num_1->imaginaria + num_2->imaginaria
    );

    return soma;
}



// --------------------------------------------------

numero_complexo* subtracao_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2){

    numero_complexo* subtracao = criar_numero_complexo(

        num_1->real       - num_2->real,

        num_1->imaginaria - num_2->imaginaria
    );

    return subtracao;
}



// --------------------------------------------------

numero_complexo* produto_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2){

    float parte_real = num_1->real*num_2->real - num_1->imaginaria*num_2->imaginaria;

    float parte_imaginaria = num_1->real*num_2->imaginaria + num_1->imaginaria*num_2->real;

    numero_complexo* produto = criar_numero_complexo(parte_real, parte_imaginaria);

    return produto;
}



// --------------------------------------------------

void print_numero_complexo(numero_complexo* num_complex){

    if(num_complex){

        printf("z = (%f,%f)\n", num_complex->real, num_complex->imaginaria);
    }
}



// --------------------------------------------------

array_complexo* criar_array_complexo(int quantidade_de_elementos){

    array_complexo* arr_complex = (array_complexo*) malloc(sizeof(array_complexo));

    numero_complexo** num_complex = (numero_complexo**) malloc(quantidade_de_elementos*sizeof(numero_complexo*));


    arr_complex->quantidade_de_elementos = quantidade_de_elementos;

    arr_complex->array = num_complex;

    return arr_complex;
}



// --------------------------------------------------

void deletar_array_complexo(array_complexo* arr_complex){

    if(!arr_complex) return;

    if(!arr_complex->array) return;

    for(int i=0; i<arr_complex->quantidade_de_elementos; i++){

        if(arr_complex->array[i]){
            
            deletar_numero_complexo(arr_complex->array[i]);
        }
    }

    free(arr_complex->array);

    free(arr_complex);
}



// --------------------------------------------------

void print_array_numeros_complexos(array_complexo* arr_complex){

    for(int i=0; i<arr_complex->quantidade_de_elementos; i++){

        printf("z_%d = (%f,%f)\n", i, arr_complex->array[i]->real, arr_complex->array[i]->imaginaria);
    }
}
