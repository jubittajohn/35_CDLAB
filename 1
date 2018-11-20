#include<stdio.h>
#include<ctype.h>
#include<string.h>
void check(char c[])
{
	int i,len,flag=0;
	char keywords[][20]={"int","double","float","char","long","byte","boolean","short","if","else","while","void",};
	len=12;
	for(i=0;i<len;i++)
	{
		if(strcmp(c,keywords[i])==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("keyword(%s)",c);
	else
		printf("<ID(%s)>",c);
}
void main()
{
	int state=0,i;
	char ch,buffer[15];
	FILE *fptr;
	fptr=fopen("input1.txt","r");
	while((ch=fgetc(fptr))!=EOF)
	{
		switch(state)
		{
			case 0:
				if(ch=='<')
					state=1;
				else if(ch=='>')
					state=2;
				else if(isalpha(ch))
				{
					i=0;
					state=3;
					buffer[i++]=ch;
				}
				else if(ch=='!')
					state=4;
				else if(ch=='=')
					printf("<EQ>");
				else if(ch==';')
					printf(";\n");
				else if(ch==' ')
					printf(" ");
				else if(ch=='(')
					printf("(");
				else if(ch==')'||ch=='{'||ch=='}')
					printf("%c\n",ch);
				else if(isdigit(ch))
				{
					i=0;
					buffer[i++]=ch;
					state=6;
				}
				break;
			case 1:
				if(ch=='=')
				{
					printf("<LE>");
					state=0;
				}
				else
				{
					printf("<LT>");
					fseek(fptr,-1,SEEK_CUR);
					state=0;
				}
				break;
			case 2:
				if(ch=='=')
                                {
                                        printf("<GE>");
                                        state=0;
                                }
                                else
                                {
                                        printf("GT");
					fseek(fptr,-1,SEEK_CUR);
                                        state=0;
                                }
                                break;
			case 3:
				if(isalnum(ch))
				{
					buffer[i++]=ch;
					state=3;
				}
				else
				{
					fseek(fptr,-1,SEEK_CUR);
					buffer[i]='\0';
					check(buffer);
					buffer[i]=' ';
					state=0;
				}
				break;
			case 4:
				if(ch=='=')
				{
					printf("<NE>");
					state=0;
				}
				break;
			case 6:
				if(isdigit(ch))
				{
					buffer[i++]=ch;
					state=6;
				}
				else
				{
					fseek(fptr,-1,SEEK_CUR);
					buffer[i]='\0';
					printf("<DIGIT(%s)>",buffer);
					buffer[i]=' ';
					state=0;
				}
				break;
			default:
				5;
				//printf("INVALID");
		}
	}
	fclose(fptr);
}
