#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
  int data;
  point left,right;
};
void levelorder(point root)
{
  queue<point>q;
  point temp=root;
  while(temp)
  {
      cout<<temp->data<<" ";
     if(temp->left)
      q.push(temp->left);
     if(temp->right)
      q.push(temp->right);
   
     temp=q.front();
     q.pop();
  }
}
point create(int data)
{
   point temp=new Node;
   temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}
int main()
{
  point root=create(100);
  root->left=create(2);
  root->right=create(3);
  root->left->left=create(4);
  root->left->right=create(5);
  levelorder(root);
 return 0;
}
