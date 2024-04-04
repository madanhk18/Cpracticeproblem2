#include<stdio.h>
#include<stdlib.h>

struct node{
   int sem;
    char name[10],usn[10],program[10];
    struct node * llink;
    struct node * rlink;

};

struct node *first=NULL;
struct node *temp,*cur,*prev;

struct node *getnode()
{
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter name \n");
    scanf("%s",temp->name);

      printf("Enter usn \n");
    scanf("%s",temp->usn);

      printf("Enter program \n");
    scanf("%s",temp->program);

      printf("Enter sem \n");
    scanf("%d",&temp->sem);

    temp->llink=NULL;
    temp->rlink=NULL;
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
    first->llink=temp;
    temp->rlink=first;
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
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
}

void del_front()
{
    if(first==NULL)
    {
        printf("Underflow \n");
        return;
    }
    printf("The deleted element is %d",first->sem);
    temp=first;
    first=first->rlink;
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
    while(temp->rlink!=NULL)
    {
        cur=temp;
    temp=temp->rlink;
    } 
    if(cur!=NULL)
    {
        cur->rlink=NULL;
    }
    printf("Deleted %s\t%s\t%s\t%d\n",cur->name,cur->usn,cur->program,cur->sem);
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
     printf("Student details are");
    while(cur!=NULL)
    {
    printf("\n %s\t%s\t%s\t%d\n",cur->name,cur->usn,cur->program,cur->sem);
    cur=cur->rlink;
    }

    }
    int main()
    {
        int ch;
        for(;;)
        {
            
            printf("\n 1.inser front \n 2.insert end \n 3.delete front \n4. delete end \n 5. exit \n 6.display\n");
            printf(" \n Enter choice -> ");
            scanf("%d",&ch);
            switch (ch)
            {
                case 1: insert_front();
                break;

                case 2: insert_end();
                break;
                case 3: del_front();
                break;
                case 4: del_end();
                break;
                case 5: exit(0);
                break;
                case 6:display();
                break;
                default:printf("INVALID");
                break;
            }
        }
        return 0;
           
    }