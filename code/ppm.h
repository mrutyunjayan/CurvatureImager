/* date = August 15th 2020 4:24 am */

#ifndef PPM_H
#define PPM_H

#include <string.h>

typedef struct {
    uint8_t type;
    uint16_t width;
    uint16_t height;
    char name[31];
} ppmInfo;

ppmInfo* ppmCreateInfo(uint8_t type,
                       uint16_t width,
                       uint16_t height,
                       char* name /*MAX 31 chars*/ ) {
    ppmInfo* newPpmInfo = (ppmInfo*)malloc(sizeof(ppmInfo));
    
    newPpmInfo->type = type;
    newPpmInfo->width = width;
    newPpmInfo->height = height;
    strcpy(newPpmInfo->name,
           name);
    
    return (newPpmInfo);
}

void ppmDeleteInfo(ppmInfo* ppm) {
    free(ppm);
}

int ppmPrint(ppmInfo* ppm,
             outString* buffer) {
    uint16_t errorCode;
    
    errorCode = sprintf(buffer->data,
                        "P%d\n#%s\n%d %d\n",
                        ppm->type, ppm->name, ppm->width, ppm->height);
    outStringUpdateLength(buffer);
    return (errorCode);
}



#endif //PPM_H
