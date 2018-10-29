//program for insertion at the first null or free space whether it's left or right child of a node:
#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
  int data;
  point left,right;
};
point create(int data)
{
  point temp=new Node;
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}
void inorder(point root)
{
  if(root==NULL)
     return ;
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}
void insertion(point root,int key)
{
   queue<point>q;
   q.push(root);
   point temp;
   while(!q.empty())
   {
      temp=q.front();
      q.pop();
      if(!(temp->left)) 
      {
         temp->left=create(key);
         break;
      }
      else
         q.push(temp->left);
      if(!(temp->right))
      {
         temp->right=create(key);
         break;
      }
      else
         q.push(temp->right);

   }

}
int main()
{
  point root=create(10);
  root->left=create(12);
  root->left->left=create(6);
  root->left->left->left=create(18);
  root->right=create(13);
  root->right->left=create(14);
  root->right->right=create(15);
  int key=17;
  cout<<"inorder traversal\n";
  inorder(root);
  insertion(root,key);
  cout<<"inorder traversal\n";
  inorder(root);
  return 0;
}
