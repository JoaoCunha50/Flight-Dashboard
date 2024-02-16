#include "../include/query10.h"

struct metricas
{
    int n_users;
    int n_voos;
    int n_passageiros;
    int n_passageiros_unicos;
    int n_reservas;
};

int inserirID(char **id, int num, char *novo_id)
{
    for (int i = 0; i < num; i++)
    {
        if (strcmp(id[i], novo_id) == 0)
        {
            return i;
        }
    }

    strcpy(id[num + 1], novo_id);

    return -1;
}

void query10(Passenger *passengers, User *users, Flight *flights, Reservation *reservations, char *arg, int counter, int mode)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    Metricas *info = malloc(sizeof(Metricas) * 100);
    char flightID[500][50];
    char **passengerID = malloc(sizeof(char) * 75);

    int indice[100];
    int set = 0;
    int Size = 0;
    int ano = 0;
    int mes = 0;
    int l = 0;

    char *chave;
    char *temp = strdup(arg);
    char *aux = temp;

    chave = strsep(&aux, " ");
    if (chave != NULL)
    {
        ano = atoi(chave);
    }
    if (aux != NULL)
    {
        mes = atoi(aux);
    }

    if (mes != 0)
    {
        for (int i = 0; i < n_voos; i++)
        {
            if (ano == get_flight_scheduledArrivalDate_Year(flights, i) && mes == get_flight_scheduledArrivalDate_Month(flights, i))
            {
                strcpy(flightID[l], get_flight_id(flights, i));
                indice[l] = get_flight_scheduledDepartureDate_Day(flights, i);
                info[indice[l]].n_voos++;
                l++;
            }
        }
        for (int i = 0; i < n_users; i++)
        {
            if (ano == get_user_accountCreation_Year(users, i) && mes == get_user_accountCreation_Month(users, i))
            {
                info[get_user_accountCreation_Day(users, i)].n_users++;
            }
        }
        for (int i = 0; i < n_passageiros; i++)
        {
            for (int k = 0; k < l; k++)
            {
                if (strcmp(flightID[k], get_passenger_flightID(passengers, i)))
                {
                    int num = 1;
                    if (inserirID(passengerID, num, get_passenger_userID(passengers, i)) == -1)
                    {
                        info[get_flight_scheduledDepartureDate_Day(flights, i)].n_passageiros_unicos++;
                        break;
                    }
                    else
                    {
                        info[get_flight_scheduledDepartureDate_Day(flights, i)].n_passageiros++;
                        break;
                    }
                    num++;
                }
            }
        }
        for (int i = 0; i < n_reservations; i++)
        {
            if (ano == get_reservation_beginData_Year(reservations, i) && mes == get_reservation_beginData_Month(reservations, i))
            {
                info[get_reservation_beginData_Day(reservations, i)].n_reservas++;
            }
        }
    }
    else if (mes == 0 && ano != 0)
    {
        set++;
        for (int i = 0; i < n_voos; i++)
        {
            if (ano == get_flight_scheduledArrivalDate_Year(flights, i))
            {
                strcpy(flightID[l], get_flight_id(flights, i));
                indice[l] = get_flight_scheduledDepartureDate_Month(flights, i);
                info[indice[l]].n_voos++;
                l++;
            }
        }
        for (int i = 0; i < n_users; i++)
        {
            if (ano == get_user_accountCreation_Year(users, i))
            {
                info[get_user_accountCreation_Month(users, i)].n_users++;
            }
        }
        for (int i = 0; i < n_passageiros; i++)
        {
            for (int k = 0; k < l; i++)
            {
                if (strcmp(flightID[k], get_passenger_flightID(passengers, i)))
                {
                    int num = 1;
                    if (inserirID(passengerID, num, get_passenger_userID(passengers, i)) == -1)
                    {
                        info[get_flight_scheduledDepartureDate_Month(flights, i)].n_passageiros_unicos++;
                        break;
                    }
                    else
                    {
                        info[get_flight_scheduledDepartureDate_Month(flights, i)].n_passageiros++;
                        break;
                    }
                    num++;
                }
            }
        }
        for (int i = 0; i < n_reservations; i++)
        {
            if (ano == get_reservation_beginData_Year(reservations, i) && mes == get_reservation_beginData_Month(reservations, i))
            {
                info[get_reservation_beginData_Month(reservations, i)].n_reservas++;
            }
        }
    }
    else if (ano == 0 && mes == 0)
    {
        set = 2;
        for (int i = 0; i < n_voos; i++)
        {
            strcpy(flightID[l], get_flight_id(flights, i));
            indice[l] = get_flight_scheduledDepartureDate_Year(flights, i);
            info[indice[l]].n_voos++;
            l++;
        }
        for (int i = 0; i < n_users; i++)
        {
            info[get_user_accountCreation_Year(users, i)].n_users++;
        }
        for (int i = 0; i < n_passageiros; i++)
        {
            for (int k = 0; k < l; k++)
            {
                if (strcmp(flightID[k], get_passenger_flightID(passengers, i)))
                {
                    int num = 1;
                    if (inserirID(passengerID, num, get_passenger_userID(passengers, i)) == -1)
                    {
                        info[get_flight_scheduledDepartureDate_Year(flights, i)].n_passageiros_unicos++;
                        break;
                    }
                    else
                    {
                        info[get_flight_scheduledDepartureDate_Year(flights, i)].n_passageiros++;
                        break;
                    }
                    num++;
                }
            }
        }
        for (int i = 0; i < n_reservations; i++)
        {
            info[get_reservation_beginData_Year(reservations, i)].n_reservas++;
        }
    }

    for (int i = 0; i < l; i++)
    {
        if (Size < indice[i])
        {
            Size = indice[i];
        }
    }

    char outputFileName[1024];
    sprintf(outputFileName, "Resultados/command%d_output.txt", counter);
    FILE *outputFile = fopen(outputFileName, "w");
    char *output = malloc(sizeof(char));
    output[0] = '\0';

    if (set == 0)
    {
        if (mode == 0)
        {
            printf("<[Year|Month|Day]> <n_users> <n_voos> <n_passageiros> <n_passageiros_unicos> <n_reservas>\n");
            for (int i = 0; i < Size; i++)
            {
                int new_line_size = snprintf(NULL, 0, "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                output = realloc(output, strlen(output) + new_line_size + 1);
                sprintf(output + strlen(output), "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
            }
            printf("%s", output);
        }
        else
        {
            if (flag)
            {
                for (int i = 0; i < Size; i++)
                {
                    if (i != Size - 1)
                    {
                        fprintf(outputFile, "--- %d ---\nday: %d\nn_users: %d\nn_voos: %d\nn_passageiros: %d\nn_passageiros_unicos: %d\nn_reservas: %d\n\n", (i + 1), (i + 1), info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                    }
                    else
                    {
                        fprintf(outputFile, "--- %d ---\nday: %d\nn_users: %d\nn_voos: %d\nn_passageiros: %d\nn_passageiros_unicos: %d\nn_reservas: %d\n", (i + 1), (i + 1), info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                    }
                }
            }
            else
            {
                for (int i = 0; i < Size; i++)
                {
                    fprintf(outputFile, "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                }
            }
        }
    }
    else if (set == 1)
    {
        if (mode == 0)
        {
            printf("<[Year|Month|Day]> <n_users> <n_voos> <n_passageiros> <n_passageiros_unicos> <n_reservas>\n");
            for (int i = 0; i < Size; i++)
            {
                int new_line_size = snprintf(NULL, 0, "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                output = realloc(output, strlen(output) + new_line_size + 1);
                sprintf(output + strlen(output), "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
            }
            printf("%s", output);
        }
        else
        {
            if (flag)
            {
                for (int i = 0; i < Size; i++)
                {
                    if (i != Size - 1)
                    {
                        fprintf(outputFile, "--- %d ---\nmonth: %d\nn_users: %d\nn_voos: %d\nn_passageiros: %d\nn_passageiros_unicos: %d\nn_reservas: %d\n\n", (i + 1), (i + 1), info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                    }
                    else
                    {
                        fprintf(outputFile, "--- %d ---\nmonth: %d\nn_users: %d\nn_voos: %d\nn_passageiros: %d\nn_passageiros_unicos: %d\nn_reservas: %d\n", (i + 1), (i + 1), info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                    }
                }
            }
            else
            {
                for (int i = 0; i < Size; i++)
                {
                    fprintf(outputFile, "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                }
            }
        }
    }
    else if (set == 2)
    {
        if (mode == 0)
        {
            printf("<[Year|Month|Day]> <n_users> <n_voos> <n_passageiros> <n_passageiros_unicos> <n_reservas>\n");
            for (int i = 0; i < Size; i++)
            {
                int new_line_size = snprintf(NULL, 0, "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                output = realloc(output, strlen(output) + new_line_size + 1);
                sprintf(output + strlen(output), "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
            }
            printf("%s", output);
        }
        else
        {
            if (flag)
            {
                for (int i = 0; i < Size; i++)
                {
                    if (i != Size - 1)
                    {
                        fprintf(outputFile, "--- %d ---\nyear: %d\nn_users: %d\nn_voos: %d\nn_passageiros: %d\nn_passageiros_unicos: %d\nn_reservas: %d\n\n", (i + 1), (i + 1), info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                    }
                    else
                    {
                        fprintf(outputFile, "--- %d ---\nyear: %d\nn_users: %d\nn_voos: %d\nn_passageiros: %d\nn_passageiros_unicos: %d\nn_reservas: %d\n", (i + 1), (i + 1), info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                    }
                }
            }
            else
            {
                for (int i = 0; i < Size; i++)
                {
                    fprintf(outputFile, "%d;%d;%d;%d;%d\n", info[i].n_users, info[i].n_voos, info[i].n_passageiros, info[i].n_passageiros_unicos, info[i].n_reservas);
                }
            }
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (mode == 1)
        printf("\n");
    if ((mode == 1) || (mode == 3))
        printf("Fim da Q10 - %f segundos (input nº %i)\n", cpu_time_used, counter);

    free(info);
    free(output);
    fclose(outputFile);
}