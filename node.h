//header file for node
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node
{
 public:
  //define functions 
  Node(char newValue);
  ~Node();
  void setNext(Node* newNode);
  Node* getNext();
  char getValue();
  
  
 private:
  //variables
  char value;
  Node* next;
  
};

//define functions for stack and queue
void push(Node* &head, Node* newNode);
void pop(Node* &head);
char peak(Node* head);
void enqueue(Node* &head, Node* newNode);
void dequeue(Node* &head);
void print(Node* head);

#endif
