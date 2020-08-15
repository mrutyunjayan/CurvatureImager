#include "main.h"
#include "outString.h"
#include "ppm.h"

#define numOfElements(a)                                                       \
{ (sizeof(a) / sizeof(a[0])) }
// size of array / size of each element in the array}
//   bytes       /          bytes

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char** argv) {
    const int imageHeight = 2;
    const int imageWidth = 3;
    
    outString buffer;
    printf("%d", sizeof(buffer));
    buffer.data = (char*)malloc(DEFAULT_STRING_SIZE);
    buffer.allocation = DEFAULT_STRING_SIZE;
    
    ppmInfo* image = ppmCreateInfo(6,
                                   WIDTH,
                                   HEIGHT,
                                   "image");
    if (ppmPrint(image,
                 &buffer) < 0) {
        printf("ERROR writing to string");
        return (-1);
    }
    
    printf("length: %d\n",
           buffer.length);
    
    FILE* fileHandle = fopen("image.txt",
                             "w");
    fprintf(fileHandle,
            "%s", buffer.data);
    //FREE
    free(buffer.data);
    ppmDeleteInfo(image);
    
    return (0);
}
