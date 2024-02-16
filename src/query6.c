#include "../include/query6.h"

struct Aeroporto
{
    char *id;
    int passageiros;
};

char *ajustaSigla2(char *str)
{
    char *original = str;

    while (*str)
    {
        *str = toupper((unsigned char)*str);
        str++;
    }

    return original;
}

int comparaPassageiros(const void *a, const void *b)
{
    const Airport *airport1 = (const Airport *)a;
    const Airport *airport2 = (const Airport *)b;

    if (airport1->passageiros > airport2->passageiros)
    {
        return -1;
    }
    else if (airport1->passageiros < airport2->passageiros)
    {
        return 1;
    }
    else
    {

        return strcmp(airport1->id, airport2->id);
    }
}

int inserirAeroporto2(Airport *aeroportos, int num, char *aeroporto_origem, char *aeroporto_destino)
{
    for (int i = 0; i < num; i++)
    {
        if ((strcmp(aeroportos[i].id, aeroporto_origem) == 0) || (strcmp(aeroportos[i].id, aeroporto_destino) == 0))
        {
            return i;
        }
    }
    return -1;
}

void query6(Flight *flight, Passenger *passengers, char *year, char *num_outputs, int counter, int mode)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    year[4] = '\0';
    int ano = atoi(year);
    int N = atoi(num_outputs);
    int s = sizeof(Airport);
    int n_aeroportos = 0;
    Airport *airports = malloc(n_voos * s);
    for (int i = 0; i < n_voos; i++)
    {
        if (ano == get_flight_scheduledDepartureDate_Year(flight, i))
        {
            char *flight_origin = get_flight_origin(flight, i);
            char *flight_destination = get_flight_destination(flight, i);
            char *flight_id = get_flight_id(flight, i);

            char *sigla_Aeroporto_origem = ajustaSigla(flight_origin);
            char *sigla_Aeroporto_destino = ajustaSigla(flight_destination); // Adicione essa linha para obter o aeroporto de destino
            int passageiros_voo = get_flight_passengers(flight_id, passengers);
            int index = inserirAeroporto2(airports, n_aeroportos, sigla_Aeroporto_origem, sigla_Aeroporto_destino);

            if (index != -1)
            {
                airports[index].passageiros += passageiros_voo;
            }
            else
            {
                airports[n_aeroportos].id = strdup(sigla_Aeroporto_origem);
                airports[n_aeroportos].passageiros += passageiros_voo;
                n_aeroportos++;
            }

            free(flight_origin);
            free(flight_destination);
            free(flight_id);
        }
    }

    qsort(airports, n_aeroportos, s, comparaPassageiros);

    char outputFileName[1024];
    sprintf(outputFileName, "Resultados/command%d_output.txt", counter);
    FILE *outputFile = fopen(outputFileName, "w");
    char *output = malloc(sizeof(char));
    output[0] = '\0';

    if (mode == 0)
    {
        printf("<Nome do Aeroporto> <Número total de Passageiros>\n");
        for (int i = 0; i < N && i < n_aeroportos; i++)
        {
            int new_line_size = snprintf(NULL, 0, "%s;%d\n\n", airports[i].id, airports[i].passageiros);
            output = realloc(output, strlen(output) + new_line_size + 1);
            sprintf(output + strlen(output), "%s;%d\n\n", airports[i].id, airports[i].passageiros);
        }
        printf("%s", output);
    }
    else
    {
        if (flag)
        {
            for (int i = 0; i < N && i < n_aeroportos; i++)
            {
                if (i != N - 1 && i != n_aeroportos - 1)
                {
                    fprintf(outputFile, "--- %d ---\nname: %s\npassengers: %d\n\n", (i + 1), airports[i].id, airports[i].passageiros);
                }
                else
                {
                    fprintf(outputFile, "--- %d ---\nname: %s\npassengers: %d\n", (i + 1), airports[i].id, airports[i].passageiros);
                }
            }
        }
        else
        {
            for (int i = 0; i < N && i < n_aeroportos; i++)
            {
                fprintf(outputFile, "%s;%d\n", airports[i].id, airports[i].passageiros);
            }
        }
    }

    fclose(outputFile);
    for (int i = 0; i < n_aeroportos; i++)
    {
        free(airports[i].id);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (mode == 1)
        printf("\n");
    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q6 - %f segundos (input nº %i)\n", cpu_time_used, counter);

    free(airports);
    free(output);
}