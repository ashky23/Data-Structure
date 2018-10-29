#include<bits/stdc++.h>
using namespace std;
typedef struct node*point;
struct node
{
  int data ;
  struct node*left;
  struct node*right;
}
point newnode(int element)
{
   point node;
   node=(point)malloc(sizeof(struct node));
   node->data=element;
   node->left=NULL;
   node->right=NULL;
  return node;
}
int main()
{
  point root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
  root->left->right=newnode(4);
  return 0;
}
