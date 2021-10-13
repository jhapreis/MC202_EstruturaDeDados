// ==================================================
/**
  li.h
  Declarations for ...
**/
// ==================================================

#ifndef LI_H
#define LI_H









// ==================================================
// Structures
// ==================================================

typedef struct celula{
    int conteudo;
    struct celula *proximo;
} celula;









// ==================================================
// First order-call functions
// ==================================================

/** 
    * Creates a pointer to the linked list's head
    * Returns the address on the linked list   
**/
celula* create_empty_le();



/**
    Print the contend of a linked list
**/
void print_le_cabeca(celula *head);



void insert_cell_end(int x, celula *head);



celula* sublist(celula *head, int index_start, int index_finish);



void insert(celula* head, int index_start, int index_finish, int position);



void delete(celula* head);






// ==================================================
// Second (auxiliar) order-call functions
// ==================================================

celula* reverse(celula *head);



/**
    * Insert new cell on a linked list. 
        * x = new_cell's value;   
        * p = the cell before;
**/
void insert_cell(int x, celula *p);



int lenght(celula *head);




#endif // LI_H
