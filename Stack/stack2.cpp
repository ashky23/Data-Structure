#include<bits/stdc++.h>
#define max 100
using namespace std;

void push(int );
void pop();
void display();

int Stack[max];
int top=-1;
int main()
{
int t;
   while(1)
   {
    cout<<"enter the value you want to perform :\n1.push,2.pop,3.display\n";
    cin>>t;
    int value;
    switch(t)
    {
       case 1: cout<<"Enter the value you want to add:\n";
               cin>>value;
               push(value);
               break;
       case 2: pop();
               break;
       case 3: display();
               break;
       case 4: exit(0);
       default: cout<<"you opted for wrong choice:";
       }

    }
return 0;
}
    void push(int value)
    {
        if(top>=max)
           cout<<"stack overflow:\n";

        else {
           top++;
           Stack[top]=value; 
           }
        }
    void pop()
    {
      if(top<0)
           cout<<"Stack underflow:\n";
      else
         { 
           cout<<"Element to be popped :\n"<<Stack[top]<<endl;
           top--;
          }
      }
    void display()
    {
       if(top<0)
           cout<<"Stack underflow , can't display:\n";
       
       else
           for(int i=top;i>=0;i--)
              { 
                  cout<<i<<"element"<<Stack[i]<<endl;

                  }
      }

