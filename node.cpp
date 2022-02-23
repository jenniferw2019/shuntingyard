//cpp file for node
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

//stack, new head
void push(Node* &head, Node* newNode)
{
  if (head != NULL)
    {
      Node* temp = head;
      head = newNode;
      head->setNext(temp);
    }
  else
    {
      head = newNode;
    }
}

//stack, delete head
void pop(Node* &head)
{
  if (head != NULL)
    {
      Node* temp = head;
      head = head->getNext();
      delete temp;
    }
  else
    {
      cout << "Nothing to delete" << endl;
    }
}

//stack, print head value
char peak(Node* head)
{
  char tempValue;
  tempValue = head->getValue();
  return tempValue;
}

//queue, add to end
void enqueue(Node* &head, Node* newNode)
{
  Node* temp = newNode;
  if (head != NULL)
    {
      Node* current = head;
      Node* previous;
      while (current->getNext() != NULL)
	{
	  previous = current;
	  current = current->getNext();
	}
      current->setNext(temp);
    }
  else
    {
      head = temp;
    }
}

//queue, delete head
void dequeue(Node* &head)
{
  if (head != NULL)
    {
      Node* temp = head;
      head = head->getNext();
      delete temp;
    }
  else
    {
      cout << "Nothing to delete" << endl;
    }
}

//print stack and queue
void print(Node* head)
{
  if (head != NULL)
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
  else
    {
      cout << "Nothing to print" << endl;
    }
}

Node::~Node()
{
  value = '\0';
  next = NULL;
}


