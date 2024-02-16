#include "../include/query2.h"

struct info
{
    char id[20];
    int ano;
    int mes;
    int dia;
    char tipo[15];
};

int comparar_infos_decrescente(const void *a, const void *b)
{
    const struct info *info_a = (const struct info *)a;
    const struct info *info_b = (const struct info *)b;

    if (info_a->ano != info_b->ano)
    {
        return info_b->ano - info_a->ano;
    }
    else if (info_a->mes != info_b->mes)
    {
        return info_b->mes - info_a->mes;
    }
    else if (info_a->dia != info_b->dia)
    {
        return info_b->dia - info_a->dia;
    }

    return strcmp(info_a->id, info_b->id);
}

void copyinfo(Info *user, Flight *flight, int i, int s)
{
    char *id = get_flight_id(flight, i);
    strcpy(user[s].id, id);
    user[s].ano = copyDataAno(flight, user[s].ano, i);
    user[s].mes = copyDataMes(flight, user[s].mes, i);
    user[s].dia = copyDataDia(flight, user[s].dia, i);

    free(id);
}

void copyinfo1(Info *user, Reservation *reservation, int i, int s)
{
    char *id = get_reservation_id(reservation, i);
    strcpy(user[s].id, id);
    user[s].ano = copyDataAno1(reservation, user[s].ano, i);
    user[s].mes = copyDataMes1(reservation, user[s].mes, i);
    user[s].dia = copyDataDia1(reservation, user[s].dia, i);

    free(id);
}

