#include "../include/parser.h"

int passageiros;
char **user_id_sv;
char **flight_id_sv;
int j = 0;
int n = 0;

Passenger *ParsePassengers(FILE *passengers, FILE *erros, Passenger *passenger)
{
    int size = SizeofPassengers();
    passenger = malloc(size * 2);
    int r = 3;

    if (passenger == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    char *header = malloc(100 * sizeof(char));
    fgets(header, 100, passengers);
    fprintf(erros, "%s", header);
    free(header);

    char *chave;
    char *linha = malloc(250 * sizeof(char));

    for (int i = 0; fgets(linha, 250, passengers) != NULL; i++)
    {
        char *temp = strdup(linha);
        char *aux = temp;

        if (i > 0)
        {
            r += 1;
            passenger = realloc(passenger, size * r);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_passenger_flight_id(chave, passenger, i);
        }

        set_passenger_user_id(aux, passenger, i);

        if ((validationUserPassenger(user_id_sv, passenger, i) == 0) || (validationFlightPassenger(flight_id_sv, passenger, i) == 0) || (!isPvalid(passenger, i)))
        {
            fprintf(erros, "%s", linha);
            reset_passenger(passenger, i);
            i--;
        }
        free(temp);
    }

    free_flight_id_sv(flight_id_sv);

    free(linha); // Free a memória de  temporario

    puts("Catálogo de passageiros preenchido");

    return passenger;
}

Reservation *ParseReservations(FILE *reservations, FILE *erros, Reservation *reservation)
{
    int size = SizeofReservations();
    reservation = malloc((size) * 2);
    int r = 3;

    if (reservation == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    char *header = malloc(500 * sizeof(char));
    fgets(header, 500, reservations);
    fprintf(erros, "%s", header);
    free(header);

    char *chave;
    char *linha = malloc(4000 * sizeof(char));

    for (int i = 0; fgets(linha, 4000, reservations) != NULL; i++)
    {
        char *temp = strdup(linha);
        char *aux = temp;

        if (i > 0)
        {
            r += 1;
            reservation = realloc(reservation, size * r);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_id(reservation, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_user_id(reservation, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_hotel_id(reservation, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_hotel_name(reservation, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_hotel_stars(reservation, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_city_tax(reservation, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_address(reservation, chave, i);
            // printf("%s ", get_reservation_address(reservation, i));
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_begin_date(reservation, chave, i);
            // printf("%d/%d/%d ", get_reservation_beginData_Year(reservation, i), get_reservation_beginData_Month(reservation, i), get_reservation_beginData_Day(reservation, i));
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_end_date(reservation, chave, i);
            // printf("%d/%d/%d ", get_reservation_endData_Year(reservation, i), get_reservation_endData_Month(reservation, i), get_reservation_endData_Day(reservation, i));
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_price_per_night(reservation, chave, i);
            // printf("%d ", get_reservation_pricePerNight(reservation, i));
        }

        chave = strsep(&aux, ";");
        set_reservation_includes_breakfast(reservation, chave, i);

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_room_details(reservation, chave, i);
            // printf("%s ", get_reservation_roomDetails(reservation, i));
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_reservation_rating(reservation, chave, i);
            // printf("%d ", get_reservation_rating(reservation, i));
        }

        set_reservation_comment(reservation, aux, i);
        // printf("%s\n", get_reservation_comment(reservation, i));

        if ((validationreservation(user_id_sv, reservation, i) == 0) || (!isReservationValid(reservation, i)))
        {
            fprintf(erros, "%s", linha);
            reset_reservation(reservation, i);
            i--;
        }
        free(temp);
    }

    free_user_id_sv(user_id_sv);

    free(linha);

    puts("Catálogo de reservas preenchido");

    return reservation;
}

User *ParseUsers(FILE *users, FILE *erros, User *user)
{
    int size = SizeofUsers();
    user_id_sv = malloc(size * 2);
    user = malloc(size * 2);

    int r = 3;
    int c = 3;

    if (user == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    char *header = malloc(1000 * sizeof(char));
    fgets(header, 1000, users);
    fprintf(erros, "%s", header);
    free(header);

    char *chave;
    char *linha = malloc(4000 * sizeof(char));

    for (int i = 0; fgets(linha, 4000, users) != NULL; i++)
    {
        char *temp = strdup(linha);
        char *aux = temp;

        if (i > 0)
        {
            r += 1;
            user = realloc(user, size * r);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_id(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_name(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_email(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_phone_number(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_birthday_date(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_sex(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_passport(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_country_code(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_address(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_account_creation(user, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_user_pay_method(user, chave, i);
        }
        set_user_account_status(user, aux, i);

        if (!(isUserValid(user, i)))
        {
            char *userID = get_user_id(user, i);
            fprintf(erros, "%s", linha);
            user_id_sv = realloc(user_id_sv, size * c);
            c += 1;
            user_id_sv[j] = userID;
            reset_User(user, i);
            // free(userID);
            i--;
            j++;
        }
        free(temp);
        // printf("%d/%d/%d %d:%d:%d\n", get_user_accountCreation_Year(client, i), get_user_accountCreation_Month(client, i), get_user_accountCreation_Day(client, i), get_user_accountCreation_Hour(client, i), get_user_accountCreation_Minute(client, i), get_user_accountCreation_Seconds(client, i));
    }

    free(linha);

    puts("Catálogo de users preenchido");

    return user;
}

Flight *ParseFlights(FILE *flights, FILE *erros, Flight *flight)
{
    int size = SizeofFlights();
    flight = malloc(size * 2);
    flight_id_sv = malloc(size * 2);
    int r = 3;
    int c = 3;

    if (flight == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    char *header = malloc(500 * sizeof(char));
    fgets(header, 500, flights);
    fprintf(erros, "%s", header);
    free(header);

    char *chave;
    char *linha = malloc(5000 * sizeof(char));

    for (int i = 0; fgets(linha, 5000, flights) != NULL; i++)
    {
        char *temp = strdup(linha);
        char *aux = temp;

        if (i > 0)
        {
            r += 1;
            flight = realloc(flight, size * r);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_flight_id(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_airline(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_plane_model(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_total_seats(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_origin(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_destination(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_scheduled_departure_date(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_scheduled_arrival_date(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_real_departure_date(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_real_arrival_date(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_pilot(flight, chave, i);
        }

        chave = strsep(&aux, ";");
        if (chave != NULL)
        {
            set_copilot(flight, chave, i);
        }

        set_notes(flight, aux, i);

        // CountPassengers(passenger, get_flight_id(flight, i));

        if (!(isFlightValid(flight, i))) //|| SeatsInFlight(flight, i))
        {
            char *flightID = get_flight_id(flight, i);
            flight_id_sv = realloc(flight_id_sv, size * c);
            c += 1;
            flight_id_sv[n] = flightID;
            fprintf(erros, "%s", linha);
            reset_flight(flight, i);
            i--;
            n++;
        }
        free(temp);
    }
    free(linha);

    puts("Catálogo de voos preenchido");

    return flight;
}

int SeatsInFlight(Flight *flight, int i)
{
    int j = ConvertIdToInt(flight, i);
    return (j >= passageiros);
}

int validationreservation(char **user_id_sv, Reservation *reservation, int i)
{
    char *user_id = get_reservation_userID(reservation, i);
    for (int k = 0; k < j; k++)
    {
        if (strcmp(user_id_sv[k], user_id) == 0)
        {
            free(user_id);
            return 0;
        }
    }
    free(user_id);
    return 1;
}

int validationUserPassenger(char **user_id_sv, Passenger *passenger, int i)
{
    char *user_id = get_passenger_userID(passenger, i);
    for (int k = 0; k < j; k++)
    {
        if (strcmp(user_id_sv[k], user_id) == 0)
        {
            free(user_id);
            return 0;
        }
    }
    free(user_id);
    return 1;
}

int validationFlightPassenger(char **flight_id_sv, Passenger *passenger, int i)
{
    char *flight_id = get_passenger_flightID(passenger, i);
    for (int k = 0; k < n; k++)
    {
        if (strcmp(flight_id, flight_id_sv[k]) == 0)
        {
            free(flight_id);
            return 0;
        }
    }
    free(flight_id);
    return 1;
}

void free_user_id_sv(char **user_id_sv)
{
    for (int i = 0; i < j; i++)
    {
        free(user_id_sv[i]);
    }
    free(user_id_sv);
}

void free_flight_id_sv(char **flight_id_sv)
{
    for (int i = 0; i < n; i++)
    {
        free(flight_id_sv[i]);
    }
    free(flight_id_sv);
}
