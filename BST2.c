#include<stdio.h>
#include<stdlib.h>
struct tree
 {
 int data;
 struct tree*left,*right;
 } ;
struct tree*ptr,*root=NULL;
void Del_tree(int);


    
void Insert(int x)
{int flag=0;
 struct tree*newnode,*parent;
 newnode=(struct tree*)malloc(sizeof(struct tree));
 newnode->data=x;
 newnode->left=NULL;
 newnode->right=NULL;
 if(root==NULL)
 {
   root=newnode;
 }

 else
 { 
   ptr=root;
   int flag=0;
   while(ptr!=NULL&&flag==0)
   {
    if(x>ptr->data)
    {
     parent=ptr;
     ptr=ptr->right;
    }
    else if(x<ptr->data)
    {
      parent=ptr;
      ptr=ptr->left;
    }
    else
      flag=1;
  }
 
 if(flag==1)
   printf("\nAlready exists");
 else
 {
  if(x>parent->data)
     parent->right=newnode;
  else
     parent->left=newnode;
 } 
 }
}
void Del_tree(int x)
{
  
  int flag=0;
  struct tree*ptr=root,*parent=root;
  while (ptr!=NULL){
    if(x==ptr->data){
      flag=1;
      break;
    }
    else if(x<ptr->data){
      parent=ptr;
      ptr=ptr->left;
    }
    else{
      parent=ptr;
      ptr=ptr->right;
    }
  }
  if (flag==0)
    printf("Element not found\n");
  else{
    
    if (ptr->left==NULL&&ptr->right==NULL){
      if(ptr==root){
	root=NULL;
      }
      else{
	if (parent->left==NULL){
	  parent->right=NULL;
	}
	else if ((parent->left)->data==ptr->data){
	  parent->left=NULL;
	}
	else{
	  parent->right=NULL;
	}
      }
    }
    else if(ptr->left!=NULL&&ptr->right==NULL){
      if ((parent->left)->data==ptr->data){
	parent->left=ptr->left;
      }
      else{
	parent->right=ptr->left;
      }
    }
    else if(ptr->left==NULL&&ptr->right!=NULL){
      if ((parent->left)->data==ptr->data){
	parent->left=ptr->right;
      }
      else{
	parent->right=ptr->right;
      }
    }
    else{
      int i;
      struct tree*succ;
      succ=ptr->right;
      while(succ->left!=NULL){
	succ=succ->left;
      }
      i=succ->data;
      Del_tree(succ->data);
      ptr->data=i;
    }
  }
}
void preorder(struct tree*p)
{
     if(p!=NULL)
       {
         printf("\t%d",p->data);
         preorder(p->left);
         preorder(p->right);
       }
 }
void inorder(struct tree*p)
{
     if(p!=NULL)
       {
         inorder(p->left);
         printf("\t%d",p->data);
         inorder(p->right);
       }
 }
void postorder(struct tree*p)
{
     if(p!=NULL)
       {
         postorder(p->left);
         postorder(p->right);
         printf("\t%d",p->data);
       }
 }

void traversal(int ch)
{
  if(root==NULL)
     printf("\nTree empty");
  else
  {
    if(ch==1)
      preorder(root);
    else if(ch==2)
      inorder(root);
    else if(ch==3)
      postorder(root);
  }
}
void search(int key)
{
 ptr=root;
 int flag=0;
 while(ptr!=NULL&&flag==0)
 {
  if(key<ptr->data)
    ptr=ptr->left;
  else if(key>ptr->data)
    ptr=ptr->right;
  else
    flag=1;
 }
 if(flag==1)
  printf("\nFound");
 else
  printf("\nNot found");
}
int main(void)
{
 int c,x,a,ch,key;
 while(1)
 {
  printf("\n\t\tMENU:\n\t1.Insert\n\t2.Delete\n\t3.Traversal\n\t4.Search\n\t5.Exit\n\tEnter choice: ");
  scanf("%d",&c);
  if(c==5)
   break;
  else
  {
   switch(c)
   {
    case 1:printf("\nEnter element: ");
           scanf("%d",&x);
           Insert(x);
           break;
    case 2:printf("\nEnter element to be deleted: ");
           scanf("%d",&x);
           Del_tree(x);
           break;
    case 3:printf("\n\t\t1.Preorder\n\t\t2.Inorder\n\t\t3.Postorder\n\tEnter mode of traversal: ");
           scanf("%d",&ch);
           traversal(ch);
           break;
    case 4:printf("\nEnter element to be searched for : ");
	   scanf("%d",&key);
           search(key);
	   break;
    default:printf("\nInvalid choice");
   }
  }
 }
}

         
    
           

    

    
