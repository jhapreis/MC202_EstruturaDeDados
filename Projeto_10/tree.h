/**
 * @file tree.h
 * @author Jorge Reis (jhapreis@gmail.com)
 * @brief Árvore de busca binária (header)
 * @version 0.1
 * @date 2021-10-26
 */



 #ifndef TREE_H
 #define TREE_H



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
 * @brief Estrutura para guardar as informações do número de folhas, número de células e altura
 * da árvore. 
 */
typedef struct infos{
    int number_leafs;
    int number_cells;
    int height;
} infos;


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



/**
 * @brief Dada uma chave, procura quem é o elemento consecutivo (ou antecessor)
 * no armazenamento na árvore. Imprime esse valor, caso encontre. 
 * 
 * @param root 
 * @param valor valor do qual se procura um sucessor ou predecessor
 * @param tag "sucessor" ou "predecessor"
 * @return int - status de sucesso ou falha
 */
int sucessor_predecessor(tree* root, int valor, char* tag);



/**
 * @brief Função para encontrar o valor mínimo armazenado na árvore.
 * 
 * @param root 
 * @return int - valor mínimo na árvore
 */
int minimo_tree(tree* root);



/**
 * @brief  Função para encontrar o valor máximo armazenado na árvore.
 * 
 * @param root 
 * @return int - valor máximo na árvore
 */
int maximo_tree(tree* root);



/**
 * @brief Esta função aloca na memória (e depois remove, se requisitado)
 * as informações obtidas para o número de células, número de folhas e altura
 * da árvore.
 * 
 * @param root 
 * @param return_info 0 se não quiser retornar as informações; 1 se quiser 
 * @return infos* ; retorno é opcional, 
 * porém retorna ou NULL ou um ponteiro para as informações
 */
infos* info_tree(tree* root, int return_info);



/**
 * @brief Percorre a árvore, a partir da raiz, em pré-ordem:
 * raiz, sub-árvore esquerda, sub-árvore direita, repete até o final da árvore.
 * 
 * @param root 
 * @return int ; status de erro
 */
int pre_ordem_tree(tree* root);



/**
 * @brief Percorre a árvore, a partir da raiz, em in-ordem:
 * sub-árvore esquerda, raiz, sub-árvore direita, repete até o final da árvore.
 * 
 * @param root 
 * @return int ; status de erro
 */
int em_ordem_tree(tree* root);



/**
 * @brief Percorre a árvore, a partir da raiz, em pós-ordem:
 * sub-árvore esquerda, sub-árvore direita, raiz, repete até o final da árvore.
 * 
 * @param root 
 * @return int ; status de erro
 */
int pos_ordem_tree(tree* root);









// ==================================================
// Métodos auxiliares (segunda ordem)
// ==================================================

/**
 * @brief Remove uma célula da árvore binária e devolve a posição que agora ocupará.
 * Feita para ser usada como auxiliar à função find_and_remove_tree.
 * 
 * @param atual 
 * @return struct cell* ; apontador para o local, na árvore, da célula que ocupará o lugar.
 */
struct cell* remove_cell(struct cell* atual);



/**
 * @brief Deleta recursivamente cada um dos nós (células) da árvore.
 * Essa função serve, prioritariamente, como auxiliar à função free_tree. 
 * 
 * @param celula 
 */
void free_cell(struct cell* celula); 



/**
 * @brief Percorre toda a árvore para encontrar a altura dela.
 * Ao mesmo tempo, atualiza a quantidade de células e de folhas, conforme encontra.
 * É uma função auxiliar para info_tree.
 * 
 * @param root 
 * @param info 
 * @return int 
 */
int altura_tree(tree* root, infos* info);



#endif //TREE_H
