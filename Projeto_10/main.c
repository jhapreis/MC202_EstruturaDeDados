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

#include "tree.h"



int main(){

    char cmd[200];
    int x;

    tree* root = NULL;

    while(1){

        scanf("%s", cmd);

        if ( strcmp(cmd, "criar") == 0 ){ // ok
            free_tree(root);
            root = criar_tree();
        }

        else if ( strcmp(cmd, "inserir") == 0 ){
            scanf("%d", &x);
            insert_tree(root, x);
        }

        else if ( strcmp(cmd, "remover") == 0 ){
            scanf("%d", &x);
            find_and_remove_tree(root, x);
        }

        else if ( strcmp(cmd, "buscar") == 0 ){
            scanf("%d", &x);

            int found = find_value(root, x);

            if (found == 1){
                printf("%d esta na arvore\n", x);
            }
            else{
                printf("%d nao esta na arvore\n", x);
            }
        }

        else if ( strcmp(cmd, "pre-ordem") == 0 ){
            
        }

        else if ( strcmp(cmd, "em-ordem") == 0 ){
            
        }

        else if ( strcmp(cmd, "pos-ordem") == 0 ){
            
        }

        else if ( strcmp(cmd, "minimo") == 0 ){
            
        }

        else if ( strcmp(cmd, "maximo") == 0 ){
            
        }

        else if ( strcmp(cmd, "sucessor") == 0 ){
            scanf("%d", &x);
            
        }

        else if ( strcmp(cmd, "predecessor") == 0 ){
            scanf("%d", &x);
            
        }

        else if ( strcmp(cmd, "info") == 0 ){
            
        }

        else if ( strcmp(cmd, "terminar") == 0 ){ // ok
            free_tree(root);
            return 0;
        }

        else{
            printf("comando inválido :/\n");
        }

    }




    return 0;



}
