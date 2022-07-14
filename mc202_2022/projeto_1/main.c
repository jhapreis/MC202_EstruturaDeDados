#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "num_complex.h"



int main(){


    // Declaracao de variaveis
    // --------------------------------------------------

    int quantidade_de_elementos = 0;

    float parte_real = 0, parte_imaginaria = 0;

    numero_complexo* soma_array    = NULL; // Somatorio total; sera alocado dinamicamente

    numero_complexo* produto_array = NULL; // Produtorio total; sera alocado dinamicamente

    numero_complexo* temp_soma = NULL;

    numero_complexo* temp_produto = NULL;

    array_complexo* arr_complex = NULL;



    // Criar array de numeros complexos
    // --------------------------------------------------

    printf("Quantos elementos quer inserir no array? ");

    scanf("%d%*c", &quantidade_de_elementos);

    if(quantidade_de_elementos < 0){

        printf("\nVALUE ERROR: a quantidade de elementos deve ser um numero inteiro maior ou igual a zero (nao negativo). Encerrando...\n\n");

        exit(1);
    }
    else if(quantidade_de_elementos == 0){

        printf("\nA quantidade de elementos passada foi nula. Nada a ser feito. Encerrando...\n\n");

        return 0;
    }


    arr_complex = criar_array_complexo(quantidade_de_elementos);

    if(!arr_complex){

        printf("\n\nMEMORY ERROR: Problema ao alocar memoria para o array de numeros complexos. Encerrando...\n");

        exit(1);
    }



    // Alocar elementos no array
    // --------------------------------------------------

    printf("\nDigite o(s) numero(s) complexo(s) para ser(em) adicionado(s), na forma \"(x,y)\":\n");

    for(int i=0; i<quantidade_de_elementos; i++){     

        scanf("(%f,%f)%*c", &parte_real, &parte_imaginaria);


        arr_complex->array[i] = criar_numero_complexo(parte_real, parte_imaginaria);


        if(!arr_complex->array[i]){

            printf("\n\nMEMORY ERROR: Problema ao alocar novo numero complexo para dentro do array na posicao %d. Encerrando...\n\n", i);

            exit(1);
        }
    }

    printf("\nArray de numeros complexos:\n\n");
    print_array_numeros_complexos(arr_complex);



    // Realizar as operacoes
    // --------------------------------------------------

    parte_real       = arr_complex->array[0]->real;

    parte_imaginaria = arr_complex->array[0]->imaginaria;

    soma_array    = criar_numero_complexo(parte_real, parte_imaginaria);

    produto_array = criar_numero_complexo(parte_real, parte_imaginaria);


    if(quantidade_de_elementos > 1){

        for(int i=1; i<quantidade_de_elementos; i++){

            temp_soma  = soma_array;

            soma_array = soma_numeros_complexos(soma_array, arr_complex->array[i]);

            free(temp_soma);


            temp_produto  = produto_array;

            produto_array = produto_numeros_complexos(produto_array, arr_complex->array[i]);

            free(temp_produto);
        }
    }


    printf("\n\n___________Resultados___________\n\n");
    printf("Soma total:\n");
    print_numero_complexo(soma_array);
    printf("\nProduto total:\n");
    print_numero_complexo(produto_array);



    // Encerrar
    // --------------------------------------------------

    deletar_numero_complexo(soma_array);

    deletar_numero_complexo(produto_array);

    deletar_array_complexo(arr_complex);

    return 0;
}
