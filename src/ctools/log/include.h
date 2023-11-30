#ifndef CTOOLS_LOG_H
#define CTOOLS_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

#include "../std/include.h"

typedef struct{
    FILE* file;
    char* name;
    int _exit;
} Log;

static const char* log_level_colors[] = {
    RED,RED,
    MAGENTA,YELLOW,BLUE,
};
static const char* log_level_names[] = {
    "EMERGENCY","ERROR",
    "WARNING","NOTICE","INFO",
};
enum{
    LOG_EMERGENCY,LOG_ERROR,
    LOG_WARNING,LOG_NOTICE,LOG_INFO,
} LogLevel; 

Log log_init(FILE* file,char* name);
void log_message(Log* log,int level,char* format,...);
void log_check(Log* log);

#endif


