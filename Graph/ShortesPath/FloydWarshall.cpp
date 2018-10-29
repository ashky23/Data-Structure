#include<bits/stdc++.h>
using namespace std;
#define nil -1
#define infinity 9999
#define max 1000
int n;
int adj[max][max],d[max][max],pred[max][max],mat[max][max];
void create_graph()
{
   int u,v,wt;
   cout<<"Enter the no. of vertices:\n";
   cin>>n;
   int maxedge=n*(n-1);
   for(int i=0;i<maxedge;i++)
   {
      cout<<"Enter the end vertices of edge:(-1 -1 to quit)\n";
      cin>>u>>v;
      if(u==-1 && v==-1)
        break;
      if(u<0||v<0||u>=n||v>=n)
      {
          cout<<"Invalid vertices:\n";
          i--;
      }
      else 
      {
            cout<<"Enter the weight of edge:\n";
            cin>>wt;
            adj[u][v]=wt;
      }
   }
}
void display(int mat[][max])
{
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
           cout<<mat[i][j]<<" ";
       cout<<"\n";
     }
}
void floydwarshall()
{
    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
         {
              if(adj[i][j]==0)
              {
                  d[i][j]=infinity;
                  pred[i][j]=nil;
              }
              else
              {
                  pred[i][j]=i;
                  d[i][j]=adj[i][j];
              }
         }
    }
    for(int k=0;k<n;k++)
    {
         for(int i=0;i<n;i++)
              for(int j=0;j<n;j++)
              {
                   if(d[i][k]+d[k][j]<d[i][j])
                   {
                       d[i][j]=d[i][k]+d[k][j];
    		       pred[i][j]=pred[k][j];
                   }
              }
    }
    cout<<"Shortes Path matrix:\n";
    display(d);
    cout<<"Predecessor matrix:\n";
    display(pred);
    for(int i=0;i<n;i++)
    {
          if(d[i][i]<0)
          {
             cout<<"Graph contains negative cycles:\n";
             exit(1);
          }
    }
}
void pathfind(int s,int v)
{
    int count=-1;
    int path[max];
    while(v!=s)
    {
        path[++count]=v;
        v=pred[s][v];
    }
    path[++count]=s;
    for(int i=count;i>=0;i--)
          cout<<path[i]<<" ";
    cout<<endl;
}
int main()
{
    int s,v;
    create_graph();
    floydwarshall();
    while(1)
    {
         cout<<"Enter the source vertex:(-1 to quit)\n";
         cin>>s;
         if(s==-1)
            break;
        cout<<"Enter the end vertex:\n";
        cin>>v;
          if(s<0||s>=n||v<0||v>=n)
          {
             cout<<"Invalid input:\n";
             continue;
          } 
          else
              pathfind(s,v);
         
    }
    return 0;
}
