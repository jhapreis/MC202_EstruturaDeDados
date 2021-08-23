#include <stdio.h>
#include <stdlib.h>

/*
Entradas esperadas:

    hp_start_ryu
    hp_start_ken
    golpes:
        if golpe > 0:
            ryu
        elif golpe < 0:
            ken

Saídas:

    {personagem} aplicou um golpe: {valor_do_golpe}
    hp_ryu = {}
    hp_ken = {}

    ...

    if (hp_ryu) or (hp_ken) < 0:
        encerrar_luta:
            print(f"lutador vencedor: {personagem}")
            print("golper ryu = ", golpes_ryu)
            print("golper ken = ", golpes_ken)
*/



int get_initial_hp(){

    int initial_hp_fighter;

    scanf("%d", &initial_hp_fighter);

    return initial_hp_fighter;
}



int max(int number_1, int number_2){

    int maximum;

    if (number_1 >= number_2){
        maximum = number_1;
    }

    else{
        maximum = number_2;
    }

    return maximum;
}



typedef struct hit_fight{
    int hp_ryu;
    int hp_ken;
    int number_hits_ryu;
    int number_hits_ken;
} HIT_FIGHT;



HIT_FIGHT hit_fighter( HIT_FIGHT fight ){

    int hit_value;
    char *fighter_name = "{name}";

    scanf("%d", &hit_value);

    if (hit_value > 0){ 
        fighter_name = "RYU";
        fight.number_hits_ryu += 1;
        fight.hp_ken -= hit_value;
    }

    else if (hit_value < 0){
        fighter_name = "KEN";
        fight.number_hits_ken += 1;
        fight.hp_ryu += hit_value;
    }

    printf("%s APLICOU UM GOLPE: %d\n", fighter_name, abs(hit_value));
    printf("HP RYU = %d\n", max(fight.hp_ryu, 0));
    printf("HP KEN = %d\n", max(fight.hp_ken, 0));
    return fight;

}



/*
    The first rule about fight club is you don’t talk about fight club.

    The second rule about fight club is you DO NOT talk about fight club.
*/
int fight_club(int hp_ryu, int hp_ken){

    char *winner = "{winner}";
    int number_hits_ryu = 0; 
    int number_hits_ken = 0;

    HIT_FIGHT fight_data = {hp_ryu, hp_ken, number_hits_ryu, number_hits_ken};


    while (     fight_data.hp_ryu>0 && fight_data.hp_ken>0    ){
        
        fight_data = hit_fighter(fight_data);
        
    }

    if (fight_data.hp_ryu > fight_data.hp_ken){
        winner = "RYU";
    }

    else if (fight_data.hp_ryu < fight_data.hp_ken){
        winner = "KEN";
    }

    printf("LUTADOR VENCEDOR: %s\n", winner);
    printf("GOLPES RYU = %d\n", fight_data.number_hits_ryu);
    printf("GOLPES KEN = %d\n", fight_data.number_hits_ken);

    return 0;
}





int main(){

    int initial_hp_ryu, initial_hp_ken;

    initial_hp_ryu = get_initial_hp();

    initial_hp_ken = get_initial_hp();

    fight_club(initial_hp_ryu, initial_hp_ken);

    return 0;
}


