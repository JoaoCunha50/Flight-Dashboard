#include "../include/users.h"

struct data
{
    int ano;
    int mes;
    int dia;
};

struct time
{
    int horas;
    int minutos;
    int segundos;
};

struct schedule
{
    Data date;
    Time time;
};

struct user
{
    char *id;
    char *name;
    char *email;
    char *phone_number; // Parser capaz de ignorar (351) e espaços (' ')
    Data *birthday_date;
    char *sex; // Parser capaz de detetar erros
    char *passport;
    char *country_code;
    char *address;
    Schedule *account_creation;
    char *pay_method;
    char *account_status;
};

int n_users = 0;

int SizeofUsers()
{
    return sizeof(User);
}

void set_user_id(User *client, char *chave, int i)
{
    client[i].id = malloc((strlen(chave) + 1));
    strcpy(client[i].id, chave);
    n_users++;
}

void set_user_name(User *client, char *chave, int i)
{
    client[i].name = malloc((strlen(chave) + 1));
    strcpy(client[i].name, chave);
}

void set_user_email(User *client, char *chave, int i)
{
    client[i].email = malloc((strlen(chave) + 1));
    strcpy(client[i].email, chave);
}

void set_user_phone_number(User *client, char *chave, int i)
{
    client[i].phone_number = malloc((strlen(chave) + 1));
    strcpy(client[i].phone_number, chave);
}
// mudar
void set_user_birthday_date(User *client, char *chave, int i)
{
    client[i].birthday_date = malloc(sizeof(Data));
    char *token;

    token = strtok(chave, "/");
    if (token != NULL)
    {
        client[i].birthday_date->ano = atoi(token);
    }
    token = strtok(NULL, "/");
    if (token != NULL)
    {
        client[i].birthday_date->mes = atoi(token);
    }
    token = strtok(NULL, ";");
    if (token != NULL)
    {
        client[i].birthday_date->dia = atoi(token);
    }
}

void set_user_sex(User *client, char *chave, int i)
{
    client[i].sex = malloc(sizeof(char) + 1);
    strcpy(client[i].sex, chave);
}

void set_user_passport(User *client, char *chave, int i)
{
    client[i].passport = malloc((strlen(chave) + 1));
    strcpy(client[i].passport, chave);
}

void set_user_country_code(User *client, char *chave, int i)
{
    client[i].country_code = malloc((strlen(chave) + 1));
    strcpy(client[i].country_code, chave);
}

void set_user_address(User *client, char *chave, int i)
{
    client[i].address = malloc((strlen(chave) + 1));
    strcpy(client[i].address, chave);
}

int set_user_account_creation(User *client, char *chave, int i)
{
    client[i].account_creation = malloc(sizeof(Schedule));
    char *token;

    if (chave == NULL)
        return 1;

    token = strtok(chave, "/");
    if (token == NULL || strlen(token) != 4)
        return 1;

    client[i].account_creation->date.ano = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL || strlen(token) != 2)
        return 1;

    client[i].account_creation->date.mes = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL || strlen(token) != 2 || SintaxValid(token) == 0)
        return 1;

    client[i].account_creation->date.dia = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return 1;

    client[i].account_creation->time.horas = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL || strlen(token) != 2)
        return 1;

    client[i].account_creation->time.minutos = atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL || strlen(token) != 2)
        return 1;

    client[i].account_creation->time.segundos = atoi(token);

    return 0;
}

void set_user_pay_method(User *client, char *chave, int i)
{
    client[i].pay_method = malloc((strlen(chave) + 1));
    strcpy(client[i].pay_method, chave);
}

void set_user_account_status(User *client, char *chave, int i)
{
    client[i].account_status = malloc((strlen(chave) + 1));
    strcpy(client[i].account_status, chave);
}

int isEmailValid(User *client, int i)
{
    if (strlen(client[i].email) == 0)
    {
        return 0;
    }
    char *temp = strdup(client[i].email);
    char *compare_email = temp;
    char *token = strsep(&compare_email, "@");

    if (token == NULL || (strlen(token)) == 0)
    {
        free(temp);
        return 0;
    }

    token = strsep(&compare_email, ".");

    if (token == NULL || (strlen(token) < 1) || SintaxValid(token) == 0)
    {
        free(temp);
        return 0;
    }

    if (compare_email == NULL || strlen(compare_email) < 2 || SintaxValid(compare_email) == 0)
    {
        free(temp);
        return 0;
    }
    free(temp);

    return 1;
}

int SintaxValid(char *token)
{
    for (int i = 0; i < strlen(token) + 1; i++)
    {
        if (token[i] == '@' || token[i] == '~')
        {
            return 0;
        }
    }
    return 1;
}

int isAccountStatusValid(User *client, int i)
{
    toUpperCase(client[i].account_status);

    if (client[i].account_status == NULL)
    {
        return 0;
    }
    if (strcmp(client[i].account_status, "ACTIVE\n") == 0 || strcmp(client[i].account_status, "INACTIVE\n") == 0)
    {
        return 1;
    }
    else
        return 0;
}

