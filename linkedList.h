#include <ostream>

struct node {
  ~node();
  void * dataPtr;
  node * next;
};

class linkedList {
  node *head;// start node
  public:
    linkedList();// Constructor
    ~linkedList();// Destructor
    void clear();// Clears and deletes all nodes and data
    void add(void * newData);// Adds a new node with specified data to the end of the linked list
    int size();// Returns the number of nodes
    node * get(const int indexGoal);// Returns a pointer to the node at a specific index
    void set(const int indexGoal, void * newData);// Replaces the data of node at the specified index with new data
    void insert(const int indexGoal, void * newData);// Inserts a new node and new data before the specified index
    void remove(const int indexGoal);// Removes the node and data at the specified index
    bool isEmpty();// Returns true if the linked list has no elements in it
    void swap(const int index1, const int index2);// Switches the data pointers of the nodes at the specified indexes
    linkedList * subList(const int start, const int length);// Creates and returns a new list containing data from a sub-range of the linked list
};
