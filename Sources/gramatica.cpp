#include "../Headers/gramatica.h"

/** 
 * @brief retorna a letra do não terminal correspondente ao estado
 * @pre o state_id deve ser um valor válido dentro do intervalo de estados
 * @post retorna o simbolo correspondente ao estado
 * @param state_id ID do estado para o qual se deseja obter o não terminal
 * @authors @henrydnz
 */

//retorna a letra do não terminal correspondente ao estado
char get_non_terminal(int state_id) {
    if(state_id == 0) return 'S';
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[(state_id-1)%26];
}

/** 
 * @brief imprime a gramática do automato no formato especificado
 * @pre o 'automata' deve estar inicializado e conter estados válidos
 * @post a gramática é impressa no terminal, mostrando as produções de cada não terminal
 * @param automata vetor de estados que representa o automato
 * @authors @henrydnz
 */

void print_gram(Automata automata){
    cout << "GRAMATICA\n";
    //loop pra mostrar uma linha de cada vez
    for(int i = 0; i < automata.size(); i++){
        //mostra o não terminal da esquerda
        cout << get_non_terminal(i) << " -> ";
        //loop pra mostrar as produções do não terminal
        for(int j = 0; j < automata[i].transition.size(); ++j){
            //mostra a letra da transição, depois o não terminal correspondente ao estado da transição
            //( 'a' -> q1 = aA )
            cout << automata[i].transition[j].read << get_non_terminal(automata[i].transition[j].target_id);
            //mostra " | " enquanto não chegar no ultimo
            if(j < automata[i].transition.size() - 1){
                cout << " | ";
            }             
        }
        //se é final, aceita vazio
        if(automata[i].is_final){
            cout << " | @";
        }
       cout << endl;
    }
}