int isUserValid(User *user, int i)
{
    return (strlen(user[i].id) > 0 &&
            (strlen(user[i].name) > 0) &&
            isEmailValid(user, i) &&
            (strlen(user[i].phone_number) > 0) &&
            isDateValid_Users(user[i].birthday_date) &&
            (strlen(user[i].sex) > 0) &&
            (strlen(user[i].passport) > 0) &&
            (strlen(user[i].country_code) == 2) &&
            (strlen(user[i].address) > 0) &&
            isScheduleValid_User(user[i].account_creation) &&
            (strlen(user[i].pay_method) > 0) &&
            (isAccountStatusValid(user, i)));
}

void reset_User(User *user, int i)
{
    free(user[i].id);
    free(user[i].name);
    free(user[i].email);
    free(user[i].phone_number);
    free(user[i].birthday_date);
    free(user[i].sex);
    free(user[i].passport);
    free(user[i].country_code);
    free(user[i].address);
    free(user[i].account_creation);
    free(user[i].pay_method);
    free(user[i].account_status);
    user[i].id = NULL;
    user[i].name = NULL;
    user[i].email = NULL;
    user[i].phone_number = NULL;
    user[i].birthday_date = NULL;
    user[i].passport = NULL;
    user[i].country_code = NULL;
    user[i].address = NULL;
    user[i].account_creation = NULL;
    user[i].pay_method = NULL;
    user[i].account_status = NULL;
    n_users--;
}

void freeUser(User *user)
{
    for (int i = 0; i < n_users; i++)
    {
        free(user[i].id);
        free(user[i].name);
        free(user[i].email);
        free(user[i].phone_number);
        free(user[i].birthday_date);
        free(user[i].sex);
        free(user[i].passport);
        free(user[i].country_code);
        free(user[i].address);
        free(user[i].account_creation);
        free(user[i].pay_method);
        free(user[i].account_status);
    }
    free(user);
}

void freeUserQ(User *user, int s)
{
    for (int i = 0; i < s; i++)
    {
        free(user[i].id);
        free(user[i].name);
    }
    free(user);
}

char *get_user_id(User *user, int i)
{
    return strdup(user[i].id);
}

char *get_user_name(User *user, int i)
{
    return strdup(user[i].name);
}

char *get_user_email(User *user, int i)
{
    return strdup(user[i].email);
}

char *get_user_phoneNumber(User *user, int i)
{
    return strdup(user[i].phone_number);
}

int get_user_birthdayDate_Year(User *user, int i)
{
    return (user[i].birthday_date->ano);
}

int get_user_birthdayDate_Month(User *user, int i)
{
    return (user[i].birthday_date->mes);
}

int get_user_birthdayDate_Day(User *user, int i)
{
    return (user[i].birthday_date->dia);
}

char *get_user_sex(User *user, int i)
{
    return strdup(user[i].sex);
}

char *get_user_passport(User *user, int i)
{
    return strdup(user[i].passport);
}

char *get_user_countryCode(User *user, int i)
{
    return strdup(user[i].country_code);
}

char *get_user_address(User *user, int i)
{
    return strdup(user[i].address);
}

int get_user_accountCreation_Year(User *user, int i)
{
    return (user[i].account_creation->date.ano);
}

int get_user_accountCreation_Month(User *user, int i)
{
    return (user[i].account_creation->date.mes);
}

int get_user_accountCreation_Day(User *user, int i)
{
    return (user[i].account_creation->date.dia);
}

int get_user_accountCreation_Hour(User *user, int i)
{
    return (user[i].account_creation->time.horas);
}

int get_user_accountCreation_Minute(User *user, int i)
{
    return (user[i].account_creation->time.minutos);
}

int get_user_accountCreation_Seconds(User *user, int i)
{
    return (user[i].account_creation->time.segundos);
}
char *get_user_payMethod(User *user, int i)
{
    return strdup(user[i].pay_method);
}

char *get_user_accountStatus(User *user, int i)
{
    return strdup(user[i].account_status);
}

#include <string.h>
#include <locale.h>

int compararUsuarios(const void *a, const void *b)
{
    const User *userA = (const User *)a;
    const User *userB = (const User *)b;

    setlocale(LC_COLLATE, "");

    int comparacaoNomes = strcoll(userA->name, userB->name);

    if (comparacaoNomes != 0)
    {
        return comparacaoNomes;
    }
    return strcoll(userA->id, userB->id);
}

void copyUser(User *user1, User *user2, int size, int i)
{

    user1[size].id = malloc(sizeof(char) * 75);
    strcpy(user1[size].id, user2[i].id);
    user1[size].name = malloc(sizeof(char) * 75);
    strcpy(user1[size].name, user2[i].name);

    return;
}

int is_User_Empty(User *user, int index)
{
    return (user[index].id == 0 && user[index].name == NULL);
}
