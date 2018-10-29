#include<bits/stdc++.h>
using namespace std;
int board[10][10],n;
void display()
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
           cout<<board[i][j]<<" ";
       cout<<"\n";
   }
}
bool isvalid(int row,int col)
{
    for(int i=0;i<col;i++)
        if(board[row][i])
            return false;
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j])
           return false;
    for(int i=row,j=col;i<n && j>=0;i++,j--)
        if(board[i][j])
           return false;
    return true;
}
bool solveNqutil(int col)
{
    if(col>=n)
        return true;
     for(int i=0;i<n;i++)
     {
          if(isvalid(i,col))
          {
              board[i][col]=1;
              if(solveNqutil(col+1))
                   return true;
               board[i][col]=0;
          }
         
     }
     return false;
}
void solveNq()
{
    cin>>n;
    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
              board[i][j]=0;
    if(!(solveNqutil(0)))
    {  
        cout<<"Solution Doesn't quit:\n";
        return ;
    }
    display();   
}
int main()
{
   solveNq();
   return 0;
}
