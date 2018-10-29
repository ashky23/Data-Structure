#include<bits/stdc++.h>
using namespace std;
char str[400];
int getweight(char ch)
{
   switch(ch)
   {
      case '+':
      case '-':
               return 1;
      case '*':
      case '/':
               return 2;
      case '^':
              return 3;
      default :
              return 0;
   }
}
void infix2postfix(char str[],char postfix[],int n )
{
  int weight;
  char ch;
  stack<char>s;
  int i=0,k=0;
  while(i<n)
  {
     ch=str[i];
     if(ch=='(')
     {
         s.push(ch);
         i++;
         continue;
     }
     if(ch==')')
     {
         while(!s.empty()&&s.top() != '(')
         {
            postfix[k++]=s.top();
            s.pop();
          }
         if(!s.empty())
            s.pop();
     
   i++;
    continue;   
      }
    weight=getweight(ch);
    if(weight==0)
       postfix[k++]=ch;
     else
     {
       if(s.empty())
           s.push(ch);
       else
       {
         while(!s.empty() && s.top() != '(' && weight <= getweight(s.top()))
         {
                       postfix[k++]=s.top();
                       s.pop();
                      
          }
           s.push(ch);
       }
         
      }
 i++;
}
while(!s.empty())
{
  postfix[k++]=s.top();
  s.pop();
}
postfix[k]=0;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     cin>>str;
     int n=strlen(str);
     char postfix[n];
     infix2postfix(str,postfix,n);
     cout<<postfix<<"\n";
  }
return 0;
}
