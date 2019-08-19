#include<stdio.h>
void bubblesort(int Arr[],int n)
{
 int temp;
 for(int i=0;i<n;++i)
  for(int j=0;j<n-1-i;++j)
   {
     if(Arr[j]>Arr[j+1])
     {
      temp=Arr[j];
      Arr[j]=Arr[j+1];
      Arr[j+1]=temp;
     }
   }
}
int main(void)
{
 int Arr[50],n;
 printf("\nEnter the no.of elements: ");
 scanf("%d",&n);
 printf("\nEnter the elements: ");
 for(int i=0;i<n;++i)
 {
  scanf("%d",&Arr[i]);
 }
 bubblesort(Arr,n);
 printf("\nSorted array is: ");
  for(int i=0;i<n;++i)
 {
  printf("\n%d",Arr[i]);
 }
}
 
