#include "node.h"
#include <iostream>
#include <cstring>

using namespace std;

Node::Node(char newValue)
{
  value = newValue;
  next = NULL;  
}

void Node::setNext(Node* newNode)
{
  next = newNode;
}

Node* Node::getNext()
{
  return next;
}

char Node::getValue()
{
  return value;
}

void push(Node* &head, char tempValue)
{
  Node* temp = head;
  head = new Node(tempValue);
  head->setNext(temp);
}

void pop(Node* &head)
{
  Node* temp = head;
  head = head->getNext();
  delete temp;
}

char peak(Node* &head)
{
  char tempValue;
  tempValue = head->getValue();
  return tempValue;
}

void enqueue(Node* &head, Node* previous, Node* current)
{
  if (current->getNext() == NULL)
    {
      delete current;
    }
  else
    {
      enqueue(head, current, current->getNext());
    }
}

void dequeue(Node* &head)
{
  Node* temp = head;
  head = head->getNext();
  delete head;
}

void print(Node* head)
{
  Node* current = head;
  Node* previous;
  while (current->getNext() != NULL)
    {
      char temp = current->getValue();
      cout << temp << " ";

      previous = current;
      current = current->getNext();
    }
  cout << current->getValue() << endl;
}

Node::~Node()
{
  value = '\0';
  next = NULL;
}


