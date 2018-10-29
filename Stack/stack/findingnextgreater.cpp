#include<bits/stdc++.h>
using namespace std;
void printgreater(int arr[],int n)
{
   stack<int>s1;
   s1.push(arr[0]);
   for(int i=1;i<n;i++)//reverse the loop for the case of printing reverse greater element
   {
//        int next=arr[i];
  //      int elem;
        if(s1.empty())
        {
              s1.push(arr[i]);
              continue;
             
         }
             while(!s1.empty() && s1.top()<arr[i])
             {
                 cout<<s1.top()<<" Greater "<<arr[i]<<"\n"; 
                 s1.pop();
             }
        
//        if(s1.top()>arr[i]) 
            s1.push(arr[i]);
   }
   while(!s1.empty())
   {
        cout<<s1.top()<<" Greater "<<-1<<"\n";
        s1.pop();
   }
   
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
       scanf("%d",&arr[i]);
   printgreater(arr,n);
   return 0;

}
