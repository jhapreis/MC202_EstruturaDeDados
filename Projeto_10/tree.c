/**
 * @file main.c
 * @author Jorge Reis (jhapreis@gmail.com)
 * @brief 
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

#include "tree.h"



// ==================================================
// Métodos principais (primeira ordem)
// ==================================================

tree* criar_tree(){
/**
 * @brief Tenta alocar memória para o ponteiro raiz. Em caso de sucesso, aponta para NULL. 
 * Se falhar, à variável é atribuído NULL. 
 */

    tree* root = (tree*) malloc(sizeof(tree));

    if (root != NULL){
        *root = NULL;
    }

    return root;
}



void free_tree(tree* root){
/**
 * @brief Se a árvore não for vazia, deleta todos os nós da árvore e, por último, a sua raiz.
 * 
 */

    if (root == NULL){
        return;
    }

    free_cell(*root); // libera cada nó
    free(root);       // libera a raiz
}



int insert_tree(tree* root, int valor){


    if (root == NULL){ // se não existe raiz
        return 0;
    }


    struct cell* new_cell;
    new_cell = (struct cell*) malloc(sizeof(struct cell));

    if (new_cell == NULL){ // se falhou na alocação de uma nova célula
        printf("memoria insuficiente\n");
        return -1;
    }


    new_cell->value    = valor;
    new_cell->direita  = NULL;
    new_cell->esquerda = NULL;


    if (*root == NULL){ // se não há um primeiro elemento ainda, inserir na primeira posição
        *root = new_cell;
    }

    else{ // caso haja, procurar onde inserir
        struct cell* atual    = *root;
        struct cell* anterior = NULL;

        while(atual != NULL){ // percorra, na árvore, o caminho para inserir até chegar em uma de suas folhas, para inserir
            anterior = atual;
            if (valor == atual->value){  // se já existe elemento com esse valor, cancele a inserção
                free(new_cell);
                return 1;
            }
            if (valor > atual->value){   // se maior, continue a busca para a direita
                atual = atual->direita;
            }
            else{
                atual = atual->esquerda; // se menor, continue a busca para a esquerda
            }
        }

        if (valor > anterior->value){     // insira na direita
            anterior->direita = new_cell;
        }
        else{
            anterior->esquerda = new_cell; // insira na esquerda
        }
    }

    return 0;
}



int find_and_remove_tree(tree* root, int valor){

    if (root == NULL) return -1; // árvore inválida

    struct cell* anterior = NULL;
    struct cell* atual    = *root;

    while(atual != NULL){ // procure por uma correspondência

        if(atual->value == valor){ // se achou correspondência, remova e encerre a remoção

            if (atual == *root){ // se for a raiz, remova ela
                *root = remove_cell(atual);
            }
            else{ // se não for a raiz, verifique de qual lado está e repasse a posição que ocupará
                if(atual == anterior->direita){
                    anterior->direita  = remove_cell(atual); // reconecte a sub-árvore com o anterior pela direita
                }
                else{
                    anterior->esquerda = remove_cell(atual); // reconecte a sub-árvore com o anterior pela esquerda
                }
            }
            return 0;
        }

        anterior = atual; // continue percorrendo a árvore, em busca de uma correspondência
        if(valor > atual->value){
            atual = atual->direita;
        }
        else{
            atual = atual->esquerda;
        }
    }

    return 1;
}



int find_value(tree* root, int valor){

    if (root == NULL) return -1; // árvore inválida

    struct cell* atual = *root;

    while(atual != NULL){ // procure na árvore, a partir da raiz, até encontrar ou até o final

        if(atual->value == valor){
            return 1;
        }

        if(valor > atual->value){
            atual = atual->direita;
        }
        else{
            atual = atual->esquerda;
        }
    }

    return 0;
}



int sucessor_predecessor(tree* root, int valor, char* tag){
    /**
     * @brief Primeiramente, procura pelo valor passado. Caso encontre, procura um 
     * sucessor (um filho da direita) ou um predecessor (um filho da esquerda).
     * Se o descendente não for NULL (e se tiver achado), exibe a informação na tela.
     */

    if (root == NULL) return -1; // árvore inválida

    struct cell* atual = *root;

    int found = 0;

    while(atual != NULL){ // procure na árvore, a partir da raiz, até encontrar a chave ou até o final

        if(atual->value == valor){ // se encontrar, interrompa a procura
            found = 1; // especifica que foi encontrado o valor na árvore
            break;
        }

        if(valor > atual->value){ // continue procurando
            atual = atual->direita;
        }
        else{
            atual = atual->esquerda;
        }
    }


    if ( strcmp(tag, "sucessor") == 0 ){ // se estiver buscando pelo SUCESSOR
            if (found == 1 && atual->direita != NULL){ // se foi achado && se existe à direita
                printf("sucessor de %d: %d\n", valor, atual->direita->value);
                return 1;
            }
            else{ // se não foi achado ou se é NULL à direita
                printf("nao ha sucessor de %d\n", valor);
            }
        } 
    else if ( strcmp(tag, "predecessor") == 0 ){ // se estiver buscando pelo PREDECESSOR
            if (found == 1 && atual->esquerda != NULL){ // se foi achado && se existe à esquerda
                printf("predecessor de %d: %d\n", valor, atual->esquerda->value);
                return 1;
            }
            else{ // se não foi achado ou se é NULL à esquerda
                printf("nao ha predecessor de %d\n", valor);
            }
        }
    else{
        printf("comando não reconhecido :/\n");
    }

    return 0;
}



int minimo_tree(tree* root){

    if (root == NULL) return -1; // árvore inválida

    struct cell* atual = *root;

    int minimo = atual->value;

    while(atual->esquerda != NULL){ // enquanto houver valores menores (filhos da esquerda)
        minimo = atual->esquerda->value;
        atual  = atual->esquerda;
    }

    return minimo;
}



