#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char * buf;

    /*
     * `alloc` is true if it is the responsibility of this object
     * to deallocate `buf`.
     */
    bool alloc;
    
} String;

String String_new();
void String_copyFromRaw(String * str, const char * src);
void String_copyFromStr(String * str, const String src);
void String_moveFromRaw(String * str, const char * src);
void String_moveFromStr(String * str, const String src);
void String_dealloc(String * str);
