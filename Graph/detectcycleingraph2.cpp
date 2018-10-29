//for undirected graph
#include<bits/stdc++.h>
using namespace std;
void addEdge(list<int>adj[],int v,int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}
bool iscyclicutil(int v,list<int>adj[],bool visited[],int parent)
{
   visited[v]=true;
   list<int>::iterator i;
   for(i=adj[v].begin();i!=adj[v].end();i++)
   {
         if(!visited[*i])
          {
            if(iscyclicutil(*i,adj,visited,v))
               return true;
          }
          else if(*i!=parent)
               return true;
   }
   return false;
}
bool iscyclic(list<int>adj[],int V)
{
   bool visited[V];
   for(int i=0;i<V;i++)
       visited[i]=false;
   for(int i=0;i<V;i++)
       if(!visited[i])   
         if(iscyclicutil(i,adj,visited,-1))
            return true;
   return false;

}
int main()
{
 /*    list <int>adj[5];
    addEdge(adj,1, 0);
    addEdge(adj,0, 2);
    addEdge(adj,2, 0);
    addEdge(adj,0, 3);
    addEdge(adj,3, 4);
    iscyclic(adj,5)? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";*/
 
        list<int>adj[3];
    
    addEdge(adj,0, 1);
    addEdge(adj,1, 2);
    iscyclic(adj,3)? cout << "Graph contains cycle\n":
                  cout << "Graph doesn't contain cycle\n";
 
    return 0;
}
