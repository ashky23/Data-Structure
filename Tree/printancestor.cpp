#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{ 
  int data;
  point right,left;
 
};
bool printancestor(point root,int target)
{
   if(root==NULL)
      return false;
   if(root->data==target)
      return true;
   if(printancestor(root->left,target)||printancestor(root->right,target))
   {
      cout<<root->data<<" ";
      return true;
   }
return false;
}
point create(int data)
{
   point node=new Node;
   node->data=data;
   node->right=node->left=NULL;
   return node;
}
int main()
{
  point root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->left->right=create(5);
  root->left->left=create(4);
  root->left->left->left=create(7);
   printancestor(root,7);
  return 0;
}
