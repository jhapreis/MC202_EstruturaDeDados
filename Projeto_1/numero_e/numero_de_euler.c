#include <stdio.h>
#include <stdlib.h>

//e = 2.7182818284590452353602874...
//e = 1 + 1/1! + 1/2! + 1/3! + ...


/*
    Declare the functions 
*/
int* factorial_array_until_number(); //in order to call using Dynamically Allocated Array
double euler_number();



/*
    Calls the main function
*/
int main(){

    int number;
    scanf("%d", &number);
    number -= 1;

    int array_of_factorials[number]; 

    factorial_array_until_number(array_of_factorials, number);

    double euler = euler_number(array_of_factorials, number);
    
    printf("e=%.12f\n", euler);

    return 0;
}



/*
    Factorial function
*/
int* factorial_array_until_number(int *array_factorial, int number){
    
    int factorial;

    factorial = 1;

    for (   int i=0; i<number; i++   ){
        factorial = factorial*(i+1);
        array_factorial[i] = factorial;
    }

   return array_factorial;
}



double euler_number(int *array_factorial, int number){

    double euler_number = 1;

    for (   int i=0; i<number; i++  ){
        euler_number += 1/(double)array_factorial[i];
    }

    return euler_number;

}


