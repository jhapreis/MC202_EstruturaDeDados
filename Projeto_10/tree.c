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
                if(anterior->direita == atual){
                    anterior->direita  = remove_cell(atual);
                }
                else{
                    anterior->esquerda = remove_cell(atual);
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

    if (atual->esquerda == NULL){ // sem filho à esquerda, apontar para filho da direita (com filho à direita ou NULL)
        cell_2 = atual->direita;
        free(atual);
        return cell_2;
    }

    cell_1 = atual;               // procura filho mais à direita na sub-árvore da esquerda
    cell_2 = atual->esquerda;     // (ou seja, o maior filho, que pode assumir o lugar do seu ancestral, sem deixar órfãos -- já que não possui descendentes; é uma folha)
    while(cell_2->direita != NULL){ // enquanto não chegar num descendente folha
        cell_1 = cell_2;
        cell_2 = cell_2->direita;
    }

    if(cell_1 != atual){          // copia o filho mais à direita na sub-árvore da esquerda para o lugar do nó removido
        cell_1->direita  = cell_2->esquerda;
        cell_2->esquerda = atual->esquerda;
    }
    cell_2->direita = atual->direita; 
    free(atual);
    return cell_2;
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

