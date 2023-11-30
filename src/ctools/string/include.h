#ifndef CTOOLS_STRING_H
#define CTOOLS_STRING_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../memory/include.h"

char* str_snprintf(const char* format, ...);
void str_to_upper(char** str);
void str_to_lower(char** str);
int str_find_char(const char* str, char c);
int str_find_char_reverse(const char* str, char c);
int str_find_str(const char* str, const char* sub);
static char* _str_strrstr(const char* str, const char* sub) ;
int str_find_str_reverse(const char* str, const char* sub) ;
char* str_add_str(char** str, const char* add);
char* str_add_char(char** str, char add);
char* str_int(const double num);

#endif

