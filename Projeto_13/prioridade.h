//====================================================================================================
/**
 * @brief Conteúdo: chave e custo associado. O heap deve ser mínimo no custo.
 * 
 */
typedef struct elemento{

    int chave;
    int custo;

}elem;



//====================================================================================================
/**
 * @brief Conteúdo: quantidade de elementos, capacidade e dados armazenados.
 * 
 */
typedef struct fila_prioridade{

    int quantidade_de_elementos;
    int capacidade;
    elem* dados;

}fila;



//====================================================================================================
/**
 * @brief 
 * 
 * @param fp 
 * @param chave 
 * @param custo 
 * @return int 
 */
int insere_FilaPrioridade(fila* fp, int chave, int custo);




//====================================================================================================
/**
 * @brief 
 * 
 * @param fp 
 * @return int 
 */
int remove_FilaPrioridade(fila* fp, char* print_min);



//====================================================================================================
/**
 * @brief 
 * 
 * @param fp 
 * @param chave 
 * @return int 
 */
int consulta_FilaPrioridade(fila* fp, int chave);



//====================================================================================================
/**
 * @brief 
 * 
 * @param fp 
 * @param chave 
 * @param custo_novo 
 * @return int 
 */
int diminui_FilaPrioridade(fila* fp, int chave, int custo_novo);



//====================================================================================================
/**
 * @brief 
 * 
 * @param fp 
 * @param chave 
 * @return int 
 */
int procura_FilaPrioridade(fila* fp, int chave);



void promoverElemento(fila* fp, int filho);



void rebaixarElemento(fila* fp, int pai);
