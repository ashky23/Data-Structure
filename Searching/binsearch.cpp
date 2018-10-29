#include<bits/stdc++.h>
using namespace std;
int binsearch(int a[], int l, int r, int x)
{
    if(l<=r)
    {
     int mid=l+(r-l)/2;
     if(a[mid]==x)
	 return mid;      
     else if(a[mid]<x)
	 return binsearch(a,mid+1,r,x);
     else
	 return binsearch(a,l,mid-1,x);
     }	
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
     int res=binsearch(a,0,n-1,x);
     (res==-1)?cout<<"not found\n":cout<<"found at"<<res<<"index\n";
return 0;
}
