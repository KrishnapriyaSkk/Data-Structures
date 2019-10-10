#include<stdio.h>
#define MAX 4
int Stack[MAX];
int top1=-1;
int top2=MAX;
void push1(int x)
{
 if(top1==top2-1)
  printf("\nstack is full");
 else
  {
   top1++;
   Stack[top1]=x;
  }
}
void push2(int x)
{
 if(top1==top2-1)
  printf("\nstack is full");
 else
  {
   top2--;
   Stack[top2]=x;
  }
}
int pop1()
{
 int a;
 if(top1==-1)
  return 0;
 else
  {
   a=Stack[top1];
   top1--;
   return a;
  }
}
int pop2()
{
 int a;
 if(top2==MAX)
  return 0;
 else
  {
   a=Stack[top2];
   top2++;
   return a;
  }
}
void display1()
{
 if(top1==-1)
  printf("\nstack is empty");
 else
 {
 for(int i=0;i<=top1;++i)
  printf("\t%d",Stack[i]);
 }
}
void display2()
{
 if(top2==MAX)
  printf("\nstack is empty");
 else
 {
 for(int i=MAX-1;i>=top2;--i)
  printf("\t%d",Stack[i]);
}
}

int main(void)
{
 int c,x,a;
 while(1)
 {
  printf("\n\t\tMENU:\n\t1.Stack1 Push\n\t2.Stack1 Pop\n\t3.Stack1 Display\n\t4.Stack2 Push\n\t5.Stack2 Pop\n\t6.Stack2 Display\n\t7.Exit\n\tEnter choice: ");
  scanf("%d",&c);
  if(c==7)
   break;
  else
  {
   switch(c)
   {
    case 1:printf("\nEnter element: ");
           scanf("%d",&x);
           push1(x);
           break;
    case 2:a=pop1();
           printf("\nPopped %d from stack1",a);
           break;
    case 3:display1();
           break;
    case 4:printf("\nEnter element: ");
           scanf("%d",&x);
           push2(x);
           break;
    case 5:a=pop2();
           printf("\nPopped %d from stack2",a);
           break;
    case 6:display2();
           break;
    default:printf("\nInvalid choice");
   }
  }
 }
}

 
