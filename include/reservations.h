#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "schedules.h"
#include "main.h"

typedef struct data Data;

typedef struct reservation Reservation;

extern int n_reservations;

void toUpperCase(char *s);

int SizeofReservations();

void set_reservation_id(Reservation *booking, char *chave, int i);

void set_reservation_user_id(Reservation *booking, char *chave, int i);

void set_reservation_hotel_id(Reservation *booking, char *chave, int i);

void set_reservation_hotel_name(Reservation *booking, char *chave, int i);

void set_reservation_hotel_stars(Reservation *booking, char *chave, int i);

void set_reservation_city_tax(Reservation *booking, char *chave, int i);

void set_reservation_address(Reservation *booking, char *chave, int i);

void set_reservation_begin_date(Reservation *booking, char *chave, int i);

void set_reservation_end_date(Reservation *booking, char *chave, int i);

void set_reservation_price_per_night(Reservation *booking, char *chave, int i);

void set_reservation_includes_breakfast(Reservation *booking, char *chave, int i);

void set_reservation_room_details(Reservation *booking, char *chave, int i);

void set_reservation_rating(Reservation *booking, char *chave, int i);

void set_reservation_comment(Reservation *booking, char *chave, int i);

int isReservationDateValid(Reservation *booking, int i);

int isReservationValid(Reservation *booking, int i);

void reset_reservation(Reservation *booking, int i);

void freeReservation(Reservation *reservation);

void freereservationQ(Reservation *reservas_filtradas, int s);

char *get_reservation_id(Reservation *reservation, int i);

char *get_reservation_userID(Reservation *reservation, int i);

char *get_reservation_hotelID(Reservation *reservation, int i);

char *get_reservation_hotelName(Reservation *reservation, int i);

int get_reservation_hotelStars(Reservation *reservation, int i);

int get_reservation_cityTax(Reservation *reservation, int i);

char *get_reservation_address(Reservation *reservation, int i);

int get_reservation_beginData_Year(Reservation *reservation, int i);

int get_reservation_beginData_Month(Reservation *reservation, int i);

int get_reservation_beginData_Day(Reservation *reservation, int i);

Data *get_reservation_beginData(Reservation *reservation, int i);

int get_reservation_endData_Year(Reservation *reservation, int i);

int get_reservation_endData_Month(Reservation *reservation, int i);

int get_reservation_endData_Day(Reservation *reservation, int i);

Data *get_reservation_endData(Reservation *reservation, int i);

int get_reservation_pricePerNight(Reservation *reservation, int i);

char *get_reservation_includesBreakfast(Reservation *reservation, int i);

char *get_reservation_roomDetails(Reservation *reservation, int i);

int get_reservation_rating(Reservation *reservation, int i);

char *get_reservation_comment(Reservation *reservation, int i);

int get_hotel_rating(Reservation *reservation, char *hotel_id, int *i);

int compare_hotelID(Reservation *reservation, char *hotel_id, int i);

int get_hotel_price_per_night(Reservation *reservation, char *hotel_id, char *begin_date_c, char *end_date_c, int *n, int *aux);

int checkdate(Reservation reservation, Data *begin_date, Data *end_date);

int calculaNoite(Data *data1, Data *data2);

Data *convertToData(char *data, Data *date);

double calculaTotalPrice(Reservation *reserva, int i);

int comparaReservas(const void *x, const void *y);

void copyReservation(Reservation *reserva1, Reservation *reserva2, int size, int i);

int copyDataAno1(Reservation *reservation, int ano, int i);

int copyDataMes1(Reservation *reservation, int mes, int i);

int copyDataDia1(Reservation *reservation, int dia, int i);


#endif