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
   cout<<node->data<<" ";
   inorder(node->right);
}
void preorder(point node)
{
   if(node==NULL)
     return;
    cout<<node->data<<" "; 
    preorder(node->left);
    preorder(node->right);
}
void postorder(point node)
{
    if(node==NULL)
     return ;
     postorder(node->left);
    postorder(node->right);
     cout<<node->data<<" ";

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
   cout<<"\npostorder traversal\n";
   postorder(root);
   cout<<"\ninorder traversal\n";
   inorder(root);
return 0;
}