void query2(Passenger *passengers, User *users, Flight *flights, Reservation *reservations, char *arg, int counter, int mode)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    Info *user = malloc(sizeof(Info) * 500);
    int set = 0;
    int valid = 0;
    char *id = malloc(sizeof(char) * 30);
    char *opcao = malloc(sizeof(char) * 20);

    char *chave;
    char *temp = strdup(arg);
    char *aux = temp;

    chave = strsep(&aux, " ");
    strcpy(id, chave);
    if (aux != NULL)
    {
        strcpy(opcao, aux);
    }
    free(temp);

    int Size = 0;
    int Size1 = 0;
    int l = 0;

    char outputFileName[1024];
    sprintf(outputFileName, "Resultados/command%d_output.txt", counter);
    FILE *outputFile = fopen(outputFileName, "w");
    char *output = malloc(sizeof(char));
    output[0] = '\0';

    for (l = 0; l < n_users; l++)
    {
        char *user_id = get_user_id(users, l);
        char *account_status = get_user_accountStatus(users, l);
        if (strcmp(user_id, id) == 0 && strcmp(account_status, "INACTIVE\n") == 0)
        {
            fprintf(outputFile, "%s", "");
            fclose(outputFile);
            free(user_id);
            free(account_status);
            free(user);
            free(id);
            free(opcao);
            free(output);
            return;
        }
        free(user_id);
        free(account_status);
    }

    if (strcmp(opcao, "flights") == 0)
    {
        char flightID[100][15];
        valid++;

        for (int i = 0; i < n_passageiros; i++)
        {
            char *passenger_userID = get_passenger_userID(passengers, i);
            if (strcmp(passenger_userID, id) == 0)
            {
                char *passenger_flightID = get_passenger_flightID(passengers, i);
                strcpy(flightID[Size1], passenger_flightID);
                Size1++;
                free(passenger_flightID);
            }
            free(passenger_userID);
        }

        for (int i = 0; i < n_voos; i++)
        {
            char *flight_ID = get_flight_id(flights, i);
            for (int k = 0; k < Size1; k++)
            {
                if (strcmp(flight_ID, flightID[k]) == 0)
                {
                    copyinfo(user, flights, i, Size);
                    Size++;
                }
            }
            free(flight_ID);
        }
    }

    if (strcmp(opcao, "reservations") == 0 && valid == 0)
    {
        valid++;
        for (int i = 0; i < n_reservations; i++)
        {
            char *userID = get_reservation_userID(reservations, i);
            if (strcmp(userID, id) == 0)
            {
                copyinfo1(user, reservations, i, Size);
                Size++;
            }
            free(userID);
        }
    }
    else if ((strcmp(opcao, "reservations") != 0) && (strcmp(opcao, "reservations") != 0) && valid == 0)
    {
        valid++;
        char flightID[100][15];
        set++;

        for (int i = 0; i < n_passageiros; i++)
        {
            char *passenger_userID = get_passenger_userID(passengers, i);
            if (strcmp(passenger_userID, id) == 0)
            {
                char *passenger_flightID = get_passenger_flightID(passengers, i);
                strcpy(flightID[Size1], passenger_flightID);
                Size1++;
                free(passenger_flightID);
            }
            free(passenger_userID);
        }

        for (int i = 0; i < n_voos; i++)
        {
            char *flight_ID = get_flight_id(flights, i);
            for (int k = 0; k < Size1; k++)
            {
                if (strcmp(flight_ID, flightID[k]) == 0)
                {
                    copyinfo(user, flights, i, Size);
                    strcpy(user[Size].tipo, "flight");
                    Size++;
                }
            }
            free(flight_ID);
        }
        for (int i = 0; i < n_reservations; i++)
        {
            char *reservation_userID = get_reservation_userID(reservations, i);
            if (strcmp(reservation_userID, id) == 0)
            {
                copyinfo1(user, reservations, i, Size);
                strcpy(user[Size].tipo, "reservation");
                Size++;
            }
            free(reservation_userID);
        }
    }
    qsort(user, Size, sizeof(Info), comparar_infos_decrescente);

    if (set == 0)
    {
        if (mode == 0)
        {
            printf("<ID> <Date>\n");
            for (int i = 0; i < Size; i++)
            {
                int new_line_size = snprintf(NULL, 0, "%s;%02d/%02d/%02d;\n", user[i].id, user[i].ano, user[i].mes, user[i].dia);
                output = realloc(output, strlen(output) + new_line_size + 1);
                sprintf(output + strlen(output), "%s;%02d/%02d/%02d;\n", user[i].id, user[i].ano, user[i].mes, user[i].dia);
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
                        fprintf(outputFile, "--- %d ---\nid: %s\ndate: %02d/%02d/%02d\n\n", (i + 1), user[i].id, user[i].ano, user[i].mes, user[i].dia);
                    }
                    else
                    {
                        fprintf(outputFile, "--- %d ---\nid: %s\ndate: %02d/%02d/%02d\n", (i + 1), user[i].id, user[i].ano, user[i].mes, user[i].dia);
                    }
                }
            }
            else
            {
                for (int i = 0; i < Size; i++)
                {
                    fprintf(outputFile, "%s;%02d/%02d/%02d\n", user[i].id, user[i].ano, user[i].mes, user[i].dia);
                }
            }
        }
    }
    else
    {
        if (mode == 0)
        {
            printf("<ID> <Date>\n");
            for (int i = 0; i < Size; i++)
            {
                int new_line_size = snprintf(NULL, 0, "%s;%02d/%02d/%02d;%s\n", user[i].id, user[i].ano, user[i].mes, user[i].dia, user[i].tipo);
                output = realloc(output, strlen(output) + new_line_size + 1);
                sprintf(output + strlen(output), "%s;%02d/%02d/%02d;%s\n", user[i].id, user[i].ano, user[i].mes, user[i].dia, user[i].tipo);
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
                        fprintf(outputFile, "--- %d ---\nid: %s\ndate: %02d/%02d/%02d\ntype: %s\n\n", (i + 1), user[i].id, user[i].ano, user[i].mes, user[i].dia, user[i].tipo);
                    }
                    else
                    {
                        fprintf(outputFile, "--- %d ---\nid: %s\ndate: %02d/%02d/%02d\ntype: %s\n", (i + 1), user[i].id, user[i].ano, user[i].mes, user[i].dia, user[i].tipo);
                    }
                }
            }
            else
            {
                for (int i = 0; i < Size; i++)
                {
                    fprintf(outputFile, "%s;%02d/%02d/%02d;%s\n", user[i].id, user[i].ano, user[i].mes, user[i].dia, user[i].tipo);
                }
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (mode == 1)
        printf("\n");
    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q2 - %f segundos (input nº %i)\n", cpu_time_used, counter);

    free(user);
    free(output);
    free(id);
    free(opcao);
    fclose(outputFile);
}
