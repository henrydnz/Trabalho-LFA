#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "automato.h"

using namespace std;

/** 
 * @brief retorna a letra do não terminal correspondente ao estado
 * @pre o state_id deve ser um valor válido dentro do intervalo de estados
 * @post retorna o simbolo correspondente ao estado
 * @param state_id ID do estado para o qual se deseja obter o não terminal
 * @authors @henrydnz
 */

char get_non_terminal(int state_id);

 /** 
 * @brief imprime a gramática do automato no formato especificado
 * @pre o 'automata' deve estar inicializado e conter estados válidos
 * @post a gramática é impressa no terminal, mostrando as produções de cada não terminal
 * @param automata vetor de estados que representa o automato
 * @authors @henrydnz
 */

void print_gram(Automata automata);

#endif