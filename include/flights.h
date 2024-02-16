#ifndef FLIGHTS_H
#define FLIGHTS_H

#include "schedules.h"
#include "passengers.h"
#include "reservations.h"
#include "main.h"

typedef struct flight Flight;

typedef struct data Data;

typedef struct time Time;

typedef struct schedule Schedule;

extern int n_voos;

int SizeofFlights();

void free_flights(Flight *flight);

void freeflightsQ(Flight *voos_filtrados, int s);

int isScheduleValid(Flight *flight, int i);

int isRealScheduleValid(Flight *flight, int i);

void set_flight_id(Flight *flight, char *chave, int i);

void set_airline(Flight *flight, char *chave, int i);

void set_plane_model(Flight *flight, char *chave, int i);

void set_total_seats(Flight *flight, char *chave, int i);

void set_origin(Flight *flight, char *chave, int i);

void set_destination(Flight *flight, char *chave, int i);

void set_scheduled_departure_date(Flight *flight, char *chave, int i);

void set_scheduled_arrival_date(Flight *flight, char *chave, int i);

void set_real_departure_date(Flight *flight, char *chave, int i);

void set_real_arrival_date(Flight *flight, char *chave, int i);

void set_pilot(Flight *flight, char *chave, int i);

void set_copilot(Flight *flight, char *chave, int i);

void set_notes(Flight *flight, char *chave, int i);

int ConvertIdToInt(Flight *flight, int i);

int isFlightValid(Flight *flight, int i);

void reset_flight(Flight *flight, int i);

char *get_flight_id(Flight *flight, int i);

char *get_flight_airline(Flight *flight, int i);

char *get_flight_planeModel(Flight *flight, int i);

int get_flight_totalSeats(Flight *flight, int i);

char *get_flight_origin(Flight *flight, int i);

char *get_flight_destination(Flight *flight, int i);
int get_flight_scheduledDepartureDate_Year(Flight *flight, int i);
int get_flight_scheduledDepartureDate_Month(Flight *flight, int i);
int get_flight_scheduledDepartureDate_Day(Flight *flight, int i);
int get_flight_scheduledDepartureDate_Hour(Flight *flight, int i);
int get_flight_scheduledDepartureDate_Minutes(Flight *flight, int i);
int get_flight_scheduledDepartureDate_Seconds(Flight *flight, int i);
int get_flight_scheduledArrivalDate_Year(Flight *flight, int i);
int get_flight_scheduledArrivalDate_Month(Flight *flight, int i);
int get_flight_scheduledArrivalDate_Day(Flight *flight, int i);
int get_flight_scheduledArrivalDate_Hour(Flight *flight, int i);
int get_flight_scheduledArrivalDate_Minutes(Flight *flight, int i);
int get_flight_scheduledArrivalDate_Seconds(Flight *flight, int i);
int get_flight_realDepartureDate_Year(Flight *flight, int i);
int get_flight_realDepartureDate_Month(Flight *flight, int i);
int get_flight_realDepartureDate_Day(Flight *flight, int i);
int get_flight_realDepartureDate_Hour(Flight *flight, int i);
int get_flight_realDepartureDate_Minutes(Flight *flight, int i);
int get_flight_realDepartureDate_Seconds(Flight *flight, int i);
int get_flight_realArrivalDate_Year(Flight *flight, int i);
int get_flight_realArrivalDate_Month(Flight *flight, int i);
int get_flight_realArrivalDate_Day(Flight *flight, int i);
int get_flight_realArrivalDate_Hour(Flight *flight, int i);
int get_flight_realArrivalDate_Minutes(Flight *flight, int i);
int get_flight_realArrivalDate_Seconds(Flight *flight, int i);

char *get_flight_pilot(Flight *flight, int i);
char *get_flight_copilot(Flight *flight, int i);
char *get_flight_notes(Flight *flight, int i);

int isFlightInRange(Flight *flight, int i, char *begin_date_c, char *end_date_c);

int compareTimes(Time time1, Time time2);

int compareDates(Data date1, Data date2);

int comparaVoos(const void *a, const void *b);

void copyVoo(Flight *voo1, Flight *voo2, int size, int i);

int compareSchedules(Schedule *schedule1, Schedule *schedule2);

Schedule *convertToSchedule(char *string_horario, Schedule *horario);

Time get_hora_marcada(Flight *flight, int i);

Time get_hora_real(Flight *flight, int i);

int get_delay(Flight *flight, int i);

int calculaAtrasos(Time hora_marcada, Time hora_real);

char *ajustaSigla(char *str);

int copyDataAno(Flight *flight, int ano, int i);

int copyDataMes(Flight *flight, int mes, int i);

int copyDataDia(Flight *flight, int dia, int i);

#endif