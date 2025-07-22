#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <regex>
#include <map>
#include <set>
#include <string>

using namespace std;

// struct da transição que lê um caractere e mostra qual id do target state// (o estado que está)
struct Transition { 
    char read;
    int target_id;
};

// state 
struct State {
    bool is_final = false;
    vector<Transition> transition;
};

typedef vector<State> Automata;

/** 
 * @brief retorna o ID do estado de destino de uma transição
 * @pre o estado deve conter transições válidas
 * @post retorna o ID do estado de destino se a transição existir, ou -1 se não existir
 * @param state estado do automato onde a transição será verificada
 * @param symbol símbolo lido pela transição
 * @authors @henrydnz @mattheusMSL
 */

int get_target_id(State state, char symbol);

 /** 
 * @brief lê um arquivo de automato e preenche o vetor de estados 
 * @pre o arquivo deve estar no formato correto e acessível
 * @post o vetor de estados 'automata' é preenchido com os estados e transições do automato
 * @param file caminho do arquivo a ser lido
 * @authors  @mattheusMSL
 */

void read_file(const string &file);

 /** 
 * @brief cria e adiciona manualmente dois estados com transições para testes
 * @pre o vetor 'automata' deve estar disponivel e ser passado por referência
 * @post o automato conterá dois estados com transições deterministicas
 * @param word palavra a ser testada
 * @param step passo atual da leitura da palavra
 * @authors @mattheusMSL
 */

void show_word(const string &word, int step);

 /** 
 * @brief mostra o passo atual da leitura da palavra
 * @pre o 'state_id' deve ser um valor válido dentro do intervalo de estados
 * @post exibe o estado atual e a palavra a partir do passo dado
 * @param state_id ID do estado atual
 * @param word palavra a ser testada
 * @param step passo atual da leitura da palavra
 * @authors @mattheusMSL
 */

void print_step(int state_id, const string &word, int step);

 /** 
 * @brief verifica se uma palavra é válida no automato
 * @pre o automata deve estar inicializado e conter estados válidos
 * @post retorna true se a palavra é aceita pelo automato, false caso contrário
 * @param automata vetor de estados que representa o automato
 * @param word palavra a ser testada
 * @returns retorna verdadeiro se a palavra for aceite ou falso se não for aceita 
 * @authors @henrydnz @mattheusMSL
 */

bool valid(Automata automata, string word);

 /** 
 * @brief pede a palavra e mostra o resultado da validação
 * @pre o 'automata' deve estar inicializado e conter estados válidos
 * @post exibe a palavra lida, e mostra se ela é aceita ou rejeitada pelo automato
 * @param automata vetor de estados que representa o automato
 * @authors @henrydnz @mattheusMSL
 */

void test_word(Automata automata);

#endif