#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;
// struct da transição que lê um, caractere e mostra qual id do target state// (o estado que está)
typedef struct Transition { 
    char read;
    int target_id;
} Transition;
// state 
typedef struct State {
    bool is_final = false;
    vector<Transition> transition;
} State;

typedef vector<State> Automata;

int return_target_id(State s, char read_curr);
void show_word(const string &word, int step);
void print_step(const State &current_state, const string &word, int step);
// void print_step(State state_curr, string s, int i);
bool valid(Automata a, string str);
void test_word(Automata a);

#endif

