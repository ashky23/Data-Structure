#include<bits/stdc++.h>
using namespace std;
#define max 1000
int adj[max][max],indeg[max],n,topo[max];
void create_graph()
{
int u,v;
   cout<<"Enter the no of vertices \n";
   cin>>n;
   int max_edges=n*(n-1);//for directed edges:
   for(int i=0;i<max_edges;i++)
   {
 //       cout<<"Enter the end vertices of edge:(-1 -1 to quit)\n";
        cin>>u>>v;
        if(u == -1 && v == -1)
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
int indegree(int v)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
         if(adj[i][v]==1)
            count++;
    }
    return count;
}
int main()
{
    create_graph();
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        indeg[i]=indegree(i);
        if(indeg[i]==0)
          q.push(i);
        //cout<<i<<" "<<indeg[i]<<endl;
    }
    int v,count=0;
    while(!q.empty() && count<n)
    {
        v=q.front();
        q.pop();
        topo[++count]=v;
       // cout<<count<<" ";
        for(int i=0;i<n;i++)
        {
            if(adj[v][i]==1)
            {
                adj[v][i]=0;
                indeg[i]=indeg[i]-1;
                if(indeg[i]==0)
                   q.push(i);
          //      cout<<" de1\n";
            }
         }
      }
         if(count<n)
         {
             cout<<"Graph contains cycle :\n";
             exit(1);
          }
          cout<<"topological sorting:\n";
          for(int i=1;i<=count;i++)
          {
               cout<<topo[i]<<" "; 
          }
          cout<<"\n";
    
    return 0; 
}
