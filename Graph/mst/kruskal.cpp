#include<bits/stdc++.h>
using namespace std;
typedef struct edge*point;
#define nil -1
#define max 1000
struct edge
{
   int x;
   int y;
   int weight;
   point link;
}*front=NULL;
int n;
void insert_edge(int u,int v,int wt)
{
    point temp=new edge;
    temp->x=u;
    temp->y=v;
    temp->weight=wt;
    if(front==NULL || temp->weight<=front->weight)
    {
         temp->link=front;
         front=temp;
    }
    else
    {
         point q=front;
         while(q->link!=NULL && q->link->weight<=temp->weight)
             q=q->link;
         temp->link=q->link;
         q->link=temp;
         if(q->link==NULL)
         {
             temp->link=NULL;
          }         
    }
}
void create_graph()
{
    int u,v,wt;
   cout<<"Enter the no of vertices \n";
   cin>>n;
   int max_edges=n*(n-1)/2;//for directed edges:
   for(int i=0;i<max_edges;i++)
   {
        cout<<"Enter the end vertices of edge:(-1 -1 to quit)\n";
        cin>>u>>v;
        if(u==-1&&v==-1)
             break;
        cout<<"Enter the weight of the edge:\n";
        cin>>wt;
        if(u<0||v<0||u>n||v>n)
        {
            cout<<"Invalid Edge enter again\n";
            i--;
        }
        
       else 
            insert_edge(u,v,wt);
   }
}
int is_empty()
{
   if(front==NULL)
      return 1;
    return 0;
}
point del_top()
{
   point temp=front;
   front=front->link;
   return temp;
}
void make_tree(struct edge tree[])
{
   int v1,v2,root1,root2,count=0;
   int father[max]; 
   point temp;
   for(int i=0;i<n;i++)
   {
       father[i]=nil;
   }
   while(!is_empty() && count<=n)
   {
         temp=del_top();
         v1=temp->x;
         v2=temp->y;
         while(v1!=nil)
         {
             root1=v1;
             v1=father[v1];
         }
         while(v2!=nil)
         {
             root2=v2;
             v2=father[v2];
         }
         if(root1!=root2)
         { 
              count++;
              tree[count].x=temp->x;
              tree[count].y=temp->y;
              tree[count].weight=temp->weight;
              father[root2]=root1;
         }
 
 
   } 
   if(count<n-1)
   { 
        cout<<"Graph is disconnected:\n";
        exit(1);
   }
}
int main()
{
   struct edge tree[max];
   create_graph();
   make_tree(tree);
   int totalweight=0;
   for(int i=1;i<n;i++)
   {
       cout<<i<<"th edge from "<<tree[i].x<<"->"<<tree[i].y<<"\n";
       totalweight+=tree[i].weight;
   }
   cout<<"Total weight of minimum spanning tree: "<<totalweight<<endl;
   return 0;
}
