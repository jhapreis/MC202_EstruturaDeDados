#include <stdio.h>
#include <stdlib.h>


// int function(int x){
//     int *ptr = &x;
//     // int *ptr;

//     printf("%p\n", &x);
//     printf("%p\n", ptr);
//     printf("%d\n", *ptr);

//     int y = 20;
//     *ptr = y;
//     printf("%p\n", &x);
//     printf("%p\n", ptr);
//     printf("%d\n", *ptr);
//     printf("%d\n", x);


//     return 0;

// }

// int main(){
//     int x = 2;
//     function(x);
//     return 0;
// }



// int *array_return(){

//     int vector[3] = {1, 2, 3};
//     printf("\n %d\n %p\n %p", vector[0], vector, &vector[0]);
//     return vector;

// }

// int main(){

//     // int vector[3] = array_return();
//     // printf("%d\n", vector[0]);
//     int *address_first = array_return();
//     printf("\n %p\n %d\n", address_first, 0);
//     return 0;

// }


// typedef struct pessoa{
    
//     char  Nome[100];
//     int   Idade;
//     float Salario;

// } PESSOA;

// void Mostrar(struct  pessoa pessoa){

//     printf("Nome: %s\n", pessoa.Nome);
//     printf("Idade: %d\n", pessoa.Idade);
//     printf("Salario: %f\n", pessoa.Salario);

// }

// int main(){

//     PESSOA p = {"Rafael do suco de uva", 21, 1E6};
//     Mostrar(p);
//     return 0;

// }

typedef struct numbers{
    int number_x;
    int number_y;
    char *frase;
} NUMBERS;

NUMBERS Double_Value(int x, int y){
    NUMBERS n = {2*x, 2*y, "O baile da penha tá o bichoooooooo"};
    return n;
}

int main(){
    int x = 3;
    int y = 5;
    NUMBERS haxixe = Double_Value(x, y);
    printf("x = %d\n", haxixe.number_x);
    printf("y = %d\n", haxixe.number_y);
    printf("%s", haxixe.frase);
    return 0;
}

