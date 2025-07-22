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
 * @brief insere uma nova transição de um estado do automato
 * @pre o estado fornecido deve ser valido e passado por referência
 * @post a nova transição é adicionada ao vetor de transições do estado
 * @param state estado do automato onde a transição será inserida
 * @param read simbolo lido pela transição
 * @param target_id ID do estado de destino da transição
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

/**
 * @brief cria e adiciona manualmente dois estados com transições para testes
 * @pre o vetor 'automata' deve estar disponivel e ser passado por referência
 * @post o automato conterá dois estados com transições deterministicas
 * @param automata vetor de estados que representa o automato
 */

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