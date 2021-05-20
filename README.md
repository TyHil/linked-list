# linked-list
[![Run on Repl.it](https://repl.it/badge/github/TyHil/linked-list)](https://repl.it/github/TyHil/linked-list)
## Description
A singly linked list C++ library  
## Documentation
### Clear
`template <typename T> void linkedList<T>::clear()`  
Clears and deletes all nodes and data.  
### Add
`template <typename T> void linkedList<T>::add(T * newData)`  
Adds a new node with specified data to the end of the linked list.  
Parameters: `T * newData`: pointer to new data to be stored  
### Size
`template <typename T> int linkedList<T>::size()`  
Returns the number of nodes.  
Returns: `int`: the size of the linked list.  
### Get
`template <typename T> node<T> * linkedList<T>::get(const int indexGoal)`  
Returns a pointer to the node at a specific index.  
Parameters: `const int indexGoal`: index of desired node  
Returns: `node<T> *`: a pointer to the node at the specified index  
### Set
`template <typename T> void linkedList<T>::set(const int indexGoal, T * newData)`  
Replaces the data of node at the specified index with new data.  
Parameters: `const int indexGoal`: index of desired node, `T * newData`: pointer to new data to be stored  
### Insert
`void insert(const int indexGoal, void * newData)`  
Inserts a new node and new data before the specified index.  
Parameters: `const int indexGoal`: index of node to be after new node, `void * newData`: pointer to new data to be stored  
### Remove
`template <typename T> void linkedList<T>::remove(const int indexGoal)`  
Removes the node and data at the specified index.  
Parameters: `const int indexGoal`: index of node to be deleted  
### Is Empty
`template <typename T> bool linkedList<T>::isEmpty()`  
Returns true if the linked list has no elements in it.  
Returns: `bool`: whether the linked list is empty  
### Swap
`template <typename T> void linkedList<T>::swap(const int index1, const int index2)`  
Switches the data pointers of the nodes at the specified indexes.  
Parameters: `const int index1`: index of the first specified node, `const int index2`: index of the second specified node  
### Sub List
`template <typename T> linkedList<T> * linkedList<T>::subList(const int start, const int length)`  
Creates and returns a new list containing data from a sub-range of the linked list.  
Parameters: `const int start`: starting index of the sub-range, `const int length`: length of the sub-range (start + length is not included in the new linked list)  
Returns: `linkedList *`: a pointer to the new linked list  
## License
GPL-3.0 License
