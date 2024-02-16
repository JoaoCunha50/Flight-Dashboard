#include "../include/flights.h"

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

struct flight
{
    char *id;
    char *airline; 
    char *plane_model;
    int total_seats;
    char *origin;
    char *destination;
    Schedule *scheduled_departure_date;
    Schedule *scheduled_arrival_date;
    Schedule *real_departure_date;
    Schedule *real_arrival_date;
    char *pilot;
    char *copilot;
    char *notes;
};

int n_voos = 0;

int SizeofFlights()
{
    return sizeof(Flight);
}

void free_flights(Flight *flight)
{
    for (int i = 0; i < n_voos; i++)
    {
        free(flight[i].id);
        free(flight[i].airline);
        free(flight[i].plane_model);
        free(flight[i].origin);
        free(flight[i].destination);
        free(flight[i].scheduled_departure_date);
        free(flight[i].scheduled_arrival_date);
        free(flight[i].real_departure_date);
        free(flight[i].real_arrival_date);
        free(flight[i].pilot);
        free(flight[i].copilot);
        free(flight[i].notes);
    }
    free(flight);
}

void freeflightsQ(Flight *voos_filtrados, int s)
{
    for (int l = 0; l < s; l++)
    {
        free(voos_filtrados[l].id);
        free(voos_filtrados[l].airline);
        free(voos_filtrados[l].destination);
        free(voos_filtrados[l].plane_model);
    }

    free(voos_filtrados);
}

int isScheduleValid(Flight *flight, int i)
{
    int j = isDateValid_Flights(flight[i].scheduled_departure_date->date, flight[i].scheduled_arrival_date->date);
    if (j == 1)
        return 1;
    if (j == 2)
        return isTimeValid(flight[i].scheduled_departure_date->time, flight[i].scheduled_arrival_date->time);

    return 0;
}

int isRealScheduleValid(Flight *flight, int i)
{
    int j = isDateValid_Flights(flight[i].real_departure_date->date, flight[i].real_arrival_date->date);
    if (j == 1)
        return 1;
    if (j == 2)
        return isTimeValid(flight[i].real_departure_date->time, flight[i].real_arrival_date->time);

    return 0;
}

void set_flight_id(Flight *flight, char *chave, int i)
{
    flight[i].id = malloc(strlen(chave) + 1);
    strcpy(flight[i].id, chave);
    n_voos++;
}

void set_airline(Flight *flight, char *chave, int i)
{
    flight[i].airline = malloc(strlen(chave) + 1);
    strcpy(flight[i].airline, chave);
}

void set_plane_model(Flight *flight, char *chave, int i)
{
    flight[i].plane_model = malloc(strlen(chave) + 1);
    strcpy(flight[i].plane_model, chave);
}

void set_total_seats(Flight *flight, char *chave, int i)
{
    flight[i].total_seats = atoi(chave);
}

void set_origin(Flight *flight, char *chave, int i)
{
    flight[i].origin = malloc(strlen(chave) + 1);
    strcpy(flight[i].origin, chave);
}

void set_destination(Flight *flight, char *chave, int i)
{
    flight[i].destination = malloc(strlen(chave) + 1);
    strcpy(flight[i].destination, chave);
}

void set_scheduled_departure_date(Flight *flight, char *chave, int i)
{
    flight[i].scheduled_departure_date = malloc(sizeof(Schedule));
    char *token;

    if (chave == NULL)
        return;

    token = strtok(chave, "/");
    if (token == NULL || strlen(token) != 4)
        return;

    flight[i].scheduled_departure_date->date.ano = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_departure_date->date.mes = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_departure_date->date.dia = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_departure_date->time.horas = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_departure_date->time.minutos = atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_departure_date->time.segundos = atoi(token);
}

void set_scheduled_arrival_date(Flight *flight, char *chave, int i)
{
    flight[i].scheduled_arrival_date = malloc(sizeof(Schedule));
    char *token;

    if (chave == NULL)
        return;

    token = strtok(chave, "/");
    if (token == NULL || strlen(token) != 4)
        return;

    flight[i].scheduled_arrival_date->date.ano = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_arrival_date->date.mes = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_arrival_date->date.dia = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_arrival_date->time.horas = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_arrival_date->time.minutos = atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].scheduled_arrival_date->time.segundos = atoi(token);
}

void set_real_departure_date(Flight *flight, char *chave, int i)
{
    flight[i].real_departure_date = malloc(sizeof(Schedule));
    char *token;

    if (chave == NULL)
        return;

    token = strtok(chave, "/");
    if (token == NULL || strlen(token) != 4)
        return;

    flight[i].real_departure_date->date.ano = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_departure_date->date.mes = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_departure_date->date.dia = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_departure_date->time.horas = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_departure_date->time.minutos = atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_departure_date->time.segundos = atoi(token);
}

