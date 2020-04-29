/*
** EPITECH PROJECT, 2018
** str
** File description:
** str
*/

#include <string.h>
#include <stdlib.h>

void free_tab(void **tab)
{
    for (int i = 0; tab[i]; i++) {
        free(tab[i]);
    }
    free(tab);
}

int is_num_alpha_script(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') || c == ' ' || c == '-')
        return (0);
    return (1);
}

char **script(char **argv, char const *str)
{
    int j = 0;
    int c = 0;

    for (int i = 0; str[i]; i++) {
        if (is_num_alpha_script(str[i]) == 0) {
            argv[j][c] = str[i];
            c++;
        }
        if (c != 0 && (is_num_alpha_script(str[i]) == 1 &&
            is_num_alpha_script(str[i + 1] == 0)) ) {
            argv[j][c] = '\0';
            j++;
            c = 0;
        }
    }
    argv[j] = NULL;
    return (argv);
}

char **my_str_to_word_array_script(char const *str)
{
    char **argv = NULL;
    int j = 0;

    if (str[0] == 0)
        return (NULL);
    for (int i = 0; str && str[i]; i++)
        if (is_num_alpha_script(str[i]) == 1 &&
                is_num_alpha_script(str[i + 1]) == 0)
            j++;
    if ((argv = malloc(sizeof(char *) * (j + 3))) == NULL)
        return (NULL);
    for (int i = 0; i <= j; i++) {
        argv[i] = malloc(sizeof(char) * (strlen(str) + 1));
        if (argv[i] == NULL)
            return (NULL);
        for (int c = 0; c <= (int)strlen(str); c++)
            argv[i][c] = '\0';
    }
    return (script(argv, str));
}