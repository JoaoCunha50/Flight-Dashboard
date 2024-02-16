#include "../include/reservations.h"

struct data
{
    int ano;
    int mes;
    int dia;
};

struct reservation
{
    char *id;
    char *user_id;
    char *hotel_id;
    char *hotel_name;
    int hotel_stars;
    int city_tax;
    char *address;
    Data *begin_date;
    Data *end_date;
    int price_per_night;
    char *includes_breakfast;
    char *room_details;
    int rating;
    char *comment;
};

int n_reservations = 0;

void toUpperCase(char *s)
{
    if (s == NULL)
        return;

    while (*s != '\0')
    {
        *s = toupper(*s);
        s++;
    }
}

int SizeofReservations()
{
    return sizeof(Reservation);
}

void set_reservation_id(Reservation *booking, char *chave, int i)
{
    booking[i].id = malloc((strlen(chave) + 1));
    strcpy(booking[i].id, chave);
    n_reservations++;
}

void set_reservation_user_id(Reservation *booking, char *chave, int i)
{
    booking[i].user_id = malloc((strlen(chave) + 1));
    strcpy(booking[i].user_id, chave);
}

void set_reservation_hotel_id(Reservation *booking, char *chave, int i)
{
    booking[i].hotel_id = malloc((strlen(chave) + 1));
    strcpy(booking[i].hotel_id, chave);
}

void set_reservation_hotel_name(Reservation *booking, char *chave, int i)
{
    booking[i].hotel_name = malloc((strlen(chave) + 1));
    strcpy(booking[i].hotel_name, chave);
}

void set_reservation_hotel_stars(Reservation *booking, char *chave, int i)
{
    for (int j = 0; j < strlen(chave) + 1; j++)
    {
        if (chave[j] == '.')
        {
            booking[i].hotel_stars = -1;
            return;
        }
    }
    booking[i].hotel_stars = atoi(chave);
}

void set_reservation_city_tax(Reservation *booking, char *chave, int i)
{
    for (int j = 0; j < strlen(chave) + 1; j++)
    {
        if (chave[j] == '.')
        {
            booking[i].city_tax = -1;
            return;
        }
    }
    booking[i].city_tax = atoi(chave);
}

void set_reservation_address(Reservation *booking, char *chave, int i)
{
    booking[i].address = malloc((strlen(chave) + 1));
    strcpy(booking[i].address, chave);
}

void set_reservation_begin_date(Reservation *booking, char *chave, int i)
{
    booking[i].begin_date = malloc(sizeof(Data));
    char *token;

    token = strtok(chave, "/");
    if (token != NULL)
    {
        booking[i].begin_date->ano = atoi(token);
    }

    token = strtok(NULL, "/");
    if (token != NULL)
    {
        booking[i].begin_date->mes = atoi(token);
    }

    token = strtok(NULL, ";");
    if (token != NULL)
    {
        booking[i].begin_date->dia = atoi(token);
    }
}

void set_reservation_end_date(Reservation *booking, char *chave, int i)
{
    booking[i].end_date = malloc(sizeof(Data));
    char *token;

    token = strtok(chave, "/");
    if (token != NULL)
    {
        booking[i].end_date->ano = atoi(token);
    }

    token = strtok(NULL, "/");
    if (token != NULL)
    {
        booking[i].end_date->mes = atoi(token);
    }

    token = strtok(NULL, ";");
    if (token != NULL)
    {
        booking[i].end_date->dia = atoi(token);
    }
}

void set_reservation_price_per_night(Reservation *booking, char *chave, int i)
{
    booking[i].price_per_night = atoi(chave);
}

void set_reservation_includes_breakfast(Reservation *booking, char *chave, int i)
{
    toUpperCase(chave);
    if ((strlen(chave) == 0) || (strcasecmp(chave, "FALSE") == 0) || (strcasecmp(chave, "F") == 0) || (strcasecmp(chave, "0") == 0))
    {
        booking[i].includes_breakfast = "False";
    }
    else if ((strcasecmp(chave, "TRUE") == 0) || (strcasecmp(chave, "T") == 0) || (strcasecmp(chave, "1") == 0))
    {
        booking[i].includes_breakfast = "True";
    }
    else
        booking[i].includes_breakfast = "";
}

void set_reservation_room_details(Reservation *booking, char *chave, int i)
{
    booking[i].room_details = malloc((strlen(chave) + 1));
    strcpy(booking[i].room_details, chave);
}

