# Project: Push Swap

## Overview
Push Swap is a project that implements a sorting algorithm using a stack-based approach. The goal is to sort a list of integers using a series of operations on two stacks, while minimizing the number of operations performed.

## Files
- **src/**
  - `ft_memset.c`: Implements the `ft_memset` function to set memory bytes.
  - `ft_strlen.c`: Implements the `ft_strlen` function to calculate string length.
  - `last_node.c`: Implements the `last_node` function to find the last node in a linked list.
  - `ft_calloc.c`: Implements the `ft_calloc` function for memory allocation and initialization.
  - `ft_split.c`: Implements the `ft_split` function to split strings into substrings.
  - `ft_atol.c`: Implements the `ft_atol` function to convert strings to long integers.
  - `create_node.c`: Implements the `create_node` function to create linked list nodes.
  - `sort_operations.c`: Implements sorting functions for linked lists.
  - `operations.c`: Implements various operations on linked lists.
  - `utility.c`: Implements utility functions for managing linked lists.

- **include/**
  - `push_swap.h`: Contains definitions for the linked list structure and function prototypes.

- **Makefile**: Contains build instructions for compiling the project.

## Installation
To compile the project, use the provided Makefile. Run the following command in the terminal:

```
make
```

This will compile the source files and create the executable.

## Usage
After compiling, you can run the program with a list of integers as arguments. The program will sort the integers using the implemented algorithm.

Example usage:

```
./push_swap 3 2 1
```

This will sort the numbers 3, 2, and 1 using the push swap algorithm.