#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*link;
};
struct node*top=NULL;
void push(int x)
{
 struct node*newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=x;
 if(top==NULL)
 {
  
  newnode->link=NULL;
 }
 else
 {
  newnode->link=top;
 
 }
  top=newnode;
}
int pop()
{
 int a;
 struct node*temp;
 if(top==NULL)
 {
   return -1;
 }
 else
 {
  a=top->data;
  temp=top;
  top=top->link;
  free(temp);
  return a;
 }
}
void display()
{
 if(top==NULL)
 {
  printf("\nEmpty stack");
 }
 else
 {
  struct node*temp;
  temp=top;
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
 printf("\n\t\tMENU\n\t\t1.Push\n\t\t2.Pop\n\t\t3.Display\n\t\t4.Exit\n\tEnter choice: ");
 scanf("%d",&c);
 if(c==4)
  break;
 else
  {
   switch(c)
   {
    case 1:printf("\nEnter data: ");
           scanf("%d",&x);
           push(x);
           break;
    case 2:a=pop();
           if(a==-1)
             printf("\nStack empty");
           else
             printf("\nPopped %d",a);
           break;
    case 3:display();
           break;
    default:printf("\nInvalid invalid");
            break;
   }
  }
 }
}
