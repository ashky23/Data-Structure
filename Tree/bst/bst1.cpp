#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
  int data;
  point right,left;
};
point create(int key)
{
  point temp=new Node;
  temp->data=key;
  temp->right=temp->left=NULL;
  return temp;
}
point search(point root,int key)
{
  if(root==NULL||root->data==key)
    return root;
  if(root->data<key)
    return search(root->right,key);
  
  return search(root->left,key);
}
point insert(point root,int key)
{
   if(root==NULL)
     return create(key);
   if((root->data)>key)
     root->left=insert(root->left,key);
   else if((root->data)<key)
     root->right=insert(root->right,key);
  return root;
}
void inorder(point root)
{
  if(root!=NULL)
  {
      inorder(root->left); 
      cout<<root->data<<" ";
      inorder(root->right);

  }
}
int main()
{
  point root=NULL;
  root=insert(root,50);
 root= insert(root, 30);
   root= insert(root, 20);
  root= insert(root, 40);
  root= insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  cout<<"inorder traversal:\n";
    inorder(root);
 return 0;
}
