#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
  int data;
  point right,left;
};
int search(int arr[],int start,int end,int value)
{
   for(int i=start;i<=end;i++)
      if(arr[i]==value)
         return i;
}
point create(int data)
{
  point node=new Node;
  node->data=data;
  node->right=node->left=NULL;
  return node; 
}
point buildTree(int in[],int post[],int start,int end,int *preindex)
{
  if(start>end)
      return NULL;
   point tnode=create(post[(*preindex)]);
   (*preindex)--;
  if(start==end)
   return tnode;
   int index=search(in,start,end,tnode->data);
   tnode->right=buildTree(in,post,index+1,end,preindex);
   tnode->left=buildTree(in,post,start,index-1,preindex);
   return tnode;
}
point build(int in[],int post[],int n)
{
  int preindex=n-1;
  return buildTree(in,post,0,n-1,&preindex);
}
void preorder(point root)
{
  if(root==NULL)
      return ;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
int main()
{
 int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in)/sizeof(in[0]);
     point root = build(in, post,n);
 
    cout  << "Preorder of the constructed tree : \n";
    preorder(root);
 
    return 0;
}
