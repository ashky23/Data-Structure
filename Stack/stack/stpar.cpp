#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(1)
  {
    cin>>n;
   if(n==0)
       break;
   else
   {
      int a[n];
      stack<int>s1,s2,s3;
      int t;
      for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=n-1;i>=0;i--)
      {
         s1.push(a[i]);
      }
       while((s1.top())!=1)
       {
           s2.push(s1.top());
           s1.pop();
	} 
        s3.push(s1.top());
        s1.pop();
        while(1)
        {
           if(s1.empty())
             break;
           else if(s2.empty())
             break;
           else if(s1.top)
        }
   }

  }

}
