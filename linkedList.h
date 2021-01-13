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
    void clear();// Removes all nodes and data
    void add(void * newData);// Adds a new node and data to the end
    int size();// Returns the number of nodes
    node * get(const int indexGoal);// Returns the node at the specified index
    void set(const int indexGoal, void * newData);// Replaces the node at the specified index with new data, client deletes old data
    void insert(const int indexGoal, void * newData);// Inserts new node and data before the specified index
    void remove(const int indexGoal);// Removes the node and data at the specified index from this list
    bool isEmpty();// Returns true if empty
    void swap(const int index1, const int index2);// Switches the data of specified indexes
    linkedList * subList(const int start, const int length);// Returns a new list containing data from a sub-range
    bool equals(linkedList * other);// Returns true if this list and the specified list contain the same data in the same order
};
