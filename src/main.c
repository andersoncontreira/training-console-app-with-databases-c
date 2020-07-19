#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "include/helper.h"
#include "include/student/student_manager.h"
#include "include/database/connector.h"

/**
 * Global
 */
char *APP_NAME = "Training Console App With Databases";
char *APP_VERSION = "0.0.1";
bool DEBUG = false;
bool EXIT = false;

program_arguments read_arguments(int argc, char *const *argv);

void help();
int get_option();

connection_parameters get_sqlite_connection_parameters() {
    connection_parameters parameters;
    parameters.database_type = SQLITE_TYPE;
    parameters.database = "teste.db";


    return parameters;
}

connection_parameters get_mysql_connection_parameters() {
    connection_parameters parameters;
    parameters.database_type = MYSQL_TYPE;
    parameters.database = "training";
    parameters.host = "127.0.0.1";//localhost como é docker requer o IP
    parameters.user = "training";
    parameters.password = "12345";
    parameters.port = 3306;

    return parameters;

}

int main(int argc, char *argv[]) {
    printf("-----------------------------------------\n");
    printf("%s version: %s.\n", APP_NAME, APP_VERSION);
    printf("-----------------------------------------\n");

    program_arguments arguments = read_arguments(argc, argv);

    if (arguments.help) {
        help();
        return 0;
    }
    // default connection is SQLite
    connection_parameters parameters = get_sqlite_connection_parameters();

    // check if the user choose Mysql
    if (strcasecmp(arguments.type, database_type_name[MYSQL_TYPE]) == 0) {
        parameters = get_mysql_connection_parameters();
    }

    printf("Connection to %s choose\n", database_type_name[parameters.database_type]);

    printf("Starting the connection...\n");
    //Start the connection
    connection_resource resource = database_connect(&parameters);

    if (resource.connected) {

        printf("%s","Connection OK\n");

        while (EXIT != true) {
            int option = get_option();
            switch (option) {
                default:
                    printf("Invalid option.\n");
                    break;
                case 1:
                    list_students();
                    break;
                case 4:
                    EXIT = true;
                    break;
            }
        }
    } else {
        fprintf(stderr, "Can't start program... exiting\n");
        fprintf(stderr, "Error: %s\n", resource.error_message);
    }


    return 0;
}

int get_option() {
    int option = 0;
    printf("-----------------------------------------\n");
    printf("%s version: %s.\n", APP_NAME, APP_VERSION);
    printf("-----------------------------------------\n");
    //printf("What do you want do?\n");
    printf("1 - List all students\n");
    printf("1 - Add new student\n");
    printf("2 - Edit an existing student\n");
    printf("3 - Delete an existing student\n");
    printf("4 - Exit\n");
    scanf("%d", &option);
    return (option);
}

void help() {
    char * help_str = "\nUsage: console_app [option]\n"
                     "where [option] is one of:\n"
                     "\t-t, --type\t\t define the type of connection: (mysql|sqlite)\n"
                     "\t-d, --debug\t\t define if it will run in debug mode\n"
                     "\t-h, --help\t\t print this help\n";

    printf("%s", help_str);
}

program_arguments read_arguments(int argc, char *const *argv) {
    program_arguments arguments;
    arguments.type = (char *)database_type_name[SQLITE_TYPE];
    arguments.help = false;

    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            if (DEBUG) {
                printf("%s\t\n", argv[i]);
            }


            //arg
            char *argument = (char *) argv[i];
            char *key = malloc(sizeof(argument));
            char *value = malloc(sizeof(argument));

            // copy the string value
            strcpy(key, argument);
            // split
            strtok(key, "=");
            // remove (key=) from string
            key = str_replace(key, "=", "");
            // remove key from value
            value = str_replace(argument, key, "");
            value = str_replace(value, "=", "");

            if (DEBUG) {
                printf("key: %s\t\n", key);
                printf("value: %s\t\n", value);
            }

            // check if the key is type
            if (strcasecmp(key, "-t") == 0 || strcasecmp(key, "--type") == 0) {
                arguments.type = value;
            }

            // check if the key is type
            if (strcasecmp(key, "-d") == 0 || strcasecmp(key, "--debug") == 0) {
                DEBUG = true;
                arguments.debug = true;
            }

            // check if the key is help
            if (strcasecmp(key, "-h") == 0 || strcasecmp(key, "--help") == 0) {
                arguments.help = true;
            }

        }
    }

    if (DEBUG) {
        printf("arguments:\n");
        printf("arguments.type: %s\n", arguments.type);
        printf("arguments.help: %s\n", arguments.help ? "true" : "false");
        printf("arguments.debug: %s\n", arguments.debug ? "true" : "false");
    }

    return arguments;
}

