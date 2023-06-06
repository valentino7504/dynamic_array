# Dynamic Array

This project is a simple implementation of a dynamic array in C. It provides functions to create, manipulate, and manage dynamic arrays.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Functions](#functions)
- [Examples](#example-usage)
- [Tests](#tests)
- [Conclusion](#conclusion)

## Introduction

A dynamic array is a resizable array that can grow or shrink as needed. It provides the flexibility to add or remove elements at runtime. My implementation provides a struct `DynamicArray` and a set of functions to create, modify, and delete dynamic arrays.

## Usage

To use the Dynamic Array Library in your C program, follow these steps:

- Include the `dynamic_array.h` header file in your source file:

```c
#include "dynamic_array.h"
```

- Compile your program with the dynarray_helpers files.

```c
gcc dynarray_helpers*.c your_program.c -o your_program
```

- Use the provided functions to manipulate and manage your dynamic array/list

## Functions

- ``DynamicArray *create_array()``: Creates a new dynamic array of capacity 2.
- ``void delete_array(DynamicArray *array)``: Frees the memory allocated for a dynamic array.
- ``void *get(DynamicArray *array, size_t index)``: Retrieves an element at a specified index in the dynamic array.
- ``void resize(DynamicArray *array)``: Doubles the capacity of the dynamic array.
- ``void push(DynamicArray *array, void *new_element)``: Adds an element to the end of the dynamic array.
- ``void update_element(DynamicArray *array, size_t index, void *new_value)``: Updates an element at a specified index in the dynamic array.
- ``void delete_element(DynamicArray *array, size_t index)``: Removes an element at a specified index from the dynamic array.

## Example Usage

```c
#include <stdio.h>
#include "dynamic_array.h"

void print_int_element(int *element, size_t index) {
    if (element != NULL)
        printf("Element at index %zu: %d\n", index, *element);
}

int main() {
    // Create a new dynamic array
    DynamicArray *array = create_array();

    // Push elements to the array
    int element1 = 10;
    int element2 = 20;
    array->push(array->self, &element1);
    array->push(array->self, &element2);

    // Get and print elements from the array
    print_int_element(array->self, 0);
    print_int_element(array->self, 1);

    // Update an element in the array
    int newElement = 30;
    array->update_element(array->self, 1, &newElement);
    print_int_element(array->self, 1);

    // Free the dynamic array
    array->delete_array(array->self);
    return 0;
}
```

## Tests

At the moment, test cases for the dynamic array functions have not been implemented. Due to time constraints, I have not been able to thoroughly test the functionality of the dynamic array. I plan to add test cases at some point in the future though so watch this space I guess😂

## Conclusion

In conclusion, this dynamic array implementation provides a solution for managing resizable arrays in C. I utilized function pointers and a self-reference within the struct, to offer a convenient interface for manipulating the array and accessing its elements. While comprehensive test cases have not been provided at this time, I do suggest you develop and run tests to ensure the proper functioning of the dynamic array in different scenarios.
