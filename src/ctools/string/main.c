#include "include.h"

// craete string based of format
char* str_snprintf(const char* format, ...){
    if(!format) return NULL;
    va_list args;
    va_start(args, format);
    size_t size = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);
    char* buffer = mem_alloc((size+1)*sizeof(char));
    va_start(args, format);
    vsnprintf(buffer, size, format, args);
    va_end(args);
    return buffer;
}
// make every letter capital
void str_to_upper(char** str){
    if(str == NULL || *str == NULL || (*str)[0] == '\0') return;
    for(size_t i=0;(*str)[i] != '\0'; i++){(*str)[i] = toupper((*str)[i]);}
}
// make every letter small
void str_to_lower(char** str){
    if(str == NULL || *str == NULL || (*str)[0] == '\0') return;
    for(size_t i=0;(*str)[i] != '\0'; i++){(*str)[i] = tolower((*str)[i]);}
}
// find char from start
int str_find_char(const char* str, char c){
    if(str == NULL || str[0] == '\0') return -1;
    for(size_t i=0;str[i] != '\0';i++){ if(str[i] == c) return i; }
    return -1;
}
// find char from end
int str_find_char_reverse(const char* str, char c){
    if(str == NULL || str[0] == '\0') return -1;
    for(size_t i=strlen(str)-1;i>=0;i--){ if(str[i] == c) return i; }
    return -1;
}
// find string from start
int str_find_str(const char* str, const char* sub){
    if(str == NULL || sub == NULL) return -1;
    char* locate = strstr((char*)str, sub);
    if(locate == NULL) return -1;
    return locate - str;
}
// find string from end
static char* _str_strrstr(const char* str, const char* sub) {
    if(str == NULL || sub == NULL) return NULL;
    int size = strlen(sub);
    char* res = NULL;
    char* loc = strstr((char*)str, sub);
    while(loc != NULL){
        res = loc;
        loc = strstr(loc + size, sub);
    }
    return res;
}
// find string from end
int str_find_str_reverse(const char* str, const char* sub) {
    if(str == NULL || sub == NULL) return -1;
    char* loc = _str_strrstr(str, sub);
    if(loc == NULL) return -1;
    return loc - str;
}

// add string to a string
char* str_add_str(char** str, const char* add){
    if(str == NULL || add == NULL) return NULL;
    size_t size = strlen(*str);
    size_t add_size = strlen(add);
    *str = realloc(*str, sizeof(char)*(size+add_size+1));
    for(size_t i=0;i<add_size;i++){ (*str)[size+i] = add[i]; }
    (*str)[size+add_size] = '\0';
    return *str;
} 
// add char to a string
char* str_add_char(char** str, char add){
    if(str == NULL) return NULL;
    size_t size = strlen(*str);
    *str = realloc(*str, sizeof(char)*(size+2));
    (*str)[size] = add;
    (*str)[size+1] = '\0';
    return *str;
}
// stringify
char* str_int(const double num){
    char* str = mem_alloc(sizeof(char)*100);
    if(num == (int)num) sprintf(str,"%d",(int)num);
    else sprintf(str,"%f",num);
    return str;
} 
