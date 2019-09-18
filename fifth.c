#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{        // Palindrome check method-2
  int data;
  struct node *next;
};
struct node * create()
{
  struct node *temp,*start=NULL,*q,*p,*r,*t;
while(1)
{
char str1[10];
printf("\n Enter yes or no\n");
scanf("%s",str1);
if(strcmp(str1,"no")==0)
break;
else
{
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter a value ");
scanf("%d",&temp->data);
  temp->next=NULL;
  if(start==NULL)
  {
    start=temp;
    p=temp;
    q=temp;
  }
  else
  {
    p->next=temp;
    p=temp;
  }
}
}
return q;
}
struct node *check(struct node *p)
{
  int c=0,flag=0;
  struct node *start=p,*current,*prev=NULL,*next=NULL;
  while(p!=NULL)
  {
    p=p->next;
    c++;
  }
  p=start;
  if(c%2==0)
  {
    for(int i=1;i<c/2;i++)
    {
      p=p->next;
    }
    current=p->next;
    p->next=NULL;
    p=start;
    while(current!=NULL)
    {
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
    }
    while(p!=NULL&&prev!=NULL)
    {
      if(p->data==prev->data)
      {
        flag=1;
        p=p->next;
        prev=prev->next;
      }
      else
      {
      break;
      flag=0;
    }
    }
    if(flag==1)
    printf("It is palindrome\n");
    else
      printf("It is not palindrome\n");
  }
  else
  {
    prev=NULL,next=NULL;
      p=start;
    for(int i=1;i<=c/2;i++)
    {
      p=p->next;
    }
    current=p->next;
    p->next=NULL;
    p=start;

    while(current!=NULL)
    {
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
    }
    while(p->next!=NULL&&prev!=NULL)
    {
      if(p->data==prev->data)
      {
        flag=1;

        p=p->next;
        prev=prev->next;
      }
      else
      break;
    }
    if(flag==1)
    printf("It is palindrome\n");
    else
      printf("It is not palindrome\n");
  }
}
int main()
{
  struct node *p;
  p=create();
check(p);
}