void set_reservation_rating(Reservation *booking, char *chave, int i)
{
    for (int j = 0; j < strlen(chave) + 1; j++)
    {
        if (chave[j] == '.')
        {
            booking[i].rating = -1;
            return;
        }
    }
    booking[i].rating = atoi(chave);
}

void set_reservation_comment(Reservation *booking, char *chave, int i)
{
    booking[i].comment = malloc((strlen(chave) + 1));
    strcpy(booking[i].comment, chave);
}

/*int is_includes_breakfast_valid(Reservation *reservation, int i)
{
    return ((strlen(reservation[i].includes_breakfast) == 0) || (strcmp(reservation[i].includes_breakfast, "FALSE") == 0) || (strcmp(reservation[i].includes_breakfast, "F") == 0) || (strcmp(reservation[i].includes_breakfast, "0") == 0) || (strcmp(reservation[i].includes_breakfast, "TRUE") == 0) || (strcmp(reservation[i].includes_breakfast, "T") == 0) || (strcmp(reservation[i].includes_breakfast, "1") == 0));
}*/

int isReservationValid(Reservation *booking, int i)
{
    return (strlen(booking[i].id) > 0 &&
            strlen(booking[i].user_id) > 0 &&
            strlen(booking[i].hotel_id) > 0 &&
            strlen(booking[i].hotel_name) > 0 &&
            booking[i].hotel_stars > 0 &&
            booking[i].hotel_stars <= 5 &&
            booking[i].city_tax >= 0 &&
            strlen(booking[i].address) > 0 &&
            isDateValid_Reservations(booking[i].begin_date, booking[i].end_date) &&
            booking[i].price_per_night > 0 &&
            strlen(booking[i].includes_breakfast) > 0 &&
            booking[i].rating > 0 &&
            booking[i].rating <= 5 &&
            strlen(booking[i].room_details) > 0);
}

void reset_reservation(Reservation *booking, int i)
{
    free(booking[i].id);
    free(booking[i].user_id);
    free(booking[i].hotel_id);
    free(booking[i].hotel_name);
    free(booking[i].address);
    free(booking[i].begin_date);
    free(booking[i].end_date);
    free(booking[i].room_details);
    free(booking[i].comment);
    booking[i].id = NULL;
    booking[i].user_id = NULL;
    booking[i].hotel_id = NULL;
    booking[i].hotel_name = NULL;
    booking[i].address = NULL;
    booking[i].begin_date = NULL;
    booking[i].end_date = NULL;
    booking[i].includes_breakfast = 0;
    booking[i].room_details = NULL;
    booking[i].comment = NULL;
    booking[i].hotel_stars = 0; // nas variaveis do tipo int, devo dar reset?
    booking[i].city_tax = 0;
    booking[i].price_per_night = 0;
    booking[i].rating = 0;
    n_reservations--;
}

void freeReservation(Reservation *reservation)
{
    for (int i = 0; i < n_reservations; i++)
    {
        free(reservation[i].id);
        free(reservation[i].user_id);
        free(reservation[i].hotel_id);
        free(reservation[i].hotel_name);
        free(reservation[i].address);
        free(reservation[i].begin_date);
        free(reservation[i].end_date);
        free(reservation[i].room_details);
        free(reservation[i].comment);
    }
    free(reservation);
}

void freereservationQ(Reservation *reservas_filtradas, int s)
{
    for (int l = 0; l < s; l++)
    {
        free(reservas_filtradas[l].id);
        free(reservas_filtradas[l].user_id);
    }

    free(reservas_filtradas);
}

char *get_reservation_id(Reservation *reservation, int i)
{
    return strdup(reservation[i].id);
}

char *get_reservation_userID(Reservation *reservation, int i)
{
    return strdup(reservation[i].user_id);
}

char *get_reservation_hotelID(Reservation *reservation, int i)
{
    return strdup(reservation[i].hotel_id);
}

char *get_reservation_hotelName(Reservation *reservation, int i)
{
    return strdup(reservation[i].hotel_name);
}

int get_reservation_hotelStars(Reservation *reservation, int i)
{
    return reservation[i].hotel_stars;
}

int get_reservation_cityTax(Reservation *reservation, int i)
{
    return reservation[i].city_tax;
}

