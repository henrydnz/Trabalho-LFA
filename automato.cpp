#include "automato.h"

int return_target_id(state s, char read_curr){
    for(transition t : s.trans)
        if(t.read == read_curr)
            return t.target;
    return s.id;
}

void print_step(state state_curr, std::string s, int i){
    //implementar
}


void step(automata a, std::string s){
    state state_curr;
    int step = 0, target_id;
    char read_curr;
    for(int i = 0; i < s.size(); i++){
        read_curr = s[i];
        target_id = return_target_id(state_curr, read_curr);
        state_curr = a[target_id];
        print_step(state_curr, s, i); //implementar
    }
}