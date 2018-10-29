#include<bits/stdc++.h>
using namespace std;
//typedef struct node*point;
struct node
{
   int data;
    node*left,*right;
};
int height(node* root,int& ans)
{
  if(root==NULL)
     return 0;
  int lh=height(root->left,ans);
  int rh=height(root->right,ans);
  ans=max(ans,lh+rh+1);
  return max(lh,rh)+1;

}
int diameter(node* root)
{
   if(root==NULL)
      return 0;
   int ans=INT_MIN;
   int height_of_tree=height(root,ans);
    cout<<height_of_tree<<"\n";
   return ans;
}
struct node* create(int data)
{
   struct node* temp=new node;
   temp->data=data;
   temp->right=NULL;
   temp->left=NULL;
  return temp;
}
int main()
{
   struct node*  root=create(1);
   root->left=create(2);
   root->right=create(3);
   root->left->left=create(4);
   root->left->right=create(5);
   cout<<diameter(root);
  return 0;
}
