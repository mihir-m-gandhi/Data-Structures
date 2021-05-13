#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void reverse(char s[]);
void push(char s[],char c);
char pop(char s[]);
int prior(char c);
void intopost(char s[],char t[]);
void eval(char s[]);

char stk[100],stk2[100],in[100],post[100],pre[100],s1[100];
int top=-1;

void main()
{
  float value;
  clrscr();
  printf("Enter an infix expression : ");
  gets(in);
  reverse(in);
  strcpy(post," ");
  intopost(pre,post);
  strcpy(pre," ");
  reverse(post);
  printf("Prefix expression is : ");
  puts(pre);
  printf("Enter a Prefix expression for evaluation : ");
  gets(s1);
  top=-1;
  eval(s1);
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

void reverse(char s[])
{
  int length,i=0,j=0;
  length=strlen(s);
  j=length-1;
  while(j>=0)
  {
    if(s[j]=='(')
    {
      pre[i]=')';
    }
    else if(s[j]==')')
    {
      pre[i]='(';
    }
    else
    {
      pre[i]=s[j];
    }
    i=i+1;
    j=j-1;
  }
  pre[i]='\0';
}

void push(char s[],char c)
{
  if(top==99)
  {
    printf("Overflow");
  }
  else
  {
    top=top+1;
    s[top]=c;
  }
}

char pop(char s[])
{
  char c=' ';
  if(top==-1)
  {
    printf("Underflow");
  }
  else
  {
    c=s[top];
    top=top-1;
  }
  return c;
}

int prior(char c)
{
  if(c=='/'||c=='*'||c=='%')
  {
    return 1;
  }
  else if(c=='+'||c=='-')
  {
    return 0;
  }
}

void intopost(char s[],char t[])
{
  int i=0,j=0;
  char c;
  strcpy(t," ");
  while(s[i]!='\0')
  {
    if(s[i]=='(')
    {
      push(stk,s[i]);
      i=i+1;
    }
    else if(s[i]==')')
    {
      while((top!=-1)&&(stk[top]!='('))
      {
	t[j]=pop(stk);
	j=j+1;
      }
      if(top==-1)
      {
	printf("Incorrect Expression");
	exit(1);
      }
      c=pop(stk);
      i=i+1;
    }
    else if(isdigit(s[i])||isalpha(s[i]))
    {
      t[j]=s[i];
      i=i+1;
      j=j+1;
    }
    else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')
    {
      while((top!=-1)&&(stk[top]!='(')&&(prior(stk[top]>prior(s[i]))))
      {
	t[j]=pop(stk);
	j=j+1;
      }
      push(stk,s[i]);
      i=i+1;
    }
    else
    {
      printf("Incorrect element entered");
      exit(1);
    }
  }
  while((top!=-1)&&(stk[top]!='('))
  {
    t[j]=pop(stk);
    j=j+1;
  }
  t[j]='\0';
}


void eval(char s[])
{
  int i,temp,val,l,k,ch1,ch2;
  char c,x;
  l=strlen(s);
  printf("length=%d\n",l);
  for(i=l-1;i>=0;i--)
  {
    if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')
    {
      ch1=pop(stk2)-'0';
      ch2=pop(stk2)-'0';
      c=s[i];
      switch(c)
      {
	case '+':
	{
	  val=ch2+ch1;
	  break;
	}
	case '-':
	{
	  val=ch2-ch1;
	  break;
	}
	case '*' :
	{
	  val=ch2*ch1;
	  break;
	}
	case '/':
	{
	  val=ch2/ch1;
	  break;
	}
	case '%':
	{
	  val=ch2%ch1;
	  break;
	}
      }
      push(stk2,val+'0');
    }
    else
    {
      x=s[i];
      push(stk2,x);
    }
  }
  temp=pop(stk2)-'0';
  printf("\nValue of the given prefix expression is : %d",temp);
}