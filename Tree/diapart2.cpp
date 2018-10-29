#include<bits/stdc++.h>
using namespace std;
typedef struct Node*point;
struct Node
{
    int data;
    point left,right;
};
point create(int data)
{
    point node=new Node;
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
int height(point root,int &ans)
{
    if(root==NULL)
    return 0;
    int lh=height(root->left,ans);
    int rh=height(root->right,ans);
    ans=max(ans,lh+rh+1);
    return 1+max(lh,rh);
}
int diameter(point root)
{
    if(root==NULL)
      return 0;
    int ans=INT_MIN;
    int heioftree=height(root,ans);
    cout<<heioftree<<"\n";
    return ans;
}
/*int diameter(point root,int *height)
{
  int lh=0,rh=0;
  int ldia=0,rdia=0;
  if (root==NULL)
   {
       *height=0;
       return 0;
   }
  ldia=diameter(root->left,&lh);
  rdia=diameter(root->right,&rh);
*height=max(lh,rh)+1;
  return max(lh+rh+1,max(ldia,rdia));
}*/
/*void preorder(point root)
{
    if(root==NULL)
    return ;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
    
}*/
int main()
{
   
    int t,x;
    cin>>t>>x;
    int tc=t-1;
    point root=create(x);
    int count=0;
    while(tc--)
    {
        string s;
        int value;
        cin>>s>>value;
        
     point node=root;
       
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='L'&&s[i+1]!='\0')
            {
             node=node->left;
             
            }
             else if(s[i]=='R'&& s[i+1]!='\0')
             {
             node=node->right;
             }
             else if(s[i]=='L'&&s[i+1]=='\0')
             node->left=create(value);
             else if(s[i]=='R'&&s[i+1]=='\0')
             node->right=create(value);
        }
 
        
    }
    //preorder(root);
    cout<<diameter(root);
    return 0;
}
