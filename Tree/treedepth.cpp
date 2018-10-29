#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
   int data;
   point right,left;
};
int height(point root)
{
    if(root==NULL)
       return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
point create(int data)
{
   point node=new Node;
   node->data=data;
   node->left=node->right=NULL;    
}
int main()
{
   point root=create(1);
   root->left=create(2);
   root->right=create(3);
   root->left->left=create(4);
   root->left->right=create(5);
   cout<<height(root);
   return 0;
}
