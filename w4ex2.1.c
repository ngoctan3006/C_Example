#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int top=0;
int empty()
{
  return top==0;
}
int full()
{
  return top==MAX;
}
void push(char a,char stack[MAX])
{
  if(full())
    printf("FULL\n");
  else
    {
      stack[top++]=a;
    }
}
char pop(char stack[MAX])
{
  if(empty())
    printf("empty\n");
  else
    return stack[--top];
}
int pri(char c)
{
  if(c=='+')
    return 1;
  if(c=='*')
    return 2;
  else return 0;
}
int main(int argc,char *argv[])
{
  char stack[MAX];
  char *s=argv[1];
  char post[MAX];
  int p=0;
  int i,n=strlen(s);
  for(i=0;i<n;i++)
    {
      
      if(s[i]=='(')
	push(s[i],stack);
      if(s[i]>='0'&&s[i]<='9')
	post[p++]=s[i];
      if((s[i]=='+')||(s[i]=='*'))
	{
	  while(top!=0 && pri(s[i])<=pri(stack[top-1]))
	    {
	      post[p++]=pop(stack);
	    }
	  push(s[i],stack);
	}
      if(s[i]==')')
	{
	  char x=pop(stack);
	  while(x!='(')
	    {
	      post[p++]=x;
	      x=pop(stack);
	    }
	}
    }
  while(!empty(stack))
    post[p++]=pop(stack);
  int num[10],tn=0;
  for(i=0;i<p;i++)
     {
      if(post[i]>='0'&&post[i]<='9')
	num[tn++]=post[i]-'0';
      if(post[i]=='+')
	{
	  int x=num[--tn];
	  int y=num[--tn];
	  x+=y;
	  num[tn++]=x;
	}
      if(post[i]=='*')
	{
	  int x=num[--tn];
	  int y=num[--tn];
	  x*=y;
	  num[tn++]=x;
	}
    }
  printf("%d\n",num[--tn]);
  return 0;
}
