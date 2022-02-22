#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstring>

using namespace std;

class TreeNode
{
 public:
  TreeNode(char ntreeNodeValue);
  void setLeft(TreeNode* newTreeNode);
  void setRight(TreeNode* newTreeNode);
  TreeNode* getLeft();
  TreeNode* getRight();
  char getTreeNodeVal();
  ~TreeNode();

 private:
  char treeNodeValue;
  TreeNode* left;
  TreeNode* right;

};

//void makeTree(TreeNode* &head, TreeNode* left, TreeNode* right);

class TreeStack
{
public:
  TreeStack(TreeNode* newTreeNodeVal);
  ~TreeStack();
  void setNext(TreeStack* newTreeStack);
  TreeStack* getNext();
  TreeNode* getTreeStackVal();
  
private:
  TreeNode* TreeNodeVal;
  TreeStack* next;
};

TreeNode*  makeTree(TreeNode* &head, TreeNode* left, TreeNode* right);
void popTree(TreeStack* &tsHead);
void pushTree(TreeStack* &tsHead, TreeStack* newtsStack);
void printTreePost(TreeNode* head);
void printTreePrefix(TreeNode* head);
#endif
