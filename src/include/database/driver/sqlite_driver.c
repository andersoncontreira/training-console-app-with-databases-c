#include "sqlite_driver.h"

sqlite_connection_resource sqlite_driver_connect(char *filename) {
    sqlite_connection_resource resource;

    int rc = sqlite3_open(filename, &resource.sqlite);
    resource.connected = true;

    if (rc) {
        resource.error_message = strcat("Can't open database: %s", (char *) sqlite3_errmsg(resource.sqlite));
        resource.connected = false;
    }


    return resource;
}

bool sqlite_driver_disconnect(sqlite3 *database) {
    sqlite3_close(database);
    return true;
}



