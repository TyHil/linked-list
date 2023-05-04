#include "LinkedList.h"
#include <iostream>

using namespace std;

/*Card Object Test Class*/

struct Card {
  int number;
  char suit;
  Card() : number(0), suit(0) {}
  Card(int number, int suit) : number(number), suit(suit) {}
  Card(Card const &source) : number(source.number), suit(source.suit) {}
  friend ostream &operator<<(ostream &, const Card &);
};

ostream &operator<<(ostream &os, const Card &data) {
  os << data.number << data.suit;
  return os;
}

/*Main Test Code*/

int main() {
  cout << "Object tests:" << endl;
  LinkedList<Card *> objectLinkedList = LinkedList<Card *>();
  int numberData[10] = {1, 5, 8, 7, 1, 10, 13, 2, 9, 4};
  int suitData[10] = {'s', 'd', 's', 'h', 'c', 'c', 'd', 'h', 'c', 's'};
  for (uint8_t i = 0; i < 10; i++) {
    objectLinkedList.add(new Card(numberData[i], suitData[i]));
  }
  cout << "Inital data added: " << objectLinkedList << endl;

  LinkedList<Card *> *objectCopyLinkedList =
      new LinkedList<Card *>(objectLinkedList);
  cout << "Copy of list: " << *objectCopyLinkedList << endl;

  LinkedList<Card *> *objectSubLinkedList = objectLinkedList.subList(2, 5);
  cout << "New sub list created from 2 length 5: " << *objectSubLinkedList
       << " length: " << objectSubLinkedList->size() << endl;

  objectLinkedList.set(2, new Card(1, 's'));
  cout << "After set at 2: " << objectLinkedList << endl;

  objectLinkedList.insert(8, new Card(12, 'h'));
  cout << "After insert at 8: " << objectLinkedList << endl;

  objectLinkedList.remove(9);
  cout << "After remove 9: " << objectLinkedList << endl;

  objectLinkedList.swap(2, 8);
  cout << "After swap 2 and 8: " << objectLinkedList << endl;

  cout << "Access 5: " << *objectLinkedList[5] << endl;

  cout << "Before clear: empty: " << objectLinkedList.empty() << "" << endl;
  objectLinkedList.clear();
  cout << "After clear: empty: " << objectLinkedList.empty() << "" << endl;

  cout << endl << "Primitive tests:" << endl;
  LinkedList<int> primitiveLinkedList = LinkedList<int>();
  for (int i = 0; i < 10; i++) {
    primitiveLinkedList.add(i);
  }
  cout << "Inital data added: " << primitiveLinkedList << endl;

  LinkedList<int> *primitiveCopyLinkedList =
      new LinkedList<int>(primitiveLinkedList);
  cout << "Copy of list: " << *primitiveCopyLinkedList << endl;

  LinkedList<int> *primitiveSubLinkedList = primitiveLinkedList.subList(2, 5);
  cout << "New sub list created from 2 length 5: " << *primitiveSubLinkedList
       << " length: " << primitiveSubLinkedList->size() << endl;

  primitiveLinkedList.set(2, 12);
  cout << "After set at 2: " << primitiveLinkedList << endl;

  Card *testInsert = new Card();
  primitiveLinkedList.insert(8, 13);
  cout << "After insert at 8: " << primitiveLinkedList << endl;

  primitiveLinkedList.remove(9);
  cout << "After remove 9: " << primitiveLinkedList << endl;

  primitiveLinkedList.swap(2, 8);
  cout << "After swap 2 and 8: " << primitiveLinkedList << endl;

  cout << "Access 5: " << primitiveLinkedList[5] << endl;

  cout << "Before clear: empty: " << primitiveLinkedList.empty() << "" << endl;
  primitiveLinkedList.clear();
  cout << "After clear: empty: " << primitiveLinkedList.empty() << "" << endl;
}
