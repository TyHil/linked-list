# linked-list
## Description
A singly linked list C++ library
## Documentation
### Clear
`void clear()`  
Clears and deletes all nodes and data.  
### Add
`void add(void * newData)`  
Adds a new node with specified data to the end of the linked list.  
Parameters: `void * newData`: pointer to new data to be stored  
### Size
`int size()`  
Returns the number of nodes.  
Returns: `int`: the size of the linked list.  
### Get
`node * get(const int indexGoal)`  
Returns a pointer to the node at a specific index.  
Parameters: `const int indexGoal`: index of desired node  
Returns: `node *`: a pointer to the node at the specified index  
### Set
`void set(const int indexGoal, void * newData)`  
Replaces the data of node at the specified index with new data.  
Parameters: `const int indexGoal`: index of desired node, `void * newData`: pointer to new data to be stored  
### Insert
`void insert(const int indexGoal, void * newData)`  
Inserts a new node and new data before the specified index.  
Parameters: `const int indexGoal`: index of node to be after new node, `void * newData`: pointer to new data to be stored  
### Remove
`void remove(const int indexGoal)`  
Removes the node and data at the specified index.  
Parameters: `const int indexGoal`: index of node to be deleted  
### Is Empty
`bool isEmpty()`  
Returns true if the linked list has no elements in it.  
Returns: `bool`: whether the linked list is empty  
## Swap
`void swap(const int index1, const int index2)`
Switches the data pointers of the specified indexes.  
Parameters: `const int index1`: index of the first specified node, `const int index2`: index of the second specified node  
### Sub List
`linkedList * subList(const int start, const int length)`  
Creates and returns a new list containing data from a sub-range of the linked list.  
Parameters: `const int start`: starting index of the sub-range, `const int length`: length of the sub-range (start + length is not included in the new linked list)  
Returns: `linkedList *`: a pointer to the new linked list  
### Equals
`bool equals(linkedList * other)`  
Returns true if the linked list and the specified linked list contain the same data in the same order.  
Parameters: `linkedList * other`: a pointer to the other list to compare to  
Returns: `bool`: whether the lists are the same  
## License
GPL-3.0 License
