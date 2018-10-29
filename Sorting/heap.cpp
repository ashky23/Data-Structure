#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
  int largest=i;
  int l=2*i+1;
  int r=2*i+2;
  if(l<n&&a[l]>a[largest])
     {
      largest=l;
      }
   if(r<n&&a[r]>a[largest])
     {
      largest=r;
      }
   if(largest!=i)
  {
    swap(a[i],a[largest]);
    heapify(a,n,largest);//heapifying the affected subarray;
  }


}
void heapsort(int a[], int n)
{
  for(int i=n/2-1;i>=0;i--)//heapifying the max heap
  {
   heapify(a,n,i);
   }
   for(int i=n-1;i>=0;i--)//reducing the max heap by eliminating the max element 
   {
    swap(a[i],a[0]);
    heapify(a,i,0);
    }
}
void printarr(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
   cout<<"~~"<<a[i]<<endl;
  }
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

  heapsort(a,n);
  printarr(a,n);
return 0;
}
