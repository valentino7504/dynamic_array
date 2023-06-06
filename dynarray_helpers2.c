#include "dynamic_array.h"
/**
 * update_element - updates an element at a particular index in a dynamic array
 * @array: the array
 * @index: the index to update
 * @new_value: the new value
 */
void update_element(DynamicArray *array, size_t index, void *new_value)
{
	if (index >= array->length)
	{
		printf("Error: Index out of range. ");
		printf("Index provided exceeds valid range of array");
		return;
	}
	if (new_value == NULL)
	{
		printf("Error: Invalid value provided. ");
		printf("Cannot update element with a NULL value.");
		return;
	}
	array->data[index] = new_value;
}
/**
 * remove_element - removes an element at a particular index
 * @array: the array to be edited
 * @index: the index of the element to be deleted
 */
void remove_element(DynamicArray *array, size_t index)
{
	size_t i;

	if (index >= array->length)
	{
		printf("Error: Index out of range. ");
		printf("Index provided exceeds valid range of array");
		return;
	}
	for (i = index; i < (array->length - 1); i++)
		array->data[i] = array->data[i + 1];
	free(array->data[array->length - 1]);
	array->length -= 1;
}
