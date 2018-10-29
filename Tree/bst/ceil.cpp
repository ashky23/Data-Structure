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
  point root=new Node;
  root->data=data;
  root->left=root->right=NULL;
}
point insert(point root,int key)
{
  if(root==NULL)
     return create(key);
  if(root->data<key)
     root->right=insert(root->right,key);
  else if(root->data>key)
     root->left=insert(root->left,key);
 return root;
}
int Ceil(point root,int key)
{
   if(root==NULL)
      return -1;
   if(root->data<key)
      return Ceil(root->right,key);
    int ceil=Ceil(root->left,key);
    return (ceil>=key)?ceil:root->data;
}
int main()
{
   point root=NULL;
   root=insert(root,8);
   root=insert(root,4);
   root=insert(root,12);
   root=insert(root,10);
   root=insert(root,14);
   root=insert(root,2);
   root=insert(root,6);
   for(int i=0;i<16;i++)
      cout<<i<<" "<<Ceil(root,i)<<"\n";
}
