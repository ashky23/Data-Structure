#include<bits/stdc++.h>
using namespace std;
void addedge(list<int>a[],int u,int v)
{
   a[u].push_back(v);
}
void printbfs(list<int>a[],int V,int s)
{
  bool visited[V];
  for(int i=0;i<V;i++)
     visited[i]=false;
  list<int>q;
  q.push_back(s);
  visited[s]=true;
  while(!q.empty())
  {
     s=q.front();
     cout<<s<<" ";
     q.pop_front();
     list<int>::iterator i;
     for(i=a[s].begin();i!=a[s].end();i++)
     {
         if(!visited[*i])
         {
              visited[*i]=true;
              q.push_back(*i);
         }
     }
  }
}
int main()
{
  int V=5;
  list<int>a[V];
  addedge(a,0,1);
 addedge(a,0,2);
 addedge(a,2,0);
 addedge(a,1,2);
 addedge(a,2,3);
 addedge(a,3,3);
 printbfs(a,V,2);
 return 0;
}
