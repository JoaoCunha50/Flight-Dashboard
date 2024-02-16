#ifndef PASSENGERS_H
#define PASSENGERS_H

#include "main.h"

typedef struct passenger Passenger;

extern int n_passageiros;

int SizeofPassengers();

int free_passageiros(Passenger* passageiros);

void set_passenger_flight_id(char *flight_id, Passenger* passageiro, int i);

void set_passenger_user_id(char *user_id, Passenger* passageiro, int i);

int isPvalid(Passenger* passageiro1, int i);

void reset_passenger(Passenger *passageiro1, int i);

int CountPassengers(Passenger *passengers, int flight_id);

char *get_passenger_flightID(Passenger *passageiro1, int i);

char *get_passenger_userID(Passenger *passageiro1, int i);

#endif