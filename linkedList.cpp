#include "linkedList.h"

/*Node Methods*/

node::~node() {// Destructor
  free(dataPtr);
}

/*Linked List Methods*/

linkedList::linkedList() {// Constructor
  head = NULL;
}

linkedList::~linkedList() {// Destructor
  clear();
}

void linkedList::clear() {// Clears and deletes all nodes and data
  node * i = head;
  while (i != NULL) {
    node * temp = i->next;
    delete i;
    i = temp;
  }
}

void linkedList::add(void * newData) {// Adds a new node with specified data to the end of the linked list
  node *newNode = new node;
  newNode->next = NULL;
  newNode->dataPtr = newData;
  if (head == NULL) {// replace head
    head = newNode;
  } else {// add to end
    node *i = head;
    while (i->next != NULL) i = i->next;// find end
    i->next = newNode;
  }
  //insert(size(), newData);// use instead of above code to optimize for storage
}

int linkedList::size() {// Returns the number of nodes
  node * i = head;
  int index = 0;
  while (i != NULL) {
    i = i->next;
    index++;
  }
  return index;
}

node * linkedList::get(const int indexGoal) {// Returns a pointer to the node at a specific index
  node * i = head;
  int index = 0;
  while (index != indexGoal and i != NULL) {
    i = i->next;
    index++;
  }
  return i;
}

void linkedList::set(const int indexGoal, void * newData) {// Replaces the data of node at the specified index with new data
  node * i = get(indexGoal);
  free(i->dataPtr);
  i->dataPtr = newData;
}

void linkedList::insert(const int indexGoal, void * newData) {// Inserts a new node and new data before the specified index
  if (indexGoal == 0) {// replace head
    node * newNode = new node;
    newNode->dataPtr = newData;
    if (head != NULL) newNode->next = head;// not empty
    else delete head;// empty
    head = newNode;
  } else {
    node * newNode = new node;
    newNode->dataPtr = newData;
    node * temp = get(indexGoal - 1);
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void linkedList::remove(const int indexGoal) {// Removes the node and data at the specified index
  if (indexGoal == 0) {
    node * i = get(1);
    delete head;
    head = i;
  } else {
    node * i = get(indexGoal);
    get(indexGoal - 1)->next = i->next;
    delete i;
  }
}

bool linkedList::isEmpty() {// Returns true if the linked list has no elements in it
  return head == NULL;
}

void linkedList::swap(const int index1, const int index2) {// Switches the data pointers of the specified indexes
  node * i = get(index1);
  node * j = get(index2);
  void * temp = i->dataPtr;
  i->dataPtr = j->dataPtr;
  j->dataPtr = temp;
}

linkedList * linkedList::subList(const int start, const int length) {//Creates and returns a new list containing data from a sub-range of the linked list
  linkedList * result = new linkedList();
  for (int i = start; i < length + start; i++) result->add(get(i)->dataPtr);
  return result;
}

bool linkedList::equals(linkedList * other) {//Returns true if the linked list and the specified linked list contain the same data in the same order
  bool result = size()==other->size();//auto false if differnt sizes
  if (result){
    node * thisListNode = head;
    node * otherListNode = other->get(0);
    for (int i = 0; i < size() and result; i++) {
      if(thisListNode->dataPtr != otherListNode->dataPtr) {
        result = false;
      }
      thisListNode = thisListNode->next;
      otherListNode = otherListNode->next;
    }
  }
  return result;
}