#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "automato.h"

typedef struct production {
    char terminal;
    char target;
} production;

typedef struct non_terminal {
    char name;
    std::vector<production> productions;
} non_terminal;

typedef std::vector<non_terminal> gram;

char get_non_terminal(int id);
gram get_gram(automata a);
void print_gram(gram g);

#endif