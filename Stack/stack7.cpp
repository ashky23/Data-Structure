#include<bits/stdc++.h>
using namespace std;
class Stack
{
   queue<int>q1,q2;
   int currsize;
   public:
   Stack()
   {
     currsize=0;
   }
   void push(int x)
   {
      currsize++;
      q2.push(x);
      while(!(q1.empty()))
      {
         q2.push(q1.front());
          q1.pop();
      }
      queue<int>q=q1;
      q1=q2;
      q2=q;
   }
   void pop()
   {  if(q1.empty()){
       cout<<"underflow:\n";
      return ;
 } 
     q1.pop();
      currsize--;
    }
   int top()
   { 
     if(q1.empty())
     return -1;
     int x=q1.front();
     return x;
   }
   int size()
   {
      return currsize;
   }
  
};
int main()
{
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  cout<<"currentsize "<<s.size()<<endl;
 cout << s.top()<<endl;
   s.pop();
  cout<<s.top()<<endl;
    s.pop();
cout<<s.top()<<endl;
    s.pop();
  cout<<s.size()<<endl;
return 0;
}
