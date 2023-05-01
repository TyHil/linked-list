#include "LinkedList.h"
#include <iostream>

using namespace std;

/*Test Data Class*/

struct testData {
  int card;
  int suit;
};

/*Print Linked List Function*/

void printLinkedList(LinkedList<testData> * list) {
  cout << "Linked List Print:\n\tSize: " << list->size() << "\n\tData:";
  for (uint8_t i = 0; i < list->size(); i++) {
    node<testData> * test = list->get(i);
    cout << "\n\tCard: " << ((testData*)test->dataPtr)->card << " Suit: " << ((testData*)test->dataPtr)->suit;
  }
  cout << "\n\n";
}

/*Main Test Code*/

int main() {
  LinkedList<testData> * testLinkedList = new LinkedList<testData>();
  int cardData[10] = {1, 5, 8, 7, 1, 10, 13, 2, 9, 4};
  int suitData[10] = {3, 1, 3, 2, 0, 0, 1, 2, 0, 3};

  for (uint8_t i = 0; i < 10; i++) {
    testData * testAdd = new testData();
    testAdd->card = cardData[i];
    testAdd->suit = suitData[i];
    testLinkedList->add(testAdd);
  }
  cout << "Inital data added:\n";
  printLinkedList(testLinkedList);

  LinkedList<testData> * newSubList = testLinkedList->subList(1, 5);
  cout << "New sub list created from 1 length 5:\n";
  printLinkedList(newSubList);

  testData * testSet = new testData();
  testSet->card = 56;
  testSet->suit = 5;
  testLinkedList->set(2, testSet);
  cout << "After set 2:\n";
  printLinkedList(testLinkedList);

  testData * testInsert = new testData();
  testInsert->card = 100;
  testInsert->suit = 6;
  testLinkedList->insert(8, testInsert);
  cout << "After insert 8:\n";
  printLinkedList(testLinkedList);

  testLinkedList->remove(9);
  cout << "After remove 9:\n";
  printLinkedList(testLinkedList);

  testLinkedList->swap(2, 8);
  cout << "After swap 2 and 8:\n";
  printLinkedList(testLinkedList);

  cout << "Before clear:\n";
  cout << "isEmpty: " << testLinkedList->isEmpty() << "\n";
  testLinkedList->clear();
  cout << "After clear:\n";
  cout << "isEmpty: " << testLinkedList->isEmpty() << "\n";
}
