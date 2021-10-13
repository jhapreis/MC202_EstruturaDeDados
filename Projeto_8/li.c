// Includes
// ==================================================

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "li.h"



// First order-call functions
// ==================================================

void print_le_cabeca(celula *head){

    char text[20];

    int len = lenght(head);

    celula* ptr = head->proximo;

    printf("A: { ");

    for (int i = 0; i < len - 1; i++){
        printf("%d, ", ptr->conteudo);
        ptr = ptr->proximo;
    }

    sprintf(text, "%d", ptr->conteudo);
    printf("%s", text);

    printf(" }\n");
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



void insert_cell_end(int x, celula *head){

    celula* end = head;

    while(end->proximo != NULL){ // enquanto não for o último elemento da lista encadeada...
        end = end->proximo;
    }

    insert_cell(x, end);
}



celula* sublist(celula *head, int index_start, int index_finish){

    celula* cell = head;
    celula* sublist = create_empty_le();

    int start, finish, invert_order = 0;

    if (index_start <= index_finish){
        start  = index_start;
        finish = index_finish;
    }

    else{
        start  = index_finish;
        finish = index_start;
        invert_order = 1;
    }

    for (int i = 0; i <= finish; i++){

        cell = cell->proximo;

        if (cell == NULL){ // break earlier if interval is larger than list
            break;
        }

        if (i >= start){
            insert_cell_end(cell->conteudo, sublist);
        }
    }

    if (invert_order != 0){
        celula* sub_reverse = reverse(sublist);
        free(sublist);
        sublist = sub_reverse;
    }

    return sublist;
}



void insert(celula* head, int index_start, int index_finish, int position){

    celula* sub  = sublist(head, index_start, index_finish);

    celula* cell = head;

    celula *buffer, *sub_end = sub; // link of the sublist with the original list


    for (int i = 0; i < position; i++ ){
        cell = cell->proximo; // walk on the original list until the position
    } 

    buffer = cell->proximo; // connection with the elements after the link-break

    cell->proximo = sub->proximo; // connect the sublist with the left part of the list


    while (sub_end->proximo != NULL){
        sub_end = sub_end->proximo; // get the tail from the sublist
    }

    sub_end->proximo = buffer;

    free(sub);
}



void delete(celula* head){

    celula *end = head->proximo;
    celula* proximo;

    while (end != NULL){
        proximo = end->proximo;
        free(end);
        end = proximo;
    }

    head->proximo = NULL;
}





// Second (auxiliar) order-call functions
// ==================================================

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



celula* reverse(celula *head){

    celula* reverse_list = create_empty_le(); // cabeça da lista

    celula* end = head->proximo;

    while (end != NULL){

        insert_cell(end->conteudo, reverse_list); // insere sempre após o cabeça; ou seja, inverte a ordem

        end = end->proximo;
    }
    
    return reverse_list;
}



int lenght(celula *head){

    int len = 0;

    celula* ptr = head->proximo;

    while (ptr != NULL){
        ptr = ptr->proximo;
        len += 1;
    } 

    return len;
}




