#ifndef UTILS_H
#define UTILS_H

using namespace std;

#include <iostream>
#include "../Headers/automato.h"
#include "../Headers/gramatica.h"

void insert_transition(State &state, char read, int target_id);
void test_automata(Automata &a);
void menu(Automata &a);
void print_menu();
void press_enter();
void clear_terminal();
void clear_buffer();

#endif
