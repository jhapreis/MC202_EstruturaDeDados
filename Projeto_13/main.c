#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "prioridade.h"



int main(){

    char cmd[12];
    int chave = -1;
    int custo = -1;



    /**
     * @brief Obter capacidade desejada e criar uma fila de prioridades
     * inicial com esse valor.
     * 
     */

    int capacidade_fila = 0;
    scanf("%d%*c", &capacidade_fila);
    
    elem dados_fila[capacidade_fila];

    fila fila_prioridade = (fila) {.capacidade = capacidade_fila, .dados = dados_fila, .quantidade_de_elementos = 0};

    fila* fp = &fila_prioridade; // fila de prioridades


    /**
     * @brief Terminal interativo
     * 
     */

    while(1){

        // printf("Insira um comando: \n");
        scanf("%s", cmd);


        if(   strcmp(cmd, "i") == 0   ){
            scanf("%d %d", &chave, &custo);

            insere_FilaPrioridade(fp, chave, custo);
        }

        else if(   strcmp(cmd, "m") == 0   ){

            remove_FilaPrioridade(fp, "yes");
        }

        else if(   strcmp(cmd, "d") == 0   ){

            scanf("%d %d", &chave, &custo);

            diminui_FilaPrioridade(fp, chave, custo);
        }

        else if(   strcmp(cmd, "t") == 0   ){
            exit(EXIT_SUCCESS);
        }
    }


    return 0;
}
