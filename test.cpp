#include "linkedList.h"
#include <iostream>

using namespace std;

/*Test Data Class*/

struct testData {
  int card;
  int suit;
};

/*Print Linked List Function*/

void printLinkedList(linkedList<testData> * list) {
  cout << "Linked List:\nSize: " << list->size() << "\nData:";
  for (uint8_t i = 0; i < list->size(); i++) {
    node<testData> * test = list->get(i);
    cout << "\nCard: " << ((testData*)test->dataPtr)->card << " Suit: " << ((testData*)test->dataPtr)->suit;
  }
  cout << "\n\n";
}

/*Main Test Code*/

int main() {
  linkedList<testData> * testLinkedList = new linkedList<testData>();
  int cardData[10] = {1, 5, 8, 7, 1, 10, 13, 2, 9, 4};
  int suitData[10] = {3, 1, 3, 2, 0, 0, 1, 2, 0, 3};

  for (uint8_t i = 0; i < 10; i++) {
    testData * testAdd = new testData();
    testAdd->card = cardData[i];
    testAdd->suit = suitData[i];
    testLinkedList->add(testAdd);
  }
  cout << "Inital Data Added:\n";
  printLinkedList(testLinkedList);

  linkedList<testData> * newSubList = testLinkedList->subList(0, 5);
  cout << "New Sub List Created:\n";
  printLinkedList(newSubList);

  testData * testSet = new testData();
  testSet->card = 56;
  testSet->suit = 5;
  testLinkedList->set(2, testSet);
  cout << "After Set:\n";
  printLinkedList(testLinkedList);

  testData * testInsert = new testData();
  testInsert->card = 100;
  testInsert->suit = 6;
  testLinkedList->set(8, testInsert);
  cout << "After Insert:\n";
  printLinkedList(testLinkedList);

  testLinkedList->remove(9);
  cout << "After Remove:\n";
  printLinkedList(testLinkedList);

  testLinkedList->swap(2, 8);
  cout << "After Swap:\n";
  printLinkedList(testLinkedList);

  cout << "Before Clear:\n";
  cout << "isEmpty: " << testLinkedList->isEmpty() << "\n";
  testLinkedList->clear();
  cout << "After Clear:\n";
  cout << "isEmpty: " << testLinkedList->isEmpty() << "\n";
}