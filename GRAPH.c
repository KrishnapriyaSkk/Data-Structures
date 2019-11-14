#include<stdio.h>
#define MAX 100
int vis[MAX],MAT[MAX][MAX],A[MAX],Stack[MAX];
int n,top=-1;
int pop()
{
  int a;
  a=Stack[top];
  top++;
  return a;
}  
void DFS()
{
  int i,a,v;
  for(i=A[1];i<=A[n];++i)
    vis[i]=0;
  Stack[++top]=A[1];
  i=1;
  v=A[1];
  while(top!=-1)
    {
      a=pop();
      if(vis[v]==0)
	{ 
	printf("\t%d",a);
	vis[v]=1;
	for(int j=A[1];i=A[n];++j)
	{
	  if(MAT[v][j]==1)
	    Stack[++top]=A[j];
	}
	}
      i++;
      v=A[i];
    }
} 
  
int main(void)
{
  int n,i,j,ch;
  printf("\nEnter the no.of nodes: ");
  scanf("%d",&n);
  for(i=1;i<=n;++i)
    {
      printf("\nEnter the elements: ");
      scanf("%d",&A[i]);
    }
     
   printf("\nIf a node is related to another enter 1 otherwise enter 0");
  for(i=A[1];i<=A[n];++i)
    for(j=A[1];j<=A[n];++j)
      {
	printf("\nIs %d related to %d",A[i],A[j]);
	scanf("%d",&MAT[A[i]][A[j]]);
      }
  while(1)
    {
      printf("\n\t\t1.DFS\n\t\t2.BFS\n\t\t3.EXIT\n\tSelect the mode of traversal: ");
      scanf("%d",&ch);
      if(ch==3)
	break;
      else if(ch==1)
	DFS(n);
      //  else if(ch==2)
      //	BFS(n);
      else
	printf("\nInavalid choice");
    }
}
