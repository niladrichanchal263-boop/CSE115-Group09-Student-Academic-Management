#include "extract_data.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void clearStdinBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
         /* discard */
    }
}

void trimWhitespace(char *str) {
    size_t len;
    size_t start = 0;

    if (str == NULL) {
        return;
    }

    len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[len - 1] = '\0';
        len--;
    }

    while (str[start] != '\0' && isspace((unsigned char)str[start])) {
        start++;
    }

    if (start > 0) {
        memmove(str, str + start, strlen(str + start) + 1);
    }
}
bool isSafeCsvString(const char *str) {
    size_t i;

    if (str == NULL || str[0] == '\0') {
        return false;
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',' || str[i] == '\n' || str[i] == '\r') {
            return false;
        }
    }
    return true;
}
   
