// Includes
// ==================================================

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "li.h"


// A = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
// s A[0..9]
// s A[9..0]
// + A[6..3] 2
// s A[2..10]
// s A[4..7]
// s A[2..0]
// s A[1..1]
// f

// ==================================================

int main(){

    int valor = 0, index_start = 0, index_finish = 0, position = 0;
    char cmd[200];



    celula* le = create_empty_le(); // empty list

    while(   (scanf("A = {%d,", &valor) == 1) || (scanf("%d,", &valor) == 1)   ) {
        insert_cell_end(valor, le); // fill list values
    }
    
    

    while(1){

        fgets(cmd, sizeof(cmd), stdin);

        // exit
        if ( cmd[0] == 'f' ){
            delete(le);
            exit(1);
        }

        // substring
        else if ( cmd[0] == 's' ){

            sscanf(cmd, "s A[%d..%d]", &index_start, &index_finish);

            le = sublist(le, index_start, index_finish);

            print_le_cabeca(le);
        }

        // add substring
        else if ( cmd[0] == '+' ){

            sscanf(cmd, "+ A[%d..%d] %d", &index_start, &index_finish, &position);

            insert(le, index_start, index_finish, position);

            print_le_cabeca(le);
            
        }
    }


    return 0;
}
