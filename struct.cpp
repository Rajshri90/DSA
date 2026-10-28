#include<stdio.h>
#include<stdlib.h>
struct emp
{
	int eno;
	char ename[20];
	float sal;
};
struct emp * e1;
void accept()
{
	printf("enter employee number:");
	scanf("%d",&e1->eno);
	printf("enter employee name:");
	scanf("%s",&e1->ename);
	printf("enter employee salary:");
	scanf("%f",&e1->sal);
}
void disp()
{
   printf("\n employee numbre=%d",e1->eno);
   printf("\n employee name=%s",e1->ename);
   printf("\n employee salary=%f",e1->sal);	
}
int main()
{
	e1=(struct emp*)malloc(sizeof(struct emp));
	accept();
	disp();
}


