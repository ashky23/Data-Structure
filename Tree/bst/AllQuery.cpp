#include<bits/stdc++.h>
using namespace std;
typedef struct Node* point;
struct Node
{
   int data;
   point left,right;
   
};
void create(point root,int data)
{
    point temp= new Node;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(point root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(point root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(point root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}
int height(point root)
{
   if(root==NULL)
       return 0;
   int lheight=height(root->left);
   int rheight=height(root->right);
   if(lheight>rheight)
      return lheight+1;
   else
      return rheight+1;
}
point search(point ptr,int key)//Search Function
{
   if(ptr==NULL)//Recursive Function
      return NULL;
  else if(ptr->data>key)
    return search(ptr->left,key);
  else if(ptr->data>key)
    return search(ptr->right,key);
  else
    return ;
/*Non-Recursive function
  while(ptr!=NULL)
  {
     if(ptr->data<key)
        ptr=ptr->right;
     else if(ptr->data>key)
        ptr=ptr->left;
     else
        return ptr;

  }
  */
}
point min(point ptr)
{
  if(ptr!=NULL)
     while(ptr->left!=NULL)
          ptr=ptr->left;
  return ptr;
  
}
point max(point ptr)
{
   if(ptr!=NULL)
      while(ptr->right!=NULL)
         ptr=ptr->right;
   return ptr;
}
point insert(point ptr,int key)
{
}
point del(point ptr,int key)
{
}
int main()
{
   point ptr, root=NULL;
   int choice,k;
   while(1)
   {   
     cout<<"1.Search\n2.Insert\n3.Delete\n4.Max and Min in BST\n5.Preorder Traversal\n6.Postorder Traversal\n7.Inorder Traversal\n8.Height Of Tree\n9.quit\n";
    cout<< "Enter YOur Choice\n";
    cin>>choice;
    switch(1)
    {
        case 1: cout<<"Enter the key to be searched:\n";
                cin>>k;
                ptr=search(root,k);
                if(ptr==NULL)
                cout<<"Key is not present:\n";
                else
                cout<<"Key is present:\n";
                break;
       case 2: cout<<"Enter the key to be inserted:\n";
               cin>>k;
               insert(root,k);
               break;
       case 3: cout<<"Enter the key to be deleted:\n";
               cin>>k;
               del(root,k);
               break;
       case 4: ptr=max(root);
               if(ptr!=NULL)
                  cout<<"The max. element is "<<ptr->data<<"\n";
              ptr=min(root);
               if(ptr!=NULL)
                  cout<<"The min. element is "<<ptr->data<<"\n";
              break;
      case 5: preorder(root);
              break;
      case 6: postorder(root);
              break;
      case 7: inorder(root);
              break;
      case 8: cout<<"The height Of tree is"<<height(root)<<"\n";
              break;
      case 9: exit();
              break;
      default: cout<<"Wrong Choice:\n";
    }
   }
     return 0;
}
