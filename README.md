# linked-list
[![Run on Repl.it](https://repl.it/badge/github/TyHil/linked-list)](https://repl.it/github/TyHil/linked-list)
## Description
A singly linked list C++ library  
## Documentation
See `test.cpp` for examples.  
`template <typename T>` partially specialized for `T` or `T *`.  
### Initialization examples
`LinkedList<int> list = LinkedList<int>();`  
`LinkedList<Card *> list = LinkedList<Card *>();`  
### Constructor
`LinkedList()`  
Create a new `LinkedList` with no data.
### Copy Constructor
`LinkedList(LinkedList const &source)`  
Create a new `LinkedList` with copy of data from source.  
Parameters:  
&nbsp;&nbsp;`LinkedList const &source`: list to copy data from.  
### Destructor
`~LinkedList()`
Calls `clear()`.  
### Clear
`void clear()`  
Clears and deletes all nodes and data.  
### Add
`void add(T data)`  
`void add(T *data)`  
Adds a new node with specified data to the end of the linked list.  
Parameters:  
&nbsp;&nbsp;`T data` or `T *data`: primitive data or pointer to new data to be stored  
### Size
`int size()`  
Returns the number of nodes.  
Returns:  
&nbsp;&nbsp;`int`: the size of the linked list.  
### Set
`void set(const int index, T data)`  
`void set(const int index, T *data)`  
Replaces the data of the node at the specified index with new data.  
Parameters:  
&nbsp;&nbsp;`const int index`: index of desired node  
&nbsp;&nbsp;`T data` or `T *data`: primitive data or pointer to new data to be stored  
### Insert
`void insert(const int index, T data)`  
`void insert(const int index, T *data)`  
Inserts a new node and new data before the specified index.  
Parameters:  
&nbsp;&nbsp;`const int index`: index of node to be after new node  
&nbsp;&nbsp;`T data` or `T *data`: primitive data or pointer to new data to be stored  
### Remove
`void remove(const int index)`  
Removes the node and data at the specified index.  
Parameters:  
&nbsp;&nbsp;`const int index`: index of node to be deleted  
### Empty
`bool empty()`  
Returns true if the linked list has no elements in it.  
Returns:  
&nbsp;&nbsp;`bool`: whether the linked list is empty  
### Swap
`void swap(const int index1, const int index2)`  
Switches the data of the nodes at the specified indexes.  
Parameters:  
&nbsp;&nbsp;`const int index1`: index of the first specified node  
&nbsp;&nbsp;`const int index2`: index of the second specified node  
### Sub List
`LinkedList<T> * subList(const int start, const int length)`  
Creates and returns a new list containing data from a sub-range of the linked list.  
Parameters:  
&nbsp;&nbsp;`const int start`: starting index of the sub-range  
&nbsp;&nbsp;`const int length`: length of the sub-range (start + length is not included in the new linked list)  
Returns:  
&nbsp;&nbsp;`LinkedList *`: a pointer to the new linked list  
### Overload `[]`
`T operator[](const int index)`  
`T *operator[](const int index)`  
Access data at the given index.  
Parameters:  
&nbsp;&nbsp;`const int index`: index of desired node  
Returns:  
&nbsp;&nbsp;`T ` or `T *`: primitive data or pointer to data  
### Overload `<<`
`std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)`  
`std::ostream &operator<<(std::ostream &os, const LinkedList<T *> &list)`  
Print the data in the list to the ostream. The class in a pointer list `T *` must also overload the `<<` operator.  
Parameters:  
&nbsp;&nbsp;`std::ostream &os`: ostream data being added to  
&nbsp;&nbsp;`const LinkedList<T> &list` or `const LinkedList<T *> &list`: list to be printed  
Returns: `std::ostream &`: ostream with added data  
## License
GPL-3.0 License
