//
// Created by andersoncontreira on 17/07/2020.
//

#ifndef CONSOLE_APP_SQLITE_DRIVER_H
#define CONSOLE_APP_SQLITE_DRIVER_H

#include <stdbool.h>
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    sqlite3 *sqlite;
    bool connected;
    char *error_message;
} sqlite_connection_resource;

sqlite_connection_resource sqlite_driver_connect(char * filename);

bool sqlite_driver_disconnect(sqlite3 * database) ;

#endif //CONSOLE_APP_SQLITE_DRIVER_H
