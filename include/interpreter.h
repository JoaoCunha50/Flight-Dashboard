/**
 * @file inputs_batch.h
 *
 * Este ficheiro contém as assinaturas das funções relacionadas com os inputs do modo batch.
 *
 */

#ifndef INPUTS_BATCH_H
#define INPUTS_BATCH_H

#include <string.h>
#include <stdio.h>

#include "flights.h"
#include "passengers.h"
#include "reservations.h"
#include "users.h"
#include "parser.h"

#include "query1.h"
#include "query2.h"
#include "query3.h"
#include "query4.h"
#include "query5.h"
#include "query6.h"
#include "query7.h"
#include "query8.h"
#include "query9.h"
#include "query10.h"


extern int flag;
/**
 *
 * Este é o header da função que faz o tratamento dos inputs e redireciona-os para as query's correspondentes.
 *
 */
void handle_inputs(Reservation *reservation, Flight *flight, User *user, Passenger *passenger, FILE *inputs);

void handle_outputs(int counter, char *output);

void handle_input(Reservation *reservation, Flight *flight, User *user, Passenger *passenger);

#endif
