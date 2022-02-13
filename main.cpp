#include "node.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  Node* inHead = NULL;
  Node* stackHead = NULL;
  Node* outHead = NULL;
  char input[100];

  cout << "Type input" << endl;
  cin.getline(input, 100);
  
  for (int i = 0; i < strlen(input); i++)
    {
      if (inHead != NULL)
	{
	  if (input[i] != ' ')
	    {
	      Node* tempNode = new Node(input[i]);
	      enqueue(inHead, tempNode);
	    }
	}
      else
	{
	  Node* tempNode = new Node(input[i]);
	  inHead = tempNode;
	}
    }
  print(inHead);
  cout << "shunting yard" << endl;
  //shunting yard algorithm
  while (inHead != NULL)
    {
      char tempchar;
      tempchar = peak(inHead);
      Node* newtemp = new Node(tempchar);
      
      if (isdigit(tempchar) != 0)
	{
	  enqueue(outHead, newtemp);
	}
      else if (tempchar == '^')
	{
	  if (stackHead != NULL)
	    {
	      char tempv = stackHead->getValue();
	      Node* stackHeadTemp = new Node(tempv);
	      if (tempv == '^')
		{
		  enqueue(outHead, stackHeadTemp);
		  pop(stackHead);
		  push(stackHead, newtemp);
		}
	    }
	  else
	    {
	      push(stackHead, newtemp);
	    }
	}
      else if (tempchar == '*' || tempchar == '/')
	{
	  if (stackHead != NULL)
	    {
	      char tempv = stackHead->getValue();
	      Node* stackHeadTemp = new Node(tempv);
	      if (tempv == '*' || tempv == '/' || tempv == '^')
		{
		  enqueue(outHead, stackHeadTemp);
		  pop(stackHead);
		  push(stackHead, newtemp);
		}
	    }
	  else
	    {
	      push(stackHead, newtemp);
	    }
	}
      dequeue(inHead);
    }
 
  cout << "output" << endl;
  print(outHead);

  cout << "stack" << endl;
  print(stackHead);

  while (stackHead != NULL)
    {
      char tempvalue = stackHead->getValue();
      Node* tempstack = new Node(tempvalue);
      enqueue(outHead, tempstack);
      pop(stackHead);
    }
  cout << "output" << endl;
  print(outHead);

  cout << "stack" << endl;
  print(stackHead);
  
  return 0;
}
