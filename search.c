#include<stdio.h>


int linear(int Arr[],int n,int key)
{
 int i;
 for(i=0;i<n;++i)
 {
  if(Arr[i]==key)
    {
    return i;
    }
  }
  return -1;

}
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
}
int binary(int Arr[],int n,int key)
{

 sort(Arr,n);
 printf("\nSorted array is: ");
 for(int i=0;i<n;++i)
  printf("\n%d",Arr[i]);
 int mid,l,u;
 l=0;
 u=n-1;
 while(l<=u)
 {
  mid=(l+u)/2;
  if(Arr[mid]==key)
   return mid;
  else if(Arr[mid]>key)
   u=mid-1;
  else
   l=mid+1;
 }
 return -1;
}
    

int main(void)
{
 int Arr[20],n,key,x,res,c;
 while(1)
{
 printf("\nMENU:\n\t1.Linear search.\n\t2.Binary search\n\t3.Exit\nEnter your chhoice: ");
 scanf("%d",&x);
 if(x==3)
  break;
 else
 {
  printf("\nenter no.of elements in the array: ");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
   {
   printf("\nEnter element: ");
   scanf("%d",&Arr[i]);
   }
  printf("\nEnter element to be searched: ");
  scanf("%d",&key);
  switch(x)
  {
  case 1:c=linear(Arr,n,key);
         if(c==-1)
          printf("\nElement not found");
         else
          printf("\nElement found at position %d",c+1);
         break;
  case 2:c=binary(Arr,n,key);
         if(c==-1)
          printf("\nElement not found");
         else
          printf("\nElement found at position %d",c+1); 
         break;
  default:printf("\nInvalid Choice");
  }
 }
}
}
