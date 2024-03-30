#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BS 10

typedef struct employee
{
    int emp_num;
    char name[10];
}EMP;
EMP HT[BS];
struct employee input;
FILE *outfile,*infile;

void display()
{
    int i;
    printf("\n ************* HASH TABLE **************** \n");
    printf("Bucket number \t EMP NUM \t NAME \n");
    for(i=0;i<BS;i++)
    {
        printf("\n%d\t\t%d\t\t%s",i,HT[i].emp_num,HT[i].name);
    }
}

void main()
{
    int i,j,key,c=0;
    outfile=fopen("employee.dat","w+");
    for(i=0;i<BS;i++)
    {
        HT[i].emp_num=-1;
        strcpy(HT[i].name," ");
    }
    printf("\n Enter 0 for emp num for input \n ");
    while(1)
    {
        printf("Enter emp num \n");
        scanf("%d",&input.emp_num);

        if(input.emp_num==0)
        break;

        printf("first name \n");
        scanf("%s",input.name);

        fwrite(&input,sizeof(struct employee),1,outfile);
    }
    fclose(outfile);

    infile=fopen("employee.dat","r");

    while(fread(&input,sizeof(struct employee),1,infile))
    {
        printf("EMP NUM=%8d  NAME=%10s \n",input.emp_num,input.name);

        c++;

        if(c>BS)
        {
            printf("***************HASH TABLE OVERFLOW **************");
            break;
        }
        key=input.emp_num;
            if(HT[key].emp_num==-1)
            {
                HT[key].emp_num=input.emp_num;
                strcpy(HT[key].name,input.name);
                display();
            }
            else
            {
                printf("\n *******COLLISION AT BUCKET %d for the emp number %d",key,input.emp_num);
                j=(key+1)%BS;
                while(j!=key)
                {
                    if(HT[j].emp_num==-1)
                    {
                        printf("\n *****USING LINEAR PROBING TO HANDLE COLLISION ********\n");
                        printf("Bucket %d is allocated to key %d",j,key);
                        HT[j].emp_num=input.emp_num;
                        strcpy(HT[j].name,input.name);
                        display();
                        break;
                    }
                    else
                    j=(j+1)%BS;
                }
            }


        }

    }
