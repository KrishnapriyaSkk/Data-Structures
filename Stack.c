#include<stdio.h>
#define MAX 3
int Stack[MAX];
int top=-1;
void push(int x)
{
 if(top==MAX)
  printf("\nstack is full");
 else
  {
   top++;
   Stack[top]=x;
  }
}
int pop()
{
 int a;
 if(top==-1)
  printf("\nstack is empty");
 else
  {
   a=Stack[top];
   top--;
   return a;
  }
}
void display()
{
 if(top==-1)
  printf("\nstack is empty");
 else
 {
 for(int i=0;i<=top;++i)
  printf("\t%d",Stack[i]);
 }
}
 

int main(void)
{
 int c,x,a;
 while(1)
 {
  printf("\n\t\tMENU:\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit\n\tEnter choice: ");
  scanf("%d",&c);
  if(c==4)
   break;
  else
  {
   switch(c)
   {
    case 1:printf("\nEnter element: ");
           scanf("%d",&x);
           push(x);
           break;
    case 2:a=pop();
           printf("\nPopped %d",a);
           break;
    case 3:display();
           break;
    default:printf("\nInvalid choice");
   }
  }
 }
}

 
