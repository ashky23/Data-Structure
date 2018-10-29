#include<bits/stdc++.h>
using namespace std;
#define max 100
#define TRUE 1
#define FALSE 0
#define infinity 9999
#define nil -1
int n,s;
int predec[max],adj[max][max],pathlength[max],ispresent[max];
queue<int>q;
void create_graph()
{

   int u,v,wt;
   cout<<"Enter the no of vertices \n";
   cin>>n;
   int max_edges=n*(n-1);//for directed edges:
   for(int i=0;i<max_edges;i++)
   {
        cout<<"Enter the end vertices of edge:(-1 -1 to quit)\n";
        cin>>u>>v;
        if(u==-1&&v==-1)
             break;
        cout<<"Enter the weight of the edge:\n";
        cin>>wt;
        if(u<0||v<0||u>n||v>n)
        {
            cout<<"Invalid Edge enter again\n";
            i--;
        }
        
       else 
           adj[u][v]=wt;
   }
}
int bellman_ford(int s)
{
    int current,k=0;
    for(int i=0;i<n;i++)
    {
        predec[i]=nil;
        pathlength[i]=infinity;
        
     }
    q.push(s);
    ispresent[s]=TRUE;
    pathlength[s]=0;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        ispresent[current]=FALSE;
        if(s==current)
            k++;
        if(k>n)
           return -1;
        for(int i=0;i<n;i++)
        {
            if(adj[current][i]!=0)
                if(adj[current][i]+pathlength[current]<pathlength[i])
                 {
                        pathlength[i]=adj[current][i]+pathlength[current];
			predec[i]=current;
                        if(!ispresent[i])
                        {    ispresent[i]=TRUE;
                             q.push(i);
                         }
                 }
        }
    }
}
void findPath(int v)
{
   int path[max];
    int count=0;
    int m=v;
    int shortestpath=0;
    while(v!=s)
    {
       count++;
       
        path[count]=v;
        int u=predec[v];
        shortestpath+=adj[u][v]; 
        v=u;
    }
    count++;
    path[count]=s;
    for(int i=count;i>=1;i--)
       cout<<" "<<path[i];
       cout<<"\nPath LEngth= "<<shortestpath<<"\nfrom Array=> "<<pathlength[m]<<endl;
}

int main()
{
     create_graph();
     int v;
     cout<<"Enter source vertex:\n";
     cin>>s;
     int flag=bellman_ford(s);
     if(flag==-1)
     {
         cout<<"Graph contains a cycle with neg edge:\n";
         exit(1);
     }
     while(1)
     {
          cout<<"Enter the vertex to know it's shortest Path (-1 to quit):\n";
          cin>>v;
          if(v==-1)
            break;
          if(v<0||v>n)
          {    cout<<"Not a valid vertex:\n";
               continue;
          }
          else
             findPath(v);
     }    
     return 0;
}
