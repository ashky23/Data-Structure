#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
struct Node
{
  int data;
  point left,right;
  Node(int data)
  {
    this->data=data;
     left=right=NULL;
  }
  

};
int height(point node)
{
  if(node==NULL)
    return 0;
  int lh=height(node->left);
  int rh=height(node->right);
  return max(lh,rh)+1;
}
int diameter(point tree)
{
   if(tree==NULL)
     return 0;
   int lheight=height(tree->left);
   int rheight=height(tree->right);
   int rdia=diameter(tree->right);
   int ldia=diameter(tree->left);
   return max(lheight+rheight+1,max(rdia,ldia));
}
int main()
{
   point root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->right=new Node(4);
   root->left->left=new Node(5);
   cout<<diameter(root)<<"\n";
  return 0;
  
}
