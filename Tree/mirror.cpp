#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point ;
struct Node
{
  int data;
  point left,right;
};
bool ismirror(point root1,point root2)
{
  if(!root1&&!root2)
      return true;
  if(root1&&root2&&root1->data==root2->data)
    return ((ismirror(root1->left,root2->right))&&(ismirror(root1->right,root2->left)));

}
point create(int data)
{
   point node=new Node;
   node->data=data;
   node->right=node->left=NULL;
}
bool mirror(point root)
{
  return ismirror(root,root);
}
int main()
{
  point root=create(1);
  root->left=create(2);
  root->right=create(2);
  root->left->left=create(3);
  root->left->right=create(3);
  root->right->left=create(3);
  root->right->right=create(3);
  if(mirror(root))
     cout<<"YEs";
  else
     cout<<"NO";
}
