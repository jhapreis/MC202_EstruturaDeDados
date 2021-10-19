// Includes
// ==================================================

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "dupla_encadeada.h"



int main()
{


    float valor = 0, chave = 0;
    int posicao = 0, tempo = 1, len = 0;

    char cmd;

    Lista *le = create_empty_lista();


    while (1) {

	scanf("%c", &cmd);

	// exit
	if (cmd == 'f') {

	    free_lista(le);

	    exit(1);
	}
	// i x k y
	else if (cmd == 'i') {

	    scanf("%f %d %f\n", &valor, &posicao, &chave);

	    insert_cell(le, posicao, valor, chave, tempo, len);

	    tempo += 1;

        len += 1;
	}
	// r x
	else if (cmd == 'r') {

	    scanf("%f\n", &valor);

	    find_and_remove_cell(le, valor, len);

	    tempo += 1;

        len -= 1;
	}
	// p
	else if (cmd == 'p') {
	    print_lista(le);
	}
    }

    return 0;
}
