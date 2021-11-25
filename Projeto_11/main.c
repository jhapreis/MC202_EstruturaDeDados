/**
 * @file main.c
 * @author Jorge Reis (jhapreis@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-26
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "hash.h"



int main(){

    char cmd[STRING_MAX_SIZE];
    int tamanho_tabela;
    int pos;

    Hash* ha = NULL;
    Message msg;

    int timestamp = 0;


    while(1){

        printf("Digite um comando: \n");

        scanf("%s", cmd);



        if ( strcmp(cmd, "c") == 0 ){ // criar tabela
        
            scanf("%d", &tamanho_tabela);

            if(ha != NULL){ // se já existe uma tabela sendo usada, deletar
                freeHash(ha);
            }

            tamanho_tabela = tamanhoTabela(tamanho_tabela);

            printf("Creating hash table... of size %d :)\n\n", tamanho_tabela);

            ha = criarHash(tamanho_tabela);

            timestamp = 0;
        }



        else if ( strcmp(cmd, "f") == 0 ){ // finish

            printf("Finishing... :)\n\n\n");
            freeHash(ha);
            exit(0);
        }



        else if ( strcmp(cmd, "i") == 0 ){ // insert

            scanf("%*c%[^\n]", cmd); // descarta o " ", lê até "\n" e o descarta

            strcpy(msg.string, cmd);
            msg.timestamp = timestamp;

            insertHash_EnderAberto(ha, msg);

            timestamp += 1;
            printf("\n");
        }



        else if ( strcmp(cmd, "b") == 0 ){ // busca

            scanf("%*c%[^\n]", cmd); // descarta o " ", lê até "\n" e o descarta

            strcpy(msg.string, cmd);
            msg.timestamp = -1;

            buscaHash_EnderAberto(ha, cmd, msg);
        }



        else if ( strcmp(cmd, "r") == 0 ){ // remove
        
            scanf("%*c%[^\n]", cmd); // descarta o " ", lê até "\n" e o descarta

            removeHash(ha, cmd, msg);

            printf("\n");
        }



        else if ( strcmp(cmd, "p") == 0 ){ // remove
            scanf("%d", &pos); // descarta o " ", lê até "\n" e o descarta

            printHash(ha, pos);

            printf("\n");
        }
    }
}
