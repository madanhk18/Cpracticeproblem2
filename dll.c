#include<stdio.h>
#include<stdlib.h>
struct node
{
char ssn[20],name[20],dept[20],desig[20],phno[10];
long int sal;
struct node *next,*prev;
};
typedef struct node *NODE;
NODE head=NULL;
NODE getnode()
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
temp->next=NULL;
temp->prev=NULL;
puts("\n enter SSN, NAME, DEPT., DESIGNATION, PHONE NUMBER");
scanf("%s%s%s%s%s",temp->ssn,temp->name,temp->dept,temp->desig,temp->phno);
puts("enter salary");
scanf("%ld",&temp->sal);
return temp;
}
void Insert_beg()
{
NODE temp=getnode();
if(head!=NULL)
{
temp->next=head;
head->prev=temp;
}
head=temp;
}
void Insert_end()
{
NODE temp=getnode();
NODE tt;
if(head==NULL)
head=temp;
else
{
for(tt=head;tt->next!=NULL;tt=tt->next)
{ }
tt->next=temp;
temp->prev=tt;
}
}
void Create()
{
int n,i;
printf("enter the n\n");
scanf("%d",&n);
for(i=0;i<n;i++)
Insert_end();
}
void Delete_beg()
{
NODE temp=head;
if(head==NULL)
printf("List is empty\n");
else
{
head=head->next;
head->prev=NULL;
}
free(temp);
}
void Delete_end()
{
NODE tt,temp;
if(head==NULL)
printf("List is empty\n");
else if(head->next==NULL)
head=NULL;
else
{
for(tt=head;tt->next->next!=NULL;tt=tt->next)
{ }
tt->next=NULL;
}
free(temp);
}
void display()
{
NODE temp;
int count=0;
if(head==NULL)
{
printf("no node to display\n");
return;
}
printf("\n SSN\t NAME\t, DEPT\t, DESIG\t, SAL\t, PH.NO\t");
printf("\n--------------------------------------------\n");
for(temp=head;temp!=NULL;temp=temp->next)
{
count++;
printf("%s\t %s\t %s\t %s\t %ld\t %s\n", temp->ssn, temp->name, temp-> dept,temp->desig,
temp->sal, temp->phno);
}
printf("\n------------------------------------------\n");
printf("\n the total number of nodes in list is %d\n", count);
printf("\n---------------------------------------------\n");
}
void main()
{
int ch;
while(1)
{
printf("\n\n\n\t 1.create DLL...\t 2.Display DLL..\t 3.Insertion at front...\t 4.Insertion at end...\t 5.deletion at front...\t 6. Deletion at end....\t presss any key to exit\n");
printf("\n\n\n\tEnter Your Choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: Create();
display();
break;
case 2: display();
break;
case 3: Insert_beg();
display();
break;
case 4: Insert_end();
display();
break;
case 5: Delete_beg();
display();
break;
case 6:Delete_end();break;
default: exit(0);
}
}
}