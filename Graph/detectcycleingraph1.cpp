//for directed graph
#include<bits/stdc++.h>
using namespace std;
void addEdge(list<int>adj[],int u,int w)
{
   adj[u].push_back(w);
}
bool iscyclicutil(list<int>adj[],bool visited[],bool recstack[],int v)
{
   if(!visited[v])
   {
     visited[v]=true;
     recstack[v]=true;
     list<int>::iterator i;
     for(i=adj[v].begin();i!=adj[v].end();i++)
     {
         if(!visited[*i]&&iscyclicutil(adj,visited,recstack,*i))
            return true;
         else if(recstack[*i])
           return true;
     }
   }
  recstack[v]=false;
  return false;
}
bool iscyclic(list<int>adj[],bool visited[],bool recstack[],int V)
{
   for(int i=0;i<V;i++)
   {
        visited[i]=false;
        recstack[i]=false;
   }
   for(int i=0;i<V;i++)
       if(iscyclicutil(adj,visited,recstack,i))
          return true;
  return false;
}
int main()
{
    int V=4;
    list<int>adj[V];
    bool visited[V];
    bool recstack[V];
    addEdge(adj,0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    addEdge(adj,3, 3);
  
  
   if(iscyclic(adj,visited,recstack,V))
     cout<<"cyclic\n";
   else
      cout<<"acyclic\n";
  return 0;
}
