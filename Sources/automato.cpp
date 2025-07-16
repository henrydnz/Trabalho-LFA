#include "../Headers/automato.h"
#include "../utils/utils.h"

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
 * @param word
 * @param step
 * @authors @mattheusMSL
 */

//função helper recursiva pra mostrar cada letra da palavra individualmente de acordo com o passo
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
 * @param state_id
 * @param word
 * @param step
 * @authors @mattheusMSL
 */

//mostra o passo atual da leitura da palavra
void print_step(int state_id, const string &word, int step){
    //mostra estado atual
    cout << "[q" << state_id << "] ";
    //chama recursiva pra mostrar palavra a partir do passo dado
    show_word(word, step);
    cout << endl;
}

/** 
 * @brief
 * @pre
 * @post  
 * @param state
 * @param symbol
 * @returns
 * @authors @henrydnz @mattheusMSL
 */

int get_target_id(State state, char symbol){
    //analisa todas as transicoes do estado
    for(Transition transition : state.transition)
        //se o simbolo esta numa transicao, retorna o destino. valor 0 ou mais
        if(transition.read == symbol)
            return transition.target_id;
    //passou por tudo e não encontrou uma transição correspondente, retorna -1
    return -1;
}

/** 
 * @brief 
 * @pre 
 * @post  
 * @param automata
 * @param word
 * @returns
 * @authors @henrydnz @mattheusMSL
 */


//ve se uma palavra é valida no automato
bool valid(Automata automata, string word){
    //quando a palavra é vazia, se o estado inicial é final retorna true, senão false
    if(word[0] == '@') {
        return automata[0].is_final;
    }

    State current_state = automata[0];
    int i, target_id = 0;

    //vê simbolo por simbolo da palavra, anda pelo automato
    for(i = 0; i < word.size(); i++) {
        print_step(target_id, word, i); //mostra passo
        target_id = get_target_id(current_state, word[i]);  //pega estado da transicao
        //nao tem transicao pro simbolo, é invalida
        if(target_id == -1) {   
            return false;
        }
        current_state = automata[target_id];    
    }

    cout << "[q" << target_id << "]\n";

    //se quando a palavra acaba, o estado é final, retorna true, senão false
    return current_state.is_final;

}

/** 
 * @brief
 * @pre
 * @post  
 * @param automata
 * @authors @henrydnz @mattheusMSL
 */

//pede a palavra, mostra result
void test_word(Automata automata){
    string word;
    cout << "Escreva a palavra a ser testada:\n";
    cin >> word;
    clear_buffer();
    cout << "\nLendo \'" << word << "\'\n\n";
    cout << (valid(automata, word) ? "ACEITO\n" : "REJEITADO\n");
}