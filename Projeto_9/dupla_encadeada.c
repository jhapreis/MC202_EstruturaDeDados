// ==================================================
// Includes
// ==================================================

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "dupla_encadeada.h"





// ==================================================
// First order methods
// ==================================================

Lista* create_empty_lista(){

    Lista* le = (Lista*) malloc(sizeof(Lista)); // le é o cabeça

    if (le != NULL){
        *le = NULL; // este é o primeiro elemento após o cabeça
    }

    return le; // retorna o cabeça, ou seja, retorna um apontador para um apontador
}



void free_lista(Lista* head){

    if (head != NULL){ // verifica se a lista existe

        Celula* cell;
        
        while( (*head) != NULL ){ // enquanto não chegar na cauda

            cell = *head;
            *head = (*head)->proximo;
            free(cell); // libera o anterior
        }

        free(head); // libera o último
    }
}



void print_lista(Lista* head){

    if (*head == NULL){ // vazia
        printf("vazia\n");
    }

    else{
        Celula* cell = *head;

        while (cell->proximo != NULL){
            if (cell->ref != NULL){
                printf("%.1f %d %.1f %d | ", cell->chave, cell->tempo, cell->ref->chave, cell->ref->tempo);
            }
            else{
                printf("%.1f %d | ", cell->chave, cell->tempo);
            }
            cell = cell->proximo;
        }

        if (cell->ref != NULL){
            printf("%.1f %d %.1f %d\n", cell->chave, cell->tempo, cell->ref->chave, cell->ref->tempo);
        }
        else{
            printf("%.1f %d\n", cell->chave, cell->tempo);
        }
    }
}



int insert_cell(Lista* head, int posicao, float valor, float ref, int tempo, int lenght){ 

    //                      CREATE NEW CELL

    Celula* new_cell = (Celula*) malloc(sizeof(Celula)); // cria nova célula

    new_cell->chave = valor;



    //                      INSERT NEW CELL (no início, no meio ou no fim)

    if (lenght == 0){ // lista vazia, insere no início
        new_cell->proximo  = NULL;
        new_cell->anterior = NULL;
        *head = new_cell;
    }

    else if (lenght >= 1 && posicao == 0){ // não-vazia e inserção no início

        new_cell->anterior = NULL;
        new_cell->proximo  = *head;

        *head = new_cell;
        (*head)->proximo->anterior = *head;
    }

    else if (posicao == lenght){ // não-vazia e inserção no fim
        Celula* cell;
        cell = *head; // cell é o primeiro elemento da lista

        for (int i = 0; i < posicao - 1; i++){ // percorra a lista até antes da posição requerida
            cell = cell->proximo;
        }

        new_cell->proximo  = NULL;
        new_cell->anterior = cell;

        cell->proximo = new_cell;
    }

    else{ // não-vazia e inserção no meio
        
        Celula* cell;
        cell = *head; // cell é o primeiro elemento da lista

        for (int i = 0; i < posicao - 1; i++){ // percorra a lista até o anterior à posição requerida
            cell = cell->proximo;
        }

        new_cell->anterior = cell;
        new_cell->proximo  = cell->proximo;

        cell->proximo->anterior = new_cell;
        cell->proximo           = new_cell;
    }



    //                      PROCURA REF: pela esquerda ou pela direita

    if (ref == 0.0) { // se a ref é nula, encerra
        new_cell->ref   = NULL;
        new_cell->tempo = tempo;
        return 1;
    }

    int found = 0;  // indica se foi achado ou não uma ref idêntica

    Celula* anterior = new_cell->anterior;
    Celula* proximo  = new_cell->proximo;

    while (   (anterior != NULL) || (proximo != NULL)   ){ // enquanto os dois não forem nulos

        if (   (anterior != NULL) && (anterior->chave == ref)   ){
            found = 1;
            new_cell->ref   = anterior;
            new_cell->tempo = tempo;
            return 1;
        }

        else if (   (proximo != NULL) && (proximo->chave == ref)   ){
            found = 1;
            new_cell->ref   = proximo;
            new_cell->tempo = tempo;
            return 1;
        }

        if (anterior != NULL){ // atualiza, se não chegou no fim À ESQUERDA
            anterior = anterior->anterior;
        }

        if (proximo != NULL){ // atualiza se não chegou no fim À DIREITA
            proximo  = proximo->proximo;
        }
    }



    if ( found == 0 ){ // se NÃO ACHOU
        new_cell->ref   = NULL;
        new_cell->tempo = tempo;
        return 1;
    }

    else{ // ERROR
        return -1;
    }
}



int find_and_remove_cell(Lista* head, float ref, int len){

    //                      PROCURA REF: somente pela direita (pois começa no cabeça 'head')

    Celula* cell = *head;

    int pos_depois   = 0; // posição em que o contador está, após o cabeça; não é necessariamente a posição em que foi achado um idêntico
    int found_depois = 0; // indica se foi achado ou não uma ref idêntica

    while (cell != NULL){ // procure por uma ref à DIREITA
        pos_depois += 1;
        if (cell->chave == ref){
            found_depois = 1;
            break;
        }
        cell = cell->proximo;
    }

    if (found_depois == 1){ // se foi encontrado

        // int len = lenght_lista(head);

        if (len == 1){               // se só tem um único elemento, conectar a cabeça ao NULL e apagar a célula
            Celula* cell_remove = *head;

            update_ref_list(head, cell_remove);

            *head = NULL;
            free(cell_remove);
        }
    
        else if (pos_depois == 1){   // se é o primeiro elemento, conecta a cabeça ao segundo e apaga o primeiro; requer len >= 2
            Celula* cell_remove = *head;

            update_ref_list(head, cell_remove);

            *head = (*head)->proximo;
            (*head)->anterior = NULL;
            free(cell_remove);
        }

        else if (pos_depois == len){ // se é o último, conecta o penúltimo ao NULL e apaga o último
            update_ref_list(head, cell); // cell já é a célula a ser removida

            cell->anterior->proximo = NULL;
            free(cell);
        }

        else{                        // se está no meio, conecta o anterior e o proximo e apaga a célula no meio
            update_ref_list(head, cell); // cell já é a célula a ser removida

            cell->anterior->proximo = cell->proximo;
            cell->proximo->anterior = cell->anterior;
            free(cell);
        }
    }

    return 1;
}



// ==================================================
// Second order (inner) methods
// ==================================================

int lenght_lista(Lista *head){

    int len = 0;

    Celula* buffer;
    buffer = *head;

    while (buffer != NULL){
        buffer = buffer->proximo;
        len += 1;
    } 

    return len;
}



int lista_existe(Lista* head){
    
    int exist = 1;
    
    if (head == NULL){
        exist = 0;
    }

    return exist; // existe = 1, não-existe = 0
}



int lista_vazia(Lista* head){ // assume que a lista existe

    int empty = 0;


    if (*head == NULL){ // a lista está vazia SIM
        empty = 1;
    }

    // else{ // lista não existe
    //     empty = -1;
    // }

    return empty; // vazia = 1, não-vazia = 0, não-existente = -1
}



void update_ref_list(Lista* head, Celula* ref_cell){ // percorrer a lista toda e ir trocando referências a ref_cell por referências a NULL 
    
    Celula* cell = *head;
    
    while (cell != NULL){

        if (cell->ref == ref_cell){ // se encontra referência a ref_cell
            cell->ref = NULL;
        }
        cell = cell->proximo;
    }
}


