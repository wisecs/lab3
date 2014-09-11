#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/* Returns the size in bytes of the data type that the parameter type represents.
 * Parameters: type - a primitiveType enum
 * Return: the number of bytes.  0 indicates an incorrect parameter.
 */
static int getSize(primitiveType type)
{
    if(type == charType)
        return  sizeof(char);
    else if(type == shortType)
        return sizeof(short);
    else if(type == intType)
        return sizeof(int);
    else return -1;
}

/* Dynamically allocates a new arrayList with size of 4 and returns it.
 * Parameters: type - the primitiveType that you want the array to be of
 * Return: an arrayList of the specified type
 */
arrayList * initialize(primitiveType type)
{
    arrayList* list = malloc(sizeof(arrayList));
    list->elementSize = getSize(type);
    list->array = malloc(list->elementSize * 4);
    list->numElements = 0;
    list->arraySize = 4;
    list->type = type;
   
    return list;
}

/* Appends the specified element to the specified arrayList.  Doubles the size of the
 * array if it is at capacity.
 * Parameters: arylstP - a pointer to the arrayList you want to add to
 *             element - a pointer to the element you want to add
 */
void addElement(arrayList * arylstP, void * element)
{
    if(arylstP->numElements == arylstP->arraySize){
        char* array = malloc(arylstP->numElements * 2 * arylstP->elementSize);
        int i;
        for(i = 0; i < (arylstP->numElements * arylstP->elementSize); i++) {
            ((char*) array)[i] = ((char*) arylstP->array)[i];
        }
        arylstP->array = array;
        arylstP->arraySize *= 2;
    }
    int pos = arylstP->numElements; 
    if(arylstP->type == charType)
        ((char*) arylstP->array)[pos] = *((char*) element);
    else if(arylstP->type == shortType)
        ((short*) arylstP->array)[pos] = *(short*)element;
    else if(arylstP->type == intType)
        ((int*) arylstP->array)[pos] = *((int*)element);
    arylstP->numElements++;
    return;
}

/* Removes the element at the speified index, shifting all following elements left
 * Paremeters: arylstP - pointer to the arrayList you want to remove from
 *             index - the index of the element you want to remove
 */
void removeElement(arrayList * arylstP, int index)
{
    int n = arylstP->numElements--;
    for(;index < n+1; index++) {
        if (arylstP->type == charType){
            ((char*) arylstP->array)[index] = ((char*)arylstP->array)[index+1];
        }
        else if (arylstP->type == shortType){
            ((short*) arylstP->array)[index] = ((short*)arylstP->array)[index+1];
        }
        else if (arylstP->type == intType){
            ((int*) arylstP->array)[index] = ((int*)arylstP->array)[index+1];
        }
    }
    return;
}

/* Prints the specified arrayList
 * Parameters: arylstP - a pointer to the arrayList you want to print
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

