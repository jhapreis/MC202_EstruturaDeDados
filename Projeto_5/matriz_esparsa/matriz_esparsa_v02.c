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



//Structure
//##################################################
typedef struct matriz_esparsa{
    int i_row;
    int j_col;
    int value;
}MATRIZ;



//Declaration of functions
//##################################################
int retrieve_matrix_value_given_coordinates(
    MATRIZ *matrix,  
    int number_of_non_null, 
    char *input_data
    );

void print_matrix(
    MATRIZ *matrix, 
    int total_elements
    );

void sort_matrix(
    MATRIZ *matrix,
    int number_elements
    );

MATRIZ unzip_input_data(
    char *input_data
    );



//##################################################
int convert_digit_to_int(char digit){
    int digit_int = digit - '0';
    return(digit_int);
}



//##################################################
MATRIZ null_matrix(MATRIZ *matrix, int max_dimension){

    // int value = 0, row = -1, col = -1;

    // MATRIZ new_matrix[max_dimension];

    for (int i = 0; i < max_dimension; i++){
        matrix[i].i_row = -1;
        matrix[i].j_col = -1;
        matrix[i].value =  0;
    }

    return matrix[max_dimension];
}



//##################################################
MATRIZ unzip_input_data(char *input_data){

    MATRIZ data;

    char assign = input_data[0];

    int input_row, input_col, input_value;

    if (assign == 'a'){
        input_row   = 3;
        input_col   = 5;
        input_value = 8;
    }

    else if (assign == 'r'){
        input_row   = 3;
        input_col   = 5;
        input_value = 0; // esse aqui pouco importa, pois não será utilizado; não há informação passada para 'value'
    }

    else if (assign == '['){
        input_row   = 1;
        input_col   = 3;
        input_value = 6;
    }

    else{
        printf("\n   Error on \'unzip_input_data\'.\nAssign must be \'a\', \'r\' or \'[\', but was found \'%c\'.\n", assign);
        exit(-1);
    }

    data.i_row = convert_digit_to_int( input_data[input_row] );
    data.j_col = convert_digit_to_int( input_data[input_col] );
    data.value = convert_digit_to_int( input_data[input_value] );

    return data;
}



//##################################################
MATRIZ insert_new_element(MATRIZ *matrix, int max_elements, int index, char *input_data){

    MATRIZ data = unzip_input_data(input_data);

    matrix[index].i_row = data.i_row;
    matrix[index].j_col = data.j_col;
    matrix[index].value = data.value;

    return matrix[max_elements];
}



//##################################################
MATRIZ delete_null_element(MATRIZ *matrix, int max_elements, int last_element, char *input_data){

    MATRIZ data = unzip_input_data(input_data); 
    MATRIZ elemento_nulo = {-1, -1, 0};

    int value, i;

    // encontrar elemento para deletar; encontrar pelo indíce i
    for (i = 0; i < last_element; i++){
        value = matrix[i].value;
        if (value == 0){
            // elemento = matrix[i];
            break;
        }
    }

    // substitua o elemento pelo último e delete o último
    matrix[i] = matrix[last_element-1];
    matrix[last_element-1] = elemento_nulo;
    
    return matrix[max_elements];
}



//##################################################
MATRIZ replace_element(MATRIZ *matrix, int max_elements, int index, char *input_data){

    MATRIZ data = unzip_input_data(input_data);

    int row   = data.i_row;
    int col   = data.j_col;
    int value = data.value;

    for (int i = 0; i < index; i++){ // encontre o elemento para substituir

        if (matrix[i].i_row == row && matrix[i].j_col == col){
            matrix[i].value = value;
            break;
        }
    }

    return matrix[max_elements];
}



//##################################################
int retrieve_matrix_value_given_coordinates(MATRIZ *matrix, int number_elements, char *input_data){

    MATRIZ data   = unzip_input_data(input_data);

    int row = data.i_row;
    int col = data.j_col;

    int value = 0; //ou existe diferente, ou é zero

    for (int i = 0; i < number_elements; i++){

        if (matrix[i].i_row == row && matrix[i].j_col == col){
            value = matrix[i].value;
            break;
        }
    }

    return value;
}



//##################################################
void print_matrix(MATRIZ *matrix, int max_elements){

    MATRIZ new_matrix[max_elements];

    for (int i = 0; i < max_elements; i++){
        new_matrix[i] = matrix[i];
    }

    sort_matrix(new_matrix, max_elements);

    printf("VC: ");

    for (int i = 0; i < max_elements; i++){
        printf("(%d,%d,%d) ",  new_matrix[i].i_row, new_matrix[i].j_col, new_matrix[i].value);
    }

    printf("\n");
}



