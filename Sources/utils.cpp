#include "../utils/utils.h"
#include <limits>

/** 
 * @brief limpa o buffer de entrada até o próximo '\n'
 * @pre deve ser chamada apos uma leitura com 'cin' que possa deixar lixo no buffer
 * @post  o buffer de entrada é limpo, evitando problemas em leituras futuras
 * @authors @henrydnz
 */

//limpa o buffer até o \n pra evitar problemas
void clear_buffer(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/** 
 * @brief limpa a tela do terminal utilizando códigos ANSI
 * @pre o terminal deve suportar códigos ANSI
 * @post  a tela do terminal é limpa
 * @authors @henrydnz
 */

//limpa a tela do terminal com codigo ansi
void clear_terminal(){
    cout << "\033[H\033[2J" << flush;
}

/** 
 * @brief pausa o programa até que o usuário pressione Enter
 * @pre deve ser chamada quando se deseja pausar a execução para leitura do usuário
 * @post o programa só continua após o usuário pressionar Enter
 * @authors @henrydnz
 */

//nao continua o codigo até pressionar enter
void press_enter() {
    cout << "\nPressione Enter para continuar...\n";
    clear_buffer();
}

/**
 * @brief mostra o menu principal do sistema de automatos
 * @pre nenhuma pré condição específica
 * @post o menu é exibido no terminal, permitindo ao usuário escolher uma opção
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
 * @brief exibe o menu e processa a escolha do usuário
 * @pre o automata deve estar inicializado e passado por referência
 * @post o menu é exibido e a opção escolhida pelo usuário é processada
 *       permitindo a visualização da gramática ou o teste de uma palavra
 * @param automata vetor de estados que representa o automato
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