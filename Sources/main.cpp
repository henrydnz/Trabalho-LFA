#include "utils.h"

using namespace std;
static Automata a;

int main(){
    a = test_automata();
    int option;  
    while(1){ 
        menu();
        cin >> option;
        switch (option){
            case 1:
                cout << "nao implementado\n";
                break;
            case 2:
                if(automata.size() > 0)
                    print_gram(automata);
                else
                    cout << "Nenhum automato foi lido ainda";
                break;
            case 3: 
                if(automata.size()>0)
                    test_word(automata);
                else
                    cout << "Nenhum automato foi lido ainda";
                break;
            default:
                cout << "opção inválida!\n";
                continue;
        }
    }
}