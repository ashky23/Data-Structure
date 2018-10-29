//DFS using Recursion
#include<bits/stdc++.h>
using namespace std;
#define initial 1
#define visited 2
#define finished 3
#define max 100
int n,t=0;
int d[max],f[max],adj[max][max],state[max];
void create_graph()
{
      cout<<"Enter the no. of vertices\n";
   cin>>n;
   int max_edges=n*(n-1);
   int u,v;
   for(int i=0;i<max_edges;i++)
   {
        cout<<"Enter the end vertices of edge(-1 -1 to quit)\n";
        cin>>u>>v;
        if(u==-1&&v==-1)
             break;
        if(u<0||u>n||v<0||v>n)
        {
                cout<<"Invalid edge\n";
                i--;
        }
        else
            adj[u][v]=1;
   }
}
void dfs(int v)
{
    state[v]=visited;
//    t++;
    d[v]=++t;
    cout<<v<<" ";
    for(int i=0;i<n;i++)
    {
         if(adj[v][i]==1 && state[i]==initial)
         {
             dfs(i);
         }
    }
    state[v]=finished;
    f[v]=++t;
}
void df_traversal()
{
    int v;
    cout<<"Enter the vertex: df traversal\n";
    cin>>v;
    for(int i=0;i<n;i++)
        state[i]=initial;
    dfs(v);
    for(int i=0;i<n;i++)
    {
        cout<<i<<"--"<<d[i]<<"=="<<f[i]<<"\n";
    }
}
int main()
{
    create_graph();
    df_traversal();
}