char *get_reservation_address(Reservation *reservation, int i)
{
    return strdup(reservation[i].address);
}

int get_reservation_beginData_Year(Reservation *reservation, int i)
{
    return reservation[i].begin_date->ano;
}

int get_reservation_beginData_Month(Reservation *reservation, int i)
{
    return reservation[i].begin_date->mes;
}

int get_reservation_beginData_Day(Reservation *reservation, int i)
{
    return reservation[i].begin_date->dia;
}

Data *get_reservation_beginData(Reservation *reservation, int i)
{
    Data *data = (Data *)malloc(sizeof(Data));
    int day = get_reservation_beginData_Day(reservation, i);
    int month = get_reservation_beginData_Month(reservation, i);
    int year = get_reservation_beginData_Year(reservation, i);
    data->dia = day;
    data->mes = month;
    data->ano = year;
    return data;
}
int get_reservation_endData_Year(Reservation *reservation, int i)
{
    return reservation[i].end_date->ano;
}

int get_reservation_endData_Month(Reservation *reservation, int i)
{
    return reservation[i].end_date->mes;
}

int get_reservation_endData_Day(Reservation *reservation, int i)
{
    return reservation[i].end_date->dia;
}

Data *get_reservation_endData(Reservation *reservation, int i)
{
    Data *data = (Data *)malloc(sizeof(Data));
    int day = get_reservation_endData_Day(reservation, i);
    int month = get_reservation_endData_Month(reservation, i);
    int year = get_reservation_endData_Year(reservation, i);
    data->dia = day;
    data->mes = month;
    data->ano = year;
    return data;
}
int get_reservation_pricePerNight(Reservation *reservation, int i)
{
    return reservation[i].price_per_night;
}

char *get_reservation_includesBreakfast(Reservation *reservation, int i)
{
    return strdup(reservation[i].includes_breakfast);
}

char *get_reservation_roomDetails(Reservation *reservation, int i)
{
    return strdup(reservation[i].room_details);
}

int get_reservation_rating(Reservation *reservation, int i)
{
    return reservation[i].rating;
}

char *get_reservation_comment(Reservation *reservation, int i)
{
    return strdup(reservation[i].comment);
}

int compare_hotelID(Reservation *reservation, char *hotel_id, int i)
{
    return strcmp(reservation[i].hotel_id, hotel_id);
}

int get_hotel_rating(Reservation *reservation, char *hotelID, int *j)
{
    int *rating = calloc(n_reservations, sizeof(int));
    int soma = 0;
    for (int i = 0; i < n_reservations; i++)
    {
        if (compare_hotelID(reservation, hotelID, i) == 0)
        {
            rating[i] = get_reservation_rating(reservation, i);
            soma += rating[i];
            j[0]++;
        }
    }
    free(rating);
    return soma;
}

int calculaNoite(Data *data1, Data *data2)
{
    int dias_inicio = data1->ano * 365 + data1->mes * 30 + data1->dia;
    int dias_fim = data2->ano * 365 + data2->mes * 30 + data2->dia;

    int diferencaDias = dias_fim - dias_inicio;

    return diferencaDias;
}

int get_hotel_price_per_night(Reservation *reservation, char *hotel_id, char *begin_date_c, char *end_date_c, int *n, int *aux)
{
    int price_per_night = 0;

    Data *begin_date = malloc(sizeof(Data));
    begin_date = convertToData(begin_date_c, begin_date);

    Data *end_date = malloc(sizeof(Data));
    end_date = convertToData(end_date_c, end_date);

    for (int i = 0; i < n_reservations; i++)
    {
        if (strcmp(reservation[i].hotel_id, hotel_id) == 0 && checkdate(reservation[i], begin_date, end_date))
        {
            if (reservation[i].end_date->mes == end_date->mes && reservation[i].end_date->dia == end_date->dia)
            {
                aux[i] = calculaNoite(reservation[i].begin_date, end_date);
            }
            else if ((end_date->ano == reservation[i].end_date->ano && end_date->mes > reservation[i].end_date->mes) || (end_date->mes == reservation[i].end_date->mes && end_date->dia > reservation[i].end_date->dia) || (end_date->ano > reservation[i].end_date->ano))
            {
                aux[i] = calculaNoite(reservation[i].begin_date, reservation[i].end_date);
            }
            else
                aux[i] = calculaNoite(reservation[i].begin_date, end_date) + 1;

            price_per_night = get_reservation_pricePerNight(reservation, i);
        }
        n[0]++;
    }
    free(begin_date);
    free(end_date);

    return price_per_night;
}

