#include<bits/stdc++.h>
using namespace std;
void enqueue(char q[],char element,int&rear,int size)
{
  if(size==rear)
      cout<<"qUEUe overflow:\n";
  else
  {
    q[rear++]=element;
  }
}
void dequeue(char q[],int rear,int &front)
{
  if(front==rear)
     cout<<"queue underflow:\n";
  else
  {
     q[front++]=0;
  }
}
char fronts(char q[],int front)
{
  return(q[front]);
}
int main()
{
   char q[20]={'a','b','c','d'};
  int   front=0,rear=4;
  int size=20;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      char ch=fronts(q,front);
      enqueue(q,ch,rear,size);
      dequeue(q,rear,front);
   }
  for(int i=front;i<rear;i++)
  {
       cout<<q[i];
  }
 cout<<"\n";
  return 0;
}
