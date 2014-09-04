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
   arrayList* list = (arrayList*) malloc(sizeof(arrayList));
   list->elementSize = getSize(type);
   list->numElements = 0;
   list->arraySize = 0;
   list->type = type;
   return list;
}

/* 
 */
void addElement(arrayList * arylstP, void * element)
{
    return; 
}

/* 
 */
void removeElement(arrayList * arylstP, int index)
{
    return;
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
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
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
