#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*link;
};
struct node*front=NULL;
struct node*rear=NULL;
void Enqueue(int x)
{
 struct node*newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=x;
 if(front==NULL)
 {
  front=newnode;
  rear=newnode;
  newnode->link=NULL;
 }
 else
 {
  rear->link=newnode;
  rear=newnode;
 
 }
}
int Dequeue()
{
 int a;
 struct node*temp;
 if(front==NULL)
 {
   return -1;
 }
 else
 {
  a=front->data;
  temp=front;
  if(front==rear)
  {
  front=NULL;
  rear=NULL;
  }
  else
  {
   front=front->link;
  }
  free(temp);
  return a;
 }
}
void display()
{
 if(front==NULL)
 {
  printf("\nEmpty queue");
 }
 else
 {
  struct node*temp;
  temp=front;
  while(temp!=NULL)
  {
   if(temp->link==NULL)
       printf("%d-->NULL",temp->data);
   else
       printf("%d-->",temp->data);
   temp=temp->link;
  }
 }
}
int main(void)
{
 int c,a,x;
 while(1)
{
 printf("\n\t\tMENU\n\t\t1.Enqueue\n\t\t2.Dequeue\n\t\t3.Display\n\t\t4.Exit\n\tEnter choice: ");
 scanf("%d",&c);
 if(c==4)
  break;
 else
  {
   switch(c)
   {
    case 1:printf("\nEnter data: ");
           scanf("%d",&x);
           Enqueue(x);
           break;
    case 2:a=Dequeue();
           if(a==-1)
             printf("\nQueue empty");
           else
             printf("\nDeleted %d",a);
           break;
    case 3:display();
           break;
    default:printf("\nInvalid choice");
            break;
   }
  }
 }
}
