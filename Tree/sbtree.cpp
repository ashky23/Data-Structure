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
  point node=new Node;
  node->data=data;
  node->left=NULL;
  node->right=NULL;
}
bool aresubtree(point root1,point root2)
{
    if(root1==NULL&&root2==NULL)
       return true;
    if(root1==NULL||root2==NULL)
       return false;
   return( root1->data==root2->data && aresubtree(root1->left,root2->left) && aresubtree(root1->right,root2->right));
      
   
}
bool issubtree(point T,point S)
{
  if(T==NULL)
     return false;
   if(S==NULL)
     return true;
   if(aresubtree(T,S))
     return true;
   return (issubtree(T->left,S)||issubtree(T->right,S));

}
int main()
{
   point T=create(1);
    T->right              = create(3);
    T->right->right       = create(3);
    T->left               = create(10);
    T->left->left         = create(4);
    T->left->left->right  = create(30);
    T->left->right        = create(6);
 
    point S=create(10);
    S->right          = create(6);
    S->left           = create(4);
    if(issubtree(T,S))
      cout<<"subtree:\n";
    else
      cout<<"not a subtree:\n";
 return 0;
}
