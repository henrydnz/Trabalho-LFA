#include "utils.h"

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

/** @henrydnz vamos adicionar cometários nesse formato 
 * @brief
 * @pre
 * @post  //post siginica o pós-fixo
 * @authors @henrydnz
 */

void test_automata(){
    // automata a;
    State q0, q1, q2;
    insert_transition(q0, 'a', 2);
}

void menu(){
    cout << "SISTEMA DE AUTOMATOS\n";
    cout << "1 - Fazer Upload de Arquivo\n";
    cout << "2 - Mostrar Gramatica de Automato\n";
    cout << "3 - Testar uma Palavra\n\n";
}