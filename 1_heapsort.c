#include<stdio.h>
#define MAX 50
int last=0;
void heapify(int a[],int i,int n)
{
  int large,lc,rc,temp;
  large=i;
  lc=2*i+1;
  rc=2*i+2;
  if(a[lc]>a[large]&&lc<n)
     large=lc;
  if(a[rc]>a[large]&&rc<n)
     large=rc;
  if(i!=large)
   {
     temp=a[i];
     a[i]=a[large];
     a[large]=temp;
     heapify(a,large,n);
   }
}
void heapsort(int a[],int n)
{
  int i,temp;
 for(i=n/2-1;i>=0;i--)
   heapify(a,i,n);
 for(i=n-1;i>=0;i--)
     {
       temp=a[0];
       a[0]=a[i];
       a[i]=temp;
       heapify(a,0,i);
     }
}
/*void heap_insert(int a[],int item)
{
  a[last]=item;
  int i=last;
  while(i!=1)
    {
      if(a[i]>a[i/2])
	{
	  int temp;
	  temp=a[i];
	  a[i]=a[i/2];
	  a[i/2]=temp;
	  i=i/2;
	}
    }
  last++;
  }*/

int main(void)
{
  int n,a[MAX];
 printf("\nenetr no.of elements in the array: ");
 scanf("%d",&n);
 printf("\nEnter array elements: ");
 for(int i=0;i<n;++i)
   {
    scanf("%d",&a[i]);
    // heap_insert(a,a[i]);
   }
 heapsort(a,n);
 printf("\nSorted array elements: ");
 for(int i=0;i<n;++i)
    printf("%d\t",a[i]);

}