void set_real_arrival_date(Flight *flight, char *chave, int i)
{
    flight[i].real_arrival_date = malloc(sizeof(Schedule));
    char *token;

    if (chave == NULL)
        return;

    token = strtok(chave, "/");
    if (token == NULL || strlen(token) != 4)
        return;

    flight[i].real_arrival_date->date.ano = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_arrival_date->date.mes = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_arrival_date->date.dia = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_arrival_date->time.horas = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_arrival_date->time.minutos = atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL || strlen(token) != 2)
        return;

    flight[i].real_arrival_date->time.segundos = atoi(token);
}

void set_pilot(Flight *flight, char *chave, int i)
{
    flight[i].pilot = malloc(sizeof(char) * strlen(chave) + 1);
    strcpy(flight[i].pilot, chave);
}

void set_copilot(Flight *flight, char *chave, int i)
{
    flight[i].copilot = malloc(sizeof(char) * strlen(chave) + 1);
    strcpy(flight[i].copilot, chave);
}

void set_notes(Flight *flight, char *chave, int i)
{
    flight[i].notes = malloc(strlen(chave) + 1);
    strcpy(flight[i].notes, chave);
}

int ConvertIdToInt(Flight *flight, int i)
{
    int j = atoi(flight[i].id);
    return j;
}

int isFlightValid(Flight *flight, int i)
{
    return (strlen(flight[i].id) > 0) &&
           (strlen(flight[i].airline) > 0) &&
           (strlen(flight[i].plane_model) > 0) &&
           (flight[i].total_seats > 0) &&
           (strlen(flight[i].origin) == 3) &&
           (strlen(flight[i].destination) == 3) &&
           (isScheduleValid(flight, i)) &&
           (isRealScheduleValid(flight, i)) &&
           (strlen(flight[i].pilot) > 0) &&
           (strlen(flight[i].copilot) > 0);
}

void reset_flight(Flight *flight, int i)
{
    free(flight[i].id);
    free(flight[i].airline);
    free(flight[i].plane_model);
    free(flight[i].origin);
    free(flight[i].destination);

    if (flight[i].scheduled_departure_date != NULL)
    {
        free(flight[i].scheduled_departure_date);
    }
    if (flight[i].scheduled_arrival_date != NULL)
    {
        free(flight[i].scheduled_arrival_date);
    }
    if (flight[i].real_departure_date != NULL)
    {
        free(flight[i].real_departure_date);
    }
    if (flight[i].real_arrival_date != NULL)
    {
        free(flight[i].real_arrival_date);
    }

    free(flight[i].pilot);
    free(flight[i].copilot);
    free(flight[i].notes);

    flight[i].id = NULL;
    flight[i].airline = NULL;
    flight[i].plane_model = NULL;
    flight[i].total_seats = 0;
    flight[i].origin = NULL;
    flight[i].destination = NULL;
    flight[i].scheduled_departure_date = NULL;
    flight[i].scheduled_arrival_date = NULL;
    flight[i].real_departure_date = NULL;
    flight[i].real_arrival_date = NULL;
    flight[i].pilot = NULL;
    flight[i].copilot = NULL;
    flight[i].notes = NULL;

    n_voos--;
}

char *get_flight_id(Flight *flight, int i)
{
    return strdup(flight[i].id);
}

char *get_flight_airline(Flight *flight, int i)
{
    return strdup(flight[i].airline);
}

char *get_flight_planeModel(Flight *flight, int i)
{
    return strdup(flight[i].plane_model);
}

int get_flight_totalSeats(Flight *flight, int i)
{
    return flight[i].total_seats;
}

char *get_flight_origin(Flight *flight, int i)
{
    return strdup(flight[i].origin);
}

char *get_flight_destination(Flight *flight, int i)
{
    return strdup(flight[i].destination);
}

int get_flight_scheduledDepartureDate_Year(Flight *flight, int i)
{
    return flight[i].scheduled_departure_date->date.ano;
}
int get_flight_scheduledDepartureDate_Month(Flight *flight, int i)
{
    return flight[i].scheduled_departure_date->date.mes;
}
int get_flight_scheduledDepartureDate_Day(Flight *flight, int i)
{
    return flight[i].scheduled_departure_date->date.dia;
}
int get_flight_scheduledDepartureDate_Hour(Flight *flight, int i)
{
    return flight[i].scheduled_departure_date->time.horas;
}

int get_flight_scheduledDepartureDate_Minutes(Flight *flight, int i)
{
    return flight[i].scheduled_departure_date->time.minutos;
}

