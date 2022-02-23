//header file for tree
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstring>

using namespace std;

class TreeNode
{
 public:
  //define functions
  TreeNode(char ntreeNodeValue);
  void setLeft(TreeNode* newTreeNode);
  void setRight(TreeNode* newTreeNode);
  TreeNode* getLeft();
  TreeNode* getRight();
  char getTreeNodeVal();
  ~TreeNode();

 private:
  //variable
  char treeNodeValue;
  TreeNode* left;
  TreeNode* right;

};


class TreeStack
{
public:
  //define functions
  TreeStack(TreeNode* newTreeNodeVal);
  ~TreeStack();
  void setNext(TreeStack* newTreeStack);
  TreeStack* getNext();
  TreeNode* getTreeStackVal();
  
private:
  //variables
  TreeNode* TreeNodeVal;
  TreeStack* next;
};

//define functions for binary tree
TreeNode*  makeTree(TreeNode* &head, TreeNode* left, TreeNode* right);
void popTree(TreeStack* &tsHead);
void pushTree(TreeStack* &tsHead, TreeStack* newtsStack);
void printTreePost(TreeNode* head);
void printTreePrefix(TreeNode* head);
void printTreeInfix(TreeNode* head);

#endif
