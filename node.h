#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node
{
 public:
  Node(char newValue);
  ~Node();
  void setNext(Node* newNode);
  Node* getNext();
  char getValue();
  
  
 private:
  char value;
  Node* next;
  
};

void push(Node* &head, char tempValue);
void pop(Node* &head);
char peak(Node* head);
void enqueue(Node* &head, Node* previous, Node* current);
void dequeue(Node* &head);
void print(Node* head);

#endif
