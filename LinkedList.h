#include <iostream>

template <typename T> class LinkedList;

/*Node*/

template <typename T> class Node {
  T data;
  Node<T> *next;

public:
  Node() : data(NULL), next(nullptr) {}
  Node(T data) : data(data), next(nullptr) {}
  Node(T data, Node<T> *next) : data(data), next(next) {}
  Node(Node<T> *source) : data(source->data), next(source->next) {}
  friend class LinkedList<T>;
  template <typename U>
  friend std::ostream &operator<<(std::ostream &, const LinkedList<U> &);
};

template <typename T> class Node<T *> {
  T *data;
  Node<T *> *next;

public:
  Node() : data(nullptr), next(nullptr) {}
  Node(T *data) : data(data), next(nullptr) {}
  Node(T *data, Node<T *> *next) : data(data), next(next) {}
  Node(Node<T *> *source) : data(source->data), next(source->next) {}
  ~Node();
  friend class LinkedList<T *>;
  template <typename U>
  friend std::ostream &operator<<(std::ostream &, const LinkedList<U *> &);
};

template <typename T> Node<T *>::~Node() { // Destructor
  delete data;
}

/*Linked List*/

class LinkedListBase {
protected:
  int length;

public:
  int size();
};

template <typename T> class LinkedList : public LinkedListBase {
protected:
  Node<T> *head; // Start Node

public:
  LinkedList();
  LinkedList(LinkedList const &);
  ~LinkedList();
  void clear();
  void add(T);
  Node<T> *get(const int);
  void set(const int, T);
  void insert(const int, T);
  void remove(const int);
  bool empty();
  void swap(const int, const int);
  LinkedList *subList(const int, const int);

  T operator[](int);
  template <typename U>
  friend std::ostream &operator<<(std::ostream &, const LinkedList<U> &);
};

template <typename T> class LinkedList<T *> : public LinkedListBase {
protected:
  Node<T *> *head; // Start Node

public:
  void clear();
  void add(T *);
  Node<T *> *get(const int);
  void set(const int, T *);
  void insert(const int, T *);
  void remove(const int);
  bool empty();
  void swap(const int, const int);
  LinkedList<T *> *subList(const int, const int);

  T *operator[](int);
  template <typename U>
  friend std::ostream &operator<<(std::ostream &, const LinkedList<U *> &);
};

// Constructor
template <typename T> LinkedList<T>::LinkedList() { head = nullptr; }

// Copy constructor
template <typename T> LinkedList<T>::LinkedList(LinkedList const &source) {
  Node<T> *i = source.head;
  if (i != nullptr) {
    head = new Node<T>(i->data);
    Node<T> *lastSource = i;
    Node<T> *lastDest = head;
    i = i->next;
    while (i != nullptr) {
      lastDest->next = new Node<T>(i->data);
      lastDest = lastDest->next;
      lastSource = i;
      i = i->next;
    }
  }
  length = source.length;
}

// Destructor
template <typename T> LinkedList<T>::~LinkedList() { clear(); }

// Clears and deletes all Nodes and data
template <typename T> void LinkedList<T>::clear() {
  Node<T> *i = head;
  while (i != nullptr) {
    Node<T> *temp = i->next;
    delete i;
    i = temp;
  }
  head = nullptr;
  length = 0;
}
template <typename T> void LinkedList<T *>::clear() {
  Node<T *> *i = head;
  while (i != nullptr) {
    Node<T *> *temp = i->next;
    delete i;
    i = temp;
  }
  head = nullptr;
  length = 0;
}

// Adds a new node with specified data to the end of the linked list
template <typename T> void LinkedList<T>::add(T data) {
  if (head == nullptr) { // replace head
    head = new Node<T>(data);
  } else { // add to end
    Node<T> *i = head;
    while (i->next != nullptr)
      i = i->next; // find end
    i->next = new Node<T>(data);
  }
  length++;
}
template <typename T> void LinkedList<T *>::add(T *data) {
  if (head == nullptr) { // replace head
    head = new Node<T *>(data);
  } else { // add to end
    Node<T *> *i = head;
    while (i->next != nullptr)
      i = i->next; // find end
    i->next = new Node<T *>(data);
  }
  length++;
}

// Returns the number of Nodes
int LinkedListBase::size() {
  return length;
}

// Returns a pointer to the Node at a specific index
template <typename T> Node<T> *LinkedList<T>::get(const int index) {
  Node<T> *i = head;
  int indexGoal = 0;
  while (indexGoal != index and i != nullptr) {
    i = i->next;
    indexGoal++;
  }
  return i;
}
template <typename T> Node<T *> *LinkedList<T *>::get(const int index) {
  Node<T *> *i = head;
  int indexGoal = 0;
  while (indexGoal != index and i != nullptr) {
    i = i->next;
    indexGoal++;
  }
  return i;
}

