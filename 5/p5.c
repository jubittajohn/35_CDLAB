#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int n,tc=0,ntc=0,frc=0,flc=0;
char pr[13][10];
char ter[10];
char non[10];
char firsts[10];
int check(char *str,char c)
{
	char *ptr;
	int ind;
	ptr=strchr(str,c);
	if(ptr==NULL)
		ind=-1;
	else
		ind=(int)(ptr-str);
	return ind;
}
int first(int pos)
{
	int i,j,flag=0;
	for(i=0;i<n;i++)
	{
		if(pr[i][0]==non[pos])
		{
			if(pr[i][2]=='#')                        //check for epsilon in prouduction
				flag=1;
			if(!isupper(pr[i][2]) && (check(firsts,pr[i][2])==-1))
			{
				firsts[frc++]=pr[i][2];
			}
			else
			{
				if(first(check(non,pr[i][2]))==1)    //check for epsilon presence in the non terminal at index=2
				{
					if(islower(pr[i][3]) && (check(firsts,pr[i][3])==-1))		//if character at index=3 is terminal
						firsts[frc++]=pr[i][3];	
					else				//if character at index=3 is non terminal
						first(check(non,pr[i][3]));
				}
			}
		}
	}
	return flag;
}
void main()
{
	int i,j;
 	printf("Enter the number of productions:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",pr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(pr[i]);j++)
		{
			if(isupper(pr[i][j]) && check(non,pr[i][j])==-1)
				non[ntc++]=pr[i][j];
			if(!isupper(pr[i][j]) && check(ter,pr[i][j])==-1 && pr[i][j]!='=')
				ter[tc++]=pr[i][j];
		}
	}
	printf("terminals:");
	for(i=0;i<tc;i++)
		printf("%c,",ter[i]);
	printf("\nnon terminals:");
        for(i=0;i<ntc;i++)
                printf("%c,",non[i]);

	//first of all elements
	for(i=0;i<ntc;i++)
	{
		frc=0;
		for(j=0;j<10;j++)
			firsts[j]='\0';
		printf("\nFirst of %c is:",non[i]);
		first(i);
		for(j=0;j<frc;j++)
			printf("%c,",firsts[j]);

	}
	printf("\n");
//	follow();
}

