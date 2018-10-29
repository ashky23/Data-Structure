#include<bits/stdc++.h>
using namespace std;
#define temp 1
#define perm 2
#define nil -1
#define max 100
#define infinity 99999
int n,s,adj[max][max],state[max],predecess[max],short_path[max];
void create_graph()
{
   int u,v,wt;
   cout<<"Enter the no of vertices \n";
   cin>>n;
   int max_edges=n*(n-1);//for directed edges:
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
           adj[u][v]=wt;
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
void dijkstra(int s)
{
   
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
           return;
        state[current]=perm;
      for(int i=0;i<n;i++)
      {
          if(adj[current][i]!=0 && state[i]==temp)
          if(adj[current][i]+short_path[current]<short_path[i] )
          {
             short_path[i]=adj[current][i]+short_path[current];
             predecess[i]=current;
          }
     }
   }
}
void min_path(int v)
{
    int path[max];
    int count=0;
    int pathlength=0;
    while(v!=s)
    {
       count++;
        int u=predecess[v];
        path[count]=u;
        pathlength+=adj[u][v]; 
        v=u;
    }
    count++;
    path[count]=s;
    for(int i=count;i>1;i--)
       cout<<" "<<path[i];
       cout<<"Path LEngth "<<pathlength<<endl;
}
int main()
{
   int v;
   create_graph();
   cout<<"Enter the source vertex:\n";
   cin>>s;
   dijkstra(s);
   while(1)
   {
        cout<<"Enter the end vertex to know shortest path for it:(-1 to quit)\n";
        cin>>v;
        if(v==-1)
           break;
        else if(v<-1||v>n)
          cout<<"INvalid vertex;\n";
        else if(short_path[v]==infinity)
          cout<<"There is no edge between source and vertex;\n";
        else
          min_path(v);
   }
   return 0;
}
