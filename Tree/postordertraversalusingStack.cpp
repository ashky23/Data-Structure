/*
  1 initially ptr points to root
  2 then push the left subtree rooted at ptr untill (ptr->left==NULL) here ptr will point to leftmost node of the tree.
  3 if ptr has no right subtree or it's right subtree has been visited then keep on popping untill a node popped who has right subtree then ptr will point to this right subtree's root node.Process will terminate if stack is empty.
  4 push the node(i.e. root node of right sub-tree) pointed by ptr ,make ptr=ptr->right and repeat process from step 2
*/


#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
stack<point>s;
struct Node
{
   int info;
   point left,right;
   Node(int info)
   {
       this->info=info;
       right=left=NULL;
   }
};
void postorder(point root)
{   
   point q,ptr=root;
   if (ptr==NULL)
       return ;
   q=root;
   while(1)
   {
        while(ptr->left!=NULL)
        {
            s.push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL || ptr->right==q)
        {
            cout<<ptr->info<<"\n";
            q=ptr; 
            if(s.empty())
                return;
            ptr=s.top();
            s.pop();
        }
    s.push(ptr);//we are pushing the right subtree root node ptr b'coz It's postorder traversal and we have to print right subtree before root
    ptr=ptr->right; 
   }


}
int main()
{


    
   point root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->right=new Node(5);
   root->left->left=new Node(4);
   cout<<"postorder traversal\n";
   postorder(root);
   return 0;
}
