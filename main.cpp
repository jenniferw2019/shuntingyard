#include "node.h"
#include <iostream>

using namespace std;

int main()
{
  char value1 = '5';
  Node* head = new Node(value1);
  
  char value2 = '3';
  Node* node1 = new Node(value2);
  head->setNext(node1);

  char value3 = '7';
  Node* node2 = new Node(value3);
  node1->setNext(node2);

  char value4 = '1';
  Node* node3 = new Node(value4);
  node2->setNext(node3);

  node3->setNext(NULL);

  print(head);
  
  return 0;
}
