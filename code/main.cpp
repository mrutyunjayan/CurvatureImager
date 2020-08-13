#include "jstring.h"

#define numOfElements(a)                                                       \
{ (sizeof(a) / sizeof(a[0])) }
// size of array / size of each element in the array}
//   bytes       /          bytes

#define WIDTH 4
#define HEIGHT 4

int main(int argc, char** argv) {
    const int imageHeight = 2;
    const int imageWidth = 3;
    
    char* img = "P6\n#image.ppm\n";
    
    jString test = jStringNew(img);
    jStringAdd(&test,
               " world");
    
    printf("string: %s\nallocation:  %d\nlength:  %d\n ",
           test.data,
           test.alloc,
           test.length);
    
    int imgSize = numOfElements(test.data);
    
    FILE* fileHandle = fopen("image.txt",
                             "w");
    fprintf(fileHandle,
            "%s", test.data);
    
    jStringFree(&test);
    
    return (0);
}
