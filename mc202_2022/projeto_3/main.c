#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "substring.h"



// (a) leia dois números inteiros n e m;
// (b) leia uma sequência de n caracteres, que vamos chamar de texto; leia uma sequência de m
// caracteres, que vamos chamar de padrão;
// (c) encontre todas as ocorrências do padrão no texto. A resposta deve ser, portanto, uma
// sequência de ı́ndices i 1 , i 2 , . . . , i k que indicam o inı́cio de cada ocorrência do padrão no
// texto. Caso o padrão não ocorra nenhuma vez no texto, seu programa deve escrever a
// mensagem ”padrão não ocorre no texto”.
// Por exemplo, para n = 15, m = 4, texto = ‘minhamamaemeama’ e padrão = ‘ama’, a resposta
// deve ser 5, 7 e 13.



int main(){


    // Declaracao de variaveis
    // --------------------------------------------------

    int tamanho_texto = 0, tamanho_padrao = 0;

    lista* list_indexes = NULL;


    // Preencher com os parametros de tamanho de texto e padrao 
    // --------------------------------------------------

    printf("Qual o tamanho da string de texto? ");

    scanf("%d%*c", &tamanho_texto);

    printf("\nE qual o tamanho da string de padrao? ");

    scanf("%d%*c", &tamanho_padrao);


    // Coletar strings de texto e padrao
    // --------------------------------------------------
    
    char texto[tamanho_texto];

    char padrao[tamanho_padrao];

    printf("\nQual a string de texto?\n");

    scanf("%s", texto);

    printf("\nE qual a string padrao?\n");

    scanf("%s", padrao);


    // Encontrar indices do padrao e exibir
    // --------------------------------------------------

    list_indexes = find_indexes_substring(texto, padrao);

    print_lista(list_indexes);


    // Encerrando
    // --------------------------------------------------

    deletar_lista(list_indexes);

    return 0;
}
