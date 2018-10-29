#include<bits/stdc++.h>
using namespace std;
//#define node struct linkedlist*
typedef struct linkedlist*node;
struct linkedlist
{
   int data;
   struct linkedlist*next;
};
node createnode()
{
   node temp;
   temp=(node)malloc(sizeof(struct linkedlist));
   temp->next=NULL;
//  temp->data=NULL;
  return temp;
}
node addnode(node head,int value)
{
   node temp,p;
   temp->data=value;
   if(head==NULL)
      head=temp;
   else
   {
      p=head;
      while(p->next!=NULL)
         p=p->next;
   
   p->next=temp;
   }
return head;
}
void printlist(node head)
{
   node p; 
   p=head;
   while(p->next!=NULL)
  {
     cout<<p->data<<" ";
     p=p->next;
  }
}
int main()
{
   node head =createnode();
   /*node fir= crea
   addnode(head,10);
   addnode(head,20);
   addnode(head,20);
   addnode(head,210);
   addnode(head,2210);
   addnode(head,120);
   addnode(head,32);
   addnode(head,2320);
   addnode(head,23230);
*/
   addnode(head,20);
   printlist(head);
  return 0;
  
}