// Replaces the data of node at the specified index with new data
template <typename T> void LinkedList<T>::set(const int index, T data) {
  get(index)->data = data;
}
template <typename T> void LinkedList<T *>::set(const int index, T *data) {
  Node<T *> *i = get(index);
  delete i->data;
  i->data = data;
}

// Inserts a new node and new data before the specified index
template <typename T> void LinkedList<T>::insert(const int index, T data) {
  if (index == 0) { // replace head
    Node<T> *newNode = new Node<T>(data);
    if (head != nullptr)
      newNode->next = head; // not empty
    head = newNode;
  } else {
    Node<T> *prev = get(index - 1);
    prev->next = new Node<T>(data, prev->next);
  }
  length++;
}
template <typename T> void LinkedList<T *>::insert(const int index, T *data) {
  if (index == 0) { // replace head
    Node<T *> *newNode = new Node<T *>(data);
    if (head != nullptr)
      newNode->next = head; // not empty
    head = newNode;
  } else {
    Node<T *> *prev = get(index - 1);
    prev->next = new Node<T *>(data, prev->next);
  }
  length++;
}

// Removes the node and data at the specified index
template <typename T> void LinkedList<T>::remove(const int index) {
  if (index == 0) {
    Node<T> *i = get(1);
    delete head;
    head = i;
  } else {
    Node<T> *i = get(index);
    get(index - 1)->next = i->next;
    delete i;
  }
  length--;
}
template <typename T> void LinkedList<T *>::remove(const int index) {
  if (index == 0) {
    Node<T *> *i = get(1);
    delete head;
    head = i;
  } else {
    Node<T *> *i = get(index);
    get(index - 1)->next = i->next;
    delete i;
  }
  length--;
}

// Returns true if the linked list has no elements in it
template <typename T> bool LinkedList<T>::empty() {
  return head == nullptr;
}
template <typename T> bool LinkedList<T*>::empty() {
  return head == nullptr;
}

// Switches the data pointers of the specified indexes
template <typename T>
void LinkedList<T>::swap(const int index1, const int index2) {
  Node<T> *i = get(index1);
  Node<T> *j = get(index2);
  T temp = i->data;
  i->data = j->data;
  j->data = temp;
}
template <typename T>
void LinkedList<T *>::swap(const int index1, const int index2) {
  Node<T *> *i = get(index1);
  Node<T *> *j = get(index2);
  T *temp = i->data;
  i->data = j->data;
  j->data = temp;
}

// Creates and returns a new list containing data from a sub-range of the linked
// list
template <typename T>
LinkedList<T> *LinkedList<T>::subList(const int start, const int length) {
  LinkedList *result = new LinkedList<T>();
  Node<T> *i = get(start);
  if (i != nullptr) {
    result->head = new Node<T>(i->data);
    Node<T> *lastSource = i;
    Node<T> *lastDest = result->head;
    i = i->next;
    int lengthGoal = 1;
    while (i != nullptr && lengthGoal < length) {
      lastDest->next = new Node<T>(i->data);
      lastDest = lastDest->next;
      lastSource = i;
      i = i->next;
      lengthGoal++;
    }
  }
  result->length = length;
  return result;
}
template <typename T>
LinkedList<T *> *LinkedList<T *>::subList(const int start, const int length) {
  LinkedList *result = new LinkedList<T *>();
  Node<T *> *i = get(start);
  if (i != nullptr) {
    result->head = new Node<T *>(i->data);
    Node<T *> *lastSource = i;
    Node<T *> *lastDest = result->head;
    i = i->next;
    int lengthGoal = 1;
    while (i != nullptr && lengthGoal < length) {
      lastDest->next = new Node<T *>(i->data);
      lastDest = lastDest->next;
      lastSource = i;
      i = i->next;
      lengthGoal++;
    }
  }
  result->length = length;
  return result;
}

// Allows accessing the list with the bracket operator
template <typename T> T LinkedList<T>::operator[](int index) {
  return get(index)->data;
}
template <typename T> T *LinkedList<T *>::operator[](int index) {
  return get(index)->data;
}

// Prints the list
template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
  Node<T> *i = list.head;
  while (i != nullptr) {
    os << i->data;
    i = i->next;
    if (i != nullptr) {
      os << ", ";
    }
  }
  return os;
}
template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T *> &list) {
  Node<T *> *i = list.head;
  while (i != nullptr) {
    os << *(i->data);
    i = i->next;
    if (i != nullptr) {
      os << ", ";
    }
  }
  return os;
}
