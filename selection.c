#include<stdio.h>
void selectionsort(int Arr[],int n)
{
 int pos,temp;
 for(int i=0;i<n-1;++i)
  {
    pos=i;
    for(int j=i+1;j<n;++j)
     {
      
       if(Arr[pos]>Arr[j])
        pos=j;
     }
    if(pos!=i)  
     {
      temp=Arr[i];
      Arr[i]=Arr[pos];
      Arr[pos]=temp;
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
 selectionsort(Arr,n);
 printf("\nSorted array is: ");
  for(int i=0;i<n;++i)
 {
  printf("\n%d",Arr[i]);
 }
}
 