//##################################################
void print_full_matrix(){
    printf("%s\n", "O vetor de coordenadas esta' cheio.");
}



//##################################################
void sort_matrix(MATRIZ *matrix, int number_elements){

    MATRIZ elemento;

    int i, j;

    // ordenar linhas
    for (i = 1; i < number_elements; i++){

        elemento = matrix[i];

        j = i - 1;

        while(j >= 0 && matrix[j].i_row > elemento.i_row){
            matrix[j+1] = matrix[j];
            j -= 1;
        }

        matrix[j+1] = elemento;
    }

    // ordenar colunas
    for (i = 1; i < number_elements; i++){

        elemento = matrix[i];

        j = i - 1;

        while(j >= 0 && matrix[j].j_col > elemento.j_col && matrix[j].i_row == elemento.i_row){
            matrix[j+1] = matrix[j];
            j -= 1;
        }
         matrix[j+1] = elemento;
    }
}









//##################################################
int main(){

    int number_rows, number_columns, non_null_elements, max_lenght = 10;

    int value, new_value, row, col;

    int total_elements = 0;

    MATRIZ data;


    scanf("%d %d \n%d\n", &number_rows, &number_columns, &non_null_elements);

    // criar matriz vazia
    int max_elements = number_rows + number_columns; // k >= m + n para ser esparsa

    MATRIZ matriz_esparsa[max_elements];
    matriz_esparsa[max_elements] = null_matrix(matriz_esparsa, max_elements);

    // print_matrix(matriz_esparsa, max_elements);


    int running_state = 1;
    
    while(running_state == 1){

        char input_data[max_lenght];
        fgets(input_data, max_lenght, stdin);

        // print_matrix(matriz_esparsa, total_elements);

        //p
        if (input_data[0] == 'p'){
            print_matrix(matriz_esparsa, max_elements);
        }

        //t
        else if (input_data[0] == 't'){
            // printf("\n   end\n");
            running_state = 0;
        }

        //r [i,j]
        else if (input_data[0] == 'r'){
            
            data = unzip_input_data(input_data);
            row  = data.i_row;
            col  = data.j_col; 

            value = retrieve_matrix_value_given_coordinates(
                matriz_esparsa,
                max_elements,
                input_data
                );

            printf("M[%d][%d] == %d\n", row, col, value);
        }

        //a [i, j]
        else if (input_data[0] == 'a'){

            value = retrieve_matrix_value_given_coordinates(
                matriz_esparsa, 
                max_elements,
                input_data
                ); // se não achar, o valor já é zero
            
            data      = unzip_input_data(input_data);
            new_value = data.value;

            // se não está preenchido (nulo) E ainda tem espaço E o valor a inserir não é zero... adicionar
            if (value == 0 && total_elements < max_elements && new_value !=0){ 
                matriz_esparsa[max_elements] = insert_new_element(matriz_esparsa, max_elements, total_elements, input_data);
                total_elements += 1;
            }
            
            // se já está preenchido E o valor a inserir não é zero... substituir
            else if (value != 0 && new_value != 0){ 
                matriz_esparsa[max_elements] = replace_element(matriz_esparsa, max_elements, total_elements, input_data);
            } 
            
            // se já está preenchido (não-nulo) E vai ser substituído por um zero... deletar
            else if (value != 0 && new_value == 0){
                matriz_esparsa[max_elements] = replace_element(matriz_esparsa, max_elements, total_elements, input_data);
                matriz_esparsa[max_elements] = delete_null_element(matriz_esparsa, max_elements, total_elements, input_data);
                total_elements -= 1;
            }
            
            // se não tem espaço...
            else{ 
                print_full_matrix();
            }
        }

        //[i,j] x
        else if (input_data[0] == '['){
            
            data      = unzip_input_data(input_data);
            int value = data.value;

            if (value != 0){ //o valor deve ser não nulo, para não ocupar espaço desnecessariamente
                matriz_esparsa[max_elements] = insert_new_element(matriz_esparsa, max_elements, total_elements, input_data);
                total_elements += 1;
            }
        }
    }

    return 0;
}

/*

7 7
9
[0,4] 3
[0,5] 7
[1,0] 1
[2,2] 2
[2,3] 6
[2,4] 5
[4,1] 4
[4,4] 6
[4,5] 8
p
a [4,6] 9
a [0,2] 9
a [2,5] 9
a [4,4] 9
a [4,4] 0
a [0,0] 9
a [1,1] 9
a [6,6] 9
p
a [5,5] 9
p
r [2,2]
r [5,5]
t

*/
