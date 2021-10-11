/**
  li.h
  Declarations for ...
**/


#ifndef LI_H
#define LI_H



typedef struct celula{
    int conteudo;
    struct celula *proximo;
} celula;



/** 
    * ...
    * Returns the address on the linked list   
**/
celula* create_empty_le();



/**
    Print the contend of a linked list
**/
void print_le_cabeca(celula *le);


/**
    * Insert new cell on a linked list. 
        * x = new_cell's value;   
        * p = the cell before;
**/
void insert_cell(int x, celula *p);



void insert_cell_end(int x, celula *head);



void sublist(celula *head, int index_start, int index_finish);



#endif // LI_H
