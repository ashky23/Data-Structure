#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point ;
struct Node
{
  int data;
  point left,right;

};
point create(int data)
{
  point node=new Node;
  node->data=data;
  node->left=node->right=NULL;
}
void  klevel(point root,int k)
{
  if(root==NULL)
    return ;
  if(k==0)
     cout<<root->data<<" ";
   else if(k>0)
   {
        klevel(root->left,k-1);
        klevel(root->right,k-1);
   }
}
int main()
{
   point root=create(1);
   root->left=create(2); 
   root->right=create(3);
   root->left->left=create(4);
   root->left->right=create(5);
   root->right->left=create(6);
   klevel(root,2);
   return 0;
}
