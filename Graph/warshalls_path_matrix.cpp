/*
  P-1[i][j]=path from i to j doesn't employee any intermediate vertix(Adjacency Matrix):
  P0[i][j]=path from i to j ,employees  intermediate vertix from 0 to 1:
  ................
  ................
  Pk[i][j]=path from i to j , employees intermediate vertix from 0 to k: (not greater than k)
  ------------------------------------------------------------------------------------------
  we can calculate Pk[i][j] if we know Pk-1[i][j]'s value:
  ------------------------------------------------------------------------------------------
  1.)if Pk-1[i][j]=1 ---->>Pk[i][j]=1
  2.)if Pk-1[i][j]=0 ---->>
                          a.)if Pk-1[i][k]=1 && Pk-1[k][j]=1  --->  Pk[i][j]=1
                          b.)else 0
*/
#include<bits/stdc++.h>
using namespace std;
#define Max 100
int n;
int adj[Max][Max];
void display(int m[][Max],int n)
{
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
            cout<<m[i][j]<<" ";
       }
       cout<<"\n";
     }
       
}
void create_graph()
{
   int u,v;
   cout<<"Enter the no of vertices \n";
   cin>>n;
   int max_edges=n*(n-1);//for directed edges:
   for(int i=0;i<max_edges;i++)
   {
        cout<<"Enter the end vertices of edge:(-1 -1 to quit)\n";
        cin>>u>>v;
        if(u==-1&&v==-1)
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
int main()
{
    create_graph();
    int P[Max][Max];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                P[i][j] = adj[i][j];
    cout<<-1<<"-->";
    display(P,n);
    cout<<"\n";
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
	    {
                P[i][j]=P[i][j] ||(P[i][k] && P[k][j]);
            }
       cout<<k<<"--> ";
        display(P,n);
        cout<<"\n";
    }
    return 0;
}
