//³Ë³ý
#include<stdio.h>
#include<string.h>
int main(){
char str2[]="2*3/6*8/4";
int c=str2[0]-'0';
int w;
unsigned int b;
for(b=1;b<strlen(str2);b++)
{
	if(str2[b]=='*')
	{
    w=str2[b+1]-'0';
	c=c*w;
	b++;
	}
	else if(str2[b]=='/')
	{
	w=str2[b+1]-'0';
	c=c/w; 
	b++;
	}
}
printf("%d\n",c); 
return 0;
}

