#include "../include/query7.h"

struct Aeroporto
{
    char *id;
    int voos;
    int mediana;
    int *atrasos;
};

int inserirAeroporto(Airport *aeroportos, int num, char *aeroporto)
{
    for (int i = 0; i < num; i++)
    {
        if (strcmp(aeroportos[i].id, aeroporto) == 0)
        {
            return i;
        }
    }
    return -1;
}

int comparaMediana(const void *a, const void *b)
{
    const Airport *airport1 = (const Airport *)a;
    const Airport *airport2 = (const Airport *)b;
    if (airport1->mediana != airport2->mediana)
    {
        return airport2->mediana - airport1->mediana;
    }

    return strcmp(airport1->id, airport2->id);
}

void query7(Flight *flight, int n_voos, char *numero_outputs, int counter, int mode)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int N = atoi(numero_outputs);
    int s = sizeof(Airport);
    int n_aeroportos = 0;
    Airport *airports = malloc(n_voos * s);
    for (int i = 0; i < n_voos; i++)
    {
        char *flight_origin = get_flight_origin(flight,i);
        char *sigla_Aeroporto = ajustaSigla(flight_origin); // algumas siglas estavam em Minusuclas, por isso metemos todas em maiusculas
        
        int delay = get_delay(flight, i);                                  // calcula o delay de cada voo
        int index = inserirAeroporto(airports, n_aeroportos, sigla_Aeroporto);

        if (index != -1)
        {
            airports[index].voos++;
            int last_flight = airports[index].voos - 1; // -1 pois começa em 0
            int n_voos_aeroporto = airports[index].voos;
            airports[index].atrasos = realloc(airports[index].atrasos, n_voos_aeroporto * sizeof(int));
            airports[index].atrasos[last_flight] = delay;
        }
        else
        {
            airports[n_aeroportos].id = strdup(sigla_Aeroporto);
            airports[n_aeroportos].atrasos = calloc(1, sizeof(int));
            airports[n_aeroportos].atrasos[0] = delay;
            airports[n_aeroportos].voos = 1;
            n_aeroportos++;
        }
        free(flight_origin);
    }

    for (int i = 0; i < n_aeroportos; i++)
    {
        airports[i].mediana = calculaMediana(airports[i].atrasos, airports[i].voos);
    }

    // tal como noutras queries usamos o qsort para ordenar o array de structs
    qsort(airports, n_aeroportos, s, comparaMediana);

    // Preparar os outputs
    char outputFileName[1024];
    sprintf(outputFileName, "Resultados/command%d_output.txt", counter);
    FILE *outputFile = fopen(outputFileName, "w");
    char *output = malloc(sizeof(char));
    output[0] = '\0';

    // Modo iterativo
    if (mode == 0)
    {
        printf("<Nome do Aeroporto> <Mediana>\n");
        for (int i = 0; i < N && i < n_aeroportos; i++)
        {
            int new_line_size = snprintf(NULL, 0, "%s;%d\n\n", airports[i].id, airports[i].mediana);
            output = realloc(output, strlen(output) + new_line_size + 1);
            sprintf(output + strlen(output), "%s;%d\n\n", airports[i].id, airports[i].mediana);
        }
        printf("%s", output);
    }
    else // modo batch
    {
        if (flag)
        {
            for (int i = 0; i < N && i < n_aeroportos; i++)
            {
                if (i != N - 1 && i != n_aeroportos - 1)
                {
                    fprintf(outputFile, "--- %d ---\nname: %s\nmedian: %d\n\n", (i + 1), airports[i].id, airports[i].mediana);
                }
                else
                {
                    fprintf(outputFile, "--- %d ---\nname: %s\nmedian: %d\n", (i + 1), airports[i].id, airports[i].mediana);
                }
            }
        }
        else
        {
            for (int i = 0; i < N && i < n_aeroportos; i++)
            {
                fprintf(outputFile, "%s;%d\n", airports[i].id, airports[i].mediana);
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (mode == 1)
        printf("\n");
    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q7 - %f segundos (input nº %i)\n", cpu_time_used, counter);

    free(output);

    for (int i = 0; i < n_aeroportos; i++)
    {
        free(airports[i].atrasos);
        free(airports[i].id);
    }

    free(airports);
    fclose(outputFile);
}
