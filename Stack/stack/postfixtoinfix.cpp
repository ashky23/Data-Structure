#include<bits/stdc++.h>
using namespace std;
bool isoperand(char x)
{
  return ((x>='a'&&x<='z')||(x>='A'&&x<='Z'));
}
string getinfix(string str)
{
   stack<string>s;
   for(int i=0;str[i]!='\0';i++)
   {
       if(isoperand(str[i]))
        {
            string op(1,str[i]) ;
           s.push(op);
        }
        else
        {
            string op1=s.top();
  		s.pop();
            string op2=s.top();
               s.pop();
            s.push("("+op2+str[i]+op1+")");
        }
   }
return s.top();
}
int main()
{
string exp = "abcd^e-fgh*+^*+i-";
    cout << getinfix(exp);
    return 0;
}
