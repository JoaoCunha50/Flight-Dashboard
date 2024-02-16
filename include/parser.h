#ifndef PARSER_H
#define PARSER_H

#include "query3.h"
#include "query8.h"
#include "flights.h"
#include "passengers.h"
#include "reservations.h"
#include "users.h"
#include "files.h"

Passenger *ParsePassengers(FILE *passengers, FILE *erros, Passenger *passenger);

Reservation *ParseReservations(FILE *reservations, FILE *erros, Reservation *reservation);

User *ParseUsers(FILE *users, FILE *erros, User *user);

int SeatsInFlight(Flight *flight, int i);

Flight *ParseFlights(FILE *flights, FILE *erros, Flight *flight);

int validationreservation(char **user_id_sv, Reservation *reservation, int i);

int validationUserPassenger(char **user_id_sv, Passenger *passenger, int i);

int validationFlightPassenger(char **flight_id_sv, Passenger *passenger, int i);

void free_user_id_sv(char **user_id_sv);

void free_flight_id_sv(char **flight_id_sv);

#endif