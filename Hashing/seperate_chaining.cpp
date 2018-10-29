#include<bits/stdc++.h>
using namespace std;
#define max 100
struct emp 
{
   int empid;
   int age;
   string name;
};
struct record
{
    struct emp emp1;
    struct record* link;
};
int hash(int key)
{
    return (key%max);
}
int search(struct record* table[],int key)
{
   int h=hash(key);
   struct record* ptr=table[h];
   while(ptr!=NULL) 
   {
       if(ptr->emp1.empid==key)
          return h;
       ptr=ptr->link;
        
   }
   return -1;
}
void insert(struct record*table[],struct emp emprec)
{
    int key=emprec.empid;
    int h=hash(key);
    struct record*temp=new record;
    if(search(table,key)!=-1)
    {  
           cout<<"Duplicate Key\n";
           return;
     }
     temp->emp1=emprec;
     temp->link=table[h];
     table[h]=temp;
}
void display(struct record*table[])
{
    struct record* ptr;
    for(int i=0;i<max;i++)
    {
            cout<<"POs "<<i<<"\n";
           if(table[i]!=NULL)
           {
                 ptr=table[i];
                 while(ptr!=NULL)
                 {
                    cout<<" EmpId-> "<<ptr->emp1.empid<<" Name-> "<<ptr->emp1.name<<" Age-> "<<ptr->emp1.age<<endl;
                    ptr=ptr->link;
                 }
           }
    }
}
void del(struct record* table[],int key)
{
   int h=hash(key);

   struct record*ptr,*temp;
   if(table[h]==NULL)
   {
       cout<<"Not Found \n"; 
       return ;
   }
   if(table[h]->emp1.empid==key)
   {
         temp=table[h]; 
         table[h]=table[h]->link;
         delete(temp);
         return;
   }
   ptr=table[h];
   while(ptr!=NULL)
   {
         if(ptr->link->emp1.empid==key)
         {
              temp=ptr->link;
              ptr->link=temp->link;
              delete(temp);
              return;
         }
         ptr=ptr->link;
   }
   cout<<"Key Not Found;\n";
}
int main()
{
    int ch,key,i; 
    struct record* table[max];
    struct emp emprec;
    while(1)
    {
        cout<<"Enter the choice\n1.search\n2.Insertion\n3.Deletion\n4.Display\n5.exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter the key to be searched:\n";
                    cin>>key;
                    i=search(table,key);
                    if(i==-1)
                    cout<<"Key not found:\n";
                    else
                    cout<<"Key is present "<<i<<endl;
                    break;
            case 2: cout<<"Enter the id,name,age to be inserted:\n";
                    cin>>emprec.empid>>emprec.name>>emprec.age;
                    insert(table,emprec);
                    break;
            case 3: cout<<"Enter the key to be deleted:\n";
                    cin>>key;
                    del(table,key);
                    break;
            case 4: display(table);
                    break;
            case 5: exit(1);
            case 6: cout<<"Wrong choice try again:\n"; 
                    break;
        } 
    }
}
