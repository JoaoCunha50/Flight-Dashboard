#include "../include/interactive.h"

User *user1;
Flight *flight1;
Reservation *reservation1;
Passenger *passenger1;

void interactive()
{
    setlocale(LC_COLLATE, "en_US.UTF-8");
    system("clear");
    puts("\t\t\t\t\t\t\t **** MODO INTERATIVO ****\n");
    // puts("--------------------------------------------------------------------------------------------------------------");
    puts("Bem-vindo ao modo Interativo! Para continuar, indique o caminho do diretório que contém os ficheiros CSV.\n");
    printf("Diretório: ");
    char path[150];
    scanf("%s", path);

    printf("\n\t --- Abertura dos Ficheiros ---\n");
    printf("\n");
    FILE *flights_file = open_files(path, "/flights.csv");
    FILE *passengers_file = open_files(path, "/passengers.csv");
    FILE *reservations_file = open_files(path, "/reservations.csv");
    FILE *users_file = open_files(path, "/users.csv");

    FILE *flights_errors = fopen("Resultados/flights_errors.csv", "w");
    if (flights_errors == NULL)
        return;
    FILE *passengers_errors = fopen("Resultados/passengers_errors.csv", "w");
    if (passengers_errors == NULL)
        return;
    FILE *reservations_errors = fopen("Resultados/reservations_errors.csv", "w");
    if (reservations_errors == NULL)
        return;
    FILE *users_errors = fopen("Resultados/users_errors.csv", "w");
    if (users_errors == NULL)
        return;

    if ((flights_file == NULL) || (passengers_file == NULL) || (reservations_file == NULL) || (users_file == NULL))
    {
        puts("\nErro na abertura de pelo menos um dos ficheiros! Verifica o caminho introduzido.");
        return;
    }
    printf("\n\t --- Parsing dos Ficheiros --- \n");
    printf("\n");
    user1 = ParseUsers(users_file, users_errors, user1);
    flight1 = ParseFlights(flights_file, flights_errors, flight1);
    passenger1 = ParsePassengers(passengers_file, passengers_errors, passenger1);
    reservation1 = ParseReservations(reservations_file, reservations_errors, reservation1);

    printf("\n");
    printf("\t --- Fecho dos Ficheiros --- \n");
    printf("\n");
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

    printf("\n");
    puts("\nPerfeito, agora insere os input's (1 de cada vez) da seguinte forma: <query> <arg1> <arg2> <arg3>. Exemplo: 1 EdSousa");
    puts("\tPara sair do modo Interativo basta digitar <exit>\n");
    handle_input(reservation1, flight1, user1, passenger1);

    free_flights(flight1);
    free_passageiros(passenger1);
    freeReservation(reservation1);
    freeUser(user1);
}