#include "utils.h"

automata test_automata(){
    automata a;
    state q0, q1, q2;
    transition q00, q01, q02, q10, q11, q20, q21;

    q0.id = 0;
    q1.id = 1;
    q2.id = 2;
    q2.is_final = true;

    //definir transicoes e inserir em estados
    //q0 = {(a, q2), (b,q0), (c,q1)}
    q00.read = 'a'; q00.target = 2; q0.trans.push_back(q00);
    q01.read = 'b'; q01.target = 0; q0.trans.push_back(q01);
    q02.read = 'c'; q02.target = 1; q0.trans.push_back(q02);
    //q1 = {(a, q1), (c,q2)}
    q10.read = 'a'; q10.target = 1; q1.trans.push_back(q10);
    q11.read = 'c'; q11.target = 2; q1.trans.push_back(q11);
    //q2 = {(a, q1), (b,q0)}
    q20.read = 'a'; q20.target = 1; q2.trans.push_back(q20);
    q21.read = 'b'; q21.target = 0; q2.trans.push_back(q21);
    
    //inserir estados em automato
    a.push_back(q0);
    a.push_back(q1);
    a.push_back(q2);

    return a;
}

void menu(){
    std::cout << "SISTEMA DE AUTOMATOS\n";
    std::cout << "1 - Fazer Upload de Arquivo\n";
    std::cout << "2 - Mostrar Gramatica de Automato\n";
    std::cout << "3 - Testar uma Palavra\n\n";
}