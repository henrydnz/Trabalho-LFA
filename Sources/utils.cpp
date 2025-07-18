#include "../utils/utils.h"
#include <limits>

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

//limpa o buffer até o \n pra evitar problemas
void clear_buffer(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

//limpa a tela do terminal com codigo ansi
void clear_terminal(){
    cout << "\033[H\033[2J" << flush;
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

//nao continua o codigo até pressionar enter
void press_enter() {
    cout << "\nPressione Enter para continuar...\n";
    clear_buffer();
}

/** 
 * @brief
 * @pre
 * @post  
 * @param state
 * @param read
 * @param target_id
 * @authors @henrydnz
 */

//ajuda a adicionar transicoes num estado
void insert_transition(State &state, char read, int target_id){
    //cria transicao e atualiza valores
    Transition transition;
    transition.read = read;
    transition.target_id = target_id;
    //insere trasnsicao no estado passado por referencia 
    state.transition.push_back(transition);
}

//funcao que cria um automato pra debugar, provavelmente vai ser excluido dps
void test_automata(Automata &automata){
    State q0, q1;

    //(q0, 'a') = q0  /  (q0, 'b') = q1
    insert_transition(q0, 'a', 0);
    insert_transition(q0, 'b', 1);

    //(q1, 'a') = q0  /  (q1, 'b') = q1
    insert_transition(q1, 'a', 0);
    insert_transition(q1, 'b', 1);

    q0.is_final = true;
    q1.is_final = true;

    automata.push_back(q0);
    automata.push_back(q1);
}

/**
 * @brief
 * @pre
 * @post
 * @authors @henrydnz
 */
//mostra menu
void print_menu(){
    clear_terminal();
    cout << "SISTEMA DE AUTOMATOS\n";
    cout << "1 - Mostrar Gramatica de Automato\n";
    cout << "2 - Testar uma Palavra\n\n";
}

/**
 * @brief
 * @pre
 * @post
 * @param automata
 * @authors @henrydnz
 */

//loop do menu pra escolher opcoes
void menu(Automata &automata){
    int option;
    while(1){
        print_menu();
        cin >> option;
        clear_buffer();
        clear_terminal();
        switch (option){
            case 1:
                print_gram(automata);
                break;
            case 2: 
                test_word(automata);
                break;
            default:
                cout << "opção inválida!\n";
                continue;
        }
        press_enter();
    }
}

