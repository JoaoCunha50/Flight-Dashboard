#ifndef QUERY2_H
#define QUERY2_H

#include "main.h"
#include "reservations.h"
#include "statistics.h"
#include "users.h"
#include "passengers.h"
#include "flights.h"
#include "parser.h"
#include "main.h"

typedef struct metricas Metricas;

int inserirID(char **id, int num, char *novo_id);

void query10(Passenger *passengers, User *users, Flight *flights, Reservation *reservations, char *arg, int counter, int mode);

#endif