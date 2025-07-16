#include "../Headers/gramatica.h"

/** 
 * @brief
 * @pre
 * @post  
 * @param state_id
 * @authors @henrydnz
 */

//retorna a letra do não terminal correspondente ao estado
char get_non_terminal(int state_id) {
    string non_terminals = "SABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return non_terminals[state_id%27];
}

/** 
 * @brief
 * @pre
 * @post  
 * @param automata
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