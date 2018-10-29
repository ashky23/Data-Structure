#include<bits/stdc++.h>
using namespace std;
int jumpsearch(int arr[],int n, int x)
{
    int step=sqrt(n);
    int prev=0;
    while(arr[min(step,n)-1]<x)
    {
      prev=step;
      step+=sqrt(n);
      if(prev>=n)
         return -1;
      }
     while(arr[prev]<x)
     {
         prev++;
         if(prev==min(step,n))
            return -1;
     }
     if(arr[prev]==x)
          return prev;
 return -1;
}
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
        cout<<jumpsearch(a,n,x)<<endl;
return 0;
}
