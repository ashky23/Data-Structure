#include<bits/stdc++.h>
using namespace std;
#define Max 100
#define initial 1
#define waiting 2
#define visited 3
#define nil -1
#define infinity 9999
int n;
int state[Max],adj[Max][Max],predecessor[Max],dist[Max],path[Max];
void create_graph()
{
     int u,v;
   cout<<"Enter the no of vertices \n";
   cin>>n;
   int max_edges=n*(n-1);//for directed edges:
   for(int i=0;i<max_edges;i++)
   {
        cout<<"Enter the end vertices of edge:(-1 -1 to quit)\n";
        cin>>u>>v;
        if(u==-1&&v==-1)
             break;
        if(u<0||v<0||u>n||v>n)
        {
            cout<<"Invalid Edge enter again\n";
            i--;
        }
        
       else 
           adj[u][v]=1;
   }
}
void bfs(int v)
{
    queue<int>q;
    q.push(v);
    state[v]=waiting;
    predecessor[v]=nil;
    dist[v]=0;
    while(!q.empty())
    {
        v=q.front();
        cout<<v<<" ";
        q.pop();
        state[v]=visited;
        for(int i=0;i<n;i++)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
               q.push(i);
                state[i]=waiting; 
                predecessor[i]=v;
                dist[i]=dist[v]+1;
            }
        }
    }
}
void bfs_traversal()
{
   int v;
   for(int i=0;i<n;i++)
   {
        state[i] =initial;
        dist[i]=infinity;
        predecessor[i]=nil;
   }
   cout<<"Enter the starting vertex for traversal:\n";
   cin>>v;
   bfs(v);
}
int main()
{
   int v;
   create_graph();
   bfs_traversal();
   while(1)
   {
        cout<<"Enter the vertex to know the shortest path for that vertex using bfs:(or -1 to quit)\n";
        cin>>v; 
        if(v<-1||v>n-1)
        {
            cout<<"Wrong vertex:\n";
            continue;
        }
        int count=0;
        if(v==-1)
            break;
        else
        {
             cout<<"Shortest for vertex "<<v<<" is "<<dist[v]<<"\n";
             cout<<"Path array:\n";
             while(v!=nil) 
             {
                  count++;
                  path[count]=v;
                  v=predecessor[v];
             }
             for(int i=count;i>0;i--)
                  cout<<" "<<path[i]<<" ";
        }
   }
}
