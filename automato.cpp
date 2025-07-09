#include "automato.h"

void print_step(state state_curr, std::string s, int step){
    std::cout << "[q" << state_curr.id << "]";
    for(int i = step; i < s.size(); i++)
        std::cout << s[i];
    std::cout << std::endl;
}

//analisa todas as transicoes de um estado, compara com caractere pra leitura. 
//retorna o id do estado destino de acordo com o caractere lido.
//se nao encontra uma transicao correspondente retorna -1;
int return_target_id(state s, char read_curr){
    for(transition t : s.trans)
        if(t.read == read_curr)
            return t.target;
    return -1;
}

//valida uma palavra dado um automato e a string da palavra.
//passa por todos os caracteres da string e navega pelo automato.
//se o ultimo estado é final, a palavra é válida, caso contrário não.
bool valid(automata a, std::string str){
    //str vazia, estado inicial deve ser final
    if(str[0] == '@') return a[0].is_final;

    state state_curr = a[0];
    int i, target_id;

    for(i = 0; i < str.size(); i++){
        //procura transicao pro caractere
        target_id = return_target_id(state_curr, str[i]);
        //sem transicao correspondente, inválida
        if(target_id == -1) return false;
        //vai pro prox estado da transicao
        state_curr = a[target_id];
        //mostra o passo atual
        print_step(state_curr, str, i);
    }
    return state_curr.is_final;
}

void test_word(automata a){
    std::string word;
    std::cin >> word;
    std::cout << valid(a, word)? "ACEITO" : "REJEITADO";
}