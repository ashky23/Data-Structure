//We're building Segment Tree for query sum of desired range:
#include<bits/stdc++.h>
using namespace std;
#define max 1000
int n;
int seg_tree[max];
int arr[max],lazy[max];
void build(int s,int e,int pos)
{
   if(s==e)//leaf node
   {
      seg_tree[pos]=arr[s];
      return ;
   }
   int m=s+(e-s)/2;//splitting
   build(s,m,pos*2);//building left subtree (here root will present at pos 1 hence left child will be at 2*i and right child will be 2*i+1)
   build(m+1,e,pos*2+1);//Building right subtree:
   //Updating current node after building it's left and right subtree:
   seg_tree[pos]=seg_tree[2*pos]+seg_tree[2*pos+1];
   return ;//not mandatory
}
int rangeminquery(int qlow,int qhigh,int low,int high,int pos)
{
   if(qlow<=low&&qhigh>=high)//Total overloop of seg_range into query_range:
       return seg_tree[pos];
   if(qlow>high||qhigh<low)//No overlapping.
       return 0;
   //For partial overlap We will traverse in both left and right subtree:
   int mid=low+(high-low)/2;
   return rangeminquery(qlow,qhigh,low,mid,2*pos)+rangeminquery(qlow,qhigh,mid+1,high,2*pos+1);
}
void updateSegmentTree(int startRange,int endRange,int delta,int low, int high,int pos)//Updation of Segment Tree using lazy propagation:
{
   if(low>high)
       return ;
  // cout<<"De1\n";
   if(lazy[pos]!=0)
   {
      seg_tree[pos]+=lazy[pos];
    //       cout<<"De13\n";
      if(low!=high)
      {
        lazy[2*pos]+=lazy[pos];
        lazy[2*pos+1]+=lazy[pos];
      }
      lazy[pos]=0;
   }
   if(startRange>high || endRange<low)//No overloop:
   {
       return ;
   }
   if(startRange<=low && endRange >= high)    //Total overloop condition 
   {
       seg_tree[pos]+=delta;
        if(low!=high)
        {  
           seg_tree[pos]+=delta;
           lazy[2*pos]+=delta;
           lazy[2*pos+1]+=delta;
        }
        return;
   }
   int mid=low+(high-low)/2;
  // cout<<"De12\n";
   cout<<mid<<endl;
   updateSegmentTree(startRange,endRange,delta,low,mid,2*pos);
   updateSegmentTree(startRange,endRange,delta,mid+1,high,2*pos+1);
   seg_tree[pos]=seg_tree[2*pos]+seg_tree[2*pos+1];
//   cout<<"De14\n";
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,n,1);
    int a,b,ch,x,y,delta;
    while(1)
    {
        cout<<"Enter the valid range for sum query:(-1 -1 to quit)\n";
        cin>>a>>b;
        if(a==-1 && b==-1 )
            break;
        if(a>n || b >n || (a>b)||a<=0||b<=0)
        {
             cout<<"invalid range\n";
             continue;
        }
        cout<<"Answer of query--"<<rangeminquery(a,b,1,n,1)<<endl;
        cout<<"Want to UPdate your data:\nenter 1 for yes else 0:\n";
        cin>>ch;
        if(ch)
        {
              cout<<"Tell startrange and endrange and also the increment delta:\n";
              cin>>x>>y>>delta;
               updateSegmentTree(x,y,delta,1,n,1);
             for(int i=x;i<=y;i++)
                cout<<seg_tree[i]<<" ";
        }
        else 
           continue;
    }
    return 0;
}
