# C++ Data Structures, Algorithms, and OOP

Welcome to my C++ repository! This repository contains implementations of various Data Structures, Algorithms, and Object-Oriented Programming (OOP) concepts learned during my Udemy study. The codebase is organized topic-wise to serve as a clean reference for learning and future development.

---

## 📁 Repository Structure

The repository is structured into the following folders based on the topic:

### 1. [`arrays-and-vectors/`](./arrays-and-vectors/)
Focuses on dynamic arrays (`std::vector`) and multidimensional array/matrix operations.
*   `vector_basics.cpp` — Demonstrates C++ STL `vector` operations, resizing, capacity, and `at()` function.
*   `spiral_order_matrix.cpp` — Implements the spiral order traversal of a 2D matrix.

### 2. [`oop/`](./oop/)
Contains files demonstrating Object-Oriented Programming concepts in C++.
*   `const_member_functions.cpp` — Explains constant functions and how they restrict object modification.
*   `copy_constructor.cpp` — Demonstrates default and custom copy constructors.
*   `deep_shallow_copy.cpp` — Deep vs. shallow copy behavior in classes with pointers.
*   `friend_function.cpp` — Demonstrates friend classes and friend functions.
*   `initialization_list.cpp` — Explains C++ initialization lists for constructor parameters.
*   `operator_overloading.cpp` — Custom operator overloading (`+`, `*`, `==`, pre-increment `++`).
*   `fraction_operator_overloading.cpp` — Custom post-increment `++` operator overloading in a `Fraction` class.
*   `fraction_class.cpp` — Basic `Fraction` class implementation.
*   `class_template_single_type.cpp` — Class templates with a single generic parameter.
*   `class_template_multiple_types.cpp` — Class templates with multiple generic parameters and nesting.
*   `virtual_base_class.cpp` — Shows how virtual base classes resolve the diamond inheritance problem.

### 3. [`recursion/`](./recursion/)
Contains classic recursive algorithms and mathematical problems solved using recursion.
*   `fibonacci.cpp` — Computes Fibonacci numbers recursively.
*   `is_array_sorted.cpp` — Checks if an array is sorted recursively.
*   `count_zeros.cpp` — Counts the number of zeros in a number.
*   `find_element.cpp` — Checks if a specific element is present in an array.
*   `first_index.cpp` — Returns the first index of an element in an array.
*   `geometric_progression.cpp` — Computes the sum of a Geometric Progression recursively.
*   `multiply.cpp` — Performs multiplication using addition and recursion.
*   `power.cpp` — Computes $X^N$ recursively.
*   `print_numbers.cpp` — Prints numbers from 1 to N recursively.
*   `sum_array.cpp` — Computes the sum of array elements.

### 4. [`searching-and-sorting/`](./searching-and-sorting/)
Contains basic search and sort algorithms.
*   `linear_search.cpp` — Searches elements sequentially in an array.
*   `binary_search.cpp` — Fast search on sorted arrays.
*   `bubble_sort.cpp` — Implements Bubble Sort algorithm.
*   `selection_sort.cpp` — Implements Selection Sort algorithm.

### 5. [`linked-lists/`](./linked-lists/)
Contains singly linked list implementations and various operations on nodes.
*   `linked_list_basics.cpp` — Creating, inserting, and displaying a linked list.
*   `linked_list_insert_node.cpp` — Inserting a node at a specific position.
*   `linked_list_delete_node.cpp` — Deleting a node from a specific position.
*   `linked_list_search.cpp` — Searching for an element in a linked list.
*   `linked_list_length_recursive.cpp` — Finding the length of a linked list recursively.

### 6. [`stacks/`](./stacks/)
Implements Stack data structure using different underlying collections.
*   `stack_array_implementation.cpp` — Static array-based stack implementation.
*   `stack_dynamic_array.cpp` — Dynamic array-based stack (automatically doubles size when full).
*   `stack_vector_implementation.cpp` — Stack wrapper around `std::vector`.
*   `stack_linked_list_implementation.cpp` — Stack implemented using a Linked List.
*   `stack_templates.cpp` — Generic stack implementation using templates.
*   `stack_std_library.cpp` — Demonstrates C++ STL `std::stack`.

### 7. [`queues/`](./queues/)
Implements Queue data structure.
*   `queue_array_implementation.cpp` — Queue implementation using a circular array.
*   `queue_linked_list_implementation.cpp` — Queue implementation using a Linked List.
*   `queue_std_library.cpp` — Demonstrates C++ STL `std::queue`.
*   `queue_reverse.cpp` — Reverses a queue using recursion/stacks.

### 8. [`trees/`](./trees/)
Covers Tree structures (N-ary Trees, Binary Trees, and Binary Search Trees).
*   `generic_tree.cpp` — Generic N-ary tree node, tree inputs, level-wise traversals, and pre/post-order traversals.
*   `binary_tree.cpp` — Binary tree structure and operations.
*   `count_nodes.cpp` — Counts the number of nodes in a tree.
*   `binary_search_tree.cpp` — Binary Search Tree (BST) insertion, search, and validation.

### 9. [`hashmaps/`](./hashmaps/)
Covers hashing-based data structures and applications.
*   `unordered_map_basics.cpp` — Insertion, deletion, search in `std::unordered_map`.
*   `hashmap_iterator.cpp` — Iterating through maps and vectors.
*   `hashmap_custom_implementation.cpp` — Implements a custom Hash Map with separate chaining (rehashing and load factor).
*   `remove_duplicates.cpp` — Removes duplicate elements from a vector using a hash map.

### 10. [`graphs/`](./graphs/)
Covers graph traversals, visualizers, and search algorithms.
*   `bfs.cpp` — Breadth-First Search traversal on graphs.
*   `dfs.cpp` — Depth-First Search traversal on graphs.
*   `best_first_search.cpp` — Greedy Best-First Search heuristic algorithm.
*   `graph_visualization.py` — Python script to visualize graphs and search traversals.

### 11. [`backtracking/`](./backtracking/)
Backtracking algorithmic approach.
*   `n_queens.cpp` — Solves the classic N-Queens problem on a chess board.

### 12. [`artificial-intelligence/`](./artificial-intelligence/)
Advanced game-theory and AI algorithms.
*   `alpha_beta_pruning.cpp` — Alpha-beta pruning optimizations for the Minimax algorithm.

---

## 🛠️ How to Compile & Run

Make sure you have a C++ compiler installed (e.g., `g++` from GCC).

1.  Open your terminal and navigate to the directory containing the file:
    ```bash
    cd "searching-and-sorting"
    ```
2.  Compile the C++ source file using:
    ```bash
    g++ -std=c++17 binary_search.cpp -o binary_search
    ```
3.  Run the compiled binary:
    ```bash
    ./binary_search
    ```
