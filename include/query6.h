#ifndef QUERY6_H
#define QUERY6_H

#include "flights.h"
#include "statistics.h"
#include "main.h"
#include "interpreter.h"


typedef struct Aeroporto Airport;

void query6(Flight *flight, Passenger *passengers, char *year, char *num_outputs, int counter, int mode);

#endif