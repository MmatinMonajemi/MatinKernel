#ifndef MATIN_STRING_H
#define MATIN_STRING_H

#include <stddef.h>

int matin_strcmp(const char* s1, const char* s2);
int matin_strncmp(const char* s1, const char* s2, size_t n);
size_t matin_strlen(const char* str);

#endif
