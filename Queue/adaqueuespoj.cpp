#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  bool reverse=false;
  ll n;
  cin>>n;
  string s;
  deque<int>q;
  while(n--)
  {
    int element;
    cin>>s;
     if(s=="back")
     {
       if(q.empty())
         cout<<"No job for Ada?\n";
       else
       {
        if(!reverse)
        {
          cout<<q.back()<<"\n";
  	  q.pop_back();
        }
        else
        {
          cout<<q.front()<<"\n";
          q.pop_front();
        }
      }
     }
     else if(s=="front")
     {
        if(q.empty())
          cout<<"No job for Ada?\n";
        else
        {
        if(!reverse)
        {
	   cout<<q.front()<<"\n";
           q.pop_front();
        }
        else
        {
 	   cout<<q.back()<<"\n";
           q.pop_back();
        }
     }}
     else if(s=="reverse")
     {
           reverse=!reverse;
     }
     else if(s=="push_back")
     {
         cin>>element;
         if(!reverse)
         {
             q.push_back(element);
         }
         else
         {
	     q.push_front(element);
         }
     }
     else if(s=="toFront")
     {
          cin>>element;
         if(!reverse)
         {
 	    q.push_front(element);
          }
          else
          {
             q.push_back(element);
          }
     }
  }
return 0;
}
