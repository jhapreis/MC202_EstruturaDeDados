#include <stdio.h>
#include <stdlib.h>

/*

0 0 0 0 --> X
7 0 0 0 --> [1,0] 7
0 0 9 0 --> [2,2] 9
0 0 0 0 --> X
0 8 0 5 --> [4,1] 8; [4,3] 5

n m
k elementos não-nulos
entradas dos elementos não-nulos
p printf
a [i,j] value --> substituir valor
r [i,j] --> mostrar M[i,j]
t --> terminar

*/


//////////////////////////////////////////////////
typedef struct elemento_matriz_esparsa{
    int i_row;
    int j_column;
    int value;
}ELEMENTO;





//////////////////////////////////////////////////
ELEMENTO empty_matriz_esparsa(int number_rows, int number_columns, int non_null_elements){

    int number_rows_matriz_esparsa = number_rows + number_columns;

    ELEMENTO arr[number_rows_matriz_esparsa];

    return arr[number_rows_matriz_esparsa];

}



int convert_digit_to_int(char digit){

    int digit_int = digit - '0';

    return(digit_int);

}




//////////////////////////////////////////////////
ELEMENTO unpack_data_input(char *input_data){

    ELEMENTO data;

    //[i,j] x
    if (input_data[0] == '['){
        
        // data
        // = { atoi( input_data[1] ), 
        //     atoi( input_data[3] ), 
        //     atoi( input_data[6] ) };

        printf("%s", input_data);

        data.i_row    = atoi( input_data[1] );
        data.j_column = atoi( input_data[3] );
        data.value    = atoi( input_data[6] );
        
        printf("%s\n", "data input");
    }



    //a [i,j] x
    else if (input_data[0] == 'a'){

        data.i_row    = atoi( input_data[3] );
        data.j_column = atoi( input_data[5] );
        data.value    = atoi( input_data[8] );

        printf("%s\n", "add");
    }
    


    //r [i,j]
    else if (input_data[0] == 'r'){

        

        printf("%s\n", "retrieve");
    }


    return data;

}



    




//////////////////////////////////////////////////
int print_full_matrix(){

    char *error_message = "O vetor de coordenadas esta' cheio."; 

    printf("%s\n", error_message);

    return 0;

}



//////////////////////////////////////////////////
int main(){

    int number_rows, number_columns, non_null_elements, max_lenght = 10;



    scanf("%d %d\n", &number_rows, &number_columns);

    scanf("%d\n", &non_null_elements);

    ELEMENTO matriz_esparsa = empty_matriz_esparsa(number_rows, number_columns, non_null_elements);



    int running_state = 1;
    char input_data[max_lenght];
    
    while(running_state == 1){

        fgets(input_data, max_lenght, stdin);

        //p
        if (input_data[0] == 'p'){
            printf("print\n");
        }

        //t
        else if (input_data[0] == 't'){
            printf("end\n");
            running_state = 0;
        }

        else{

            unpack_data_input(input_data);

        }

    }
    
    printf("done\n");
    
    

    



    return 0;

}





















// ELEMENTO arr_struct(){

//     ELEMENTO arr[3]
//     = { {1, 2, 3}, 
//         {4, 5, 6}, 
//         {7, 8, 9} };

//     return arr[3];

// }





// check_instruction_input(int running){

//     int max_lenght = 10;

//     char input_data[max_lenght];

//     fgets(input_data, max_lenght, stdin);

//     ELEMENTO data;

//     //p
//     if (input_data[0] == 'p'){
//         printf("%s\n", "print");
//     }

//     //t
//     else if (input_data[0] == 't'){
//         printf("%s\n", "end");
//         running = 0;
//     }

// }
