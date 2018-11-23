#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int n;
struct expr
{
	char op[2],op1[5],op2[5],res[5];
	int flag;
}table[10];

void input()
{
	int i;
	printf("Enter the num of expressions:");
	scanf("%d",&n);
	printf("\nEnter the expressions in quadruple format\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",table[i].op);
		scanf("%s",table[i].op1);
		scanf("%s",table[i].op2);
		scanf("%s",table[i].res);
		table[i].flag=0;
	}
}
void display()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(table[i].op[0]=='=')
			printf("%s = %s\n",table[i].res,table[i].op1);
		else
			printf("%s = %s %s %s\n",table[i].res,table[i].op1,table[i].op,table[i].op2);
	}
}
void change(int pos,char *r)
{
	int i;
	strcpy(table[pos].op1,r);
	strcpy(table[pos].op,"=");
	strcpy(table[pos].op2,"-");
	for(i=pos+1;i<n;i++)
	{
		if(strcmp(table[pos].res,table[i].op1)==0)
			strcpy(table[i].op1,r);
		if(strcmp(table[pos].res,table[i].op2)==0)
                        strcpy(table[i].op2,r);
	}
}
void constant()
{
	int i;
	int op1,op2,res;
	char op,res1[5];
	for(i=0;i<n;i++)
	{
		if((isdigit(table[i].op1[0]) && isdigit(table[i].op2[0])) || strcmp(table[i].op,"=")==0)
		{
			op1=atoi(table[i].op1);
			op2=atoi(table[i].op2);
			op=table[i].op[0];
			switch(op)
			{
				case '+':
					res=op1+op2;break;
				case '-':
					res=op1-op2;break;
				case '*':
					res=op1*op2;break;
				case '/':
					res=op1/op2;break;
				case '=':
					res=op1;break;
			}
			sprintf(res1,"%d",res);
			table[i].flag=1;
			change(i,res1);
		}
	}
}
void main()
{
	int i;
	input();
	printf("\nThe input expressions are\n");
	display();
	constant();
	printf("\n The optimized code in quadruple format:\n");
	for(i=0;i<n;i++)
	{
	//	if(table[i].flag==0)
			printf("%s %s %s %s\n",table[i].op,table[i].op1,table[i].op2,table[i].res);
	}
	printf("\nThe optimized code\n");
	display();
	/*for(i=0;i<n;i++)
		if(table[i].flag==0)
			printf("%s = %s %s %s\n",table[i].res,table[i].op1,table[i].op,table[i].op2);*/

}
