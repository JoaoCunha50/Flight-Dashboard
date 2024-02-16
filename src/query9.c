#include "../include/query9.h"
#include <locale.h>

int isPrefix(const char *str, const char *prefix)
{
    int lenStr = strlen(str);
    int lenPrefix = strlen(prefix);

    if (lenPrefix > lenStr)
    {
        return 0;
    }

    if (prefix[0] == '"')
    {
        prefix++;
        lenPrefix--;
    }

    if (prefix[lenPrefix - 1] == '"')
    {
        lenPrefix--;
    }

    return (strncmp(str, prefix, lenPrefix) == 0);
}

void query9(User *users, int n_users, char *prefix, int counter, int mode)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int s = SizeofUsers();
    User *users_filtrados = malloc(n_users * s);
    int Size = 0;

    for (int i = 0; i < n_users; i++)
    {
        char *user_name = get_user_name(users, i);
        char *user_AccountStatus = get_user_accountStatus(users, i);
        if (isPrefix(user_name, prefix) && !(strcmp(user_AccountStatus, "INACTIVE\n") == 0))
        {
            copyUser(users_filtrados, users, Size, i);
            Size++;
        }

        free(user_name);
        free(user_AccountStatus);
    }

    qsort(users_filtrados, Size, s, compararUsuarios);

    char outputFileName[1024];
    sprintf(outputFileName, "Resultados/command%d_output.txt", counter);
    FILE *outputFile = fopen(outputFileName, "w");
    char *output = malloc(sizeof(char));
    output[0] = '\0';

    if (mode == 0)
    {
        printf("<ID> <Name>\n");
        for (int i = 0; i < Size; i++)
        {
            char *userID = get_user_id(users_filtrados, i);
            char *userName = get_user_name(users_filtrados, i);

            int new_line_size = snprintf(NULL, 0, "%s;%s\n\n", userID, userName);
            output = realloc(output, strlen(output) + new_line_size + 1);
            sprintf(output + strlen(output), "%s;%s\n\n", userID, userName);

            free(userID);
            free(userName);
        }
        printf("%s", output);
    }
    else
    {
        if (flag)
        {
            for (int i = 0; i < Size; i++)
            {
                char *userID = get_user_id(users_filtrados, i);
                char *userName = get_user_name(users_filtrados, i);

                if (i != Size - 1)
                {
                    fprintf(outputFile, "--- %d ---\nid: %s\nname: %s\n\n", (i + 1), userID, userName);
                }
                else
                {
                    fprintf(outputFile, "--- %d ---\nid: %s\nname: %s\n", (i + 1), userID, userName);
                }

                free(userID);
                free(userName);
            }
        }
        else
        {
            for (int i = 0; i < Size; i++)
            {
                char *userID = get_user_id(users_filtrados, i);
                char *userName = get_user_name(users_filtrados, i);

                fprintf(outputFile, "%s;%s\n", userID, userName);

                free(userID);
                free(userName);
            }
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (mode == 1)
        printf("\n");
    if ((mode == 1) || (mode == 0) || (mode == 3))
        printf("Fim da Q9 - %f segundos (input nº %i)\n", cpu_time_used, counter);

    freeUserQ(users_filtrados, Size);
    fclose(outputFile);
    free(output);
}
