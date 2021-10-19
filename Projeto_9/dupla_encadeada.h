// ==================================================
/**
  dupla_encadeada.h
  Declarations for ...
**/
// ==================================================

#ifndef DUPLA_ENCADEADA_H
#define DUPLA_ENCADEADA_H



struct celula{
    struct celula *anterior;
    struct celula *proximo;
    struct celula *ref;
    float chave;
    int tempo;
};

typedef struct celula Celula;

typedef struct celula* Lista;






// ==================================================
// First order methods
// ==================================================

Lista* create_empty_lista();

void free_lista(Lista* head);

void print_lista(Lista* head);

int insert_cell(Lista* head, int posicao, float valor, float ref, int tempo, int lenght);

int find_and_remove_cell(Lista* head, float ref, int len);



// ==================================================
// Second order (inner) methods
// ==================================================

int lenght_lista(Lista* head);

int lista_existe(Lista* head);

int lista_vazia(Lista* head);

void update_ref_list(Lista* head, Celula* ref_cell);







#endif //DUPLA_ENCADEADA_H
