#include "../include/statistics.h"

double media(double soma, double total)
{
    float media = 0;
    media = soma / total;
    return media;
}

int get_flight_delay(Flight *flight, int i)
{
    int delay = ((get_flight_realDepartureDate_Hour(flight, i) - get_flight_scheduledDepartureDate_Hour(flight, i)) * 3600) + ((get_flight_realDepartureDate_Minutes(flight, i) - get_flight_scheduledDepartureDate_Minutes(flight, i)) * 60) + (get_flight_realDepartureDate_Seconds(flight, i) - get_flight_scheduledDepartureDate_Seconds(flight, i));
    return delay;
}

int get_user_age(User *user, int i)
{
    int age = (CURRENT_YEAR - get_user_birthdayDate_Year(user, i));

    if (CURRENT_MONTH < get_user_birthdayDate_Month(user, i) ||
        (CURRENT_MONTH == get_user_birthdayDate_Month(user, i) &&
         CURRENT_DAY < get_user_birthdayDate_Day(user, i)))
    {
        age--;
    }

    return age;
}

int get_user_flightnum(char *id, Passenger *passengers)
{
    int count = 0;
    for (int i = 0; i < n_passageiros; i++)
    {
        char *userID = get_passenger_userID(passengers, i);
        if (strcmp(id, userID) == 0)
        {
            count++;
        }
        free(userID);
    }
    return count;
}

int get_user_reservationsnum(char *id, Reservation *booking)
{
    int count = 0;
    for (int i = 0; i < n_reservations; i++)
    {
        char *userID = get_reservation_userID(booking, i);
        if (strcmp(id, userID) == 0)
        {
            count++;
        }
        free(userID);
    }
    return count;
}

double get_user_reservation_totalspent(char *id, Reservation *booking)
{
    double total = 0;
    for (int i = 0; i < n_reservations; i++)
    {
        char *userID = get_reservation_userID(booking, i);
        if (strcmp(id, userID) == 0)
        {
            total += get_reservation_totalprice(id, booking, i);
            // total += (get_user_reservation_nights(id, booking, i)) * get_reservation_pricePerNight(booking, i);
        }
        free(userID);
    }
    return total;
}

int get_reservation_nights(char *id, Reservation *booking, int i)
{
    int nights = 0;
    nights = (get_reservation_endData_Day(booking, i) - get_reservation_beginData_Day(booking, i));
    return nights;
}

double get_reservation_totalprice(char *id, Reservation *booking, int i)
{
    double total = 0;
    total = get_reservation_pricePerNight(booking, i) * get_reservation_nights(id, booking, i) + ((get_reservation_pricePerNight(booking, i) * get_reservation_nights(id, booking, i)) / (double)100) * get_reservation_cityTax(booking, i);
    return total;
}

int get_flight_passengers(char *id, Passenger *passenger)
{
    int count = 0;
    for (int i = 0; i < n_passageiros; i++)
    {
        char *flightID = get_passenger_flightID(passenger, i);
        if (strcmp(id, flightID) == 0)
        {
            count++;
        }
        free(flightID);
    }
    return count;
}

int comparador(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int calculaMediana(int *valores, int n_total)
{
    if (n_total == 0)
    {
        return 0;
    }
    qsort(valores, n_total, sizeof(int), comparador);
    if (n_total % 2 == 0)
    {
        int meio = n_total / 2;
        return (valores[meio - 1] + valores[meio]) / 2;
    }
    else
    {
        return valores[n_total / 2];
    }
}