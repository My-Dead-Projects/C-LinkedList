#include "String.h"

String String_new()
{
    String str;
    str.alloc = false;
    str.buf = NULL;
    return str;
}

void String_copyFromRaw(String * str, const char * src)
{
    String_dealloc(str);
    str->buf = malloc(sizeof(src));
    strcpy(str->buf, src);
    str->alloc = true;
}

void String_copyFromStr(String * str, const String src)
{
    String_dealloc(str);
    str->buf = malloc(sizeof(src.buf));
    strcpy(str->buf, src.buf);
    str->alloc = true;
}

void String_moveFromRaw(String * str, const char * src)
{
    String_dealloc(str);
    strcpy(str->buf, src);
}

void String_moveFromStr(String * str, const String src)
{
    String_dealloc(str);
    strcpy(str->buf, src.buf);
}

void String_dealloc(String * str)
{
    if (str->alloc)
    {
        free(str->buf);
        str->buf = NULL;
        str->alloc = false;
    }
}
