#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,x,temp;
cin>>n>>x;
pair<int,int>p;
queue<pair<int,int> >q1;
for(int i=1;i<=n;i++)
{
  cin>>temp;
  p.first=temp;
  p.second=i;
  q1.push(p);
}
int it=x;
while(it--)
{
   
  int max=-1,pos;
  queue<pair<int,int> >q2,q3;
  q2=q1;
  while(!q1.empty())
  {
     q1.pop();
  }
  int i=x;
  while(i--)
  { 
   p=q2.front();
   q3.push(p);
   if(max<(p.first))
   {
      max=p.first;
      pos=p.second;
   }
   q2.pop();
   if(q2.empty())
        break;
     
  }
 
  while(!q2.empty())
  {
    p=q2.front();
    q1.push(p);
    q2.pop();
  }
  while(!q3.empty())
  {
    p=q3.front();
    if(max==p.first&&pos==p.second)
      q3.pop();
    else{
    if(p.first!=0)
     {
       p.first=p.first-1;
       
     }
    q1.push(p);
   q3.pop();
   }
  }
  cout<<pos<<" ";
}

return 0;
}
