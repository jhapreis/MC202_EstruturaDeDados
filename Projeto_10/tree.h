/**
 * @file tree.h
 * @author Jorge Reis (jhapreis@gmail.com)
 * @brief Árvore de busca binária (header)
 * @version 0.1
 * @date 2021-10-26
 */

// ==================================================
// Includes
// ==================================================

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>



// ==================================================
// Métodos principais (primeira ordem)
// ==================================================

/**
 * @brief Estrutura que define a criação de uma árvore.
 * 
 */
typedef struct cell* tree;



/**
 * @brief Estrutura para a criação de cada novo nó da árvore.
 * 
 */
struct cell{
    int value;
    struct cell* esquerda;
    struct cell* direita;
};



/**
 * @brief Aloca memória (com malloc) para a criação da primeira célula da árvore, que é sua raiz.
 * 
 * @return tree*; raiz da árvore 
 */
tree* criar_tree();



/**
 * @brief Libera a memória alocada dinamicamente pela árvore; destrói a árvore criada.
 * 
 * @param root 
 */
void free_tree(tree* root);



/**
 * @brief Insere um determinado valor na árvore de busca binária.
 * 
 * @param root 
 * @param valor 
 * @return int ; sucesso ou não
 */
int insert_tree(tree* root, int valor);



/**
 * @brief Procura, na árvore binária, por uma correspondência para o valor dado. 
 * Se encontrar, remove esse valor e redireciona os apontadores para cobrir o espaço aberto na árvore.
 * 
 * @param root 
 * @param valor 
 * @return int ; sucesso ou não
 */
int find_and_remove_tree(tree* root, int valor);




/**
 * @brief Percorre a árvore de busca binária à procura de uma correspondência com o valor requerido.
 * 
 * @param root 
 * @param valor 
 * @return int. Status: 0 se não há; 1 caso haja
 */
int find_value(tree* root, int valor);







// ==================================================
// Métodos auxiliares (segunda ordem)
// ==================================================

/**
 * @brief Remove uma célula da árvore binária e devolve a posição que agora ocupará.
 * Feita para ser usada como auxiliar à função find_and_remove_tree.
 * 
 * @param atual 
 * @return struct cell* ; apontador para o local, na árvore, da célula que acabou de ser removida
 */
struct cell* remove_cell(struct cell* atual);



/**
 * @brief Deleta recursivamente cada um dos nós (células) da árvore.
 * Essa função serve, prioritariamente, como auxiliar à função free_tree. 
 * 
 * @param celula 
 */
void free_cell(struct cell* celula);
