#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class stack1
{
  int top;
  public:
  int a[MAX];
  stack1(){
   top=-1;
   }
  int push(int x);
  int pop();
  bool isempty();
};
int stack1 :: push(int x)
{
  if(top>=MAX)
{
   cout<<"Stack overflow\n";
   return 0;
}
  else {
  a[++top]=x;
  return x;
}
}
int stack1::pop()
{
   if(top<0){
    cout<<"Stack underflow:\n";
   return 0;
}
   else{
    int x=a[top--];
    return x;
}}
bool stack1:: isempty()
{
 // if(top<0)
   //return true;

return (top<0);
 }
int main(){
  stack1 s;
 cout<<s.pop()<<endl;
cout<<"pushed element :"<<s.push(10)<<endl;
cout<<"pushed element"<<s.push(20);
cout<<s.push(30);
cout<<s.push(40);
 cout<<s.pop()<<endl;
 cout<<s.isempty()<<endl;

return 0;
}

