cmake_minimum_required(VERSION 3.16)
project(console_app C)

set(CMAKE_C_STANDARD 99)

add_executable(console_app ./src/main.c ./src/include/helper.c src/include/student/student_manager.c
        src/include/database/connector.c
        src/include/database/driver/mysql_driver.c src/include/database/driver/sqlite_driver.c src/include/student/student_manager.c)
find_package (SQLite3 REQUIRED)
if (SQLite3_FOUND)
    include_directories(${SQLite3_INCLUDE_DIRS})
    target_link_libraries (console_app ${SQLite3_LIBRARIES})
endif (SQLite3_FOUND)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(MYSQL REQUIRED)
if (MYSQL_FOUND)
    include_directories(${MYSQL_INCLUDE_DIR})
    target_link_libraries(console_app ${MYSQL_LIBRARIES})
endif (MYSQL_FOUND)


#include_directories(${MYSQL_INCLUDE_DIR})
#target_link_libraries(cgm ${MYSQL_LIB})
#find_package(MySQL REQUIRED)

#find_package (SQLite3)
#include_directories(/usr/include)
#link_directories(/usr/lib)
#target_link_libraries(console_app sqlite3)

