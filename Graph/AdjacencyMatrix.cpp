#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,f,max_edges,u,v;
   cout<<"Enter the no. of vertices.\n";
   cin>>n;
   int g[n][n];
   cout<<"Enter the type of Graph 1 for undirected or 2 for directed!\n";
   cin>>f;
   if(f==1)
       max_edges=n*(n-1)/2;
   else
       max_edges=n*(n-1);
       
   for(int i=1;i<=max_edges;i++)
   {
          cout<<"Enter the "<<i<<"th edge's vertices"" from source to destination or Enter -1 -1 to break;\n";
          cin>>u>>v;
          if(v==-1||u==-1)
               break;
          else
          {
               g[u][v]=1;
               if(f==2)
                 g[v][u]=1;
           }
          
   }
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n;j++)
        {
             if(g[i][j]==1)
               cout<<"Edge is present from "<<i<<" to"<<j<<"\n"; 
             else
               cout<<"Edge is not present from "<<i<<"to "<<j<<"\n";
        }
   }
   return 0;
}
