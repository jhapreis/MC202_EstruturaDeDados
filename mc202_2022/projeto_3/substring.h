#ifndef __SUBSTRING__
#define __SUBSTRING__


// ==================================================
// Structs
// --------------------------------------------------
/**
 * @brief 
 * 
 */

typedef struct node{

    int chave;

    struct node* proximo;

}no;


typedef struct lista{

    int quantidade;

    no* root;

}lista;
// ==================================================


/**
 * @brief 
 * 
 * @return lista* 
 */
lista* criar_lista();



/**
 * @brief 
 * 
 * @param list 
 */
void deletar_lista(lista* list);



/**
 * @brief 
 * 
 * @param list 
 * @param chave 
 * @return int 
 */
int adicionar_elemento_lista(lista* list, int chave);



/**
 * @brief 
 * 
 * @param list 
 */
void print_lista(lista* list);



// --------------------------------------------------
/**
 * @brief 
 * 
 * @param texto 
 * @param padrao 
 * @return array_indexes* 
 */
lista* find_indexes_substring(char* texto, char* padrao);



#endif
