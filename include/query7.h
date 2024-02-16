#ifndef QUERY7_H
#define QUERY7_H

#include "main.h"
#include "flights.h"
#include "interpreter.h"
#include "statistics.h"

typedef struct Aeroporto Airport;
int comparaMediana(const void *a, const void *b);
int inserirAeroporto(Airport *aeroportos, int num, char *aeroporto);

void query7(Flight *flight, int n_voos, char *numero, int counter, int mode);

#endif