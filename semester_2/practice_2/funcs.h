#include <stdbool.h>


int* array_create(int len);
bool array_pushback(int* arr, int len, int elem);
bool array_popback(int* arr, int len);
bool array_insert(int *arr, int len, int *elems, int nelems, int pos);
bool array_remove(int *arr, int len, int pos, int nelems);
