//cpp file for tree
#include <iostream>
#include <cstring>
#include "tree.h"
#include "node.h"

using namespace std;

TreeNode::TreeNode(char ntreeNodeValue)
{
  treeNodeValue = ntreeNodeValue;
  left = NULL;
  right = NULL;
}

void TreeNode::setLeft(TreeNode* newTreeNode)
{
  left = newTreeNode;
}

void TreeNode::setRight(TreeNode* newTreeNode)
{
  right = newTreeNode;
}

TreeNode* TreeNode::getLeft()
{
  return left;
}

TreeNode* TreeNode::getRight()
{
  return right;
}

char TreeNode::getTreeNodeVal()
{
  return treeNodeValue;
}

TreeNode::~TreeNode() {}

TreeStack::TreeStack(TreeNode* newTreeNodeVal)
{
  TreeNodeVal = newTreeNodeVal;
  next = NULL;
}

void TreeStack::setNext(TreeStack* newTreeStack)
{
  next = newTreeStack;
}

TreeStack* TreeStack::getNext()
{
  return next;
}

TreeNode* TreeStack::getTreeStackVal()
{
  return TreeNodeVal;
}

TreeStack::~TreeStack() {}

//tree stack delete head
void popTree(TreeStack* &tsHead)
{
  if ( tsHead!= NULL)
    {
      TreeStack* temp = tsHead;
      tsHead = tsHead->getNext();
      //delete temp;
    }
  else
    {
      cout << "nothing to delete" << endl;
    }
}

//tree stack new head
void pushTree(TreeStack* &tsHead, TreeStack* newtsStack)
{
  if (tsHead != NULL)
    {
      TreeStack* temp = tsHead;
      tsHead = newtsStack;
      tsHead->setNext(temp);
    }
  else
    {
      tsHead = newtsStack;
    }
  
}

//tree node set left and right child
TreeNode* makeTree(TreeNode* &head, TreeNode* left, TreeNode* right)
{
  if (head != NULL)
    {
      head->setLeft(left);
      head->setRight(right);
    }

  return head;  
}

//print tree postfix
void printTreePost(TreeNode* head)
{
  if (head != NULL)
    {
      printTreePost(head->getLeft());
      printTreePost(head->getRight());
      cout << head->getTreeNodeVal() << " ";
    }
}

//print tree prefix
void printTreePrefix(TreeNode* head)
{
  if (head != NULL)
    {
      cout << head->getTreeNodeVal() << " ";
      printTreePrefix(head->getLeft());
      printTreePrefix(head->getRight());
    }
}

void printTreeInfix(TreeNode* head)
{
  if (head != NULL)
    {
      if (isdigit(head->getTreeNodeVal()) == 0)
	{
	  cout << "( ";
	}
      printTreeInfix(head->getLeft());
      cout << head->getTreeNodeVal() << " ";
      printTreeInfix(head->getRight());
      if (isdigit(head->getTreeNodeVal()) == 0)
	{
	  cout << " )";
	}
    }
}
