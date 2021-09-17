#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int convert_digit_to_int(char digit){

    int digit_int = digit - '0';

    return(digit_int);

}



int main(){

    int i;
    scanf("%i", &i);

    // char input_data[10];

    // gets(input_data);

    char input_data[] = "a [1, 2] 7";
    printf("input_data = %s\n", input_data);
    
    // char *data_copy;
    // strcpy(data_copy, input_data);

    // char split[] = "a";
    // strtok(data_copy, split);
    // printf("copy strtok = %s\n", data_copy);

    char delimit[] = ", []a";
    char *token = strtok(input_data, delimit);
    
    // printf("token = %s\n", token);

    while (token != NULL){
        printf("input_data = %s\n", input_data);
        printf("token = %s\n", token);
        token = strtok(NULL, delimit);
    }

    int k;

    sscanf(input_data, "%d", &k);

    printf("k = %d\n", k);

    

	
    return 0;

}