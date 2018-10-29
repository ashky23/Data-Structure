#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    char ch;
    
    while(n--)
    {
        cin>>ch;
        int a;
        queue<int>q;
        if(ch=='E')
        { 
          cin>>a;
          q.push(a);
          cout<<q.size()<<"\n";
        }
        else if(ch=='D')
        {
            if(q.empty())
            {
                cout<<-1<<" "<<q.size()<<"\n";
            }
            else
            {
                int d=q.front();   
                cout<<d<<" "<<q.size()<<"\n";
                q.pop();
            }
        }
    }
    
    return 0;
}
