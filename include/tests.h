#ifndef TESTS_H
#define TESTS_H

/**
 * @file tests.c
 *  Este ficheiro contém as funções relacionadas com os testes funcionais e de desempenho.
 *
 */

#include "query1.h"
#include "query2.h"
#include "query3.h"
#include "query4.h"
#include "query5.h"
#include "query6.h"
#include "query7.h"
#include "query8.h"
#include "query9.h"
#include "files.h"
#include "files.h"
#include "interpreter.h"
#include "statistics.h"
#include "parser.h"

bool compare(FILE *file1, FILE *file2, int *linha);

void check(int counter);

void noOutput(int counter);

void q1_test(Flight *flight, Reservation *reserva, User *user, Passenger *passenger, int counter, char *input);

void q2_test(Flight *flight, Reservation *reserva, User *user, Passenger *passenger, int counter, char *input);

void q3_test(Reservation *reserva, int counter, char *input);

void q4_test(Reservation *reserva, int counter, char *input);

void q5_test(Flight *flight, int counter, char *input);

void q7_test(Flight *flight, int counter, char *input);

void q8_test(Reservation *reserva, int counter, char *input);

void q9_test(User *user, int counter, char *input);

#endif