#include<bits/stdc++.h>
using namespace std;
int ternarysearch(int a[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid1=l+(r-l)/3;
        int mid2=r+(l-r)/3;
        if(a[mid1]==x)
            return mid1;
        else if(a[mid2]==x)
            return mid2;
        else if(x<a[mid1])
            return ternarysearch(a,l,mid1-1,x);
        else if(x>a[mid2])
            return ternarysearch(a,mid2+1,r,x);
        else
            return ternarysearch(a,mid1+1,mid2-1,x);
    }
    return -1;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   int x;
   cout<<"Enter the element to be searched:\n";
   cin>>x;
   cout<<ternarysearch(a,0,n-1,x)<<"\n";
   return 0;
}
