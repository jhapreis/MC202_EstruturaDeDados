#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prioridade.h"



//====================================================================================================

int insere_FilaPrioridade(fila* fp, int chave, int custo){

    if(fp == NULL) return 0; // inexistente

    if(fp->quantidade_de_elementos == fp->capacidade) return 0; // fila cheia

    // Procure para saber se ele já existe na fila
    int existente = procura_FilaPrioridade(fp, chave);
    if(existente == 1) return 0;


    fp->dados[fp->quantidade_de_elementos].chave = chave;
    fp->dados[fp->quantidade_de_elementos].custo = custo; 

    promoverElemento(fp, fp->quantidade_de_elementos);


    fp->quantidade_de_elementos++;


    return 1;
}



//====================================================================================================

void promoverElemento(fila* fp, int filho){

    int pai = (filho - 1) / 2;

    elem _;


    while(   (filho > 0) && (fp->dados[pai].custo >= fp->dados[filho].custo)   ){

        _ = fp->dados[filho];

        fp->dados[filho] = fp->dados[pai];

        fp->dados[pai] = _;

        filho = pai;
        pai   = (pai - 1) / 2;
    }
}



//====================================================================================================

int remove_FilaPrioridade(fila* fp, char* print_min){

    if(fp == NULL) return 0;

    if(fp->quantidade_de_elementos == 0){
        printf("heap vazio\n");
        return 0;
    }

    elem _ = fp->dados[0];

    fp->quantidade_de_elementos--;
    fp->dados[0] = fp->dados[fp->quantidade_de_elementos];

    rebaixarElemento(fp, 0);

    if( strcmp(print_min, "yes") == 0 ) printf("minimo {%d,%d}\n", _.chave, _.custo);

    return 1;
}



//====================================================================================================

void rebaixarElemento(fila* fp, int pai){

    elem _;

    int filho = 2*pai + 1;


    while(filho < fp->quantidade_de_elementos){

        /**
         * @brief Procure pelo filho com o menor custo (caso haja dois filhos).
         * 
         */
        if(filho < fp->quantidade_de_elementos - 1){
            if(fp->dados[filho].custo > fp->dados[filho+1].custo){
                filho++;
            }
        }


        /**
         * @brief Se o pai <= filho, termine o processo.
         * 
         */
        if(fp->dados[pai].custo <= fp->dados[filho].custo) break;


        /**
         * @brief Troque pai e filho de lugar
         * 
         */
        _ = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = _;

        pai   = filho;
        filho = 2*pai + 1;
    }
}



//====================================================================================================

int consulta_FilaPrioridade(fila* fp, int chave){

    if(fp == NULL || fp->quantidade_de_elementos == 0) return 0;

    chave = fp->dados[0].chave;

    return 1;
}



//====================================================================================================

int diminui_FilaPrioridade(fila* fp, int chave, int custo_novo){

    if(fp == NULL || fp->quantidade_de_elementos == 0) return -1;

    /**
     * @brief Procure na fila pelo elemento encontrado na chave. 
     * 
     * A realocação envolve trocar o custo do elemento e reposicioná-lo na fila.
     * 
     * @param i 
     */
    for(int i=0; i<fp->quantidade_de_elementos; i++){

        if( fp->dados[i].chave == chave ){ // elemento foi encontrado

            fp->dados[i].custo = custo_novo;

            if(i == 0) return 1;

            promoverElemento(fp, i);

            return 1;
        }
    }

    return 0;
}



//====================================================================================================

int procura_FilaPrioridade(fila* fp, int chave){

    if(fp == NULL || fp->quantidade_de_elementos == 0) return -1;

    /**
     * @brief Procure na fila pelo elemento encontrado na chave. 
     * 
     * @param i 
     */
    for(int i=0; i<fp->quantidade_de_elementos; i++){

        if( fp->dados[i].chave == chave ){ // elemento foi encontrado

            return 1;
        }
    }
    

    return 0;
}
