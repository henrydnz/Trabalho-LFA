#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

// struct da transição que lê um caractere e mostra qual id do target state// (o estado que está)
struct Transition { 
    char read;
    int target_id;
};

// state 
struct State {
    bool is_final = false;
    vector<Transition> transition;
};

typedef vector<State> Automata;

int get_target_id(State state, char symbol);
void show_word(const string &word, int step);
void print_step(int state_id, const string &word, int step);
bool valid(Automata automata, string word);
void test_word(Automata automata);

#endif

