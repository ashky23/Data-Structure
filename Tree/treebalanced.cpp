#include<bits/stdc++.h>
using namespace std;
#define bool int
typedef struct Node*point;
struct Node
{
   int data;
   point left,right;
};
/*int height(point root)
{
   if(root==NULL)
      return 0;
    return 1+max(height(root->left),height(root->right));
}
bool isbalanced(point root)
{
   if(root==NULL)
      return true;
   int lh=height(root->left);
   int rh=height(root->right);
   if((abs(lh-rh))<=1&&isbalanced(root->left)&&isbalanced(root->right))
      return true;
   return false;
}*/
bool isbalanced(point root,int &height)
{
  int lh=0,rh=0,l=0,r=0;
  if(root==NULL)
  {
     height=0;
      return 0;
  }
  l=isbalanced(root->left,lh);
  r=isbalanced(root->right,rh);
 height=max(lh,rh)+1;
  if(lh-rh>=2||rh-lh>=2)
      return 0;
  else
      return l&&r;
}
point create(int e)
{
   point node=new Node;
   node->data=e;
   node->left=NULL;
   node->right=NULL;
}
int main()
{
 int height=0;
 point root=create(1);
 root->left=create(2);
 root->right=create(3);
 root->left->right=create(4);
 root->left->left=create(5);
 root->left->left->left=create(3);
 if(isbalanced(root,height))
    cout<<"Tree is balanced:\n";
  else
    cout<<"Tree is not balanced:\n";
  cout<<height;
 return 0;
}

