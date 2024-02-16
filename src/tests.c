#include "../include/tests.h"


User *user_test;
Flight *flight_test;
Reservation *reservation_test;
Passenger *passenger_test;

bool compare(FILE *file1, FILE *file2, int *linha)
{
    int ch1, ch2;
    int same = 1;
    *linha = 1;

    while (((ch1 = fgetc(file1)) != EOF) && ((ch2 = fgetc(file2)) != EOF))
    {
        if (ch1 != ch2)
        {
            same = 0;
            break;
        }
        if (ch1 == '\n')
        {
            (*linha)++;
        }
    }
    if (same)
    {
        if (fgetc(file1) == EOF && fgetc(file2) == EOF)
            same = 1;
        else
            same = 0;
    }
    return same;
}

void check(int counter)
{
    char filename[30], filepath[60], resultfile[50];
    sprintf(filename, "command%d_output.txt", counter);
    sprintf(resultfile, "Resultados/%s", filename);

    sprintf(filepath, "test-outputs/%s", filename);

    FILE *expected = fopen(filepath, "r");
    FILE *result = fopen(resultfile, "r");
    int line_number = 1;
    if (compare(expected, result, &line_number))
        printf("Test %d passed ✅\n", counter);
    else
        printf("Test %d failed at line %d ❌\n", counter, line_number);
    fclose(expected);
    fclose(result);
}

void noOutput(int counter)
{
    printf("Test %d not found ⏸\n", counter);
}

void q1_test(Flight *flight, Reservation *reserva, User *user, Passenger *passenger, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query1(flight, reserva, user, passenger, input + 3, counter, 3);
    }
    else
    {
        flag = 0;
        query1(flight, reserva, user, passenger, input + 2, counter, 3);
    }
    check(counter);
}

void q2_test(Flight *flight, Reservation *reserva, User *user, Passenger *passenger, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query2(passenger, user, flight, reserva, input + 3, counter, 3);
    }
    else
    {
        flag = 0;
        query2(passenger, user, flight, reserva, input + 2, counter, 3);
    }
    check(counter);
}

void q3_test(Reservation *reserva, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query3(reserva, input + 3, counter, 3);
    }
    else
    {
        flag = 0;
        query3(reserva, input + 2, counter, 3);
    }
    check(counter);
}

void q4_test(Reservation *reserva, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query4(reserva, input + 3, counter, 1);
    }
    else
    {
        flag = 0;
        query4(reserva, input + 2, counter, 1);
    }
    check(counter);
}

void q5_test(Flight *flight, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query5(flight, n_voos, input + 3, input + 8, input + 30, counter, 3);
    }
    else
    {
        flag = 0;
        query5(flight, n_voos, input + 2, input + 7, input + 29, counter, 3);
    }
    check(counter);
}

void q7_test(Flight *flight, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query7(flight, n_voos, input + 2, counter, 3);
    }
    else
    {
        flag = 0;
        query7(flight, n_voos, input + 2, counter, 3);
    }
    check(counter);
}

void q8_test(Reservation *reserva, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query8(reserva, input + 3, input + 11, input + 22, counter, 3);
    }
    else
    {
        flag = 0;
        query8(reserva, input + 2, input + 10, input + 21, counter, 3);
    }
    check(counter);
}

void q9_test(User *user, int counter, char *input)
{
    if (input[1] == 'F')
    {
        flag = 1;
        query9(user, n_users, input + 3, counter, 3);
    }
    else
    {
        flag = 0;
        query9(user, n_users, input + 2, counter, 3);
    }
    check(counter);
}

int main()
{
    system("clear");
    puts("\t\t\t\t\t\t\t **** MODO DE TESTES ****\n");
    clock_t start = clock();

    puts("Bem-vindo ao Programa de Testes! Para continuar, coloque o caminho do diretório dos ficheiros CSV!.\n");
    printf("Diretório: ");
    char caminho[200];
    scanf("%s", caminho);

    system("mkdir ErrosTestes");
    FILE *flights_file = open_files(caminho, "/flights.csv");
    FILE *passengers_file = open_files(caminho, "/passengers.csv");
    FILE *reservations_file = open_files(caminho, "/reservations.csv");
    FILE *users_file = open_files(caminho, "/users.csv");
    FILE *inputs = fopen("test-outputs/inputs.txt", "r");
    FILE *flights_errors = fopen("ErrosTestes/flights_errors.csv", "w");
    if (flights_errors == NULL)
        return 0;
    FILE *passengers_errors = fopen("ErrosTestes/passengers_errors.csv", "w");
    if (passengers_errors == NULL)
        return 0;
    FILE *reservations_errors = fopen("ErrosTestes/reservations_errors.csv", "w");
    if (reservations_errors == NULL)
        return 0;
    FILE *users_errors = fopen("ErrosTestes/users_errors.csv", "w");
    if (users_errors == NULL)
        return 0;

    system("mkdir Resultados");

    user_test = ParseUsers(users_file, users_errors, user_test);
    flight_test = ParseFlights(flights_file, flights_errors, flight_test);
    passenger_test = ParsePassengers(passengers_file, passengers_errors, passenger_test);
    reservation_test = ParseReservations(reservations_file, reservations_errors, reservation_test);

    fclose(flights_file);
    if (flights_file != NULL)
        puts("Ficheiro dos Voos fechado.");
    fclose(passengers_file);
    if (passengers_file != NULL)
        puts("Ficheiro dos Passageiros fechado.");
    fclose(reservations_file);
    if (reservations_file != NULL)
        puts("Ficheiro das Reservas fechado.");
    fclose(users_file);
    if (users_file != NULL)
        puts("Ficheiro dos Usuários fechado.");

    fclose(flights_errors);
    fclose(passengers_errors);
    fclose(users_errors);
    fclose(reservations_errors);

    int counter = 1;

    char *input;
    input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs))
    {
        if (strchr(input, '\n'))
            *(strchr(input, '\n')) = '\0';
        puts("-----------------------------------------------");
        printf("Input: %s\n", input);
        if (input[0] == '1' && input[1] != '0')
            q1_test(flight_test, reservation_test, user_test, passenger_test, counter, input);
        else if (input[0] == '2')
            q2_test(flight_test, reservation_test, user_test, passenger_test, counter, input);
        else if (input[0] == '3')
            q3_test(reservation_test, counter, input);
        else if (input[0] == '4')
            q4_test(reservation_test, counter, input);
        else if (input[0] == '5')
            q5_test(flight_test, counter, input);
        else if (input[0] == '6')
            noOutput(counter);
        else if (input[0] == '7')
            q7_test(flight_test, counter, input);
        else if (input[0] == '8')
            q8_test(reservation_test, counter, input);
        else if (input[0] == '9')
            q9_test(user_test, counter, input);
        else if (input[0] == '1' && input[1] == '0')
            noOutput(counter);

        counter++;
    }

    free_flights(flight_test);
    free_passageiros(passenger_test);
    freeReservation(reservation_test);
    freeUser(user_test);
    free(input);
    fclose(inputs);
    system("rm -r Resultados");
    puts("-------------------------------------------");

    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("O Programa Acabou em %f segundos!\n", cpu_time_used);

    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory utilizada pelo programa de testes: %ld KB\n\n", r_usage.ru_maxrss);

    return 1;
}