#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isOperator(char c)
{
       if(c=='+'||c=='-'||c=='*'||c=='/')
	   return 1;
	   else return 0;
}
void moveczf(char *p)
{
	while(*p!='\0')
	{
		*p=*(p+1);
		p++;
	}
}
void moveczs(float *p,float *end)
{
    while(p!=end)
	{
		*p=*(p+1);
		p++;
	}
}
int main()
{
	char str[100];
	char czf[100]={'\0'};
	float czs[100];
	printf("请输入算式:\n");
	scanf("%s",str);
	int czfxb=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(isOperator(str[i]))
		{
			czf[czfxb]=str[i];
			czfxb++;
		}
	}
	int czsxb=0;
	for(int i=0;i<strlen(str);i++)
	{
		char temp[100]={'\0'};
		int tempxb=0;
		while(!isOperator(str[i]))
		{
			temp[tempxb]=str[i];
			i++;
			tempxb++;
		}
		float ansl=atof(temp);
		czs[czsxb++]=ansl;
	}
	char *fh=czf;
	float *sz=czs;
	float ans;
	while(*fh!=='\0')
	{
		if(*fh=='*')
		{
			float zczs=*sz;
			float yczs=*(sz+1);
			ans=zczs*yczs;
			*sz=ans;
			moveczf(fh);
			moveczs(sz+1,&czs[czsxb--]);
		}
		if(*fh=='/')
		{
			float zczs=*sz;
			float yczs=*(sz+1);
			ans=zczs/yczs;
			*sz=ans;
			moveczf(fh);
			moveczs(sz+1,&czs[czsxb--]);
		}
		else
		{
			fh++;
			sz++;
		}
	}
	fh=czf;
	sz=czs;
	while(*fh!='\0')
	{
		if(*fh=='+')
		{
			float zczs=*sz;
			float yczs=*(sz+1);
			float ans=zczs+yczs;
			*sz=ans;
			moveczf(fh);
			moveczs(sz+1,&czs[czsxb]);
			czsxb--;
		}
		else if(*fh=='-')
		{
			float zczs=*sz;
			float yczs=*(sz+1);
			float ans=zczs-yczs;
			*sz=ans;
			moveczf(fh);
			moveczs(sz+1,&czs[czsxb--]);
		}
	}
    printf("%0.2f\n",czs[0]);
	return 0;
}
