#include<stdio.h>
void insertionsort(int Arr[],int n)
{
 int temp,j;
 for(int i=1;i<n;++i)
 {  
  j=i;
  while(j>0&&Arr[j-1]>Arr[j])
  {
   temp=Arr[j];
   Arr[j]=Arr[j-1];
   Arr[j-1]=temp;
   j--;
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
 insertionsort(Arr,n);
 printf("\nSorted array is: ");
  for(int i=0;i<n;++i)
 {
  printf("\n%d",Arr[i]);
 }
}
 
