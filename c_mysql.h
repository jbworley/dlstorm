/***************************************************************
 **
 **   DLSTORM   Deadline's Code Storm Library
 **
 **          /\
 **   ---- D/L \----
 **       \/
 **
 **   License:      BSD
 **   Copyright:    2013
 **   File:         c_mysql.h
 **   Description:  MySQL class wrapper
 **   Author:       Seth Parson
 **   Twitter:      @Sethcoder
 **   Website:      www.sethcoder.com
 **   Email:        defectiveseth@gmail.com
 **
 ** You must compile with `mysql_config --cflags --libs`
 **
 ******************************************************************************/
#include "dlstorm.h"
#include <mysql.h>
class C_MySQL {
public:
    C_MySQL(char *host, char *user, char *pass, char *db);
    ~C_MySQL();

    MYSQL *con;
    MYSQL_RES * Query(char *q);
    MYSQL_ROW Fetch_Object(MYSQL_RES *result);


};
