#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
	int top=-1,flag=1,inptr=0,i,j,ii,jj;
	char stack[25],input[10],stackel,curip,symbol[4],intype;

	char symtab[6][7][4]={
				{"-"	,"i"	,"+"	,"*"	,"("	,")"	,"$"},
				{"E"	,"TX"	,"-"	,"-"	,"TX"	,"-"	,"-"},
				{"X"	,"-"	,"+TX"	,"-"	,"-"	,"\0"	,"\0"},
				{"T"	,"FY"	,"-"	,"-"	,"FY"	,"-"	,"-"},
				{"Y"	,"-"	,"\0"	,"*FY"	,"-"	,"\0"	,"\0"},
				{"F"	,"i"	,"-"	,"-"	,"(E)"	,"-"	,"-"}
				};
	printf("The table\n*****\n\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
		printf("%s\t",symtab[i][j]);
		}
		printf("\n\n");
	}
	printf("Enter the input:");
	scanf("%s",input);
	stack[++top]='$';
	stack[++top]='E';
	while(top!=-1)
	{
//		printf("haii");
		for(i=0;i<=top;i++)
                {
                        printf("%c ,",stack[i]);
                }
                printf("\n");

		stackel=stack[top--];
		if(input[inptr]=='\0')
		{
			flag=0;
			break;
		}
		curip=input[inptr];
		if(!isupper(stackel))
		{
			if(islower(curip))
				curip='i';
			if(stackel==curip)
				inptr++;
			else
			{
				flag=0;
				break;
			}
		}
		else
		{
			for(i=0;i<6;i++)
			{
				if(symtab[i][0][0]==stackel)
					ii=i;
			}
			if(islower(curip))
				intype='i';
			else
				intype=curip;
			for(i=0;i<7;i++)
			{
				if(symtab[0][i][0]==intype)
					jj=i;
			}
			if(symtab[ii][jj][0]=='-')
			{
				flag=0;
				break;
			}
			else if(symtab[ii][jj][0]=='\0')
				4;
			else
			{
				strcpy(symbol,symtab[ii][jj]);
				for(i=strlen(symbol)-1;i>=0;i--)
					stack[++top]=symbol[i];
			}
		}
	}
	if(input[inptr]!='\0')
		flag=0;
	if(flag==0)
		printf("Input not accepted!!\n");
	else
		printf("Input accepted!!\n");
}//
