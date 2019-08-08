#include<stdio.h>

void sort(int Arr[],int n)
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
 printf("\nSorted array is: ");
 for(int i=0;i<n;++i)
  printf("\n%d",Arr[i]);
}
int binary(int Arr[],int n,int key,int l,int u)
{
  int mid;
  if(l>u)
   return -1;
  mid=(l+u)/2;
  if(Arr[mid]==key)
   return mid;
  else if(Arr[mid]>key)
   return binary(Arr,n,key,0,mid-1);
  else
   return binary(Arr,n,key,mid+1,n-1); 
  
}
    
int main(void)
 {
  int Arr[50],key,c,n;
  printf("\nenter no.of elements in the array: ");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
   {
   printf("\nEnter element: ");
   scanf("%d",&Arr[i]);
   } 
  printf("\nEnter element to be searched: ");
  scanf("%d",&key);
  sort(Arr,n);
  c=binary(Arr,n,key,0,n-1);
  if(c==-1)
     printf("\nElement not found");
  else
     printf("\nElement found at position %d",c+1); 
}

