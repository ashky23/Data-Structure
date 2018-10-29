#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
struct Node
{
  int data;
  point right,left;
};
point create(int data)
{
  point node=new Node;
  node->data=data;
  node->right=NULL;
  node->left=NULL;
}
void mirror(point node)
{
   if(node==NULL)
      return ;
   else
   {
      mirror(node->left);
      mirror(node->right);
      swap(node->left,node->right); 
   }
}
///via queue a.k.a. level order traversal
/*void mirror(point node)
{
   queue<point>q;
   q.push(node);
   while(!q.empty())
   {
       point curr=q.front();
       q.pop();
       swap(curr->left,curr->right);
       if(curr->left)
          q.push(curr->left);
       if(curr->right)
          q.push(curr->right);
   }
}*/
void inorder(point node)
{
  if(node==NULL)
    return ;
  else
  {
      inorder(node->left);
      cout<<node->data;
      inorder(node->right);
  }
}
int main()
{
  point root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->left->left=create(4);
  root->left->right=create(5);
  cout<<"before mirroring\n";
  inorder(root);
  cout<<"\n";
  mirror(root); 
  cout<<"after mirroring\n";
  inorder(root);
}
