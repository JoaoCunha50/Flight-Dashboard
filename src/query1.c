#include "../include/interpreter.h"
#include "../include/query1.h"

void query1(Flight *flight, Reservation *reservation, User *user, Passenger *passenger, char *id, int counter, int mode)
{

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int n = atof(id);
    int i = 0;
    char *output = NULL;
    output = (char *)malloc(1000000);
    if (n > 0)
    {
        for (i = 0; (i < n_voos); i++)
        {
            char *flightID = get_flight_id(flight, i);
            if (strcmp(id, flightID) == 0)
            {
                free(flightID);
                break;
            }
            free(flightID);
        }

        if (i < n_voos)
        {
            char *airline = get_flight_airline(flight, i);
            char *plane_model = get_flight_planeModel(flight, i);
            char *origin = get_flight_origin(flight, i);
            char *destination = get_flight_destination(flight, i);

            if (flag)
            {
                sprintf(output, "--- 1 ---\nairline: %s\nplane_model: %s\norigin: %s\ndestination: %s\nschedule_departure_date: %d/%02d/%02d %02d:%02d:%02d\nschedule_arrival_date: %d/%02d/%02d %02d:%02d:%02d\npassengers: %d\ndelay: %d\n", // usando o %02d garantimos que o parametro, no output tem dois digitos e se nao tiver atraves do inteiro, completa com o 0
                        airline, plane_model, origin, destination, get_flight_scheduledDepartureDate_Year(flight, i), get_flight_scheduledDepartureDate_Month(flight, i),
                        get_flight_scheduledDepartureDate_Day(flight, i), get_flight_scheduledDepartureDate_Hour(flight, i), get_flight_scheduledDepartureDate_Minutes(flight, i), get_flight_scheduledDepartureDate_Seconds(flight, i),
                        get_flight_scheduledArrivalDate_Year(flight, i), get_flight_scheduledArrivalDate_Month(flight, i), get_flight_scheduledArrivalDate_Day(flight, i),
                        get_flight_scheduledArrivalDate_Hour(flight, i), get_flight_scheduledArrivalDate_Minutes(flight, i), get_flight_scheduledArrivalDate_Seconds(flight, i),
                        get_flight_passengers(id, passenger), get_flight_delay(flight, i));
            }
            else
                sprintf(output, "%s;%s;%s;%s;%d/%02d/%02d %02d:%02d:%02d;%d/%02d/%02d %02d:%02d:%02d;%d;%d\n", // usando o %02d garantimos que o parametro, no output tem dois digitos e se nao tiver atraves do inteiro, completa com o 0
                        airline, plane_model, origin, destination, get_flight_scheduledDepartureDate_Year(flight, i), get_flight_scheduledDepartureDate_Month(flight, i),
                        get_flight_scheduledDepartureDate_Day(flight, i), get_flight_scheduledDepartureDate_Hour(flight, i), get_flight_scheduledDepartureDate_Minutes(flight, i), get_flight_scheduledDepartureDate_Seconds(flight, i),
                        get_flight_scheduledArrivalDate_Year(flight, i), get_flight_scheduledArrivalDate_Month(flight, i), get_flight_scheduledArrivalDate_Day(flight, i),
                        get_flight_scheduledArrivalDate_Hour(flight, i), get_flight_scheduledArrivalDate_Minutes(flight, i), get_flight_scheduledArrivalDate_Seconds(flight, i),
                        get_flight_passengers(id, passenger), get_flight_delay(flight, i));

            free(airline);
            free(plane_model);
            free(origin);
            free(destination);
        }
        else
            sprintf(output, "%s", "");
    }
    else if (id[0] == 'B')
    {
        for (i = 0; i < n_reservations; i++)
        {
        char *reservation_id = get_reservation_id(reservation, i);
            if (strcmp(id, reservation_id) == 0)
            {
                free(reservation_id);
                break;
            }
            free(reservation_id);
        }

        if (i < n_reservations)
        {
            char *hotelID = get_reservation_hotelID(reservation, i);
            char *hotelName = get_reservation_hotelName(reservation, i);
            char *breakfast = get_reservation_includesBreakfast(reservation, i);
            if (flag)
            {
                sprintf(output, "--- 1 ---\nhotel_id: %s\nhotel_name: %s\nhotel_stars: %d\nbegin_date: %d/%02d/%02d\nend_date: %d/%02d/%02d\nincludes_breakfast: %s\nnights: %d\ntotal_price: %.3f\n",
                        hotelID, hotelName,
                        get_reservation_hotelStars(reservation, i), get_reservation_beginData_Year(reservation, i),
                        get_reservation_beginData_Month(reservation, i), get_reservation_beginData_Day(reservation, i),
                        get_reservation_endData_Year(reservation, i), get_reservation_endData_Month(reservation, i),
                        get_reservation_endData_Day(reservation, i), breakfast,
                        get_reservation_nights(id, reservation, i), get_reservation_totalprice(id, reservation, i));
            }
            else
                sprintf(output, "%s;%s;%d;%d/%02d/%02d;%d/%02d/%02d;%s;%d;%.3f\n",
                        hotelID, hotelName, get_reservation_hotelStars(reservation, i), get_reservation_beginData_Year(reservation, i),
                        get_reservation_beginData_Month(reservation, i), get_reservation_beginData_Day(reservation, i),
                        get_reservation_endData_Year(reservation, i), get_reservation_endData_Month(reservation, i),
                        get_reservation_endData_Day(reservation, i), breakfast,
                        get_reservation_nights(id, reservation, i), get_reservation_totalprice(id, reservation, i));

            free(hotelID);
            free(hotelName);
            free(breakfast);
        }
        else
            sprintf(output, "%s", "");
    }
    else
    {
        for (i = 0; (i < n_users); i++)
        {
            char *user_id = get_user_id(user, i);

            if (strcmp(id, user_id) == 0)
            {
                free(user_id);
                break;
            }
            free(user_id);
        }

        if (i < n_users)
        {
            char *accountStatus = get_user_accountStatus(user, i);
            if (strcmp(accountStatus, "INACTIVE\n") == 0)
            {
                sprintf(output, "%s", "");
            }
            else
            {
                char *name = get_user_name(user, i);
                char *sex = get_user_sex(user, i);
                char *country_code = get_user_countryCode(user, i);
                char *passport = get_user_passport(user, i);
                if (flag)
                {
                    sprintf(output, "--- 1 ---\nname: %s\nsex: %s\nage: %d\ncountry_code: %s\npassport: %s\nnumber_of_flights: %d\nnumber_of_reservations: %d\ntotal_spent: %.3f\n", name, sex, get_user_age(user, i), country_code, passport, get_user_flightnum(id, passenger), get_user_reservationsnum(id, reservation), get_user_reservation_totalspent(id, reservation));
                }
                else
                    sprintf(output, "%s;%s;%d;%s;%s;%d;%d;%.3f\n", name, sex, get_user_age(user, i), country_code, passport, get_user_flightnum(id, passenger), get_user_reservationsnum(id, reservation), get_user_reservation_totalspent(id, reservation));
                free(name);
                free(sex);
                free(country_code);
                free(passport);
            }
            free(accountStatus);
        }
        else
            sprintf(output, "%s", "");
    }
    if (mode == 0)
    {
        printf("<Nome> <Género> <Código do País> <Passaporte> <Número de Voos> <Número de reservas> <Total Gasto> \n");
        if (strcmp(output, "") == 0)
        {
            printf("NA\n");
        }

        printf("%s", output);
    }
    else
        handle_outputs(counter, output);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (mode == 1)
        printf("\n");

    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q1 - %f segundos (input nº %i)\n", cpu_time_used, counter);
    free(output);
}