int checkdate(Reservation reservation, Data *begin_date, Data *end_date)
{
    if ((reservation.begin_date->ano > begin_date->ano ||
         (reservation.begin_date->ano == begin_date->ano && reservation.begin_date->mes > begin_date->mes) ||
         (reservation.begin_date->ano == begin_date->ano && reservation.begin_date->mes == begin_date->mes && reservation.begin_date->dia >= begin_date->dia)) &&
        (reservation.begin_date->ano < end_date->ano ||
         (reservation.begin_date->ano == end_date->ano && reservation.begin_date->mes < end_date->mes) ||
         (reservation.begin_date->ano == end_date->ano && reservation.begin_date->mes == end_date->mes && reservation.begin_date->dia <= end_date->dia)))
    {
        return 1;
    }

    return 0;
}

Data *convertToData(char *data, Data *date)
{
    char *token;
    char *data_aux = strdup(data);
    char *temp = data_aux;

    token = strsep(&temp, "/");

    date->ano = atoi(token);

    token = strsep(&temp, "/");

    date->mes = atoi(token);

    date->dia = atoi(temp);

    free(data_aux);
    return date;
}

int comparaReservas(const void *x, const void *y)
{
    const Reservation *reservaX = (const Reservation *)x;
    const Reservation *reservaY = (const Reservation *)y;

    if (reservaX->begin_date == NULL || reservaY->begin_date == NULL)
    {
        return 0;
    }

    int compara_datas = (reservaY->begin_date->ano - reservaX->begin_date->ano) * 365 +
                        (reservaY->begin_date->mes - reservaX->begin_date->mes) * 30 +
                        (reservaY->begin_date->dia - reservaX->begin_date->dia);

    if (compara_datas != 0)
        return compara_datas;

    return strcmp(reservaX->id, reservaY->id);
}

void copyReservation(Reservation *reserva1, Reservation *reserva2, int size, int i)
{

    reserva1[size].id = malloc(sizeof(char) * 75);
    strcpy(reserva1[size].id, reserva2[i].id);
    reserva1[size].begin_date = reserva2[i].begin_date;
    reserva1[size].end_date = reserva2[i].end_date;
    reserva1[size].city_tax = reserva2[i].city_tax;
    reserva1[size].user_id = malloc(sizeof(char) * 75);
    reserva1[size].rating = reserva2[i].rating;
    strcpy(reserva1[size].user_id, reserva2[i].user_id);
    reserva1[size].price_per_night = reserva2[i].price_per_night;

    return;
}

double calculaTotalPrice(Reservation *reserva, int i)
{
    double price_per_night = 0;
    double num_noites = 0;
    double price_sem_tax = 0;
    double tax = 0;
    double city_tax = 0;

    Data *begin_data = malloc(sizeof(Data));
    Data *end_data = malloc(sizeof(Data));
    begin_data->ano = get_reservation_beginData_Year(reserva, i);
    begin_data->mes = get_reservation_beginData_Month(reserva, i);
    begin_data->dia = get_reservation_beginData_Day(reserva, i);
    end_data->ano = get_reservation_endData_Year(reserva, i);
    end_data->mes = get_reservation_endData_Month(reserva, i);
    end_data->dia = get_reservation_endData_Day(reserva, i);

    price_per_night = get_reservation_pricePerNight(reserva, i);
    if (begin_data != NULL && end_data != NULL)
    {
        num_noites = calculaNoite(begin_data, end_data);
    }

    city_tax = get_reservation_cityTax(reserva, i);
    price_sem_tax = price_per_night * num_noites;
    tax = (price_sem_tax * city_tax) / 100;
    double preço_final = (price_sem_tax + tax);
    free(begin_data);
    free(end_data);
    return (preço_final);
}

int copyDataAno1(Reservation *reservation, int ano, int i)
{
    ano = get_reservation_beginData_Year(reservation, i);

    return ano;
}

int copyDataMes1(Reservation *reservation, int mes, int i)
{
    mes = get_reservation_beginData_Month(reservation, i);

    return mes;
}

int copyDataDia1(Reservation *reservation, int dia, int i)
{
    dia = get_reservation_beginData_Day(reservation, i);

    return dia;
}