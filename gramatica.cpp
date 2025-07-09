#include "gramatica.h"

//maps non terminal by state id
char get_non_terminal(int id) {
    return (id == 0) ? 'S' : 'A' + id - 1;
}

//prints automata gram 
void print_gram(automata a){
    std::cout << "GRAMATICA\n\n";
    for(state state_curr : a){
        std::cout << get_non_terminal(state_curr.id) << " -> ";
        for(int i = 0; i < state_curr.trans.size(); ++i){
            std::cout << state_curr.trans[i].read << get_non_terminal(state_curr.trans[i].target);
            if(i < state_curr.trans.size() - 1) 
                std::cout << " | ";
        }
        if(state_curr.is_final)
            std::cout << " | @";
        std::cout << "\n\n";
    }
}