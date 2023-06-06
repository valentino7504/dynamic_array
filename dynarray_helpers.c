#include "dynamic_array.h"
/**
 * create_array - creates a dynamic array of capacity 2
 * Return: a pointer to the array
 */
DynamicArray *create_array()
{
	DynamicArray *array = NULL;

	array = malloc(sizeof(DynamicArray));
	if (array == NULL)
		return (NULL);
	array->data = malloc(sizeof(void *));
	if (array->data == NULL)
	{
		free(array);
		printf("Failed to create dynamic array\n");
		return (NULL);
	}
	array->capacity = 1;
	array->length = 0;
	array->self = array;
	array->delete_array = &free_dynarray;
	array->get = &get_element;
	array->resize = &resize_array;
	array->push = &dynarray_push;
	array->update_element = &update_element;
	array->delete_element = &remove_element;
	return (array);
}
/**
 * free_dynarray - this function frees up a dynamic array
 * @array: the array to be freed
 */
void free_dynarray(DynamicArray *array)
{
	int i = 0;

	for (i = 0; i < array->length; i++)
		free(array->data[i]);
	free(array->data);
	free(array);
}
/**
 * get_element - returns an element in a array
 * @array: the array
 * @index: the index of the element
 * Return: a pointer to the element
 */
void *get_element(DynamicArray *array, size_t index)
{
	if (index >= array->length)
	{
		printf("Error: Index out of range. ");
		printf("Index provided exceeds valid range of array");
		return (NULL);
	}
	return (array->data[index]);
}
/**
 * resize_array - doubles the capacity of the array
 * @array: the dynamic array
 */
void resize_array(DynamicArray *array)
{
	void **temp = realloc(array->data, sizeof(void *) * array->capacity * 2);

	if (temp == NULL)
	{
		free(temp);
		return;
	}
	array->data = temp;
	array->capacity *= 2;
}
/**
 * dynarray_push - adds an element to the end of the dynamic array
 * @array: the array to which the element is to be added
 * @new_element: the element to be added
 */
void dynarray_push(DynamicArray *array, void *new_element)
{
	size_t old_capacity = array->capacity;

	if (array->length == array->capacity)
	{
		array->resize(array->self);
		if (array->capacity == old_capacity)
			return;
	}
	array->data[array->length] = new_element;
	array->length += 1;
}
