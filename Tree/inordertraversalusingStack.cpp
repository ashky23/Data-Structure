/*
  1 initially ptr points to root
  2 then push the left subtree rooted at ptr untill (ptr->left==NULL) here ptr will point to leftmost node of the tree.
  3 if ptr has no right subtree then keep on popping untill a node popped who has right subtree then ptr will point to this right subtree node .Process will terminate if stack is empty.
  4 visit the node pointed by ptr and make ptr=ptr->right repeat process from step 2
*/
#include<bits/stdc++.h>
using namespace std;
#define struct Node*point;
stack<point>s;
struct Node
{
   int data;
   point left,right;
   Node(int dat)
   {
      data=dat;
      left=right=NULL;
   }
};
void inorder(point root)
{
    point ptr=root;
    while(1)
    {
       while(ptr->left!=NULL)
       {     
            s.push(ptr);
            ptr=ptr->left;
       }
       while(ptr->right==NULL)
       {
           cout<<ptr->data<<"\n";
           ptr=s.top();
           s.pop();
          
       }
       cout<<ptr->data<<"\n";
       ptr=ptr->right;
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
   cout<<"postorder traversal\n";
   postorder(root);
}
