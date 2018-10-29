//WAP for deletion so that tree shriks:-means deleted node will be replaced by the bottommost node:
#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
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
void deletdeepest(point root,point deepest)
{
  queue<point>q;
  q.push(root);
  point temp;
  while(!q.empty())
  {
      temp=q.front();
      q.pop();
     if(temp->left)
     {
      if(temp->left==deepest)
      {
        temp->left=NULL;
        delete (deepest);
        return ;
      }
      else
         q.push(temp->left);
     }
     if(temp->right)
     {
      if(temp->right==deepest)
      {
        temp->right=NULL;
        delete (deepest);
        return ;
      }
      else
         q.push(temp->right);
  }

   }
}
void deletenode(point root,int key)
{
  queue<point>q;
  q.push(root);
  point temp;
  point keynode;
  while(!q.empty())
  {
     temp=q.front();
     q.pop();
     if(temp->data==key)
         keynode=temp;
     if(temp->left)
      q.push(temp->left);
     if(temp->right)
      q.push(temp->right);
  }
  int x=temp->data;
  deletdeepest(root,temp);
   keynode->data=x;
}
void inorder(point root)
{
   if(!root)
   {
      return;
       
   }
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}
int main()
{
      point root=create(1);
      root->left=create(2);      
      root->right=create(3);      
      root->left->left=create(4);      
      root->left->right=create(5);      
      root->right->left=create(6);      
      root->right->right=create(7);      
      root->right->left->left=create(8);      
      root->right->left->right=create(9);      
      cout<<"pre-inorder\n";
      inorder(root);
      deletenode(root,5);
      cout<<"\npost-inorder\n";
      inorder(root);
return 0;
      
}
