/*
  Algorithm for searching string p in string t and as well as returning the no. of occurences.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> makelookup(string p)
{
   int m=p.length();
   vector<int>F(m);
   F[0]=0;
   for(int i=1;i<m;i++)
   {
      int j=F[i-1];
      while(j>0&&p[j]!=p[i])
      {
           j=F[j-1];
      }
      if(p[j]==p[i])
      {
          j++;
      }
          F[i]=j;
   }
   return F;
}
int kmp(string t,string p)
{
   int n=t.length();
   int m=p.length();
   int j=0,ctr=0,i=0;
   vector<int>F=makelookup(p);
   while(i<n)
   {
//      cout<<i<<"pra\n";
      if(t[i]==p[j])
      {
          i++;
          j++;
      }
      if(j==m)
      {
          ctr++;
          j=F[j-1];
      }
      else if(i<n && t[i]!=p[j])
      {   
         if(j!=0)
           j=F[j-1];
      
         else
            i++;
      }
   }
   return ctr;
}
int main()
{
    string t="abcabcabc";
    string p="abc";

  cout<<kmp(t,p)<<"\n";
   return 0;
}
