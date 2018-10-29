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
int height(point node);
void printgivenlevel(point root ,int level);
void printlevel(point root)
{
  int h=height(root);
  for(int i=1;i<=h;i++)
  {
      printgivenlevel(root,i);
  }

}
void printgivenlevel(point root ,int level)
{
   if(root==NULL)
      return ;
   if(level==1)
     cout<<root->data<<" ";
   else if(level>1)
   {
      printgivenlevel(root->left,level-1);
      printgivenlevel(root->right,level-1);
   } 
}
int height(point node)
{
   if(node==NULL)
     return 0;
   else
   {
      int lheight=height(node->left);
      int rheight=height(node->right);
      if(lheight>rheight)
       return lheight+1;
      else
       return rheight+1;
  }
}
int main()
{
  point root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  cout<<"level order traversal\n";
  printlevel(root);
return 0;
}
