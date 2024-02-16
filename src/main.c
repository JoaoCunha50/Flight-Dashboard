#include "../include/main.h"
#include "../include/batch.h"
#include "../include/interactive.h"

int main(int argc, char *argv[])
{
    __clock_t start;

    if (argc == 1)
    {
        start = clock();
        system("mkdir Resultados");
        interactive();
    }

    else if (argc == 3)
    {
        start = clock();
        system("mkdir Resultados");
        puts("\nDiretório Resultados criado\n");
        puts("Número de argumentos válidos! (3)\n");
        batch(argv);
    }
    else
    {
        printf("\nNumero de argumentos invalido (%i).\n", argc);
        return -1;
    }

    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n\n", cpu_time_used);

    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory utilizada: %ld KB\n", r_usage.ru_maxrss);

    puts("");
    return 0;
}