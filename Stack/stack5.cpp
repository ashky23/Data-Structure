#include<bits/stdc++.h>
using namespace std;
class Stack
{
  static const int max=100;
  int top;
  int a[max];
  public:
  Stack()
  {top=-1;}
  bool isempty();
  bool isfull();
  void push(int x);
  int pop();
};
bool Stack::isempty()
{
  if(top==-1)
     return true;
   return false;  
}
bool Stack::isfull()
{
  if(top==max-1)
     return true;
   return false;
 }
void Stack::push(int x)
{
  if(top==max-1)
    cout<<"Stack overflow:\n";

  else
     top++;
    a[top]=x;
}
int Stack::pop()
{ int x;

  if(top==-1)
    cout<<"Stack underflow:\n";
  else{
     x=a[top];
    top--;
}
  return x;

}
//specialstack implementation 
class specialstack:public Stack
{
  Stack min;
  public:
  void push(int x);
  int pop();
  int getmin();
};
void specialstack::push(int x)
{
  if(isempty()==true)
  {
     Stack::push(x);
     min.push(x);
   }
  else
  {
     Stack::push(x);
     int y=min.pop();
     min.push(y);
     if(x<y)
      min.push(x);
     else
      min.push(y);
   }
}
int specialstack::pop()
{
  int x=Stack::pop();
  min.pop();
  return x;
}
int specialstack::getmin()
{
  int x=  min.pop();
  min.push(x);
  return x;
}
int main()
{
   specialstack s;
//   s.pop();
   s.push(12);
   s.push(30);
   s.push(40);
   s.push(32);
   s.push(23);
   cout<<s.getmin()<<endl;
   cout<<s.pop()<<endl;
   s.push(2);
   cout<<s.getmin()<<endl;

   cout<<s.pop()<<endl;
   return 0;
}
