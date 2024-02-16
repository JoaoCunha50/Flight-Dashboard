#ifndef USERS_H
#define USERS_H

#include "main.h"
#include "schedules.h"
#include "reservations.h"

typedef struct data Data;
typedef struct time Time;
typedef struct schedule Schedule;

typedef struct user User;

extern int n_users;

int SizeofUsers();

void set_user_id(User *client, char *chavent, int i);

void set_user_name(User *client, char *chavent, int i);

void set_user_email(User *client, char *chavent, int i);

void set_user_phone_number(User *client, char *chavent, int i);

void set_user_birthday_date(User *client, char *chave, int i);

void set_user_sex(User *client, char *chave, int i);

void set_user_passport(User *client, char *chave, int i);

void set_user_country_code(User *client, char *chave, int i);

void set_user_address(User *client, char *chave, int i);

int set_user_account_creation(User *client, char *chave, int i);

void set_user_pay_method(User *client, char *chave, int i);

void set_user_account_status(User *client, char *chave, int i);

void reset_User(User *user, int i);

void freeUser(User* user) ;

void freeUserQ(User *user, int s);

int isAccountStatusValid(User* status, int i);

int SintaxValid(char *token);

int isEmailValid(User *client, int i);

int isUserValid(User *user, int i);

char *get_user_id(User *user, int i);

char *get_user_name(User *user, int i);

char *get_user_email(User *user, int i);

char *get_user_phoneNumber(User *user, int i);

int get_user_birthdayDate_Year(User *user, int i);

int get_user_birthdayDate_Month(User *user, int i);

int get_user_birthdayDate_Day(User *user, int i);

char *get_user_sex(User *user, int i);

char *get_user_passport(User *user, int i);

char *get_user_countryCode(User *user, int i);

char *get_user_address(User *user, int i);

int get_user_accountCreation_Year(User *user, int i);

int get_user_accountCreation_Month(User *user, int i);

int get_user_accountCreation_Day(User *user, int i);

int get_user_accountCreation_Hour(User *user, int i);

int get_user_accountCreation_Minute(User *user, int i);

int get_user_accountCreation_Seconds(User *user, int i);

char *get_user_payMethod(User *user, int i);

char *get_user_accountStatus(User *user, int i);

int compararUsuarios(const void *a, const void *b);

void copyUser(User *user1, User *user2, int size, int i);

int is_User_Empty(User *user, int index);

#endif