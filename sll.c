#include<stdio.h>
 #include<stdlib.h>
 void insert_front();
  void insert_end();
  void del_front();
    void del_end();
    void display();



 int main()
 {
    int ch;
    for(;;)
    {
        printf("\n 1.Insert front \n 2.Insert end \n 3.Delete front \n 4.Delete End \n 5.Display \n 6.Exit \n");
        printf("\n Enter your choice -->");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_front();
            break;

            case 2:insert_end();
            break;

            case 3:del_front();
            break;

            case 4:del_end();
            break;

            case 5:display();
            break;
            
            case 6:exit(0);
            break;

            default:printf("\n Invalid");
            break;
        }
    }
    return 0;
 }

struct node
{
    char name[20],usn[20];
    int sem;
    struct node *link;
};

struct node * first =NULL;
struct node *temp,*cur;

struct node * getnode()
{
    temp=(struct node *)malloc(sizeof(struct node ));
    printf("\n Enter the name \n");
    scanf("%s",temp->name);
    printf("\n Enter the usn \n");
    scanf("%s",temp->usn);
    printf("\n Enter the sem \n");
    scanf("%d",&temp->sem);

    temp->link=NULL;
    return temp;

}

 void insert_front()
 {
    temp=getnode();
    if(first==NULL)
    {
        first=temp;
        return;
    }
    temp->link=first;
        first=temp;

 }

 void insert_end()
 {
    temp=getnode();
    if(first==NULL)
    {
        first=temp;
        return;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=NULL;

 }

 void del_front()
 {
    if(first==NULL)
    {
        printf("Underflow \n");
        return;
    }
    temp=first;
    printf("Deleted %s\t%s\t%d",temp->name,temp->usn,temp->sem);
    first=first->link;
    free(temp);
 }

 void del_end()
 {
    if(first==NULL)
    {
        printf("Underflow \n");
        return;
    }
    temp=first;
    cur=NULL;
    while(temp->link!=NULL)
    {
        cur=temp;
        temp=temp->link;
    }
    printf("Deleted %s\t%s\t%d",temp->name,temp->usn,temp->sem);
  cur=cur->link;
  free(temp);
    
 }

 void display()
 {
    if(first==NULL)
    {
        printf("Underflow \n");
        return;
    }
    cur=first;
    printf("\n STUDENT DETAILS \n");
    printf(" -------------------------\n");
    while(cur!=NULL)
    {
        printf("%s\t%s\t%d\n",cur->name,cur->usn,cur->sem);
        cur=cur->link;
    }
 }
