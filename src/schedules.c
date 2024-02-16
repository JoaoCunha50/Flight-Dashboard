#include "../include/schedules.h"

struct data
{
    int ano;
    int mes;
    int dia;
};

struct time
{
    int horas;
    int minutos;
    int segundos;
};

struct schedule
{
    Data date;
    Time time;
};

int isDateValid_Flights(Data date_departure, Data date_arrival)
{
    if (date_departure.ano > 1000 && date_departure.mes > 0 && date_departure.mes <= 12 && date_departure.dia > 0 && date_departure.dia <= 31 && date_arrival.ano > 1000 && date_arrival.mes > 0 && date_arrival.mes <= 12 && date_arrival.dia > 0 && date_arrival.dia <= 31)
    {
        if (date_departure.mes > date_arrival.mes)
            return 0;
        else if (date_departure.mes == date_arrival.mes && date_departure.dia > date_arrival.dia)
            return 0;
        else if (date_departure.mes == date_arrival.mes && date_departure.dia == date_arrival.dia)
            return 2;
        else
            return 1;
    }
    return 0;
}

int isDateValid_Users(Data *birthday)
{
    return (birthday->ano > 1000 && birthday->mes > 0 && birthday->mes <= 12 && birthday->dia > 0 && birthday->dia <= 31);
}

int isDateValid_User(Data birthday)
{
    return (birthday.ano > 1000 && birthday.mes > 0 && birthday.mes <= 12 && birthday.dia > 0 && birthday.dia <= 31);
}

int isScheduleValid_User(Schedule *schedule)
{
    return (isDateValid_User(schedule->date) && schedule->time.horas >= 0 && schedule->time.horas < 24 && schedule->time.minutos >= 0 && schedule->time.minutos < 60 && schedule->time.segundos >= 0 && schedule->time.segundos < 60);
}

int isTimeValid(Time time_departure, Time time_arrival)
{
    if (time_departure.horas >= 0 && time_departure.horas <= 23 && time_departure.minutos >= 0 && time_departure.minutos <= 59 && time_departure.segundos >= 0 && time_departure.segundos <= 59 && time_arrival.horas >= 0 && time_arrival.horas <= 23 && time_arrival.minutos >= 0 && time_arrival.minutos <= 59 && time_arrival.segundos >= 0 && time_arrival.segundos <= 59)
    {
        if (time_departure.horas > time_arrival.horas)
            return 0;
        else if (time_departure.horas == time_arrival.horas && time_departure.minutos > time_arrival.minutos)
            return 0;
        else
            return 1;
    }
    return 0;
}

int isDateValid_Reservations(Data *date_departure, Data *date_arrival)
{
    if (date_departure->ano > 1000 && date_departure->mes > 0 && date_departure->mes <= 12 && date_departure->dia > 0 && date_departure->dia <= 31 && date_arrival->ano > 1000 && date_arrival->mes > 0 && date_arrival->mes <= 12 && date_arrival->dia > 0 && date_arrival->dia <= 31)
    {
        if (date_departure->mes > date_arrival->mes)
            return 0;
        else if (date_departure->mes == date_arrival->mes && date_departure->dia > date_arrival->dia)
            return 0;
        else if (date_departure->mes == date_arrival->mes && date_departure->dia == date_arrival->dia)
            return 2;
        else
            return 1;
    }
    return 0;
}