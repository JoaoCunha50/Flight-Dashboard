#include "../include/batch.h"

User *user;
Flight *flight;
Reservation *reservation;
Passenger *passenger;

void batch(char **argv)
{
    FILE *passengers = open_files(argv[1], "/passengers.csv");
    if (passengers == NULL)
        return;
    FILE *passengers_errors = fopen("Resultados/passengers_errors.csv", "w");
    if (passengers_errors == NULL)
        return;
    FILE *users = open_files(argv[1], "/users.csv");
    if (users == NULL)
        return;
    FILE *users_errors = fopen("Resultados/users_errors.csv", "w");
    if (users_errors == NULL)
        return;
    FILE *flights = open_files(argv[1], "/flights.csv");
    if (flights == NULL)
        return;
    FILE *flights_errors = fopen("Resultados/flights_errors.csv", "w");
    if (flights_errors == NULL)
        return;
    FILE *reservations = open_files(argv[1], "/reservations.csv");
    if (reservations == NULL)
        return;
    FILE *reservations_errors = fopen("Resultados/reservations_errors.csv", "w");
    if (reservations_errors == NULL)
        return;
    FILE *inputs;
    inputs = open_files(argv[2], "");
    if (inputs == NULL)
        return;

    user = ParseUsers(users, users_errors, user);
    flight = ParseFlights(flights, flights_errors, flight);
    passenger = ParsePassengers(passengers, passengers_errors, passenger);
    reservation = ParseReservations(reservations, reservations_errors, reservation);

    fclose(passengers);
    puts("\nFicheiro dos Passengers fechado");
    fclose(passengers_errors);
    puts("\nFicheiro dos Passengers errors fechado");
    fclose(users);
    puts("\nFicheiro dos Users fechado");
    fclose(users_errors);
    puts("\nFicheiro dos users errors fechado");
    fclose(flights);
    puts("\nFicheiro dos Flights fechado");
    fclose(flights_errors);
    puts("\nFicheiro dos flights errors fechado");
    fclose(reservations);
    puts("\nFicheiro das Reservations fechado");
    fclose(reservations_errors);
    puts("\nFicheiro dos reservations errors fechado");

    handle_inputs(reservation, flight, user, passenger, inputs);

    free_flights(flight);
    free_passageiros(passenger);
    freeReservation(reservation);
    freeUser(user); 
    
    fclose(inputs);
    if (inputs != NULL)
        puts("\nFicheiro dos Inputs fechado\n");
}
