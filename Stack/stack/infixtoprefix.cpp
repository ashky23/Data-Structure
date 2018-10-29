#include<bits/stdc++.h>
using namespace std;
int getweight(char ch)
{
   switch(ch)
   {
      case '+':
              return 2;
      case '-':
              return 1;
     case '/':
             return 4;
      case '*':
              return 3;
      case '^':
             return 5;
      default:
             return 0;
   }
}
string getpostfix(string infix)
{
   int l=infix.length();
   string output;
   stack<char>s;
   for(int i=0;i<l;i++)
   { 
       if(infix[i]=='(')
       {
          s.push(infix[i]);
          continue;
        }
       if(infix[i]==')')
       {
          while(!s.empty()&&s.top()!='(')
          {
                  output+=s.top();
                  s.pop();
          }
          if(!s.empty())
              s.pop();

          continue;
       }

   int weight=getweight(infix[i]);
   if(weight==0)
    {
        output+=infix[i];
     }
   else
   {
      if(s.empty())
          s.push(infix[i]);
       else
        {
            while(!s.empty()&&s.top()!='('&&weight<=getweight(s.top()))
            {
                output+=s.top();
                s.pop();
            }
         s.push(infix[i]);
        }
   }
   }
   while(!s.empty())
   {
      output+=s.top();
      s.pop();
   
}
cout<<output<<endl;
return output;
}
string getprefix(string infix)
{
  int l=infix.length();
  reverse(infix.begin(),infix.end());

  for(int i=0;i<l;i++)
  {
      if(infix[i]=='(')
      {
         infix[i]=')';
            i++;
       }
      else if(infix[i]==')')
      {
          infix[i]='(';
            i++;
      }
  }

   cout<<"infix "<<infix<<endl;
   string prefix=getpostfix(infix);
  reverse(prefix.begin(),prefix.end());
  return prefix;
}
int main()
{
  string s="a+b*c+d";
  cout<<getprefix(s)<<" \n";

}
