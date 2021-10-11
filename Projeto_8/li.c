// Includes
// ==================================================

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "li.h"



// 
// ==================================================


int convert_digit_to_int(){

    return 0;

}



void print_le_cabeca(celula *le){

    celula* ptr = le->proximo;

    while (ptr != NULL){
        printf("%d ", ptr->conteudo);
        ptr = ptr->proximo;
    }
}



celula* create_empty_le(){
    /** 
        * Creates a pointer to the linked list's head
        * Allocates memory to store the head
        * Ignore the value, but the pointer to the next is NULL (it's empty)
        * Returns the address on the linked list   
    **/

    celula *le;

    le = malloc( (sizeof(celula)) );

    le->proximo = NULL;

    return le;
}



void insert_cell(int x, celula *p){
    /** 
        * Inserts a new cell on the linked list
        * Allocates memory to store the new cell
        * The value is the given x value
        * The address of the next cell is the value stored on the previous
        * The address of the previous is now the address of the new cell
    **/

   celula *new_cell;

   new_cell = malloc (sizeof (celula));

   new_cell->conteudo = x;

   new_cell->proximo = p->proximo;
   p->proximo = new_cell;
}



void insert_cell_end(int x, celula *head){

    celula* end = head;

    while(end->proximo != NULL){ // enquanto não for o último elemento da lista encadeada...
        end = end->proximo;
    }

    insert_cell(x, end);
}



void sublist(celula *head, int index_start, int index_finish){

    celula* cell = head;

    int start, finish;

    if (index_start <= index_finish){
        start  = index_start;
        finish = index_finish;
    }

    else{
        // descending
    }

    for (int i = 0; i <= finish; i++){

        cell = cell->proximo;

        if (cell == NULL){
            break;
        }

        else if (i == start){
            head->proximo = cell;
        }

        else if (i == finish){ // quebra o link nesse índice
            cell->proximo = NULL;
        }
    }
}



