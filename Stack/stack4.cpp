#include<bits/stdc++.h>
struct node
{
int data;
struct node*next;
};
void push(struct node**topref,int newdata);
int pop(struct node**topref);

struct queue
{
   struct node* stack1;
   struct node* stack2;
};

void enqueue(struct queue*q,int x)
{
   push(&q->stack1,x);
   }

int dequeue(struct queue*q)
{
  int x;
  if(q->stack1==NULL&&q->stack2==NULL)
  {
     std::cout<<"queue underflow:\n";
     exit(0);
   }
  if(q->stack2==NULL)
  {
   while(q->stack1!=NULL)
   {
    x=pop(&q->stack1);
    push(&q->stack2,x);
    }
   }
  x=pop(&q->stack2);
  return x;
}

void push(struct node**topref,int newdata)
{
   struct node* newnode=(struct node*)malloc(sizeof(struct node*));
   if(newnode==NULL)
   {
    std::cout<<"stack overflow:\n";
    exit(0);
   }
   newnode->data=newdata;
   newnode->next=*topref;
   *topref=newnode;
}

int pop(struct node**topref)
{
 int res;
 struct node*top;
 if(*topref==NULL)
 {
  std::cout<<"stack overflow:\n";
  }
 top= *topref;
 res=top->data;
 *topref=top->next;
 free(top);
return res;
}
int main()
{
  struct queue*p=(struct queue*)malloc(sizeof(struct queue*));
  p->stack1=NULL;
  p->stack2=NULL;
  enqueue(p,23);
  enqueue(p,64);
  enqueue(p,32);
  printf("%d\n",dequeue(p));
  printf("%d\n",dequeue(p));
  printf("%d\n",dequeue(p));
  printf("%d\n",dequeue(p));

return 0;
}

