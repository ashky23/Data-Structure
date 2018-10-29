#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   int x;
   cin>>x;
   int count=0;
   for(int i=0;i<n;i++)
   {
       if(a[i]==x)
       {   
           count=1;
           cout<<" "<<i<<endl;
       }
    }
    if(count==0)
	cout<<-1<<endl;
return 0;
}
