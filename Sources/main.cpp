#include "utils.h"

using namespace std;

static Automata a;

int main(){
    a = test_automata();
    int op;
    while(1){
        menu();
        cin >> op;
        switch (op){
            case 1:
                cout << "nao implementado\n";
                break;
            case 2:
                if(a.size()>0)
                    print_gram(a);
                else
                    cout << "Nenhum automato foi lido ainda";
                break;
            case 3: 
                if(a.size()>0)
                    test_word(a);
                else
                    cout << "Nenhum automato foi lido ainda";
                break;
            default:
                cout << "opção inválida!\n";
                continue;
        }
    }
}