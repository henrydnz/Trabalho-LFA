#include "../utils/utils.h"
#include <limits>


/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

void clear_buffer(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

void clear_terminal(){
    cout << "\033[H\033[2J" << flush;
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

void press_enter() {
    cout << "\nPressione Enter para continuar...\n";
    clear_buffer();
}

/** 
 * @brief
 * @pre
 * @post  
 * @authors @henrydnz
 */

void insert_transition(State &state, char read, int target_id){
   Transition transition;
   transition.read = read;
   transition.target_id = target_id;
   state.transition.push_back(transition);
}

/**
 * @brief
 * @pre
 * @post
 * @authors @henrydnz
 */

void test_automata(Automata &a){
    State q0, q1;

    //(q0, 'a') = q0  /  (q0, 'b') = q1
    insert_transition(q0, 'a', 0);
    insert_transition(q0, 'b', 1);

    //(q1, 'a') = q0  /  (q1, 'b') = q1
    insert_transition(q1, 'a', 0);
    insert_transition(q1, 'b', 1);

    q0.is_final = true;
    q1.is_final = true;

    a.push_back(q0);
    a.push_back(q1);
}

/**
 * @brief
 * @pre
 * @post
 * @authors @henrydnz
 */

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
 * @authors @henrydnz
 */

void menu(Automata &a){
    int option;
    while(1){
        print_menu();
        cin >> option;
        clear_buffer();
        clear_terminal();
        switch (option){
            case 1:
                print_gram(a);
                break;
            case 2: 
                test_word(a);
                break;
            default:
                cout << "opção inválida!\n";
                continue;
        }
        press_enter();
    }
}

