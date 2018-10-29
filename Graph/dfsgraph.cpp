#include<bits/stdc++.h>
using namespace std;
class graph
{
  int V;
  list<int>*adj;
  bool *visited;
  void dfsutil(int V,bool visited[]);
  public:
  graph(int V);
  void addedge(int v,int w);
  void dfs();
};
graph::graph(int V)
{
   this->V=V;
       //V=d;
       adj=new list<int>[V];
}
void graph::addedge(int v,int w)
{
  adj[v].push_back(w);

}
void graph::dfsutil(int v,bool visited[])
{
  visited[v]=true;
  cout<<v<<" ";
  list<int>::iterator i;
  for(i=adj[v].begin();i!=adj[v].end();i++)
  {
       if(!visited[*i]) 
           dfsutil(*i,visited);
  }
}
//we are making this function for connected and disconnected all graph:
void graph::dfs()
{
   visited=new bool[V];
   for(int i=0;i<V;i++)
      visited[i]=false;
   for(int i=0;i<V;i++)
      if(!visited[i])
         dfsutil(i,visited);
}
int main()
{
graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs();
 
    return 0;
}
