#define MAX_ACCEPTABLE_DIFFERENCE 0.00001



#ifndef __NUMERO_COMPLEXO__
#define __NUMERO_COMPLEXO__



// ==================================================
// Structs
// --------------------------------------------------
/**
 * @brief 
 * 
 */
typedef struct numero_complexo{

    float real;

    float imaginaria;

} numero_complexo;

// --------------------------------------------------
/**
 * @brief 
 * 
 */
typedef struct array_numeros_complexos{

    int quantidade_de_elementos;

    numero_complexo** array;

} array_complexo;
// ==================================================





// ==================================================
// Alocacao de memoria
// --------------------------------------------------
/**
 * @brief 
 * 
 * @param parte_real 
 * @param parte_imaginaria 
 * @return numero_complexo* 
 */
numero_complexo* criar_numero_complexo(float parte_real, float parte_imaginaria);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param num_complex 
 */
void deletar_numero_complexo(numero_complexo* num_complex);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param quantidade_de_elementos 
 * @return array_complexo* 
 */
array_complexo* criar_array_complexo(int quantidade_de_elementos);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param arr_complex 
 */
void deletar_array_complexo(array_complexo* arr_complex);
// ==================================================





// ==================================================
// Operacoes
// --------------------------------------------------
/**
 * @brief 
 * 
 * @param num_1 
 * @param num_2 
 * @return int 
 */
int comparar_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param num_complex 
 * @return numero_complexo* 
 */
numero_complexo* conjugado_numero_complexo(numero_complexo* num_complex);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param num_1 
 * @param num_2 
 * @return numero_complexo* 
 */
numero_complexo* soma_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param num_1 
 * @param num_2 
 * @return numero_complexo* 
 */
numero_complexo* subtracao_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param num_1 
 * @param num_2 
 * @return numero_complexo* 
 */
numero_complexo* produto_numeros_complexos(numero_complexo* num_1, numero_complexo* num_2);
// ==================================================





// ==================================================
// Prints
// --------------------------------------------------
/**
 * @brief 
 * 
 * @param num_complex 
 */
void print_numero_complexo(numero_complexo* num_complex);

// --------------------------------------------------
/**
 * @brief 
 * 
 * @param arr_complex 
 */
void print_array_numeros_complexos(array_complexo* arr_complex);
// ==================================================



#endif
