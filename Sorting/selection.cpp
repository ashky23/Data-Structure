#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];

  for(int i=0;i<n;i++)
   { cin>>a[i];
    }
  int mini;
  for(int i=0;i<n-1;i++)
{ 
  mini=i;
  for(int j=i+1;j<n;j++)
   	{
    if(a[j]>a[mini])
       mini=j;
  }
// a[i]=a[mini];
//a[mini]=a[i];
swap(a[mini],a[i]);
}
for(int i=0;i<n;i++)
   { 
     cout<<"==>>"<<a[i]<<endl;
   }
return 0;
}
