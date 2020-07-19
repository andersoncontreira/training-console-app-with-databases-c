

#ifndef TRAINING_CONNECTOR_H
#undef TRAINING_CONNECTOR_H

#include "driver/sqlite_driver.h"
#include "driver/mysql_driver.h"

enum database_type {
    SQLITE_TYPE,
    MYSQL_TYPE
};

static const char *database_type_name[] = {"SQLITE", "MYSQL"};

typedef struct {
    char *host;
    char *user;
    char *password;
    char *database;
    int port;
    enum database_type database_type;

} connection_parameters;

typedef struct {
    bool connected;
    sqlite3 *sqlite;
    int mysql;
    char *error_message;
} connection_resource;

connection_resource database_connect(connection_parameters *parameters);

bool execute(char *sql);

bool create_table(char *table_name);


#endif

