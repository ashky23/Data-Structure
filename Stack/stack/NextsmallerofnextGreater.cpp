#include<bits/stdc++.h>
using namespace std;
void nextgreater(int a[],int n,char order,int next[])
{
    stack<int>s;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty()&&((order=='G')?a[s.top()]<=a[i]:a[s.top()]>=a[i]))
             s.pop();
        if(!s.empty())
            next[i]=s.top();
        else
            next[i]=-1;
        s.push(i);
            
    }
}
void nextsmallerofnextgreater(int arr[],int n)
{

    int ng[n],ns[n];
    nextgreater(arr,n,'G',ng);
    nextgreater(arr,n,'S',ns);
    for(int i=0;i<n;i++)
    {
        if(ng[i]!=-1 && ns[ng[i]]!=-1)
            cout<<arr[i]<<"   "<<arr[ns[ng[i]]]<<"\n";
        else
            cout<<arr[i]<<"   "<<"-1"<<"\n";
    }
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
     scanf("%d",a+i);
     nextsmallerofnextgreater(a,n);
  return 0;
}
