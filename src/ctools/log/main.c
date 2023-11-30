#include "include.h"

// create a log
Log log_init(FILE* file,char* name){
    assert(file != NULL && "file is NULL");
    assert(name != NULL && "name is NULL");
    Log log = {
        .file = file,
        .name = name
    };
    return log;
}
// write a message to the log
void log_message(Log* log,int level,char* format,...){
    if(level == LOG_EMERGENCY || level == LOG_ERROR){log->_exit = 1;}
    va_list args;
    va_start(args, format);
    fprintf(
        log->file, 
        "%s[%s%s%s][in: %s%s%s][msg: ",
        WHITE, 
        log_level_colors[level],
        log_level_names[level], 
        WHITE, 
        MAGENTA,
        log->name,
        WHITE
    );
    vfprintf(log->file, format, args);
    fprintf(log->file, "]\n%s",RESET);
    va_end(args);
}
// log check
void log_check(Log* log){ if(log->_exit){ exit(1); } }
