#include "../Headers/automato.h"

// primeira versão de print_step (nao recursiva)
// void print_step(State &current_state, string word, int step){
//     cout << "[q" << current_state.id << "]";
//     for(int i = step; i < word.size(); i++)
//         cout << word[i];
//      cout << endl;
// }

/** 
 * @brief
 * @pre
 * @post  
 * @authors @mattheusMSL
 */

void show_word(const string &word, int step){
    if(step < word.size()){
        cout << word[step];
        show_word(word, step + 1);
    }
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @mattheusMSL
 */

void print_step(int state_id, const string &word, int step){
    cout << "[q" << state_id << "] ";
    show_word(word, step);
    cout << endl;
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz @mattheusMSL
 */

//analisa todas as transicoes de um estado, compara com caractere pra leitura. 
//retorna o id do estado destino de acordo com o caractere lido.
//se nao encontra uma transicao correspondente retorna -1;
int get_target_id(State state, char current_symbol){
    for(Transition transition : state.transition)
        if(transition.read == current_symbol)
            return transition.target_id;
    return -1;
}

/** 
 * @brief 
 * @pre 
 * @post  
 * @authors @henrydnz @mattheusMSL
 */

//valida uma palavra dado um automato e a string da palavra, passa por todos os caracteres da string e navega pelo automato, 
//se o ultimo estado é final, a palavra é válida, caso contrário não.
bool valid(Automata automata, string word){
    if(word[0] == '@') {
        return automata[0].is_final;
    }

    State current_state = automata[0];
    int i, target_id = 0;

    for(i = 0; i < word.size(); i++) {
        print_step(target_id, word, i);
        target_id = get_target_id(current_state, word[i]);
        if(target_id == -1) { 
            return false;
        }
        current_state = automata[target_id];    
    }

    cout << "[q" << target_id << "] @\n";
    return current_state.is_final;

}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz @mattheusMSL
 */

void test_word(Automata automata){
    string word;
    cout << "Escreva a palavra a ser testada:\n";
    cin >> word;
    cout << "\nLendo \'" << word << "\'\n\n";
    cout << (valid(automata, word) ? "ACEITO\n" : "REJEITADO\n");
}