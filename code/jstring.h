/* date = August 6th 2020 7:24 pm */

#ifndef JSTRIN_H
#define JSTRIN_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define kiloBytes(value) ((value) * 1024LL)
#define megaBytes(value) (kiloBytes(value) * 1024LL)
#define gigaBytes(value) (megaBytes(value) * 1024LL)
#define teraBytes(value) (gigaBytes(value) * 1024LL)

#define DEFAULT_STRING_SIZE megaBytes(2)

//define a string
typedef struct {
    size_t alloc; //Stores the # of bytes allocated
    size_t length;
    char* data;
} jString;

//length of string
unsigned int jStrLen(char* charStr) {
    unsigned int len = 0;
    char* p = charStr; 
    
    while(*p != '\0') {
        ++len;
        ++p;
    }
    
    return (len);
}

//create a new string
jString jStringNew(char* charStr) {
    jString str  = {};
    
    if (charStr != NULL) {
        str.alloc = DEFAULT_STRING_SIZE;
        str.length = jStrLen(charStr);
        
        memcpy(str.data,
               charStr,
               str.length);
        str.data[str.length] = '\0';
    } else {
        str.alloc = 1;
        str.data = (char*)malloc(1);
        str.data[0] = '\0';
        str.length = 0;
    }
    
    return (str);
}

//grow the string
void jStringGrow(jString* str) {
    str->data = (char*)realloc(str->data,
                               (str->alloc + megaBytes(2)));
}

void jStringAdd(jString str, char* newChars) {
    unsigned int strLength = jStrLen(str.data);
    unsigned int newCharLength = jStrLen(newChars);
    unsigned int newLength = strLength + newCharLength;
    
    if ((strLength + newCharLength) >= str.alloc) {
        jStringGrow(&str);
    }
    memcpy((str.data + str.length), 
           newChars, 
           newCharLength);
    str.data[newLength] = '\0';
    str.length = newLength;
}

#endif //JSTRING_H
