/*
This program takes a mathematical expression containing 4 basic arithmetic expression, power, integer numbers, and parenthesis and
translates it into postfix. Then create an expression tree and output expression as infix, prefix, or postfix notation
Author: Jennifer Wang
2/22/22
 */
#include "node.h"
#include "tree.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  //variables
  Node* inHead = NULL;
  Node* stackHead = NULL;
  Node* outHead = NULL;
  TreeStack* treeStackHead = NULL;
  char input[100];

  //user input infix as char array
  cout << "Type mathematical expression in infix notation using spaces" << endl;
  cin.getline(input, 100);

  //create input queue node with char array
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
  
  //shunting yard algorithm
  
  while (inHead != NULL)
    {
      char tempchar;
      tempchar = peak(inHead);
      Node* newtemp = new Node(tempchar);

      //if input is a  number, push to output queue
      if (isdigit(tempchar) != 0)
	{
	  enqueue(outHead, newtemp);
	}
      // if input is ^
      else if (tempchar == '^')
	{
	  //if stack head is null, push to stack head
	  if (stackHead == NULL)
	    {
	      push(stackHead, newtemp);
	    }
	  else
	    {
	      //pop stack head if ^, else push input to stack
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
	}
      //if input is * or /
      else if (tempchar == '*' || tempchar == '/')
	{
	  //if stack head is null, push to stack head
	  if (stackHead == NULL)
	    {
	      push(stackHead, newtemp);
	    }
	  else
	    {
	      //pop stack head if same or greater precedence, else push to stack head
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
      // if input is + or -
      else if (tempchar == '+' || tempchar == '-')
	{
	  //if stack head is null, push to stack head
	  if (stackHead == NULL)
	    {
	      push(stackHead, newtemp);
	    }
	  
	  else 
	    {
	      //pop stack head if same or grreater precedence, break if '(', push to stack head
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
      // if (, push to stack head
      else if (tempchar == '(')
	{
	  push(stackHead, newtemp);
	}
      //if ), find ( and pop off stack
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
  
  //move all remaining operators from stack to output
  while (stackHead != NULL)
    {
      char tempvalue = stackHead->getValue();
      Node* tempstack = new Node(tempvalue);
      enqueue(outHead, tempstack);
      pop(stackHead);
    }

  //print out postfix expression
  cout << "Postfix expression: ";
  print(outHead);
  cout << endl;
  
  // binary tree

  TreeNode* treeNodeHead = NULL;
  //binary tree algorithm
  while (outHead != NULL)
    {
      char tempNodeValue = peak(outHead);
      //if number, push to stack
      if (isdigit(tempNodeValue) != 0)
	{ 
	  TreeNode* tempNode = new TreeNode(tempNodeValue);
	  TreeStack* tempStack = new TreeStack(tempNode);
	  pushTree(treeStackHead, tempStack);
	  
	}
      //if operator, pop two pointer, make new tree, push tree pointer back onto stack
      else if (tempNodeValue == '+' || tempNodeValue == '-' || tempNodeValue == '*' || tempNodeValue == '/' || tempNodeValue == '^')
	{
	  TreeStack* temp1 = treeStackHead;
	  popTree(treeStackHead);
	  TreeStack* temp2 = treeStackHead;
	  popTree(treeStackHead);

	  if (temp2 == NULL || temp1 == NULL)
	    {
	      cout << "Error in infix input expression" << endl;
	      return 1;
	    }
	  else
	    {
	      TreeNode* templeft = temp2->getTreeStackVal();
	      TreeNode* tempright = temp1->getTreeStackVal();
	    
	      TreeNode* tempNode = new TreeNode(tempNodeValue);
	      treeNodeHead = tempNode;
	      
	      TreeNode* newtreeNode = makeTree(treeNodeHead, templeft, tempright);
	      TreeStack* newtreeStack = new TreeStack(newtreeNode);
	      pushTree(treeStackHead, newtreeStack);
	    }
	}
      dequeue(outHead);
      
    }

  
  //print out infix from tree
  cout << "infix expression:" << endl;
  printTreeInfix(treeNodeHead);
  cout << endl;

  //print out prefix from tree
  cout << "prefix expression:" << endl;
  printTreePrefix(treeNodeHead);
  cout << endl;

  //print out postfix from tree
  cout << "postfix expression:" << endl;
  printTreePost(treeNodeHead);
  cout << endl;
  
  return 0;
}

