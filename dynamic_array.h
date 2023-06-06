#ifndef DYNARRAY_H
#define DYNARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct DynamicArray DynamicArray;
/**
 * struct DynamicArray - implements a dynamic array in C
 * @data: the elements in the array
 * @length: the number of elements in the array currently
 * @capacity: the number of elements the array can take
 * @self: self reference to the dynamic array
 * @push: used to add an element at the end of the array
 * @get: retrieve element at a certain index
 * @update_element: updates an element at a certain index
 * @resize: dynamically allocates more memory for the array
 * @delete_element: deletes an element at a particular index
 * @delete_array: frees up the DynamicArray
 *
 * Description - A simple dynamic array implementation
 */
struct DynamicArray
{
	void **data;
	size_t length;
	size_t capacity;
	DynamicArray *self;
	void (*push)(DynamicArray *array, void *new_element);
	void *(*get)(DynamicArray *array, size_t index);
	void (*update_element)(DynamicArray *array, size_t index, void *new_value);
	void (*resize)(DynamicArray *array);
	void (*delete_element)(DynamicArray *, size_t index);
	void (*delete_array)(DynamicArray *);
};
DynamicArray *create_array();
void free_dynarray(DynamicArray *array);
void *get_element(DynamicArray *array, size_t index);
void resize_array(DynamicArray *array);
void dynarray_push(DynamicArray *array, void *new_element);
void update_element(DynamicArray *array, size_t index, void *new_value);
void remove_element(DynamicArray *array, size_t index);
#endif
