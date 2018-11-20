#include<stdio.h>
#include<string.h>
int A();
int B();
char ip[10];
int j=0;
int  S()
{
	if(ip[j]=='c')
	{
		j++;
		if(ip[j]=='d')
		{
			j++;
			if(j==strlen(ip))
			{
				 printf("|S->cd\n");
                        	printf("Input accepted\n");
				return 1;
			}
                	else
                        {
				printf("Input not accepted\n");
				return 0;
			}
		}	
		else
		{
		 j--;
		}
	}
	if(A())
	{
		if(B())
		{
			if(j==strlen(ip))
			{
				printf("|S->AB\n");
				 printf("Input accepted\n");
				return 1;
			}
                       	else
			{
                               printf("Input not accepted\n");
				return 0;
			}
		}
		else
			j--;
	}
	if(B())
        {
                if(j==strlen(ip))
                {
                        printf("|S->B\n");
                      printf("Input accepted\n");
                        return 1;
                }
                else
                {
                     printf("Input not accepted\n");
                        return 0;
                }
        }
	 else
        {
                printf("Input not accepted\n");
		return 0;
        }	
}
int A()
{
	if(ip[j]=='a'&&((j+1)!=strlen(ip)))
	{
		printf("|A->a\n");
		j++;
		return 1;
	}
	if(ip[j]=='b' && (j+1)!=strlen(ip))
	{
		printf("|A->b\n");
		j++;
		return 1;
	}
	return 0;
}
int B()
{
	if(ip[j]=='b')
	{
		printf("|B->b\n");
		j++;
		return 1;
	}
	if(ip[j]=='c')
	{	
		j++;
		if(A())
		{
			if(ip[j]=='d')
			{
				j++;
				printf("|B->cAd\n");
				return 1;
			}
			else
				j--;
		}
		else
			j--;
	}
	return 0;
}
void main()
{
	printf("Enter the input:");
	scanf("%s",ip);
	S();
}
