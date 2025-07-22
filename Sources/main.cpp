#include "../utils/utils.h"

using namespace std;

static Automata automata;

int main(){
    read_automata(automata);
    //test_automata(automata);   //debugging
    menu(automata);
}