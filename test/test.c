#include <stdio.h>

typedef enum{charType,shortType,intType} primitiveType;

static int getSize(primitiveType type);

int main(){
    printf("hello world\n");
    primitiveType c = charType;
    primitiveType s = shortType;
    primitiveType i = intType;
    printf("%d\n", getSize(c) & 0xff);
    printf("%d\n", getSize(s) & 0xffff);
    printf("%d\n", getSize(i) & 0xffffffff);
    return 0;
}

static int getSize(primitiveType type) {
    if(type == charType)
        return sizeof(char);
    else if(type == shortType)
        return sizeof(short);
    else if(type == intType)
        return sizeof(int);
    else
        return 0;
}
