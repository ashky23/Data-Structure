#include<bits/stdc++.h>
using namespace std;
void showstack(stack <int> q)
{
    stack<int>gq=q;
    while(!gq.empty())
    {
       cout<<"\t"<<gq.top();
       gq.pop();
    }
    cout<<"\n";
}
int main()
{
   stack<int>gquiz;
   gquiz.push(10);
 
   gquiz.push(30);
   gquiz.push(64);
   gquiz.push(23);
   gquiz.push(12);
   gquiz.push(32);
   gquiz.push(33);
   gquiz.push(40);
   gquiz.push(43);
   gquiz.push(0);
   gquiz.push(3);

   showstack(gquiz);
   cout<<"The top element of stack:"<<gquiz.top();
   cout<<"\nThe size of stack:"<<gquiz.size();
   

       cout << "\ngquiz.pop() : ";
//    gquiz.pop();
    showstack(gquiz);







   return 0;
}
