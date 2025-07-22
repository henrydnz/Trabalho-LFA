#ifndef UTILS_H
#define UTILS_H

using namespace std;

#include <iostream>
#include "../Headers/automato.h"
#include "../Headers/gramatica.h"

/** 
 * @brief insere uma nova transição de um estado do automato
 * @pre o estado fornecido deve ser valido e passado por referência
 * @post a nova transição é adicionada ao vetor de transições do estado
 * @param state estado do automato onde a transição será inserida
 * @param read simbolo lido pela transição
 * @param target_id ID do estado de destino da transição
 * @authors @henrydnz
 */

void insert_transition(State &state, char read, int target_id);

/**
 * @brief cria e adiciona manualmente dois estados com transições para testes
 * @pre o vetor 'automata' deve estar disponivel e ser passado por referência
 * @post o automato conterá dois estados com transições deterministicas
 * @param automata vetor de estados que representa o automato
 */

void test_automata(Automata &automata);

/**
 * @brief exibe o menu e processa a escolha do usuário
 * @pre o automata deve estar inicializado e passado por referência
 * @post o menu é exibido e a opção escolhida pelo usuário é processada
 *       permitindo a visualização da gramática ou o teste de uma palavra
 * @param automata vetor de estados que representa o automato
 * @authors @henrydnz
 */

void menu(Automata &automata);

/**
 * @brief mostra o menu principal do sistema de automatos
 * @pre nenhuma pré condição específica
 * @post o menu é exibido no terminal, permitindo ao usuário escolher uma opção
 * @authors @henrydnz
 */

void print_menu();

/** 
 * @brief pausa o programa até que o usuário pressione Enter
 * @pre deve ser chamada quando se deseja pausar a execução para leitura do usuário
 * @post o programa só continua após o usuário pressionar Enter
 * @authors @henrydnz
 */

void press_enter();

/** 
 * @brief limpa a tela do terminal utilizando códigos ANSI
 * @pre o terminal deve suportar códigos ANSI
 * @post  a tela do terminal é limpa
 * @authors @henrydnz
 */

void clear_terminal();

/** 
 * @brief limpa o buffer de entrada até o próximo '\n'
 * @pre deve ser chamada apos uma leitura com 'cin' que possa deixar lixo no buffer
 * @post  o buffer de entrada é limpo, evitando problemas em leituras futuras
 * @authors @henrydnz
 */

void clear_buffer();

#endif
