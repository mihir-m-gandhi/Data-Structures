#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct node
{
  char data;
  struct node *left;
  struct node *right;
};

struct node *stk[3];
int top=-1;

int prior(char c);
void push(struct node *c,struct node *s[]);
struct node* pop(struct node *s[]);
void inorder(struct node *t);
void postorder(struct node *t);
struct node* makeTree(char s[]);
int eval(struct node *a);

void main()
{
	char s[MAX];
	struct node *root;
	int value,value2;
	clrscr();
	printf("Enter the postfix expression: ");
	gets(s);
	printf("\nCreating Expression tree...");
	root=makeTree(s);          //forms tree of postfix expression
	printf("\nExpression Tree Created");
	printf("\n\nThe expression in infix form is : ");
	inorder(root);
	printf("\n\nThe expression in postfix form is : ");
	postorder(root);
	printf("\n\nCalculating value of the expression...");
	value=eval(root);         //evaluates the expression value
	printf("\nThe value of the entered expression is : ");
	printf("%d",value);
	printf("\n\nProgram by Mihir Gandhi B1 1611077");
	getch();
}

int prior(char c)       //to seperate operators from operands
{
	if(c=='/'||c=='*'||c=='%'||c=='-'||c=='+')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(struct node *c,struct node *s[])
{
	if(top==2)		//checking overflow
	{
		printf("Overflow");
	}
	else
	{
		top=top+1;
		s[top]=c;
	}
}

struct node* pop(struct node *s[])
{
	struct node *c;
	if(top==-1)		//checking underflow
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

void inorder(struct node *t)    //displays the tree in inorder form
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%c ", t->data);
		inorder(t->right);
	}
}

void postorder(struct node *t)
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("%c ",t->data);
  }
}


struct node* makeTree(char s[])		//creating a tree
{
	int i=0;struct node *p1,*p2;
	while(s[i]!='\0')		//till the end of input string is not reached
	{
		if(prior(s[i])==1)  //if operator is encountered
		{
			p2=(struct node*)malloc(sizeof(struct node));
			p2->data=s[i];
			p2->right=pop(stk);
			p2->left=pop(stk);
			push(p2,stk);
			i++;

		}
		else                 //if operand is encountered
		{
			p1=(struct node*)malloc(sizeof(struct node));
			p1->data=s[i];
			p1->left=NULL;
			p1->right=NULL;
			push(p1,stk);
			i++;
		}
	}
	return pop(stk);
}

int eval(struct node *a)
{
	struct node *ptr;
	int l,r,val;
	ptr=a;
	if(prior(ptr->data)==0)         //if operand
	{
		return ptr->data-48;	//as ASCII value of '0' is 48
	}
	else                            //if operator
	{
		l=eval(ptr->left);
		r=eval(ptr->right);
		if(ptr->data=='+')     //checking for which operation to perform
		{
		       return l+r;
		}
		else if(ptr->data=='-')
		{
			return l-r;
		}
		else if(ptr->data=='*')
		{
			return l*r;
		}
		else if(ptr->data=='/')
		{
			return l/r;
		}
		else if(ptr->data=='%')
		{
			return l%r;
		}
	}
}




