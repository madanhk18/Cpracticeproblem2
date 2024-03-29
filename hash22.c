#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BS 10
typedef struct employee
{
int emp_num;
char name[20];
}EMP;
EMP HT[BS];
FILE *outfile,*infile;
struct employee input;
void disp()
{
int i;
printf("\n\n***********HASH TABLE *******\n\n");
printf("Bucket no\t EMP NUM \t  NAME\n");
for(i=0;i<BS;i++)
printf("%d\t\t %d\t\t %s\n",i,HT[i].emp_num, HT[i].name);
}
void main()
{
int i,key,j,c=0;
outfile=fopen("employee.dat","w+");
for(i=0;i<BS;i++)
{
HT[i].emp_num=-1;
strcpy(HT[i]. name," ");
}
printf("enter 0 for emp_num to end input…");
while(1)
{
printf("\n emp num:");
scanf("%d",&input.emp_num);
if(input.emp_num==0)
break;
printf("first name:");
scanf("%s",input.name);
fwrite(&input, sizeof(struct employee),1,outfile);
}
fclose(outfile);
infile=fopen("employee.dat","r");
while(fread(&input,sizeof(struct employee),1,infile))
{
printf("EMP NUM=%8d NAME=%10s\n",input.emp_num,input.name);
c++;
if(c>BS)
{
printf("\n\n***********HASH TABLE OVERFLOW*******\n\n");
break;
}
key=input.emp_num%BS;
if(HT[key].emp_num==-1)
{
HT[key].emp_num=input.emp_num;
strcpy(HT[key].name,input.name);
disp();
}
else
{
printf("\n *********COLLISION AT %d bucket for emp number=%d*****\n",key,input.emp_num);
j=(key+1)%BS;
while(j!=key)
{
if(HT[j].emp_num==-1)
{
printf("\n*************USING LINEAR PROBING TO HANDLE COLLISION****\n");
printf("\n bucket %d is allocated for key %d\n",j,key);
HT[j].emp_num=input.emp_num;
strcpy(HT[j].name,input.name);
disp();
break;
}
else
j=(j+1)%BS;
}
}
}
}