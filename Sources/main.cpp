#include "../utils/utils.h"

using namespace std;

static Automata automata;

int main(){
    string file;

    clear_terminal();
    cout << "Para comecar o sistema, digite o nome completo do arquivo para leitura do automato:\n";
    cin >> file;
    clear_buffer();

    read_afd_file(file, automata);

    cout << "Arquivo lido com sucesso!\n";

    press_enter();

    menu(automata);
}

