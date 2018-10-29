#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
struct Node
{
  int data;
  point left,right;
  Node(int data)
  {
     this->data=data;
     left=right=NULL;
  }
};
void inorder(point node)
{
   if(node==NULL)
       return ;
   inorder(node->left);
   cout<<node<<" ";
   inorder(node->right);
}
void preorder(point node)
{
   if(node==NULL)
     return;
    cout<<node<<" "; 
    preorder(node->left);
    preorder(node->right);
}
void postorder(point node)
{
    if(node==NULL)
     return ;
     preorder(node->left);
    preorder(node->right);
     cout<<node<<" ";

}
int main()
{
   point root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->right=new Node(5);
   root->left->left=new Node(4);
   cout<<"PReorder traversal\n";
   preorder(root);
   cout<<"postorder traversal\n";
   postorder(root);
   cout<<"inorder traversal\n";
   inorder(root);
return 0;
}
