//---Prim's Algorithm is based on Dijkstra shortest path algorithm
#include<bits/stdc++.h>
using namespace std;
#define temp 1
#define perm 2
#define nil -1
#define max 100
#define infinity 99999
int n,adj[max][max],state[max],predecess[max],short_path[max];
struct edge
{
    int u; 
    int v;
    int weight;
};
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
       {  
         adj[u][v]=wt;
         adj[v][u]=wt;
        }
   }
}
int min_temp()
{
   int k=nil;
   int min=infinity;
   for(int i=0;i<n;i++)
   {
        if(state[i]==temp && short_path[i]<min)
        {     
              min=short_path[i];
              k=i; 
        }
   }
  
   return k;
}
void make_tree(int s,struct edge tree[])//s is an alias of root of the tree;
{
   
   int count=0;
   for(int i=0;i<n;i++)
   {
       state[i]=temp;
       predecess[i]=nil;
       short_path[i]=infinity;
   }
   short_path[s]=0;
   while(1)
   {
        int current=min_temp();
        if(current==nil)
        {
          if(count==n-1)
          return;
          else
             exit(1);
         }
        if(current!=s)
        {   
            count++;
            tree[count].u=predecess[current];
            tree[count].v=current;
        }
        state[current]=perm;
        for(int i=0;i<n;i++)
        {
          if(adj[current][i]!=0 && state[i]==temp)
          if(adj[current][i]<short_path[i] )
          {
             short_path[i]=adj[current][i];
             predecess[i]=current;
          }
     }
   }
}

int main()
{
   int root;
   cout<<"Enter the root:\n";
   cin>>root;
   struct edge tree[max];
   create_graph();
   make_tree(root,tree);
   int total_wt=0;
   for(int i=1;i<n;i++)
   {
       cout<<i<<"th edge from "<<tree[i].u<<"->"<<tree[i].v<<"\n";
       total_wt+=adj[tree[i].u][tree[i].v];
   }
   cout<<"Total Weight "<<total_wt<<endl;
   return 0;
}


