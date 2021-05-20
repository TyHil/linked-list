/*Node*/

template <typename T> struct node {
  ~node();
  T * dataPtr;
  node<T> * next;
};
template <typename T> node<T>::~node() { //Destructor
  delete dataPtr;
}

/*Linked List*/

template <typename T> class linkedList {
  node<T> * head; //start node
  public:
    linkedList();
    ~linkedList();
    void clear();
    void add(T * newData);
    int size();
    node<T> * get(const int indexGoal);
    void set(const int indexGoal, T * newData);
    void insert(const int indexGoal, T * newData);
    void remove(const int indexGoal);
    bool isEmpty();
    void swap(const int index1, const int index2);
    linkedList * subList(const int start, const int length);
};

template <typename T> linkedList<T>::linkedList() { //Constructor
  head = nullptr;
}

template <typename T> linkedList<T>::~linkedList() { //Destructor
  clear();
}

template <typename T> void linkedList<T>::clear() { //Clears and deletes all nodes and data
  node<T> * i = head;
  while (i != nullptr) {
    node<T> * temp = i->next;
    delete i;
    i = temp;
  }
  head = nullptr;
}

template <typename T> void linkedList<T>::add(T * newData) { //Adds a new node with specified data to the end of the linked list
  node<T> * newNode = new node<T>;
  newNode->next = nullptr;
  newNode->dataPtr = newData;
  if (head == nullptr) { //replace head
    head = newNode;
  } else { //add to end
    node<T> * i = head;
    while (i->next != nullptr) i = i->next; //find end
    i->next = newNode;
  }
  //insert(size(), newData); //use instead of above code to optimize for storage
}

template <typename T> int linkedList<T>::size() { //Returns the number of nodes
  node<T> * i = head;
  int index = 0;
  while (i != nullptr) {
    i = i->next;
    index++;
  }
  return index;
}

template <typename T> node<T> * linkedList<T>::get(const int indexGoal) { //Returns a pointer to the node at a specific index
  node<T> * i = head;
  int index = 0;
  while (index != indexGoal and i != nullptr) {
    i = i->next;
    index++;
  }
  return i;
}

template <typename T> void linkedList<T>::set(const int indexGoal, T * newData) { //Replaces the data of node at the specified index with new data
  node<T> * i = get(indexGoal);
  delete i->dataPtr;
  i->dataPtr = newData;
}

template <typename T> void linkedList<T>::insert(const int indexGoal, T * newData) { //Inserts a new node and new data before the specified index
  if (indexGoal == 0) { //replace head
    node<T> * newNode = new node<T>;
    newNode->dataPtr = newData;
    if (head != nullptr) newNode->next = head; //not empty
    else delete head; //empty
    head = newNode;
  } else {
    node<T> * newNode = new node<T>;
    newNode->dataPtr = newData;
    node<T> * temp = get(indexGoal - 1);
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

template <typename T> void linkedList<T>::remove(const int indexGoal) { //Removes the node and data at the specified index
  if (indexGoal == 0) {
    node<T> * i = get(1);
    delete head;
    head = i;
  } else {
    node<T> * i = get(indexGoal);
    get(indexGoal - 1)->next = i->next;
    delete i;
  }
}

template <typename T> bool linkedList<T>::isEmpty() { //Returns true if the linked list has no elements in it
  return head == nullptr;
}

template <typename T> void linkedList<T>::swap(const int index1, const int index2) { //Switches the data pointers of the specified indexes
  node<T> * i = get(index1);
  node<T> * j = get(index2);
  T * temp = i->dataPtr;
  i->dataPtr = j->dataPtr;
  j->dataPtr = temp;
}

template <typename T> linkedList<T> * linkedList<T>::subList(const int start, const int length) {//Creates and returns a new list containing data from a sub-range of the linked list
  linkedList * result = new linkedList();
  for (int i = start; i < length + start; i++) {
    result->add(get(i)->dataPtr);
  }
  return result;
}
