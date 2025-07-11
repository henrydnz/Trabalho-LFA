#ifndef UTILS_H
#define UTILS_H

using namespace std;

#include <iostream>
#include "automato.h"
#include "gramatica.h"

void insert_transition(State &state, char read, int target_id);
void test_automata();
void menu();

#endif
