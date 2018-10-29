#include<bits/stdc++.h>
using namespace std;
typedef struct vertex*node;
typedef struct edge*line;
struct vertex
{
   int info;
   node nextvertex;
   line firstedge;
}*start=NULL;
struct edge
{
   node destnode;
   line nextedge;
};
void insertvertex(int val)
{
    node ptr,temp;
    temp=new vertex;
    temp->info=val;
    temp->nextvertex=NULL;
    temp->firstedge=NULL;
    if(start==NULL)
    {
       start=temp;
       return;
    }
    ptr=start;
    while(ptr->nextvertex!=NULL)
    {
        ptr=ptr->nextvertex;
    }
    ptr->nextvertex=temp;
}
node findvertex(int val)
{
   node ptr;
   ptr=start;
   while(ptr!=NULL)
   {
        if(ptr->info==val)
          return ptr;
        ptr=ptr->nextvertex;
   }
   return ptr;
}
void insertedge(int u,int v)
{
    line temp,ptr;
    node locu,locv;
    locu=findvertex(u);
    locv=findvertex(v);
    if(locu==NULL||locv==NULL)
    {
          cout<<"The given vertex is not present hence we can't add edge, first insert that vertex\n";
          return;
    }
    temp=new edge;
    temp->destnode=locv;
    temp->nextedge=NULL;
    if(locu->firstedge==NULL)
    {
       locu->firstedge=temp;
       return;
    }
    ptr=locu->firstedge;
    while(ptr->nextedge!=NULL)
    {
         ptr=ptr->nextedge;
    }
    ptr->nextedge=temp;
}
void delincomingedges(int val)
{
     node ptr;
     ptr=start;
     line temp,q;
     while(ptr!=NULL)
     {
         if(ptr->firstedge==NULL)
         {
		ptr=ptr->nextvertex;
 		continue;
         }
 
         if(ptr->firstedge->destnode->info==val)
         {
 		temp=ptr->firstedge;
  		ptr->firstedge=ptr->firstedge->nextedge;
                delete(temp); 
          	
                continue;
         }
         q=ptr->firstedge;
        while(q->nextedge!=NULL)
        {
            if(q->nextedge->destnode->info==val)
            {
                 temp=q->nextedge;
                 q->nextedge=q->nextedge->nextedge;
                 delete(temp);
                 continue;
            }
             q=q->nextedge;
        }
        ptr=ptr->nextvertex;
     }
}
void deletevertex(int val)
{
     node ptr,temp;
     ptr=start;
     if(start==NULL)
     {
        cout<<"Graph is empty\n";
        return ;
      }
     if(start->info==val)
      {
           temp=start;
           start=start->nextvertex;
           
      }
     else
     {
       while(ptr->nextvertex != NULL)
       {
          if(ptr->nextvertex->info==val)
              break;
            ptr=ptr->nextvertex;
       }
       if(ptr->nextvertex==NULL)
           cout<<"vertex not found;\n";
       else
       {
           temp=ptr->nextvertex;
           ptr->nextvertex=temp->nextvertex;
       }
     }
     
     line ptr1,temp1;
     ptr1=ptr->firstedge;
     while(ptr1!=NULL)
     {
         temp1=ptr1;
         ptr1=ptr1->nextedge;
         delete(temp1);
     }
     delete(temp);
}
void deledge(int u,int v)
{
    node locu;
    locu=findvertex(u);
    line temp,ptr;
    if(locu==NULL)
    {
       cout<<"Start vertex is not present in graph\n";
       return;
     }
    if(locu->firstedge==NULL)
    {
       cout<<"Edge is not present\n";
        return;
     }
    if(locu->firstedge->destnode->info==v)
    {
           temp=locu->firstedge;
           locu->firstedge=temp->nextedge;
           delete(temp);
           return;
     }  
     ptr=locu->firstedge;
     while(ptr->nextedge!=NULL)
     {
                if(ptr->nextedge->destnode->info!=v)
   		{
                    temp=ptr->nextedge;
                    ptr->nextedge=temp->nextedge;
                    delete(temp);
                    return;
		}
                    ptr=ptr->nextedge;
     }
}
void display()
{
   node ptr;
   line temp;
   ptr=start;
   while(ptr!=NULL)
   {
       cout<<ptr->info<<"-->";
       temp=ptr->firstedge;
       while(temp!=NULL)
       {
           cout<<temp->destnode->info<<" ";
           temp=temp->nextedge;
       }
       ptr=ptr->nextvertex;
       cout<<"\n";
   }
}

int main()
{
    int ch,val,u,v;
    while(1)
    {
        printf("Enter the no. to perform corresponding task;\n1.insertvertex\n2.insertedge\n3.deletevertex\n4.deleteedge\n5.display\n6.exit\n");
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter the value of vertex to be inserted\n";
                    cin>>val;
                    insertvertex(val);
                    break;
            case 2: cout<<"Enter the edge co-ordinate to be inserted\n";
                    cin>>u>>v;
                    insertedge(u,v);
 		    break;
            case 3: cout<<"Enter the value of vertex to be deleted\n";
                    cin>>val;
                    delincomingedges(val);
                    deletevertex(val);
                    break;
 	    case 4: cout<<"Enter the edge to be deleted\n";
                    cin>>u>>v;
 		    deledge(u,v);
                    break;
            case 5: cout<<"Graph is--->\n";
		    display();
                    break;
            case 6: exit(1);                    
           default: printf("wrong choice :P\n");
                    break;
        }
    
    }
    
    return 0;
}
