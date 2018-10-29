/*
  1.Push the root Node on the stack
  2.pop a node from stack
  3.visit popped node
  4.push its right and left child on stack
  5.repeat steps 2,3,4,5
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
stack<point>s;
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
void preorder(point root)
{
  point ptr=root;
  if(ptr==NULL)
    cout<<"Tree empty\n";
  s.push(ptr);
  while(!s.empty())
  {
     ptr=s.top();
     s.pop();
     cout<<ptr->data<<"\n";
     if(ptr->right!=NULL)
       s.push(ptr->right);
     if(ptr->left!=NULL)
       s.push(ptr->left);
     
  }
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
/*   cout<<"postorder traversal\n";
   postorder(root);
   cout<<"inorder traversal\n";
   inorder(root);
*/
return 0;
}
