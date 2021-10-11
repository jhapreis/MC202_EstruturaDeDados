// Includes
// ==================================================

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "li.h"



// 
// ==================================================

int main(){

    int A[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    celula* le = create_empty_le();

    for (int i = 0; i < 10; i++){
        insert_cell_end(A[i], le);
    }

    print_le_cabeca(le);


    sublist(le, 0, 2);

    printf("\n");
    print_le_cabeca(le);
    printf("\n\n");










    return 0;

}
