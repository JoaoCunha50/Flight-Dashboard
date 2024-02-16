#ifndef STATISTICS_H
#define STATISTICS_H

#include "flights.h"
#include "main.h"
#include "users.h"
#include "passengers.h"
#include "reservations.h"

#define CURRENT_YEAR 2023
#define CURRENT_MONTH 10
#define CURRENT_DAY 1

double media(double soma, double total);

int get_flight_delay(Flight *flight, int i);

int get_user_age(User *user, int i);

int get_user_flightnum(char *id, Passenger *passengers);

int get_user_reservationsnum(char *id, Reservation *booking);

double get_user_reservation_totalspent(char *id, Reservation *booking);

int get_reservation_nights(char *id, Reservation *booking, int i);

double get_reservation_totalprice(char *id, Reservation *booking, int i);

int get_flight_passengers(char *id, Passenger *passenger);

int comparador(const void *a, const void *b);

int calculaMediana(int *valores, int n_total);


#endif