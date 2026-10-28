#include<stdio.h>
#define MAX 5
struct stack
{
	int a[MAX];
	int top;
};
struct stack s1;
int main()
{ 
	s1.top=-1;
}
  int isempty()
  {
  	if(s1.top==-1)
  	return 1;
 else
    return 0;
  }
  int isfull()
  {
  	if(s1.top==MAX-1)
  	return 1;
 else
    return 0;
  }
  void push(int num)
  {
     if(isfull())
  {
  	printf("\n stack isfull");
  }
  else
  {
  	s1.top++;
  	s1.a[s1.top]= num;
  	printf("\n inserted succefull...!");
  }
}
void pop()
{
	int val;
	if(isempty())
	{
		printf("stack isempty...!");
	}
	else
	{
		val=s1.a[s1.top];
		s1.top--;
		printf("popped value=%d",val);
	}
}
void disp()
{
	int i;
	for(i=s1.top; i>=0; i--)
	{
		printf("\n %d",s1.a[i]);
	}
}
void main()
{
	int ch,num;
	do{
	printf("\n1.push:");
	printf("\n2.pop:");
	printf("\n3.display:");
	printf("\n4.exit:");
	printf("\n enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			printf("\n enter number to push:");
			scanf("%d",&num);
			push(num)
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			disp();
			break;
		}
		case 3:
		{
			exit(0);
		}
	} while(ch<4)
}


