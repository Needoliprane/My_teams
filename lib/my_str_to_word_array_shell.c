/*
** EPITECH PROJECT, 2018
** str
** File description:
** str
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// void free_tab(void **tab)
// {
//     for (int i = 0; tab[i]; i++) {
//         free(tab[i]);
//     }
//     free(tab);
// }

// int is_num_alpha_script(char c)
// {
//     if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
//             (c >= 'A' && c <= 'Z') || c == ' ' || c == '-')
//         return (0);
//     return (1);
// }

// char **script(char **argv, char const *str)
// {
//     int j = 0;
//     int c = 0;

//     for (int i = 0; str[i]; i++) {
//         if (is_num_alpha_script(str[i]) == 0) {
//             argv[j][c] = str[i];
//             printf("%c", argv[j][c]);
//             c++;
//         }
//         if (c != 0 && (is_num_alpha_script(str[i]) == 1 &&
//             is_num_alpha_script(str[i + 1] == 0)) ) {
//             argv[j][c] = '\0';
//             j++;
//             c = 0;
//         }
//     }
//     printf("%d\n", j);
//     argv[j+1] = NULL;
//     return (argv);
// }

// char **my_str_to_word_array_script(char const *str)
// {
//     char **argv = NULL;
//     int j = 0;

//     if (str[0] == 0)
//         return (NULL);
//     for (int i = 0; str && str[i]; i++)
//         if (is_num_alpha_script(str[i]) == 1 &&
//                 is_num_alpha_script(str[i + 1]) == 0)
//             j++;
//     if ((argv = malloc(sizeof(char *) * (j + 3))) == NULL)
//         return (NULL);
//     for (int i = 0; i <= j; i++) {
//         argv[i] = malloc(sizeof(char) * (strlen(str) + 1));
//         if (argv[i] == NULL)
//             return (NULL);
//         for (int c = 0; c <= (int)strlen(str); c++)
//             argv[i][c] = '\0';
//     }
//     return (script(argv, str));
// }

void extract_between_quotes(char const *line, char ** dest)
{
    char *p = (char *)line, *sp = NULL, *ep = NULL;
    char delim = '\"';
    size_t i = 0;

    for (int index = 1; *p; p++) {
        if (!sp && *p == delim)
            sp = p, sp++;
        else if (!ep && *p == delim)
            ep = p;
        if (sp && ep) {
            char substr[ep - sp + 1];
            for (i = 0, p = sp; p < ep; p++)
                substr[i++] = *p;
            substr[ep - sp] = 0;
            dest[index] = strdup(substr);
            index++;
            sp = ep = NULL;
        }
    }
}

char **my_str_to_word_array_script(char const *str)
{
    int count = 0;
    char **tab = NULL;

    for (int i = 0; str[i]; (str[i] == '[') ? count++ : 0, i++);
    tab = malloc(sizeof(char *) * (count + 2));
    tab[0] = calloc(strlen(str), sizeof(char));
    for (int i = 0; str[i] && str[i] != ' '; tab[0][i] = str[i], tab[0][i + 1] = 0, i++);
    extract_between_quotes(str, tab);
    tab[count + 1] = NULL;
    return (tab);
}