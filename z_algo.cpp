/*Z-Algorithm Pattern Searching:
Z[k]=Core Concept of the z Algorithm
    =It denotes the longest substring from k which is also a prefix of the string.
---------------------------------------------------------------------------------
Given: p=pattern string
       text=string in which searching is to be performed
Step1: add p and text strings together with a delimeter which is not present in either of the strings, let's name that string z.
Step2: Then build z array which is mentioned above.
Step3: let the size of string p is m , if we got the same value as m in z array then we found the string because we've added both the strings so that p string will appear as prefix, we can get the index by i=k-(m+1); where k is the index in z where same length has been found:
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>makez(string z)
{
     //cout<<"debug1\n";
     int l=0;
     int r=0;
     vector<int>v(z.length());
     v.at(0)=0;
   //  cout<<v[0]<<"Debug2\n";
     for(int i=1;i<z.length();i++)
     {
        if(i>r)
        {
           l=r=i;
           while(r<z.length() && z[r]==z[r-l])
              r++;
           v.at(i)=r-l;
            r--;
        }
        else
        {
            int k1=i-l;
            if(v[k1]<r-i+1)
                v.at(i)=v[k1];
            else
            {
               l=i;
               while(r<z.length() && z[r]==z[r-l])
                  r++;
               v.at(i)=r-l;
               r--;
             }
        }
    }
   return v;
}
vector<int>zmain(string t,string p)
{
  //cout<<"kl\n";
  string z=p+"$"+t;
 // cout<<z<<"\n";
  vector<int>s=makez(z);
  vector<int>result;
  for(int i=0;i<s.size();i++)
  {
      if(s[i]==p.length())
         result.push_back(i-p.length()-1);
  }
  return result;
}
int main()
{   
    //cout<<"Kullu\n";
    string t,p;
    cin>>t>>p;
    //cout<<"fdfds\n";
   vector<int>s=zmain(t,p);
  // for(int i=0;i<s.size();i++)
    //  cout<<s[i]<<" ";
   cout<<"\n"<<s.size()<<"\n";
    return 0;
}
