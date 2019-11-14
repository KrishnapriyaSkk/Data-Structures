#include<stdio.h>
#define MAX 100
int quicksort(int a[],int lb,int ub)
{
  int pivot,right,left,temp;
  if(lb<ub)
    {
  pivot=lb;
  left=lb;
  right=ub;
  while(left<right)
  {
    while((a[left]<=a[pivot])&&(left<ub))
    	++left;
    while(a[right]>a[pivot])
	--right;
    if(left<right){
      
      temp=a[left];
      a[left]=a[right];
      a[right]=temp;
    }
   
  }
      temp=a[pivot];
      a[pivot]=a[right];
      a[right]=temp;
      quicksort(a,lb,right-1);
      quicksort(a,right+1,ub);
    }
}
int main(void)
{
 int n;
  int a[MAX];
 printf("\nenter no.of elements in the array: ");
 scanf("%d",&n);
 printf("\nEnter array elements: ");
 for(int i=0;i<n;++i)
    scanf("%d",&a[i]);
 quicksort(a,0,n-1);
 printf("\nSorted array elements: ");
 for(int i=0;i<n;++i)
    printf("%d\t",a[i]);

}
  
