/*
  1.Postorder Traversal will provide postfix expression.
  2.Preorder Travesal will provide prefix expression.
  3.Inorder Traversal will provide Infix expression(but without '()')
  4.To convert inorder traversal into Infix expression with brackets we will follow follow    ing procedure.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
struct Node
{
   char info; 
   point left,right;
   Node(char t)//Creation of New Node of Tree;
   {
       info=t;
       left=right=NULL;
   }

};
void infixWithBrackets(point root)
{
   if(root==NULL)
      return ;
   if(root->left==NULL&&root->right==NULL)
       cout<<root->info;
   else
   {
       cout<<"(";
       infixWithBrackets(root->left);
       cout<<root->info;
       infixWithBrackets(root->right);
       cout<<")";
   }
}
int main()
{
   point root=new Node('/');
   root->left=new Node('-');
   root->right=new Node('+');
   root->left->left=new Node('a');
   root->left->right=new Node('*');
   root->left->right->left=new Node('b');
   root->left->right->right=new Node('c');
   root->right->left=new Node('d');
   root->right->right=new Node('/');
   root->right->right->left=new Node('e');
   root->right->right->right=new Node('f');
   infixWithBrackets(root);
 
 return 0;
   

}
