#include<stdio.h>
#include<string.h>
#include<ctype.h>
char input[20],table[20][4],alpha[20],op[20];
int i,j,alphap=-1,opp=-1,rownum=0,tcount=1;

int priority(char ch)
{
	if(ch=='=')
		return 0;
	if(ch=='(')
		return 1;
	if(ch=='+'||ch=='-')
		return 2;
	if(ch=='*'||ch=='/')
		return 3;
}
void numprint(char ch)
{
	if(ch>48&&ch<58)
		printf("t%c ",ch);
	else
		printf("%c ",ch);
}
void operator1()
{
	if(opp==-1)
		op[++opp]=input[i];
	else if(input[i]=='(')
		op[++opp]=input[i];
	else if(input[i]==')')
	{
		while(op[opp]!='(')
		{
			table[rownum][0]=op[opp--];
                	table[rownum][2]=alpha[alphap--];
                	table[rownum][1]=alpha[alphap--];

                	table[rownum][3]=(char)((tcount++)+48);
                	alpha[++alphap]=table[rownum][3];
                	rownum++;
		}
		op[opp--];
	}
	else if(priority(input[i])>priority(op[opp]))
		op[++opp]=input[i];
	else
	{
		table[rownum][0]=op[opp--];
		table[rownum][2]=alpha[alphap--];
		table[rownum][1]=alpha[alphap--];		
		table[rownum][3]=(char)((tcount++)+48);
		alpha[++alphap]=table[rownum][3];
		rownum++;
		operator1();
	}
}
void end()
{
	while(opp!=0)
	{ 
		table[rownum][0]=op[opp--];
         	table[rownum][2]=alpha[alphap--];
         	table[rownum][1]=alpha[alphap--];
        	table[rownum][3]=(char)((tcount++)+48);
                alpha[++alphap]=table[rownum][3];
                rownum++;
	}
	table[rownum][0]='=';
	table[rownum][1]=alpha[alphap--];
	table[rownum][2]='\0';
	table[rownum][3]=alpha[alphap--];
	rownum++;
}
void display()
{
	printf("The quadruple table representation form\n\n");
	printf("Operator\tOperand1\tOperand2\tResult\n\n");
	for(i=0;i<rownum;i++)
	{
		for(j=0;j<4;j++)
		{
			numprint(table[i][j]);
			printf("\t\t");
		}
		printf("\n");
	}
	printf("The intermediate code:\n\n");
	for(i=0;i<rownum-1;i++)
	{
		numprint(table[i][3]);
		printf(" = ");
		numprint(table[i][1]);
		numprint(table[i][0]);
		numprint(table[i][2]);
		printf("\n");
	}
	numprint(table[i][3]);
	numprint(table[i][0]);
	numprint(table[i][1]);

}
void main()
{
	printf("Enter the expression:");
	scanf("%s",input);
	for(i=0;i<strlen(input);i++)
	{
		if(isalpha(input[i]))
			alpha[++alphap]=input[i];
		else
			operator1();
	}
	end();
	display();
	printf("\n\n");
}
