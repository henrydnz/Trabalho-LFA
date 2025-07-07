#include "automato.h"

void print_step(state state_curr, std::string s, int step){
    std::cout << "[q" << state_curr.id << "]";
    
    for(int i = step; i < s.size(); i++)
        std::cout << s[i];

    std::cout << std::endl;
}

int return_target_id(state s, char read_curr){
    //passa pelas transicoes do estado e retorna o id 
    //do estado de destino
    for(transition t : s.trans)
        if(t.read == read_curr)
            return t.target;
    //se nao tem o caractere em nenhuma transicao entao
    //a palavra ja e invalida
    return -1;
}

int valid(automata a, std::string s){
    //se string vazia, q0 deve ser final
    if(s[0] == '@')
        return a[0].is_final;

    state state_curr;
    int i, target_id;

    //roda por cada char da string, avança pra próxima transição
    for(i = 0; i < s.size(); i++){
        target_id = return_target_id(state_curr, s[i]);
        
        //sem transicao, palavra rejeitada
        if(target_id == -1) 
            return false;

        state_curr = a[target_id];
        print_step(state_curr, s, i);
    }

    //se rodou por toda a string entao testa se o ultimo
    //estado é final
    return state_curr.is_final;
}

