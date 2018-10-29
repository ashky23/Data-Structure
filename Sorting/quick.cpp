#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int low, int high)
{
int pi=a[high];
int j=low-1;
for(int i=low;i<high;i++)
{
if(a[i]<=pi)
{j++;
swap(a[i],a[j]);
}
}
swap(a[j+1],a[high]);
return (j+1);
}
void quicksort(int a[], int low, int high)
{
  if(low<high)
      {
       int pi=partition(a,low,high);
       
       quicksort(a,low,pi-1);
       quicksort(a,pi+1,high);
      }

}
void print(int a[],int n)
{
  for(int i=0;i<n;i++)
   {
   cout<<"~"<<a[i]<<endl;

   }

}
int main()
{
   int n;
    cin >>n;

   int a[n];
   for(int i=0;i<n;i++)
   { 

    cin>>a[i];
   }
quicksort(a,0,n-1);
print(a,n);
return 0 ;
}

