#include "../Headers/gramatica.h"

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

char get_non_terminal(int id) {
    return (id == 0) ? 'S' : 'A' + id - 1;
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

void print_gram(Automata automata){
    cout << "GRAMATICA\n";
    for(int i = 0; i < automata.size(); i++){
        cout << get_non_terminal(i) << " -> ";
        for(int j = 0; j < automata[i].transition.size(); ++j){
            cout << automata[i].transition[j].read << get_non_terminal(automata[i].transition[j].target_id);
            if(j < automata[i].transition.size() - 1){
                cout << " | ";
            }             
        }
        if(automata[i].is_final){
            cout << " | @";
        }
       cout << endl;
    }
}