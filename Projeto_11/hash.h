#define STRING_MAX_SIZE 250





//==================================================
// STRUCTURES
//==================================================

/**
 * @brief Estrutura que armazena a mensagem, como uma string (char*) 
 */
typedef struct message{

    char string[STRING_MAX_SIZE];

    int timestamp;

}Message;



/**
 * @brief Estrutura da tabela hash.
 * Armazena a quantidade total de elementos, o tamanho total (espaço total) e
 * os endereços das mensagens gravadas na tabela hash. 
 * 
 * Conforme os elementos são requisitados a entrar na tabela, a alocação da memória é feita
 * para esse único elemento.
 */
typedef struct hash{

    int quantidade_total;

    int tamanho_total;

    Message* *strings;
}Hash;





//==================================================
// HASH HANDLING
//==================================================

/**
 * @brief Aloca espaço para o array de ponteiros e os inicializa com NULL.
 * O ideal é escolher um tamanho que seja um número primo e evitar números que
 * seja potências de 2, tendo em vista que estes têm alta chance de colisão
 * enquanto que aqueles possuem baixa.
 * 
 * @param size 
 * @return Hash* 
 */
Hash* criarHash(int size);



/**
 * @brief 
 * 
 * @param ha 
 */
void freeHash(Hash* ha);



/**
 * @brief Calcula a posição da chave a ser inserida no array.
 * Recalcula, em caso de colisão, a posição (limitar número de tentativas).
 * Aloca espaço para os dados e os armazena na posiçao calculada. 
 * 
 * @param ha 
 * @param string 
 * @return int 
 */
int insertHash_EnderAberto(Hash* ha, Message string);



/**
 * @brief Calcula a posição da chave no array. Verifica se há
 * dados na posição calculada e se esses dados combinam com a chave.
 * Recalcula a posição enquanto os dados forem diferentes da chave.
 * Retorna os dados.
 * 
 * @param ha 
 * @param substring 
 * @param string 
 * @return int 
 */
int buscaHash_EnderAberto(Hash* ha, char* substring, Message msg);



/**
 * @brief 
 * 
 * @param ha 
 * @param substring 
 * @param msg 
 * @return int 
 */
int removeHash(Hash* ha, char* substring, Message msg);



/**
 * @brief 
 * 
 * @param ha 
 * @param pos 
 * @return int 
 */
int printHash(Hash* ha, int pos);



/**
 * @brief 
 * 
 * @param num 
 * @return int 
 */
int tamanhoTabela(int num);





//==================================================
// HASHING FUNCTIONS
//==================================================

/**
 * @brief 
 * 
 * @param str 
 * @return unsigned long 
 */
unsigned long djb2(char *str);



/**
 * @brief 
 * 
 */
int duploHash(int pos_inicial, Message msg, int i, int table_size);
