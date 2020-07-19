#include "connector.h"

connection_resource database_connect(connection_parameters * parameters) {
    connection_resource resource;
    sqlite_connection_resource tmp_sqlite;
    mysql_connection_resource tmp_mysql;

    switch (parameters->database_type) {
        case MYSQL_TYPE:
            tmp_mysql = mysql_driver_connect(parameters->host, parameters->user,
                                             parameters->password, parameters->database, parameters->port);

            resource.connected = tmp_mysql.connected;
            resource.sqlite = NULL;
            resource.mysql = tmp_mysql.mysql;
            resource.error_message = tmp_mysql.error_message;
            break;
        case SQLITE_TYPE:
            tmp_sqlite = sqlite_driver_connect(parameters->database);
            resource.connected = tmp_sqlite.connected;
            resource.sqlite = tmp_sqlite.sqlite;
            resource.mysql = NULL;
            resource.error_message = tmp_sqlite.error_message;
            break;
    }

    if (!resource.connected) {
        if (strcasecmp(resource.error_message, (char * ) "Error: Unknown database 'training'")) {
            printf("Deu erro\n");
        }
    }

    return resource;
}

bool execute(char * sql) {

}

bool create_table(char * table_name) {

}

