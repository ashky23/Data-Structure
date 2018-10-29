#include<bits/stdc++.h>
using namespace std;
class twostacks
{
  int *arr;
  int top1;
  int top2;
  int size;
  public:
  twostacks(int n)
  {
     size=n;
     arr=new int[n];
     top1=-1;
     top2=size;
     }
  void push1(int x)
  {
     if(top1<top2-1)
     {
        top1++;
        arr[top1]=x;
        }
     else
     {
        cout<<"Stack overflow:\n";
        exit(1);
        }
     }
  void push2(int x)
  {
     if(top1<top2-1)
     {
        top2--;
        arr[top2]=x;
        }
     else
     {
        cout<<"Stack overflow:\n";
        exit(1);
        }
     }
  int pop1()
  {
     if(top1>=0)
      {
      int x=arr[top1];
      top1--;
      return x;
       }
     else
       cout<<"Stack underflow:\n";
  } 
    int pop2()
  {
     if(top2<size)
      {
      int x=arr[top2];
      top2++;
      return x; 
       }
     else
       cout<<"Stack underflow:\n";
  }

};
int main()
{
  twostacks (10);
  twostacks t;
  t.push1(23);
  t.push2(34);
  t.push1(12);
  t.push2(21);
  t.push1(41);
  t.push2(31);
  cout<<"popping1 "<<t.pop1()<<endl;
  cout<<"popping again2"<<t.pop2()<<endl;
 
  return 0;
  
}
