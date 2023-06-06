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

    // Remove an element from the array
    array->delete_element(array->self, 0);
    print_int_element(array->self, 0);

    array->push(array->self, &element2);
    array->push(array->self, &element3);
    print_int_element(array->self, 1);
    print_int_element(array->self, 2);
    printf("array length: %zu\n", array->length);

    // Free the dynamic array
    array->delete_array(array->self);
    return 0;
}
```

### Output

Here is the output of the above code. I used Valgrind to check for memory leaks.

```console
user@hostname:~/c/dynamic_array$ gcc dynarray_helpers*.c main.c -o main
user@hostname:~/c/dynamic_array$ ./main
Element at index 0: 10
Element at index 1: 20
Element at index 1: 30
Element at index 0: 30
Element at index 1: 20
Element at index 2: 55
array length: 3
user@hostname:~/c/dynamic_array$ valgrind ./main
==5757== Memcheck, a memory error detector
==5757== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5757== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==5757== Command: ./main
==5757== 
Element at index 0: 10
Element at index 1: 20
Element at index 1: 30
Element at index 0: 30
Element at index 1: 20
Element at index 2: 55
array length: 3
==5757== 
==5757== HEAP SUMMARY:
==5757==     in use at exit: 0 bytes in 0 blocks
==5757==   total heap usage: 5 allocs, 5 frees, 1,160 bytes allocated
==5757== 
==5757== All heap blocks were freed -- no leaks are possible
==5757== 
==5757== For lists of detected and suppressed errors, rerun with: -s
==5757== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Tests

At the moment, test cases for the dynamic array functions have not been implemented. Due to time constraints, I have not been able to thoroughly test the functionality of the dynamic array. I plan to add test cases at some point in the future though so watch this space I guess😂

## Conclusion

In conclusion, this dynamic array implementation provides a solution for managing resizable arrays in C. I utilized function pointers and a self-reference within the struct, to offer a convenient interface for manipulating the array and accessing its elements. While comprehensive test cases have not been provided at this time, I do suggest you develop and run tests to ensure the proper functioning of the dynamic array in different scenarios.
