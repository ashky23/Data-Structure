#include<bits/stdc++.h>
using namespace std;
#define initial 1
#define waiting 2
#define visited 3
#define Max 100
int state[Max];
int n;
int adj[Max][Max];
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
void bfs(int v)
{
   queue<int>q;
   q.push(v);
   state[v]=waiting;
                 //        cout<<"entersd\n";
    while(!q.empty())
    {
           v=q.front();
           cout<<v<<" ";
               //          cout<<"enterfds\n";
           state[v]=visited;
           q.pop();
           for(int i=0;i<n;i++)
           {
                 if(adj[v][i]==1 && state[i]==initial)
                 {
                        q.push(i);
                         state[i]=waiting;
             //            cout<<"enter\n";
                  }
           }
    }
}
void bf_traversal()
{
   int v;
   for(int i=0;i<n;i++)
       state[i]=initial;
   cout<<"Enter the starting vertex for traversal\n";
   cin>>v;
   bfs(v);
   for(int i=0;i<n;i++)
   {
         if(state[i]==initial)
              bfs(i);
   }

}
int main()
{
    create_graph();
    bf_traversal();
    return 0;
}
