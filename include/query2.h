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

typedef struct info Info;

void copyinfo(Info *user, Flight *flight, int i, int s);

void copyinfo1(Info *user, Reservation *reservation, int i, int s);

int comparar_infos(const void *a, const void *b);

void query2(Passenger *passenger, User *users, Flight *flights, Reservation *reservations, char *arg, int counter, int mode);

#endif
