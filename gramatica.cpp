#include "gramatica.h"

//maps state id 
char get_non_terminal(int id) {
    return (id == 0) ? 'S' : 'A' + id - 1;
}

gram get_gram(automata a){
    gram g;
    g.resize(a.size());
    
    for(int i = 0; i < a.size(); i++){
        g[i].name = get_non_terminal(a[i].id);
        
        for(int j = 0; j < a[i].trans.size(); j++){
            production p;
            p.terminal = a[i].trans[j].read;
            p.target = get_non_terminal(a[i].trans[j].target);
            g[i].productions.push_back(p);
        }
        
        //producoes vazias p estados finais
        if(a[i].is_final){
            production p;
            p.terminal = '@';
            p.target = '\0';
            g[i].productions.push_back(p);
        }
    }
    return g;
}


void print_gram(gram g){
    for(non_terminal nt : g){
        std::cout << nt.name <<" -> ";
        if(nt.productions.size() == 1)
            std::cout << nt.productions[0].terminal << nt.productions[0].target;
        else
            for(int i = 0; i < nt.productions.size(); i++){
                std::cout << nt.productions[i].terminal << nt.productions[i].target;
                if(i!=nt.productions.size()-1)
                    std::cout << " | ";
            }
        std::cout << std::endl;
    }
}
