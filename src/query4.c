#include "../include/query4.h"
void query4(Reservation *reservation, char *id, int counter, int mode)
{

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int s = SizeofReservations();
    Reservation *reservas_filtradas = malloc(1000* s);
    int Size = 0;

    for (int i = 0; i < n_reservations; i++)
    {
        char *hotelID = get_reservation_hotelID(reservation, i);
        if (strcmp(hotelID, id) == 0)
        {
            copyReservation(reservas_filtradas, reservation, Size, i);
            Size++;
        }
        free(hotelID);
    }

    qsort(reservas_filtradas, Size, s, comparaReservas);

    char nomeOutput[100];
    sprintf(nomeOutput, "Resultados/command%d_output.txt", counter);
    FILE *output_file = fopen(nomeOutput, "w");
    char *output = NULL;
    output = (char *)malloc(1000000);
    if (mode == 1)
    {
        for (int i = 0; i < Size; i++)
        {
            char *reservation_id = get_reservation_id(reservas_filtradas, i);
            char *userID = get_reservation_userID(reservas_filtradas, i);
            if (flag == 0)
            {
                fprintf(output_file, "%s;%02d/%02d/%02d;%02d/%02d/%02d;%s;%d;%.3f\n",
                        reservation_id,
                        get_reservation_beginData_Year(reservas_filtradas, i),
                        get_reservation_beginData_Month(reservas_filtradas, i),
                        get_reservation_beginData_Day(reservas_filtradas, i),
                        get_reservation_endData_Year(reservas_filtradas, i),
                        get_reservation_endData_Month(reservas_filtradas, i),
                        get_reservation_endData_Day(reservas_filtradas, i),
                        userID,
                        get_reservation_rating(reservas_filtradas, i),
                        calculaTotalPrice(reservas_filtradas, i));
            }
            else
            {
                if (i != Size - 1)
                {
                    fprintf(output_file, "--- %d ---\nid: %s\nbegin_date: %02d/%02d/%02d\nend_date: %02d/%02d/%02d\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n\n",
                            i + 1,
                            reservation_id,
                            get_reservation_beginData_Year(reservas_filtradas, i),
                            get_reservation_beginData_Month(reservas_filtradas, i),
                            get_reservation_beginData_Day(reservas_filtradas, i),
                            get_reservation_endData_Year(reservas_filtradas, i),
                            get_reservation_endData_Month(reservas_filtradas, i),
                            get_reservation_endData_Day(reservas_filtradas, i),
                            userID,
                            get_reservation_rating(reservas_filtradas, i),
                            calculaTotalPrice(reservas_filtradas, i));
                }
                else
                {
                    fprintf(output_file, "--- %d ---\nid: %s\nbegin_date: %02d/%02d/%02d\nend_date: %02d/%02d/%02d\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n",
                            i + 1,
                            reservation_id,
                            get_reservation_beginData_Year(reservas_filtradas, i),
                            get_reservation_beginData_Month(reservas_filtradas, i),
                            get_reservation_beginData_Day(reservas_filtradas, i),
                            get_reservation_endData_Year(reservas_filtradas, i),
                            get_reservation_endData_Month(reservas_filtradas, i),
                            get_reservation_endData_Day(reservas_filtradas, i),
                            userID,
                            get_reservation_rating(reservas_filtradas, i),
                            calculaTotalPrice(reservas_filtradas, i));
                }
            }
            free(reservation_id);
            free(userID);
        }
    }
    else if (mode == 0)
    {
        printf("<ID> <Início da Reserva> <Fim da Reserva> <User ID> <Rating> <Preço Total>\n");
        for (int i = 0; i < Size; i++)
        {
            char *reservation_id = get_reservation_id(reservas_filtradas, i);
            char *userID = get_reservation_userID(reservas_filtradas, i);
            int new_line_size = snprintf(NULL, 0, "%s;%02d/%02d/%02d;%02d/%02d/%02d;%s;%d;%.3f\n\n",
                                         reservation_id,
                                         get_reservation_beginData_Year(reservas_filtradas, i),
                                         get_reservation_beginData_Month(reservas_filtradas, i),
                                         get_reservation_beginData_Day(reservas_filtradas, i),
                                         get_reservation_endData_Year(reservas_filtradas, i),
                                         get_reservation_endData_Month(reservas_filtradas, i),
                                         get_reservation_endData_Day(reservas_filtradas, i),
                                         userID,
                                         get_reservation_rating(reservas_filtradas, i),
                                         calculaTotalPrice(reservas_filtradas, i));

            output = realloc(output, strlen(output) + new_line_size + 1);

            sprintf(output + strlen(output), "%s;%02d/%02d/%02d;%02d/%02d/%02d;%s;%d;%.3f\n\n",
                    reservation_id,
                    get_reservation_beginData_Year(reservas_filtradas, i),
                    get_reservation_beginData_Month(reservas_filtradas, i),
                    get_reservation_beginData_Day(reservas_filtradas, i),
                    get_reservation_endData_Year(reservas_filtradas, i),
                    get_reservation_endData_Month(reservas_filtradas, i),
                    get_reservation_endData_Day(reservas_filtradas, i),
                    userID,
                    get_reservation_rating(reservas_filtradas, i),
                    calculaTotalPrice(reservas_filtradas, i));

            free(reservation_id);
            free(userID);
        }
        printf("%s", output);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (mode == 1)
        printf("\n");

    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q4 - %f segundos (input nº %i)\n", cpu_time_used, counter);

    freereservationQ(reservas_filtradas, Size);
    free(output);
    fclose(output_file);
}
