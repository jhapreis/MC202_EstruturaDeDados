#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hash.h"



Hash* criarHash(int size){

    Hash* ha = (Hash*) malloc(sizeof(Hash));

    if(ha != NULL){

        ha->tamanho_total = size;

        ha->strings = (Message**) malloc(size * sizeof(Message*));

        if(ha->strings == NULL){ // problema na alocação do ponteiro para as informações
            free(ha);
            return NULL;
        }

        ha->quantidade_total = 0;
        for(int i=0; i<ha->tamanho_total; i++){ //do malloc, passa para todos os espaços o valor NULL
            ha->strings[i] = NULL;
        }
    }

    return ha;
}



void freeHash(Hash* ha){

    if(ha != NULL){ // verifica se há uma tabela a ser removida

        for(int i=0; i < ha->tamanho_total; i++){ // percorre a tabela

            if(ha->strings[i] != NULL){ // se a posição não está vazia, remova o elemento
                free(ha->strings[i]);
            }
        }

        free(ha->strings); // remova o array que define os itens

        free(ha); // remova a tabela em si, anteriormente alocada
    }
}



int insertHash_EnderAberto(Hash* ha, Message msg){

    int new_pos = 0;

    if(ha == NULL || ha->quantidade_total == ha->tamanho_total){ // tabela inexistente ou cheia
        return 0;
    }

    // printf("   pos = %lu\n", djb2(msg.string));

    int pos = (int) (djb2(msg.string) % ha->tamanho_total); // converte a posição calculada, devolvida pela função de hashing, para um número que caiba na tabela

    for(int i=0; i < ha->tamanho_total; i++){

        new_pos = duploHash(pos, msg, i, ha->tamanho_total);

        if(ha->strings[new_pos] == NULL){ // posição vazia foi encontrada

            Message* new_msg = (Message*) malloc(sizeof(Message));

            if(new_msg == NULL){ // erro na alocação de memória
                return 0;
            }

            *new_msg = msg;

            ha->strings[new_pos] = new_msg;

            ha->quantidade_total += 1;

            printf("   pos = %d\n", new_pos);

            return 1;
        }
        
        else if(   strcmp(ha->strings[new_pos]->string, msg.string) == 0   ){ // se ele esbarrar com a mesma mensagem, pare
            printf("   found \n");
            return 0;
        }
    }

    return 1;
}



int buscaHash_EnderAberto(Hash* ha, char* string, Message msg){

    int new_pos = 0;

    if(ha == NULL){ // tabela inexistente
        return 0;
    }

    int pos = (int) (djb2(string) % ha->tamanho_total); // converte a posição calculada, devolvida pela função de hashing, para um número que caiba na tabela

    for(int i=0; i < ha->tamanho_total; i++){

        printf("%d ", i);

        new_pos = duploHash(pos, msg, i, ha->tamanho_total);

        if(ha->strings[new_pos] == NULL){ // posição vazia foi encontrada
            printf("TS de [%s]: %d\n", string, -1);
            return -1;
        }
        
        else if(   strcmp(ha->strings[new_pos]->string, string) == 0   ){ // se ele esbarrar com a mesma mensagem, pare
            printf("TS de [%s]: %d\n", string, ha->strings[new_pos]->timestamp);
            return 0;
        }
    }

    return -1;
}



int removeHash(Hash* ha, char* substring, Message msg){

    int pos = buscaHash_EnderAberto(ha, substring, msg);

    if(pos == -1){ // falha na busca
        return 0;
    }
    
    free(ha->strings[pos]); // libera a informação nesse índice da tabela

    ha->strings[pos] = NULL; // o respectivo endereço agora está vazio

    return 1;
}



int printHash(Hash* ha, int pos){

    if(ha == NULL){
        return 0;
    }

    if(ha->strings[pos] == NULL){
        return 0;
    }

    printf("   message = %s\n   timestamp = %d\n", ha->strings[pos]->string, ha->strings[pos]->timestamp);

    return 1;
}





//==================================================
// FUNÇÃO DE HASHING
//==================================================

unsigned long djb2(char *str) {

    unsigned char* string = (unsigned char*) str;

    unsigned long hash = 5381;
    int c;
  
    while ((c = *string++))
        hash = ((hash << 5) + hash) ^ c; // hash * 33 XOR c
    
    return hash;
}



int duploHash(int pos_inicial, Message msg, int i, int table_size){

    int deslocamento = 7;

    int pos_final = (pos_inicial + i*deslocamento) % table_size;

    return pos_final;
}





//==================================================
// TAMANHO DA TABELA HASH
//==================================================

int ehPrimo(int number){

    for(int i=2; i<=number/2; i++){
        if(number % i == 0){
            return 0;
        }
    }

    return 1;
}



int tamanhoTabela(int num){

    int size = (int) (num/0.80) + 1; // arredondamento para cima da margem de 80 porcento

    if(ehPrimo(size) == 1){ // retorna se já for um número primo
        return size;
    }

    while(ehPrimo(size) != 1){ // procure por um número primo
        size++;
    }

    return size;
}
