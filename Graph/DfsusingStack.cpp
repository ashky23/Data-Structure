#include<bits/stdc++.h>
using namespace std;
#define initial 1
#define visited 2
#define Max 100
int state[Max],adj[Max][Max],predecessor[Max];
int n;
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
   stack<int>s;
   s.push(v);
   predecessor[v]=-1;
   while(!s.empty())
   {
       v=s.top();
       s.pop();
       if(state[v]==initial)
       {
            state[v]=visited;
            cout<<v<<" ";
        }
        for(int i=n-1;i>=0;i--)
        {
            if(adj[v][i]==1 && state[i]==initial) 
            {
 		s.push(i);
                predecessor[i]=v;
            }
        }
   }
}
void df_traversal()
{
    int v;
    for(int i=0;i<n;i++)
         state[i]=initial;
    cout<<"Enter the starting vertex for traversal:\n";
    cin>>v;
    dfs(v);
    for(v=0;v<n;v++)
    {
        if(state[v]==initial) 
           dfs(v);
    }
    cout<<"\nPredecessor\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Predecessor of "<<i<<" - > "<<predecessor[i]<<"\n";
    }
}
int main()
{
    create_graph();
    df_traversal();
     return 0;
}
