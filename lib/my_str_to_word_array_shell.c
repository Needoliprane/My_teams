/*
** EPITECH PROJECT, 2018
** str
** File description:
** str
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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