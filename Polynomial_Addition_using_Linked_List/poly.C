#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node		// Structure to store a term of a 3 variable polynomial
{
  int coeff;
  int powx;
  int powy;
  int powz;
  struct node *next;
}NODE;

NODE *create(NODE *start);					// Function to create a polynomial as a linked list
NODE *add(NODE *start1,NODE *start2,NODE *start3);		// Function to add 2 polynomials
NODE *addnode (NODE *start, int c, int x, int y, int z );		// Function to add a node to list
void display(NODE *start);					// Function to display a polynomial

void main()
{
  int c;
  NODE *start1=NULL;
  NODE *start2=NULL;
  NODE *start3=NULL;
  clrscr();
  do
  {
    printf("\n\n*** MAIN MENU *** \n1. Create polynomial 1 \n2. Create polynomial 2 \n3. Display polynomial 1 \n4. Display polynomial 2 \n5. Add the two polynomials \n6. Display sum \n7.Exit \nEnter your choice : ");			// Menu for user to select options from 
    scanf("%d",&c);
    switch(c)			// Switching flow according to choice of user		
    {
	case 1:
	{
	  start1=create(start1);
	  break;
	}
	case 2:
	{
	  start2=create(start2);
	  break;
	}
	case 3:
	{
	  printf("\nPolynomial 1 is ");
	  display(start1);
	  break;
	}
	case 4:
	{
	 printf("\nPolynomial 2 is ");
	 display(start2);
	 break;
	}
	case 5:
	{
	  printf("\nAdding the polynomials...");
	  start3=add(start1,start2,start3);
	  break;
	}
	case 6:
	{
	  printf("\nAddition of the 2 polynomials is  ");
	  display(start3);
	  break;
	}
   }
  }while(c!=7);
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

NODE *create(NODE *start)
{
  NODE *newnode,*ptr;
  int i,c,x,y,z,n;
   printf("\nCreating new polynomial...");
  printf("\nHow many terms in the polynomial? ");			// Asking the number of terms in polynomial
  scanf("%d",&n);
  for(i=0;i<n;i++)						// Each loop creates 1 node. So the number of nodes user enters are created using for loop
  {
    printf("Enter the coefficient, power of x, power of y, power of z : ");	// Accepting data
    scanf("%d %d %d %d",&c,&x,&y,&z);
    newnode=(NODE *)malloc(sizeof(NODE));			// Allocating memory to new node
    newnode->coeff=c;					/* Assigning
    newnode->powx=x;					   values
    newnode->powy=y;  					   to new
    newnode->powz=z;					   node */
    newnode->next=NULL;					// Setting address part of new node to NULL
    if(start==NULL)						// Checking if list is initially empty
    {
      start=newnode;
    }
    else							// If the list is not empty
    {
      ptr=start;
      while(ptr->next!=NULL)					// Checking if the current node is the last node of the list 
      {
	ptr=ptr->next;
      }
      ptr->next=newnode;
    }
  }
  printf("Polynomial Created!");
  return start;
}

NODE *add(NODE *start1,NODE *start2,NODE *start3)
{
  int sum,c,x,y,z;
  NODE *ptr1,*ptr2;
  ptr1=start1;			// Pointer pointing to start of first polynomial
  ptr2=start2;			// Pointer pointing to start of second polynomial
  while((ptr1!=NULL)&&(ptr2!=NULL))	// Checking if the last node of either of the list is reached 
  {
    if((ptr1->powx==ptr2->powx)&&(ptr1->powy==ptr2->powy)&&(ptr1->powz==ptr2->powz))	// Checking if power of all 3 variables of polynomial 1 and 2 is same i.e. the 2 terms are like
    {
      sum=ptr1->coeff+ptr2->coeff;	// Adding coefficients
      x=ptr1->powx;			// Assigning values of pointer 1 to variables (pointer 2 can also be used)
      y=ptr1->powy;
      z=ptr1->powz;
      start3=addnode(start3,sum,x,y,z);	// Adding a new node to list 3 with these values
      ptr1=ptr1->next;			// Moving to next node of polynomial 1
      ptr2=ptr2->next;			// Moving to next node of polynomial 2
    }
    else if(ptr1->powx>ptr2->powx)	// Checking if power of x in polynomial 1 is greater than that in polynomial 2
    {
      c=ptr1->coeff;			// Assigning values of pointer 1 to variables 
      x=ptr1->powx;
      y=ptr1->powy;
      z=ptr1->powz;
      start3=addnode(start3,c,x,y,z);	// Adding a new node to list 3 with these values
      ptr1=ptr1->next;			// Moving to next node of polynomial 1
    }
    else if(ptr1->powx<ptr2->powx)	// Checking if power of x in polynomial 1 is less than that in polynomial 2
    {
      c=ptr2->coeff;			// Assigning values of pointer 2 to variables 
      x=ptr2->powx;
      y=ptr2->powy;
      z=ptr2->powz;
      start3=addnode(start3,c,x,y,z);	// Adding a new node to list 3 with these values
      ptr2=ptr2->next;			// Moving to next node of polynomial 2
    }
    else if(ptr1->powx==ptr2->powx)	// Checking if power of x in polynomial 1 is equal  to that in polynomial 2
    {
      if(ptr1->powy>ptr2->powy)			// Checking if power of y in polynomial 1 is greater than that in polynomial 2
      {
	c=ptr1->coeff;			// Assigning values of pointer 1 to variables 
	x=ptr1->powx;
	y=ptr1->powy;
	z=ptr1->powz;
	start3=addnode(start3,c,x,y,z);		// Adding a new node to list 3 with these values
	ptr1=ptr1->next;
      }
      else if(ptr1->powy<ptr2->powy)		// Checking if power of y in polynomial 1 is less than that in polynomial 2
      {
	c=ptr2->coeff;			// Assigning values of pointer 2 to variables
	x=ptr2->powx;
	y=ptr2->powy;
	z=ptr2->powz;
	start3=addnode(start3,c,x,y,z);		// Adding a new node to list 3 with these values
	ptr2=ptr2->next;
      }
      else if(ptr1->powy==ptr2->powy)		// Checking if power of y in polynomial 1 is equal  to that in polynomial 2
      {
	if(ptr1->powz>ptr2->powz)		// Checking if power of z in polynomial 1 is greater than that in polynomial 2
	{
	  c=ptr1->coeff;			// Assigning values of pointer 1 to variables 
	  x=ptr1->powx;
	  y=ptr1->powy;
	  z=ptr1->powz;
	  start3=addnode(start3,c,x,y,z);		// Adding a new node to list 3 with these values
	  ptr1=ptr1->next;
	}
	else if(ptr1->powz<ptr2->powz)		// Checking if power of z in polynomial 1 is less than that in polynomial 2
	{
	  c=ptr2->coeff;			// Assigning values of pointer 2 to variables
	  x=ptr2->powx;
	  y=ptr2->powy;
	  z=ptr2->powz;
	  start3=addnode(start3,c,x,y,z);		// Adding a new node to list 3 with these values
	  ptr2=ptr2->next;
	}
      }
    }
  }
  if(ptr1==NULL)			// Checking if polynomial 1 is exhausted
  {
    while(ptr2!=NULL)			// Loop to be repeated until the last node of polynomial 2 is reached
    {
      c=ptr2->coeff;			// Assigning values of pointer 2 to variables 
      x=ptr2->powx;
      y=ptr2->powy;
      z=ptr2->powz;
      start3=addnode(start3,c,x,y,z);	// Adding a new node to list 3 with these values
      ptr2=ptr2->next;
    }
  }
  else if(ptr2==NULL)			// Checking if polynomial 2 is exhausted
  {
    while(ptr1!=NULL)			// Loop to be repeated until the last node of polynomial 1 is reached
    {
      c=ptr1->coeff;			// Assigning values of pointer 1 to variables 
      x=ptr1->powx;
      y=ptr1->powy;
      z=ptr1->powz;
      start3=addnode(start3,c,x,y,z);	// Adding a new node to list 3 with these values
      ptr1=ptr1->next;
    }
  }
  printf("\nThe 2 polynomials have been added.");
  return start3;
}

NODE *addnode(NODE *start, int c, int x, int y, int z)
{
  NODE *ptr, *newnode;
  if(start == NULL)						// Checking if list is initially empty
  {
    newnode = (NODE*)malloc(sizeof(NODE));			// Allocating memory to new node
    newnode->coeff=c;					/* Assigning
    newnode->powx=x;					   values	
    newnode->powy=y;					   to new
    newnode->powz=z;					   node */
    newnode -> next = NULL;					// Setting address part of new node to NULL
    start = newnode;
  }
  else							// If the list is not empty
  {
    ptr = start;
    while(ptr -> next != NULL)
    {
      ptr = ptr -> next;
    }
    newnode = (NODE*)malloc(sizeof(NODE));			// Allocating memory to new node
    newnode->coeff=c;					/* Assigning
    newnode->powx=x;					   values
    newnode->powy=y; 					   to new
    newnode->powz=z;					   node */
    newnode -> next = NULL;					// Setting address part of new node to NULL
    ptr -> next = newnode;
  }
  return start;
}


void display(NODE *start)
{
  NODE *ptr2;
  ptr2=start;
  while(ptr2!=NULL)			// Checking if the current node is the last node of the list 
  {
    printf("%d x%d y%d z%d + ",ptr2->coeff,ptr2->powx,ptr2->powy,ptr2->powz);
    ptr2=ptr2->next;
  }
  printf("END");			// Indicating end of the polynomial
}
