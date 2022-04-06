//¼Ó¼õ³Ë³ý
#include<stdio.h>
#include<string.h>
int main(){
	char str[]="4+9-4*2/2+4";
	char str2[]="";
	unsigned int a;
	int w;
    int r=str2[0]-'0';
	for(a=1;a<strlen(str);a++)
	{
	 str[a]=str2[a];
     if(str[a]=='/')
	 {
         str2[a-1]=str[a-1]/str[a+1];
	     a++;
	 }
	else if(str[a]=='*')
	{
	     str2[a-1]=str[a-1]*str[a+1];
      	 a++;
	}
	}
	 for(a=1;a<strlen(str2);a++)
	 {
	 	if(str2[a]=='+')
	{
        w=str2[a+1]-'0';
	    r=r+w;
	    a++;
	}
	else if(str2[a]=='-')
	{
	    w=str2[a+1]-'0';
	    r=r-w; 
	    a++;
	}
	 }
	printf("%d\n",r);
return 0;
}