int get_flight_scheduledDepartureDate_Seconds(Flight *flight, int i)
{
    return flight[i].scheduled_departure_date->time.segundos;
}
int get_flight_scheduledArrivalDate_Year(Flight *flight, int i)
{
    return flight[i].scheduled_arrival_date->date.ano;
}
int get_flight_scheduledArrivalDate_Month(Flight *flight, int i)
{
    return flight[i].scheduled_arrival_date->date.mes;
}
int get_flight_scheduledArrivalDate_Day(Flight *flight, int i)
{
    return flight[i].scheduled_arrival_date->date.dia;
}
int get_flight_scheduledArrivalDate_Hour(Flight *flight, int i)
{
    return flight[i].scheduled_arrival_date->time.horas;
}

int get_flight_scheduledArrivalDate_Minutes(Flight *flight, int i)
{
    return flight[i].scheduled_arrival_date->time.minutos;
}

int get_flight_scheduledArrivalDate_Seconds(Flight *flight, int i)
{
    return flight[i].scheduled_arrival_date->time.segundos;
}

int get_flight_realDepartureDate_Year(Flight *flight, int i)
{
    return flight[i].real_departure_date->date.ano;
}
int get_flight_realDepartureDate_Month(Flight *flight, int i)
{
    return flight[i].real_departure_date->date.mes;
}
int get_flight_realDepartureDate_Day(Flight *flight, int i)
{
    return flight[i].real_departure_date->date.dia;
}
int get_flight_realDepartureDate_Hour(Flight *flight, int i)
{
    return flight[i].real_departure_date->time.horas;
}

int get_flight_realDepartureDate_Minutes(Flight *flight, int i)
{
    return flight[i].real_departure_date->time.minutos;
}

int get_flight_realDepartureDate_Seconds(Flight *flight, int i)
{
    return flight[i].real_departure_date->time.segundos;
}

int get_flight_realArrivalDate_Year(Flight *flight, int i)
{
    return flight[i].real_arrival_date->date.ano;
}
int get_flight_realArrivalDate_Month(Flight *flight, int i)
{
    return flight[i].real_arrival_date->date.mes;
}
int get_flight_realArrivalDate_Day(Flight *flight, int i)
{
    return flight[i].real_arrival_date->date.dia;
}
int get_flight_realArrivalDate_Hour(Flight *flight, int i)
{
    return flight[i].real_arrival_date->time.horas;
}

int get_flight_realArrivalDate_Minutes(Flight *flight, int i)
{
    return flight[i].real_arrival_date->time.minutos;
}

int get_flight_realArrivalDate_Seconds(Flight *flight, int i)
{
    return flight[i].real_arrival_date->time.segundos;
}

char *get_flight_pilot(Flight *flight, int i)
{
    return strdup(flight[i].pilot);
}

char *get_flight_copilot(Flight *flight, int i)
{
    return strdup(flight[i].copilot);
}

char *get_flight_notes(Flight *flight, int i)
{
    if (flight[i].notes != NULL)
    {
        return strdup(flight[i].notes);
    }
    else
        return " ";
}

int calcula_atraso(Schedule *estimada, Schedule *real)
{
    int segundos_estimada = 0;
    int segundos_real = 0;
    int diferença = 0;

    segundos_estimada = (estimada->date.dia * 86400) + ((estimada->time.horas * 3600) + (estimada->time.minutos * 60) + (estimada->time.segundos));
    segundos_real = (estimada->date.dia * 86400) + ((real->time.horas * 3600) + (real->time.minutos * 60 + (real->time.segundos)));

    diferença = (segundos_real - segundos_estimada);

    return diferença;
}

Schedule *convertToSchedule(char *string_horario, Schedule *horario)
{
    char *token;
    char *aux = strdup(string_horario);
    char *temp = aux;

    token = strsep(&temp, "/");

    horario->date.ano = atoi(token);

    token = strsep(&temp, "/");

    horario->date.mes = atoi(token);

    token = strsep(&temp, " "); 

    horario->date.dia = atoi(token);

    token = strsep(&temp, ":");

    horario->time.horas = atoi(token);

    token = strsep(&temp, ":");

    horario->time.minutos = atoi(token);

    token = strsep(&temp, ":");

    if (token != NULL)
    {
        horario->time.segundos = atoi(token);
    }
    else
    {
        horario->time.segundos = 0;
    }

    free(aux);
    return horario;
}

