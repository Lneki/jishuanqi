//¼Ó¼õ
#include<stdio.h>
#include<string.h>
int main(){
char str[]="1+5-9+8-7";
int r=str[0]-'0';
int w;
unsigned int a;
for(a=1;a<strlen(str);a++)
{
	if(str[a]=='+')
	{
    w=str[a+1]-'0';
	r=r+w;
	a++;
	}
	else if(str[a]=='-')
	{
	w=str[a+1]-'0';
	r=r-w; 
	a++;
	}
}
printf("%d\n",r); 
return 0;
}