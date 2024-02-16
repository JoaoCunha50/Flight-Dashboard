#include "../include/query5.h"

void query5(Flight *flight, int n_voos, char *aeroporto, char *begin_date, char *end_date, int counter, int mode)
{

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int s = SizeofFlights();
    Flight *voos_filtrados = malloc(n_voos * s);
    int Size = 0;
    aeroporto[3] = '\0';
    begin_date[19] = '\0';
    end_date[19] = '\0';
    for (int i = 0; i < n_voos; i++)
    {
        char *flight_origin = get_flight_origin(flight, i);
        if ((strcmp(ajustaSigla(flight_origin), aeroporto) == 0) && isFlightInRange(flight, i, begin_date, end_date))
        {
            copyVoo(voos_filtrados, flight, Size, i);
            Size++;
        }
        free(flight_origin);
    }

    qsort(voos_filtrados, Size, s, comparaVoos);

    char outputFileName[1024];
    sprintf(outputFileName, "Resultados/command%d_output.txt", counter);
    FILE *outputFile = fopen(outputFileName, "w");
    char *output = malloc(sizeof(char));
    output[0] = '\0';

    if (mode == 0)
    {
        printf("<ID> <Schedule Departure Date> <Destination> <Airline> <Plane Model>\n");
        for (int i = 0; i < Size; i++)
        {
            char *flight_id = get_flight_id(voos_filtrados, i);
            char *airline = get_flight_airline(voos_filtrados, i);
            char *planeModel = get_flight_planeModel(voos_filtrados, i);
            char *destination = ajustaSigla(get_flight_destination(voos_filtrados, i));
            int new_line_size = snprintf(NULL, 0, "%s;%d/%02d/%02d %02d:%02d:%02d;%s;%s;%s\n\n",
                                         flight_id,
                                         get_flight_scheduledDepartureDate_Year(voos_filtrados, i),
                                         get_flight_scheduledDepartureDate_Month(voos_filtrados, i),
                                         get_flight_scheduledDepartureDate_Day(voos_filtrados, i),
                                         get_flight_scheduledDepartureDate_Hour(voos_filtrados, i),
                                         get_flight_scheduledDepartureDate_Minutes(voos_filtrados, i),
                                         get_flight_scheduledDepartureDate_Seconds(voos_filtrados, i),
                                         destination,
                                         airline,
                                         planeModel);

            output = realloc(output, strlen(output) + new_line_size + 1);

            sprintf(output + strlen(output), "%s;%d/%02d/%02d %02d:%02d:%02d;%s;%s;%s\n\n",
                    flight_id,
                    get_flight_scheduledDepartureDate_Year(voos_filtrados, i),
                    get_flight_scheduledDepartureDate_Month(voos_filtrados, i),
                    get_flight_scheduledDepartureDate_Day(voos_filtrados, i),
                    get_flight_scheduledDepartureDate_Hour(voos_filtrados, i),
                    get_flight_scheduledDepartureDate_Minutes(voos_filtrados, i),
                    get_flight_scheduledDepartureDate_Seconds(voos_filtrados, i),
                    destination,
                    airline,
                    planeModel);

            free(flight_id);
            free(airline);
            free(planeModel);
            free(destination);
        }
        printf("%s", output);
    }
    else
    {
        if (flag)
        {
            for (int i = 0; i < Size; i++)
            {
                char *flight_id = get_flight_id(voos_filtrados, i);
                char *airline = get_flight_airline(voos_filtrados, i);
                char *planeModel = get_flight_planeModel(voos_filtrados, i);
                char *destination = ajustaSigla(get_flight_destination(voos_filtrados, i));
                if (i != Size - 1)
                {
                    fprintf(outputFile, "--- %d ---\nid: %s\nschedule_departure_date: %d/%02d/%02d %02d:%02d:%02d\ndestination: %s\nairline: %s\nplane_model: %s\n\n", (i + 1),
                            flight_id,
                            get_flight_scheduledDepartureDate_Year(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Month(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Day(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Hour(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Minutes(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Seconds(voos_filtrados, i),
                            destination, airline, planeModel);
                }
                else
                {
                    fprintf(outputFile, "--- %d ---\nid: %s\nschedule_departure_date: %d/%02d/%02d %02d:%02d:%02d\ndestination: %s\nairline: %s\nplane_model: %s\n", (i + 1), flight_id,
                            get_flight_scheduledDepartureDate_Year(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Month(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Day(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Hour(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Minutes(voos_filtrados, i),
                            get_flight_scheduledDepartureDate_Seconds(voos_filtrados, i),
                            destination, airline, planeModel);
                }
                free(flight_id);
                free(airline);
                free(planeModel);
                free(destination);
            }
        }
        else
        {
            for (int i = 0; i < Size; i++)
            {
                char *flight_id = get_flight_id(voos_filtrados, i);
                char *airline = get_flight_airline(voos_filtrados, i);
                char *planeModel = get_flight_planeModel(voos_filtrados, i);
                char *destination = ajustaSigla(get_flight_destination(voos_filtrados, i));
                fprintf(outputFile, "%s;%d/%02d/%02d %02d:%02d:%02d;%s;%s;%s\n", flight_id,
                        get_flight_scheduledDepartureDate_Year(voos_filtrados, i),
                        get_flight_scheduledDepartureDate_Month(voos_filtrados, i),
                        get_flight_scheduledDepartureDate_Day(voos_filtrados, i),
                        get_flight_scheduledDepartureDate_Hour(voos_filtrados, i),
                        get_flight_scheduledDepartureDate_Minutes(voos_filtrados, i),
                        get_flight_scheduledDepartureDate_Seconds(voos_filtrados, i),
                        destination, airline, planeModel);

                free(flight_id);
                free(airline);
                free(planeModel);
                free(destination);
            }
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (mode == 1)
        printf("\n");
    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q5 - %f segundos (input nº %i)\n", cpu_time_used, counter);

    freeflightsQ(voos_filtrados, Size);
    fclose(outputFile);
    free(output);
}