int compareSchedules(Schedule *schedule1, Schedule *schedule2)
{
    if (schedule1->date.ano != schedule2->date.ano)
    {
        return schedule1->date.ano - schedule2->date.ano;
    }
    if (schedule1->date.mes != schedule2->date.mes)
    {
        return schedule1->date.mes - schedule2->date.mes;
    }
    if (schedule1->date.dia != schedule2->date.dia)
    {
        return schedule1->date.dia - schedule2->date.dia;
    }

    if (schedule1->time.horas != schedule2->time.horas)
    {
        return schedule1->time.horas - schedule2->time.horas;
    }
    if (schedule1->time.minutos != schedule2->time.minutos)
    {
        return schedule1->time.minutos - schedule2->time.minutos;
    }
    if (schedule1->time.segundos != schedule2->time.segundos)
    {
        return schedule1->time.segundos - schedule2->time.segundos;
    }

    return 0;
}

int compareTimes(Time time1, Time time2)
{
    if (time1.horas != time2.horas) {
        return time1.horas - time2.horas;
    }

    if (time1.minutos != time2.minutos) {
        return time1.minutos - time2.minutos;
    }

    return time1.segundos - time2.segundos;
}

int compareDates(Data date1, Data date2)
{
    if (date1.ano != date2.ano) {
        return date1.ano - date2.ano;
    }

    if (date1.mes != date2.mes) {
        return date1.mes - date2.mes;
    }

    return date1.dia - date2.dia;
}

int isFlightInRange(Flight *flight, int i, char *begin_schedule_c, char *end_schedule_c)
{
    Schedule *begin_schedule = malloc(sizeof(Schedule));
    Schedule *end_schedule = malloc(sizeof(Schedule));
    convertToSchedule(begin_schedule_c, begin_schedule);
    convertToSchedule(end_schedule_c, end_schedule);

    if (compareDates(flight[i].scheduled_departure_date->date, begin_schedule->date) >= 0 &&
        compareTimes(flight[i].scheduled_departure_date->time, begin_schedule->time) >= 0 &&
        compareDates(flight[i].scheduled_departure_date->date, end_schedule->date) <= 0 &&
        compareTimes(flight[i].scheduled_departure_date->time, end_schedule->time) <= 0)
    {
        free(begin_schedule);
        free(end_schedule);
        return 1;
    }

    free(begin_schedule);
    free(end_schedule);
    return 0;
}

int comparaVoos(const void *a, const void *b)
{
    const Flight *flightA = (const Flight *)a;
    const Flight *flightB = (const Flight *)b;

    int dateComparison = -compareSchedules(flightA->scheduled_departure_date, flightB->scheduled_departure_date);

    if (dateComparison == 0)
    {
        return -strcmp(flightA->id, flightB->id);
    }

    return dateComparison;
}

void copyVoo(Flight *voo1, Flight *voo2, int size, int i)
{

    voo1[size].id = malloc(sizeof(char) * 100);
    strcpy(voo1[size].id, voo2[i].id);
    voo1[size].scheduled_departure_date = voo2[i].scheduled_departure_date;
    voo1[size].destination = malloc(sizeof(char) * 100);
    strcpy(voo1[size].destination, voo2[i].destination);
    voo1[size].airline = malloc(sizeof(char) * 100);
    strcpy(voo1[size].airline, voo2[i].airline);
    voo1[size].plane_model = malloc(sizeof(char) * 100);
    strcpy(voo1[size].plane_model, voo2[i].plane_model);

    return;
}

Time get_hora_marcada(Flight *flight, int i)
{
    return (flight[i].scheduled_departure_date->time);
}

Time get_hora_real(Flight *flight, int i)
{
    return (flight[i].real_departure_date->time);
}

int calculaAtrasos(Time hora_marcada, Time hora_real)
{
    int delay = 0;
    int hora_marcada_convertida = (hora_marcada.horas * 3600) + (hora_marcada.minutos * 60) + hora_marcada.segundos;
    int hora_real_convertida = (hora_real.horas * 3600) + (hora_real.minutos * 60) + hora_real.segundos;
    delay = hora_real_convertida - hora_marcada_convertida;

    return delay;
}

int get_delay(Flight *flight, int i)
{
    return (calculaAtrasos(get_hora_marcada(flight, i), get_hora_real(flight, i)));
}

char *ajustaSigla(char *str)
{
    char *original = str;

    while (*str)
    {
        *str = toupper((unsigned char)*str);
        str++;
    }

    return original;
}

int copyDataAno(Flight *flight, int ano, int i)
{
    ano = get_flight_scheduledArrivalDate_Year(flight, i);

    return ano;
}

int copyDataMes(Flight *flight, int mes, int i)
{
    mes = get_flight_scheduledArrivalDate_Month(flight, i);

    return mes;
}

int copyDataDia(Flight *flight, int dia, int i)
{
    dia = get_flight_scheduledArrivalDate_Day(flight, i);

    return dia;
}
