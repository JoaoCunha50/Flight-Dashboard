#include "../include/passengers.h"

struct passenger
{
    char *flight_id;
    char *user_id;
};

int n_passageiros = 0;

int SizeofPassengers()
{
    return sizeof(Passenger);
}

int free_passageiros(Passenger *passageiros)
{
    for (int i = 0; i < n_passageiros; i++)
    {
        free(passageiros[i].flight_id);
        free(passageiros[i].user_id);
    }

    free(passageiros);
    return 0;
}

void set_passenger_flight_id(char *flight_id, Passenger *passenger, int i)
{
    passenger[i].flight_id = malloc(sizeof(char) * (strlen(flight_id) + 1));
    strcpy(passenger[i].flight_id, flight_id);
    n_passageiros++;
}

void set_passenger_user_id(char *user_id, Passenger *passenger, int i)
{
    passenger[i].user_id = malloc(sizeof(char) * (strlen(user_id) + 1));
    user_id[strlen(user_id) - 1] = '\0';
    strcpy(passenger[i].user_id, user_id);
}

int isPvalid(Passenger *passenger, int i)
{
    return (strlen(passenger[i].flight_id) > 0 && strlen(passenger[i].user_id) > 0);
}

void reset_passenger(Passenger *passenger, int i)
{
    free(passenger[i].flight_id);
    free(passenger[i].user_id);
    passenger[i].flight_id = NULL;
    passenger[i].user_id = NULL;
    n_passageiros--;
}

int CountPassengers(Passenger *passengers, int flight_id)
{
    int count;
    for (int i = 0; i < n_passageiros; i++)
    {
        int j = atoi(passengers[i].flight_id);
        if (j == flight_id)
            count++;
    }
    return count;
}

char *get_passenger_flightID(Passenger *passenger, int i)
{
    return strdup(passenger[i].flight_id);
}

char *get_passenger_userID(Passenger *passenger, int i)
{
    return strdup(passenger[i].user_id);
}

