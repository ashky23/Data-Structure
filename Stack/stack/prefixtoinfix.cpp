#include<bits/stdc++.h>
using namespace std;
bool isoperand(char ch)
{
   return ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'));
}
void getinfix(string str)
{
    stack<string>s;
   int l=str.length();
    for(int i=l-1;i>=0;i--)
    {
       char ch=str[i];
       if(isoperand(ch))
       {
          string op(1,ch);
          s.push(op);
       }
       else
       {
          string op1=s.top();
	  s.pop();
	  string op2=s.top();
          s.pop();
          s.push("("+op1+ch+op2+")");
       }
        
    }
  cout<<s.top()<<endl;
}
int main()
{
  string s="*-A/BC-/AKL";
  getinfix(s);
}
