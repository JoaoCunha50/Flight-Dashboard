/*
Modulo responsável por ler o ficheiro de comandos,
interpretar cada um, e executar a respetiva query com os argumentos indicados (se existirem);
*/
#include "../include/interpreter.h"

int flag = 0;
void handle_inputs(Reservation *reservation, Flight *flight, User *user, Passenger *passenger, FILE *inputs)
{

    int counter = 1;
    char *input;
    input = malloc(100 * sizeof(char));

    while (fgets(input, 100, inputs))
    {
        if (strchr(input, '\n'))
            *(strchr(input, '\n')) = '\0';

        if (input[0] == '1' && input[1] != '0')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query1(flight, reservation, user, passenger, input + 3, counter, 1);
            }
            else
            {
                flag = 0;
                query1(flight, reservation, user, passenger, input + 2, counter, 1);
            }
        }
        else if (input[0] == '3')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query3(reservation, input + 3, counter, 1);
            }
            else
            {
                flag = 0;
                query3(reservation, input + 2, counter, 1);
            }
        }
        else if (input[0] == '8')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query8(reservation, input + 3, input + 11, input + 22, counter, 1);
            }
            else
            {
                flag = 0;
                query8(reservation, input + 2, input + 10, input + 21, counter, 1);
            }
        }
        else if (input[0] == '9')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query9(user, n_users, input + 3, counter, 1);
            }
            else
            {
                flag = 0;
                query9(user, n_users, input + 2, counter, 1);
            }
        }
        else if (input[0] == '4')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query4(reservation, input + 3, counter, 1);
            }
            else
            {
                flag = 0;
                query4(reservation, input + 2, counter, 1);
            }
        }
        else if (input[0] == '5')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query5(flight, n_voos, input + 3, input + 8, input + 30, counter, 1);
            }
            else
            {
                flag = 0;
                query5(flight, n_voos, input + 2, input + 7, input + 29, counter, 1);
            }
        }
        else if (input[0] == '7')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query7(flight, n_voos, input + 3, counter, 1);
            }
            else
            {
                flag = 0;
                query7(flight, n_voos, input + 2, counter, 1);
            }
        }
        else if (input[0] == '2')
        {
            if (input[1] == 'F')
            {
                flag = 1;
                query2(passenger, user, flight, reservation, input + 3, counter, 1);
            }
            else
            {
                flag = 0;
                query2(passenger, user, flight, reservation, input + 2, counter, 1);
            }
            /*}
            else if (input[0] == '1' && input[1] == '0')
            {
                if (input[2] == 'F')
                {
                    flag = 1;
                    query10(passenger, user, flight, reservation, input + 4, counter, 1);
                }
                else
                {
                    flag = 0;
                    query10(passenger, user, flight, reservation, input + 3, counter, 1);
                }*/
        }

        counter++;
    }

    free(input);
}

void handle_input(Reservation *reservation, Flight *flight, User *user, Passenger *passenger)
{
    int counter = 1;
    char *input;
    input = malloc(100 * sizeof(char));

    while ((fgets(input, 100, stdin)) && (strcmp(input, "exit\n") != 0))
    {
        if (strchr(input, '\n'))
        {
            *(strchr(input, '\n')) = '\0';
        }

        if (input[0] == '1')
            query1(flight, reservation, user, passenger, input + 2, counter, 0);
        else if (input[0] == '3')
        {
            query3(reservation, input + 2, counter, 0);
        }
        else if (input[0] == '4')
        {
            query4(reservation, input + 2, counter, 0);
        }
        else if (input[0] == '5')
        {
            query5(flight, n_voos, input + 2, input + 7, input + 29, counter, 0); 
        }
        else if (input[0] == '6')
        {
            query6(flight, passenger, input + 2, input + 7, counter, 0);
        }
        else if (input[0] == '7')
        {
            query7(flight, n_voos, input + 2, counter, 0);
        }
        else if (input[0] == '8')
        {
            query8(reservation, input + 2, input + 10, input + 21, counter, 0);
        }
        else if (input[0] == '9')
        {
            query9(user, n_users, input + 2, counter, 0);
        }
        else if (input[0] == '2')
        {
            query2(passenger, user, flight, reservation, input + 2, counter, 0);
        }
        counter++;
        puts("------------------------------------------------------");
        printf("Input => ");
    }
    free(input);
}

void handle_outputs(int counter, char *output)
{
    char filename[50];
    sprintf(filename, "Resultados/command%i_output.txt", counter);

    FILE *new_output = fopen(filename, "a");
    if (new_output != NULL)
    {
        fprintf(new_output, "%s", output);
        fclose(new_output);
    }
    else
    {
        fprintf(stderr, "Error opening file %s\n", filename);
    }
}