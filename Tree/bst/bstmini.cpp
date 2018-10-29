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
void inorder(point root)
{
  if(root)
  {
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
  }
}
point insert(point root,int key)
{
  if(root==NULL)
    return create(key);
  if(root->data>key)
      root->left=insert(root->left,key);
  if(root->data<key)
      root->right=insert(root->right,key);
 return root;

}
int mini(point root)
{
   point curr=root;
   while(curr->left!=NULL)
       curr=curr->left;
   return (curr->data);
}
int main()
{
    point root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
     cout<<mini(root)<<" ";
}
