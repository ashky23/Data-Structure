#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
struct Node
{
  int data;
  point left,right;
};
point newNode(int data)
{
   point node=new Node;
   node->data=data;
   node->left=node->right=NULL;
   return node;
}
void inorder(point root)
{
  if(root==NULL)
      return ;
  
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
int countnodes(point root)
{
    if(root==NULL)
       return 0;
    return countnodes(root->left)+countnodes(root->right)+1;
}
void storeinorder(point root,int arr[],int*i)
{
    if(root==NULL)
     return;
     
     storeinorder(root->left,arr,i);
     arr[*i]=root->data;
     (*i)++;
    storeinorder(root->right,arr,i);
     
}
void arraytobst(point root,int arr[],int* i)
{
   if(root)
    { 
       arraytobst(root->left,arr,i);
       root->data=arr[*i];
       (*i)++;
       arraytobst(root->right,arr,i);
        
    }

}
void binarytobst(point root)
{
  if(root==NULL)
    return ;
  //vector<int>vec;
   int n=countnodes(root);
    int arr[n];
  int i=0;
  storeinorder(root,arr,&i);
  sort(arr,arr+n);
   i=0;
   arraytobst(root,arr,&i);
}
int main()
{
    point root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    cout<<countnodes(root)<<" \n";
    cout<<"inorder of bt:\n";
    inorder(root);

    binarytobst(root);
    cout<<"inorder of bst:\n";
    inorder(root);
}
