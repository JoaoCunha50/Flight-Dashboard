#include "../include/query8.h"
#include "../include/interpreter.h"

void query8(Reservation *booking, char *hotel_id, char *begin_date, char *end_date, int counter, int mode)
{

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    hotel_id[7] = '\0';
    begin_date[10] = '\0';
    int *n = calloc(100, sizeof(int));
    int *n_nights = calloc(n_reservations, sizeof(int));
    int revenue = 0;
    
    char *output;
    output = malloc(sizeof(char) * 25);
    int price = get_hotel_price_per_night(booking, hotel_id, begin_date, end_date, n, n_nights);
    char outputFileName[1024];
    sprintf(outputFileName, "Resultados/command%d_output.txt", counter);
    FILE *outputFile = fopen(outputFileName, "w");

    for (int i = 0; i < n[0]; i++)
    {
        if (n_nights[i] != 0)
        {
            revenue += (price)*n_nights[i];
        }
    }
    sprintf(output, "%d", revenue);
    if (mode == 0)
    {
        printf("<Revenue>\n");
        printf("%s\n", output);
    }
    else
    {
        if (flag)
        {
            fprintf(outputFile, "--- 1 ---\nrevenue: %d\n", revenue);
        }
        else
            fprintf(outputFile, "%d\n", revenue);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (mode == 1)
        printf("\n");
    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q8 - %f segundos (input nº %i)\n", cpu_time_used, counter);
    
    fclose(outputFile);    
    free(n);
    free(n_nights);
    free(output);
}
