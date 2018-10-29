#include<bits/stdc++.h>
using namespace std;
void printgreater(string arr,int n)
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
             while(!s1.empty() && s1.top()>arr[i])
             {
                 char s=s1.top();
                 cout<<s<<" Smaller "<<arr[i]<<"\n";
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
   string s;
   //scanf("%s",s);
   cin>>s;
   int n=s.size();
   
   printgreater(s,n);
   return 0;

}
       
