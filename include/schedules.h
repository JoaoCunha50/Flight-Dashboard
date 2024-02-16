#ifndef SCHEDULES_H
#define SCHEDULES_H

#include "main.h"

typedef struct data Data;

typedef struct time Time;

typedef struct schedule Schedule;

int isDateValid_Flights(Data date_departure, Data date_arrival);

int isDateValid_Users(Data *birthday);

int isDateValid_User(Data birthday);

int isScheduleValid_User(Schedule *schedule);

int isTimeValid(Time time_departure, Time time_arrival);

int isDateValid_Reservations(Data *date_departure, Data *date_arrival);

#endif