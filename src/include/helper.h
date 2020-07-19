//
// Created by andersoncontreira on 17/07/2020.
//

#ifndef CONSOLE_APP_HELPER_H
#define CONSOLE_APP_HELPER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct key_par {
    char * key;
    char * value;
} key_par;

typedef struct {
    char * type;
    bool help;
    bool debug;
} program_arguments;

char *str_to_lower(char *str);

char *str_to_upper(char *str);

// You must free the result if result is non-NULL.
char *str_replace(char *orig, char *rep, char *with);

#endif //CONSOLE_APP_HELPER_H
