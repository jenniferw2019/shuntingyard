#include "node.h"
#include "tree.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  Node* inHead = NULL;
  Node* stackHead = NULL;
  Node* outHead = NULL;
  TreeStack* treeStackHead = NULL;
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
	  if (stackHead == NULL)
	    {
	      push(stackHead, newtemp);
	    }
	  else
	    {
	      while (stackHead != NULL)
		{
		  char tempv = stackHead->getValue();
		  Node* stackHeadTemp = new Node(tempv);
		  if (tempv == '^')
		    {
		      enqueue(outHead, stackHeadTemp);
		      pop(stackHead);
		    }
		  else if (tempv == '+' || tempv == '-' || tempv == '*' || tempv == '/' || tempv == '(')
		    {
		      break;
		    }
		}
	      push(stackHead, newtemp);
	    }
	  /*
	  if (stackHead != NULL)
	    {
	      char tempv = stackHead->getValue();
	      Node* stackHeadTemp = new Node(tempv);
	      if (tempv == '^')
		{
		  while (tempv == '^')
		    {
		      enqueue(outHead, stackHeadTemp);
		      pop(stackHead);
		    }
		  push(stackHead, newtemp);
    
		}
	      else
		{
		  push(stackHead, newtemp);
	
		}
	    }
	  else
	    {
	      push(stackHead, newtemp);
	    }
	  */
	}
      else if (tempchar == '*' || tempchar == '/')
	{
	  if (stackHead == NULL)
	    {
	      push(stackHead, newtemp);
	    }
	  else
	    {
	      while (stackHead != NULL)
		{
		  char tempv = stackHead->getValue();
		  Node* stackHeadTemp = new Node(tempv);
		  if (tempv == '*' || tempv == '/' || tempv == '^')
		    {
		      enqueue(outHead, stackHeadTemp);
		      pop(stackHead);
		    }
		  else if (tempv == '+' || tempv == '-' || tempv == '(')
		    {
		      break;
		    }
		}
	      push(stackHead, newtemp);
	    }	  
	  
	}
      else if (tempchar == '+' || tempchar == '-')
	{
	  if (stackHead == NULL)
	    {
	      push(stackHead, newtemp);
	    }
	  
	  else 
	    {
	      
	      while (stackHead != NULL)
		{
		  char tempv = stackHead->getValue();
		  Node* stackHeadTemp = new Node(tempv);
		  
		  
		  if (tempv == '+' || tempv == '-' || tempv == '*' || tempv == '/' || tempv == '^')
		    {
		      enqueue(outHead, stackHeadTemp);
		      pop(stackHead);
		    }
		  else if (tempv == '(')
		    {
		      break;
		    }
		}
	      
	      push(stackHead, newtemp);
			
	    }
	  
	}
      else if (tempchar == '(')
	{
	  push(stackHead, newtemp);
	}
      else if (tempchar == ')')
	{
	  if (stackHead->getValue() == '(')
	    {
	      pop(stackHead);
	    }
	  else
	    {
	      while (stackHead != NULL)
		{
		  char tempv = stackHead->getValue();
		  Node* stackHeadTemp = new Node(tempv);

		  if (tempv != '(')
		    {
		      enqueue(outHead, stackHeadTemp);
		      pop(stackHead);
		    }
		  else
		    {
		      break;
		    }
		}
	      pop(stackHead);
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


  // binary tree

  TreeNode* treeNodeHead = NULL;
  
  while (outHead != NULL)
    {
      char tempNodeValue = peak(outHead);
      if (isdigit(tempNodeValue) != 0)
	{ 
	  TreeNode* tempNode = new TreeNode(tempNodeValue);
	  TreeStack* tempStack = new TreeStack(tempNode);
	  pushTree(treeStackHead, tempStack);
	}
      else if (tempNodeValue == '+' || tempNodeValue == '-' || tempNodeValue == '*' || tempNodeValue == '/' || tempNodeValue == '^')
	{
	  TreeStack* temp1 = treeStackHead;
	  popTree(treeStackHead);
	  TreeStack* temp2 = treeStackHead;
	  popTree(treeStackHead);

	  TreeNode* templeft = temp1->getTreeStackVal();
	  TreeNode* tempright = temp2->getTreeStackVal();
	  TreeNode* newtreeNode = makeTree(treeNodeHead, templeft, tempright);
	  TreeStack* newtreeStack = new TreeStack(newtreeNode);
	  pushTree(treeStackHead, newtreeStack);
	}  
      
    }
  return 0;
}

