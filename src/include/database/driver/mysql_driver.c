//
// Created by andersoncontreira on 17/07/2020.
//
#include "mysql_driver.h"
#include <stdio.h>

mysql_connection_resource mysql_driver_connect(char *host, char *user, char *password, char *database, int port) {
    mysql_connection_resource resource;
    MYSQL * conn;
    conn = mysql_init(NULL);

    printf("MySQL client version : %s\n", mysql_get_client_info());

    if (!mysql_real_connect(conn, host, user, password, database, port, NULL, 0)) {
        resource.error_message = mysql_error(conn);
        resource.connected = false;
    } else {
        resource.connected = true;
    }

    return resource;
}

bool mysql_driver_disconnect(MYSQL * database) {
    return false;
}