#include "main.h"
#include "outString.h"
#include "ppm.h"
#include "vec3.h"

#define WIDTH 3
#define HEIGHT 2
#define MAX_VALUE 255
#define PPM_TYPE 3

int main(int argc, char** argv) {
    outString buffer;
    buffer.data = (char*)malloc(DEFAULT_STRING_SIZE);
    buffer.allocation = DEFAULT_STRING_SIZE;
    
    ppmInfo* image = ppmCreateInfo(PPM_TYPE,
                                   WIDTH,
                                   HEIGHT,
                                   MAX_VALUE);
    if (ppmPrint(image,
                 &buffer) < 0) {
        printf("ERROR writing to string");
        return (-1);
    }
    
    Vec3 test;
    
    printf("Memory occuppied by Vec3: %d\n",
           sizeof(test));
    
    FILE* fileHandle = fopen("image.ppm",
                             "w");
    fprintf(fileHandle,
            "%s", buffer.data);
    //FREE
    free(buffer.data);
    ppmDeleteInfo(image);
    
    return (0);
}
