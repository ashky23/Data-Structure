#include<bits/stdc++.h>
using namespace std;
void addgraph(vector<int> adj[] , int u, int v)
{
   adj[u].push_back(v);
   adj[v].push_back(u);
}
void printgraph(vector<int> adj[],int V)
{
  for(int v=0;v<V;v++)
  {
     cout<<v<<"->";
       for(auto x : adj[v])
       {
           cout<<x<<"->";
        }
    cout<<"\n";
  }
}
int main()
{

  int V=5;
  vector<int> adj[V];
  addgraph(adj,0,1);
  addgraph(adj,0,4);
  addgraph(adj,1,2);
  addgraph(adj,1,3);
  addgraph(adj,1,4);
  addgraph(adj,2,3);
  addgraph(adj,3,4);
  printgraph(adj,V);
  return 0;
}
