#include<stdio.h>
#include<stdlib.h>
 struct node
{
 int coeff;
 int exp;
 struct node*link;
}p,q,r;
struct node *phead=NULL;
struct node *qhead=NULL;
struct node *rhead=NULL;
void MULT()
{
 struct node*pptr,*qptr,*rptr,*temp,*temp1,*temp2,*newnode,*t;
 pptr=phead;
 qptr=qhead;
 newnode=(struct node*)malloc(sizeof(struct node));
 rhead=newnode;
 rptr=rhead;
 while(pptr!=NULL)
 {
  qptr=qhead;
  while(qptr!=NULL)
  {
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->coeff=pptr->coeff*qptr->coeff;
   newnode->exp=pptr->exp+qptr->exp;
   newnode->link=NULL;
   rptr->link=newnode;
   rptr=newnode;
   qptr=qptr->link;
  }
 pptr=pptr->link;
 }
 t=rhead;
 rhead=rhead->link;
 free(t);
 temp=rhead;
 while(temp!=NULL)
 {
  temp1=temp->link;
  temp2=temp;
  while(temp1!=NULL)
  {
   if(temp->exp==temp1->exp)
    {
     temp->coeff=temp->coeff+temp1->coeff;
     temp2->link=temp1->link;
     free(temp1);
     temp1=temp2->link;
    }
   else
    {
    temp2=temp2->link;
    temp1=temp2->link;
    }
  }
  temp=temp->link;
 }
}
     
void traverse(struct node*head)
{
 struct node *ptr;
 if(head==NULL)
   printf("\nList is empty" );
 else
 {
 ptr=head;
 while(ptr!=NULL)
  {
    if(ptr->link==NULL)
       printf("%dx^%d",ptr->coeff,ptr->exp);
    else
       printf("%dx^%d+",ptr->coeff,ptr->exp);
    ptr=ptr->link;
  }
 }
 
} 

int main(void)
{
 int x,d1,d2,n,m;
 struct node*pptr,*qptr;
 printf("\nEnter the degree of 1st polynomial: ");
 scanf("%d",&d1);
 for(int i=d1;i>=0;i--)
{
 struct node*newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter coefficient of x^%d: ",i); 
 scanf("%d",&n);
 if(n==0)
  continue;
 else
{
 newnode->coeff=n;
 newnode->exp=i;
 newnode->link=NULL;
 if(phead==NULL){
  phead=newnode;
  pptr=phead;
 }
 else
 {
  pptr->link=newnode;
  pptr=newnode;
 }
}
}
printf("\nEnter the degree of 2nd polynomial: ");
scanf("%d",&d2);
for(int i=d2;i>=0;i--)
{
 struct node*newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter coefficient of x^%d: ",i); 
 scanf("%d",&m);
 if(n==0)
  continue;
 else
{
 newnode->coeff=m;
 newnode->exp=i;
 newnode->link=NULL;
 if(qhead==NULL){
  qhead=newnode;
  qptr=qhead;
 }
 else
  {
  qptr->link=newnode;
  qptr=newnode;
  }
}
}
MULT();
traverse(phead);
printf(" x ");
traverse(qhead);
printf(" = ");
traverse(rhead);
free(phead);
free(qhead);
free(rhead);
}

