#ifndef __SUBSTRING__
#define __SUBSTRING__


// ==================================================
// Structs
// --------------------------------------------------
/**
 * @brief 
 * 
 */
// typedef struct array_indexes{

//     int quantidade;

//     int** array;

// }array_indexes;


typedef struct node{

    int chave;

    struct node* proximo;

}no;


typedef struct lista{

    int quantidade;

    no* root;

}lista;
// ==================================================



lista* criar_lista();

void deletar_lista(lista* list);

int adicionar_elemento_lista(lista* list, int chave);

void print_lista(lista* list);



// --------------------------------------------------
// /**
//  * @brief 
//  * 
//  * @param quantidade_de_indexes 
//  * @return array_indexes* 
//  */
// array_indexes* criar_array_indexes(int quantidade_de_indexes);



// --------------------------------------------------
// /**
//  * @brief 
//  * 
//  * @param array 
//  */
// void deletar_array_indexes(array_indexes* array);



// --------------------------------------------------
/**
 * @brief 
 * 
 * @param texto 
 * @param padrao 
 * @return array_indexes* 
 */
lista* find_indexes_substring(char* texto, char* padrao);



// --------------------------------------------------
// /**
//  * @brief 
//  * 
//  * @param array 
//  */
// void print_array_indexes(array_indexes* array);



#endif
