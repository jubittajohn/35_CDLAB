%{
#include "y.tab.h"
%}

id [a-zA-Z]([a-zA-Z]|[0-9])*
num [0-9]+
op [\+\-\/\*]

%%

"switch"  {return SW;}
"case"    {return CS;}
"break"   {return BR;}
"default" {return DEF;}
"("       {return OB;}
")"       {return CB;}
{id}      {return ID;}
{id}\(\)      {return FUNC;}
{num}     {return NUM;}
{op}      {return OP;}
"\n"      {return NL;}
"{"       {return COB;}
"}"       {return CCB;}
"="       {return EQ;}
";"       {return SEM;}
":"       {return Q;}

%%

int yywrap()
{
	return 0;
}
