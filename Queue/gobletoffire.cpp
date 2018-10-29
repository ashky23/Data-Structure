#include<bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   int q,a,b,temp;
   cin>>q;
   char ch;
   queue<int>q1[5],q2;
   while(q--)
   {
      cin>>ch;
      if(ch=='E')
      {
         cin>>a>>b;
         if(q1[a].empty())
            q2.push(a);
            q1[a].push(b);
      }
      else
      {
         temp=q2.front(); 
         cout<<temp<<" "<<q1[temp].front()<<endl;
         q1[temp].pop();
         if(q1[temp].empty())
            q2.pop();
      }
   }
return 0;
}
