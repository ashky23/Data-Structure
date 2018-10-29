#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
  int data;
  point right,left;
};
int search(char arr[],int start,int end,char value)
{
   for(int i=start;i<=end;i++)
      if(arr[i]==value)
         return i;
}
point create(char data)
{
   point node=new Node;
   node->data=data;
   node->right=node->left=NULL;
  return node;
}
point buildtree(char in[],char pre[],int start,int end)
{
  static int preindex=0;
   if(start>end)
      return NULL;
   point tnode=create(pre[preindex++]);
   if(start==end)
     return tnode;
   
    int index=search(in,start,end,tnode->data);
     tnode->left=buildtree(in,pre,start,index-1);
     tnode->right=buildtree(in,pre,index+1,end);
  return tnode;
}
void print(point root)
{
   if(root==NULL)
      return ;
   print(root->left);
   cout<<(char)root->data<<" ";
//   printf("%c",root->data);
   print(root->right);
}
int main()
{
 char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  point root= buildtree(in,pre,0,len-1);
  print(root);
 return 0;
}
