#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>

typedef struct transition {
    char read;
    int target;
} transition;

typedef struct state {
    int id;
    int is_final = 0;
    std::vector<transition> trans;
} state;

typedef std::vector<state> automata;

int return_target_id(state s, char read_curr);
void print_step(state state_curr, std::string s, int i);
void step(automata a, std::string s);

#endif

