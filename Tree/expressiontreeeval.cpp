#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
  char ch;
  point left,right;

};
point create(char ch)
{
   point temp=new Node;
   temp->ch=ch;
   temp->right=NULL;
   temp->left=NULL;
  return temp;
}
bool isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
       return true;

  return false;
}
point construct(string postfix)
{
  stack<point>st;
  point t,t1,t2;
  for(int i=0;i<postfix.length();i++)
  {
     if(!isoperator(postfix[i]))
     {
        t=create(postfix[i]);
        st.push(t);
     }
     else
     {
        t=create(postfix[i]);
        t1=st.top();
        st.pop();
        t2=st.top();
        st.pop();
        t->right=t1;
        t->left=t2;
        st.push(t);
     }
  }
  t=st.top();
  st.pop();
  return t;
}
void inorder(point node)
{
  if(node)
  {
      inorder(node->left);
    //      cout<<node->ch<<" ";
      printf("%c ",node->ch);
      inorder(node->right);
  }

}
void preorder(point node)
{
  if(node)
  {
      //cout<<node->ch<<" ";
      printf("%c ",node->ch);
      preorder(node->left);
      preorder(node->right);
  }

}
int main()
{
  string str="ab+ef*g*-";
  point root=construct(str);
  inorder(root);
  cout<<"\n";
  preorder(root);
 
return 0;
}
