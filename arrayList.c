#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/* 
 */
arrayList * initialize(primitiveType type)
{
   arrayList list;
   list.array = malloc(sizeof(type)*10);
   list.elementSize = getSize(type);
   list.numElements = 0;
   list.arraySize = 10;
   list.type = type;
   
   arrayList* listP = &list;
   return listP;
}

/* 
 */
void addElement(arrayList * arylstP, void * element)
{
    /*if(arylstP->numElements == arylstP->arraySize)
        arylstP->array = malloc(sizeof(arylstP->array)*2);*/
    int pos = arylstP->elementSize * arylstP->numElements;
    switch(arylstP->type){
        case charType:
            ((char*) arylstP->array)[pos] = *((char*) element);
        case shortType:
            ((short*) arylstP->array)[pos] = *(short*)element;
        case intType:
            ((int*) arylstP->array)[pos] = *(int*)element;
    }
    arylstP->numElements++;
    return;
}

/* 
 */
void removeElement(arrayList * arylstP, int index)
{
    /*int pos = arylstP->elementSize * arylstP->numElements;
    switch(arylstP->type){
        case charType:
            ((char*) arylstP->array)[pos] = *((char*) element);
        case shortType:
            ((short*) arylstP->array)[pos] = *(short*)element;
        case intType:
            ((int*) arylstP->array)[pos] = *(int*)element;
    }
    arylstP->numElements++;
    return;*/
}

/* 
 */
void printArray(arrayList * arylstP)
{
    int i;
    printf("array size: %d, num elements: %d contents: ", 
        arylstP->arraySize, arylstP->numElements);
    for (i = 0; i < arylstP->numElements; i++)
    {
        if (arylstP->type == charType){
            char c = ((char*) arylstP->array)[i];
            printf("%02x ", c & 0xff);
        }
        else if (arylstP->type == shortType){
            short s = ((short*) arylstP->array)[i];
            printf("%04x ", s & 0xffff);
        }
        else if (arylstP->type == intType){
            int d = ((int*) arylstP->array)[i];
            printf("%08x ", d & 0xffffffff);
        }
    }
    printf("\n");
}

/* Returns the size in bytes of the data type that the parameter typ represents 
 * Parameters: type - a primitiveType enum
 * Return: the number of bytes.  0 indicates an incorrect parameter.
 */
static int getSize(primitiveType type)
{
    switch(type){
        case charType:
            return sizeof(char);
        case shortType:
            return sizeof(short);
        case intType:
            return sizeof(int);
        default:
            return 0;
    }
}
