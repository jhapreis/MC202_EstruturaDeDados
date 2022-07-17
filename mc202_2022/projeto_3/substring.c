#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "substring.h"



lista* criar_lista(){

    lista* nova_lista = (lista*) malloc(sizeof(lista));

    no* root = (no*) malloc(sizeof(no));

    root->chave   = -1;

    root->proximo = NULL;

    nova_lista->quantidade = 0; 

    nova_lista->root = root;

    return nova_lista;
}



void deletar_lista(lista* list){

    no* atual = list->root;

    while(atual->proximo){

        *list->root = *atual->proximo;

        free(atual);
    }

    free(list);
}



int adicionar_elemento_lista(lista* list, int chave){

    if(!list) return -1;


    no* novo_no = (no*) malloc(sizeof(no));

    if(!novo_no) return -1;

    novo_no->proximo = NULL;

    novo_no->chave = chave;


    no* atual = list->root;

    while(atual->proximo){

        atual = atual->proximo;
    }

    atual->proximo = novo_no;

    return 1;
}



// array_indexes* criar_array_indexes(int quantidade_de_indexes){

//     array_indexes* arr_indexes = (array_indexes*) malloc(sizeof(array_indexes));

//     int** array = (int**) calloc(quantidade_de_indexes, sizeof(int*));


//     arr_indexes->array = array;

//     arr_indexes->quantidade = quantidade_de_indexes;


//     return arr_indexes;
// }



// void deletar_array_indexes(array_indexes* array){

//     for(int i=0; i<array->quantidade; i++){

//         free(array->array[i]);
//     }

//     free(array);
// }



lista* find_indexes_substring(char* texto, char* padrao){

    if(!texto){

        printf("\nVariavel \"texto\" nao encontrada. Ignorando...\n");

        return NULL;
    }
    else if(!padrao){

        printf("\nVariavel \"padrao\" nao encontrada. Ignorando...\n");

        return NULL;
    }
    else if(strlen(padrao) > strlen(texto)){

        printf("\nVariavel \"padrao\" com tamanho maior que a variavel \"texto\". Ignorando...");

        return NULL;
    }


    char slice[strlen(padrao)];

    lista* list = criar_lista();

    int lenght_diff = strlen(texto) - strlen(padrao);



    for(int i=0; i <= lenght_diff; i++){

        strncpy(slice, texto + i, sizeof(slice));

        if(strcmp(slice, padrao) == 0){

            adicionar_elemento_lista(list, i+1);            

            list->quantidade++;
        }
    }

    return list;
}



void print_lista(lista* list){

    no* atual = list->root;

    printf("\nIndexes: ");

    while(atual->proximo){

        printf("%d ", atual->proximo->chave);

        atual = atual->proximo;
    }

    printf("\n");
}



// void print_array_indexes(array_indexes* array){

//     printf("\n");

//     for(int i=0; i<array->quantidade; i++){

//         printf("%ls ", array->array[i]);
//     }

//     printf("\n");
// }
