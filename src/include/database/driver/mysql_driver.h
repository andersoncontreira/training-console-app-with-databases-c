//
// Created by andersoncontreira on 17/07/2020.
//

#ifndef CONSOLE_APP_MYSQL_DRIVER_H
#define CONSOLE_APP_MYSQL_DRIVER_H

#include <mysql.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    MYSQL *mysql;
    bool connected;
    char *error_message;
} mysql_connection_resource;

mysql_connection_resource mysql_driver_connect(char *host, char *user, char *password, char *database, int port);

bool mysql_driver_disconnect(MYSQL * database) ;

#endif //CONSOLE_APP_MYSQL_DRIVER_H
