#include<stdio.h>
#define MAX 5
int front=-1;
int rear=-1;
int Queue[MAX];
void Enqueue(int x)
{
 if(front==(rear+1)%MAX)
  printf("\nQueue is full");
 else
 {
   if(front==-1)
    {
     front=0;
     rear=0;
    }
   else
     rear=(rear+1)%MAX;
    
   Queue[rear]=x;
 }
}
int Dequeue()
{
 int a;
 if(front==-1)
  return -1;
 else if(front==rear)
  {
    a=Queue[front];
    front=-1;
    rear=-1;
    return a;
  }
 else
  {
    a=Queue[front];
    front=(front+1)%MAX;
    return a;
   }
}
void display()
{
 if(front==-1)
  printf("\nQueue empty");
 else
 { if(rear>=front)
   {
    for(int i=front;i<=rear;++i)
      printf("%d\t",Queue[i]);
   }
   else
   { 
    for(int i=front;i<MAX;++i)
      printf("%d\t",Queue[i]);
    for(int i=0;i<=rear;++i)
      printf("%d\t",Queue[i]);
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
