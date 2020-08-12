#include "jstring.h"

#define numOfElements(a)                                                       \
{ (sizeof(a) / sizeof(a[0])) }
// size of array / size of each element in the array}
//   bytes       /          bytes

int main(int argc, char** argv) {
#if 0
    const int imageHeight = 2;
    const int imageWidth = 3;
    
    char* hw[] ;
    printf("%s\n", hw);
    int hwSize = numOfElements(hw);
    
    FILE* fileHandle = fopen("image.ppm",
                             "w");
    fprintf(fileHandle,
            "%s", hw);
#endif
    
    return (0);
}
