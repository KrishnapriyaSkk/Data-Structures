#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node{
 int data;
 struct node*link;
};

struct node*head[MAX]={NULL};
int SIZE;
void insert(int key)
{
  int i;
  struct node*temp,*newnode;
  i=key%SIZE;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=key;
  newnode->link=NULL;
  if(head[i]==NULL)
     head[i]=newnode;
  else
  {
    temp=head[i];
    while(temp->link!=NULL)
    {
     temp=temp->link;
    }
   temp->link=newnode;
  }
}
void display()
{
  int i=0;
  struct node*temp;
  while(i<SIZE)
  {
   printf("\n Position %d:",i);
   if(head[i]!=NULL)
   {
    temp=head[i];
    while(temp!=NULL)
    {
      printf("\t%d",temp->data);
      temp=temp->link;
    }
   printf("\n");
  
  }
 i++;
 }
}
void search(int key)
{
 int pos,flag=0;
 struct node*temp;
 pos=key%SIZE;
 if(head[pos]==NULL)
    printf("\nNot found");
 else
 {
  temp=head[pos];
  while(temp!=NULL)
  {
   if(temp->data==key)
    {
     printf("\nelement found at position %d",pos);
     flag=1;
     break;
    }
   temp=temp->link;
  }
 } 
if(flag==0)
  printf("\nNot found");
}
   
int main(void)
{
 int c,x,a,ch,key;
 printf("\nenetr size of hashtable: ");
 scanf("%d",&SIZE);
 while(1)
 {
  printf("\n\t\tMENU:\n\t1.Insert\n\t2.Display\n\t3.Search\n\t4.Exit\n\tEnter choice: ");
  scanf("%d",&c);
  if(c==4)
   break;
  else
  {
   switch(c)
   {
    case 1:printf("\nEnter element: ");
           scanf("%d",&x);
           insert(x);
           break;
    case 2:display();
           break;
    case 3:printf("\nEnter element to be searched for : ");
	   scanf("%d",&key);
           search(key);
	   break;
    default:printf("\nInvalid choice");
   }
  }
 }
}

           
 
  
  