int maximo_tree(tree* root){

    if (root == NULL) return -1; // árvore inválida

    struct cell* atual = *root;

    int maximo = atual->value;

    while(atual->direita != NULL){ // enquanto houver valores menores (filhos da esquerda)
        maximo = atual->direita->value;
        atual  = atual->direita;
    }

    return maximo;
}



infos* info_tree(tree* root, int return_info){
    /**
     * @brief Utiliza o método do cálculo de alturas (altura_tree) para salvar e imprimir na tela
     * as informações requisitadas. Devolver as informações é opcional. 
     */

    infos* info = (infos*) calloc( 1, sizeof(infos) ); // Iniciar valores com zero.

    int altura = altura_tree(root, info);

    if (altura >= 1){ // correção da altura, porque o nível original é zero, não um
        info->height = altura - 1;
    }
    else{ // não é necessário correção
        info->height = altura;
    }
    
    printf("nos: %d, folhas: %d, altura: %d\n", info->number_cells, info->number_leafs, info->height);

    if(return_info != 1){
        free(info);
        info = NULL;
    }
    
    return info;   
}



int pre_ordem_tree(tree* root){

    if (root == NULL) return -1;  // árvore inválida
    if (*root == NULL) return 0; // fim da árvore

    printf("%d ", (*root)->value);

    pre_ordem_tree( &( (*root)->esquerda ) );

    pre_ordem_tree( &( (*root)->direita  ) );

    return 0;
}



int em_ordem_tree(tree* root){

    if (root == NULL) return -1;  // árvore inválida
    if (*root == NULL) return 0; // fim da árvore

    em_ordem_tree( &( (*root)->esquerda ) );

    printf("%d ", (*root)->value);
        
    em_ordem_tree( &( (*root)->direita ) );

    return 0;
}



int pos_ordem_tree(tree* root){

    if (root == NULL) return -1;  // árvore inválida
    if (*root == NULL) return 0; // fim da árvore

    pos_ordem_tree( &( (*root)->esquerda ) );
    
    pos_ordem_tree( &( (*root)->direita  ) );

    printf("%d ", (*root)->value);

    return 0;
}







// ==================================================
// Métodos auxiliares (segunda ordem)
// ==================================================

struct cell* remove_cell(struct cell* atual){
    /**
     * @brief 
     * [...]
     * Caso não encontre um descendente na linhagem para assumir o lugar, o elemento é deletado e 
     * quem assume é o elemento à esquerda do atual, que passa a fazer conexão direta com o anterior (pela esquerda) e
     * que recebe, como linhagem, a sub-árvore da direita do elemento atual.
     */

    struct cell *cell_1, *cell_2;

    if (atual->esquerda == NULL && atual->direita == NULL){ // remover nó folha
        cell_2 = NULL;
        free(atual);
        return cell_2;
    }
    else if(atual->esquerda == NULL){ // sem filho somente à esquerda
        cell_2 = atual->direita;
        free(atual);
        return cell_2;
    }
    else if(atual->direita == NULL){ // sem filho somente à direita
        cell_2 = atual->esquerda;
        free(atual);
        return cell_2;
    }
    else{ // nó com dois filhos

        cell_1 = atual;               
        cell_2 = atual->direita; // entra na sub-árvore da direita
        while(cell_2->esquerda != NULL){
            /**
             * Enquanto não chegar num nó folha, procurar, na sub-árvore da direita,
             * o menor valor possível (um descendente para substituir). 
             */
            cell_1 = cell_2;
            cell_2 = cell_2->esquerda;
        }

        /**
         * Copia o filho mais à esquerda na sub-árvore da direita
         * para o lugar do nó a ser removido 
         */
        if(cell_1 != atual){
            cell_1->esquerda  = cell_2->direita;
            cell_2->direita = atual->direita;
        }
        cell_2->esquerda = atual->esquerda; 
        free(atual);
        return cell_2;
    }   
}



void free_cell(struct cell* celula){

    if (celula == NULL){ // se não há nada para deletar
        return;
    }

    free_cell(celula->esquerda);
    free_cell(celula->direita);
    free(celula);

    celula = NULL;
}



int altura_tree(tree* root, infos* info){
    /**
     * @brief Função auxiliar da função info_tree. 
     * Recursivamente, em cada sub-árvore, tenta encontrar a altura delas, até que chegue em uma folha.
     * Daí, vai somando uma unidade, de trás pra frente, até chegar de volta com a altura total até a raiz.
     * Enquanto isso, vai coletando outras duas informações: o número de células e o número de folhas.
     */


    if (root == NULL){ // isso representa um erro, pois a raiz não deve ser nula.
        return 0;
    }


    if (*root == NULL){ // se isso aconteceu, é porque não existe a célula; chegou ao fim da árvore
        return 0;
    }
    else if ( (*root)->direita == NULL && (*root)->esquerda == NULL ){ // procura por células e folhas (que também são células)
        info->number_leafs += 1;
        info->number_cells += 1;
    }
    else if( (*root)->direita != NULL || (*root)->esquerda != NULL ){ // procura por céluas que não são folhas
        info->number_cells += 1;
    }


    int dist_esquerda = altura_tree(   &( (*root)->esquerda ) , info  ); // rode na sub-árvore da esquerda
    int dist_direita  = altura_tree(   &( (*root)->direita  ) , info  ); // rode na sub-árvore da direita

    if(dist_esquerda > dist_direita){ // a altura é definida como sendo a maior altura, ou da direita ou da esquerda
        return (dist_esquerda + 1);
    }
    else{
        return(dist_direita + 1);
    }
}
