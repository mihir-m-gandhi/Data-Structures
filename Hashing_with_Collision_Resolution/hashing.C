#include<stdio.h>
#include<conio.h>

#define M 10		//Maximum size of table

void linear(int in[M],int table[M],int key[M],int n);	//Function for linear probing
void quad(int in[M],int table[M],int key[M],int n);	//Function for quadratic probing
void searchlp(int table[M]);				//Function for searching using linear probing
void searchqp(int table[M]);				//Function for searching using quadratic probing
void display(int table[M]);				//Function for displaying the hash table

void main()
{
  int in[M],key[M],table[M]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},n,i,ch;
  clrscr();
  printf("Enter the no. of elements: ");
  scanf("%d",&n);
  if(n>M)
  {
    printf("No. of elements exceeded");
  }
  else
  {
    for(i=0;i<n;i++)	//Accepting elements from user
    {
      printf("Enter element %d: ",i+1);
      scanf("%d",&in[i]);
      key[i]=in[i];	//Assigning key
    }
    do			//MENU DRIVEN PROGRAM
    {
      printf("\n\nMain Menu");
      printf("\n1.Linear Probe \n2.Quadratic Probe \n3.Search using LP \n4.Search using QP \n5.Display \n6.Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1:
	{
	  linear(in,table,key,n);
	  break;
	}
	case 2:
	{
	  quad(in,table,key,n);
	  break;
	}
	case 3:
	{
	  searchlp(table);
	  break;
	}
	case 4:
	{
	  searchqp(table);
	  break;
	}
	case 5:
	{
	  display(table);
	  break;
	}
      }
    }while(ch!=6);
  }
  printf("\nProgram by Mihir Gandhi B1 1611077")
  getch();
}

void linear(int in[M],int table[M],int key[M],int n)
{
    int i,j,h;
    for(i=0;i<n;i++)
    {
      h=key[i]%M;		//Determining index using hash function
      if(table[h]==-1)		//If the position at given index is free i.e. no collision
      {
	table[h]=in[i];		//Entering the element in table
      }
      else			//If there is a collision
      {
	for(j=1;j<M;j++)
	{
	  h=(h+j)%M;		//New index using linear probing technique
	  if(table[h]==-1)	//Checking for collision again
	  {
	    break;
	  }
	}
	table[h]=in[i];		//Entering the element in table
      }
      display(table);
    }
}

void quad(int in[M],int table[M],int key[M],int n)
{
  int i,j,h;
  for(i=0;i<n;i++)
    {
      h=key[i]%M;		//Determining index using hash function
      if(table[h]==-1)		//If the position at given index is free i.e. no collision
      {
	table[h]=in[i];		//Entering the element in table
      }
      else
      {
	for(j=1;j<M;j++)
	{
	  h=(h+j+j*j)%M;	//New index using quadratic probing technique
	  if(table[h]==-1)	//Checking for collision again
	  {
	    break;
	  }
	}
	table[h]=in[i];		//Entering the element in table
      }
      display(table);
    }
}
void searchlp(int table[M])
{
  int s,hs,j;
  printf("\nEnter the element that you want to search: ");
  scanf("%d",&s);
  hs=s%M;		//Determining index using hash function
  if(table[hs]==s)	//Checking if the value at that index is same as the searched
  {
    printf("\n%d is present at index %d",s,hs);
  }
  else
  {
    for(j=1;j<M;j++)
    {
      hs=(hs+j)%M;		//Next index using linear probing technique
      if(table[hs]==s)		//Checking if the value at that index is same as the searched		
      {
	printf("\n%d is present at index %d",s,hs);
	break;
      }
    }
    if(table[hs]!=s)	//If the element is not present in table
    {
      printf("\nThe entered element is not present in the table.");
    }
  }
}
void searchqp(int table[M])
{
  int s,hs,j;
  printf("\nEnter the element that you want to search: ");
  scanf("%d",&s);
  hs=s%M;		//Determining index using hash function
  if(table[hs]==s)	//Checking if the value at that index is same as the searched
  {
    printf("\n%d is present at index %d",s,hs);
  }
  else
  {
    for(j=1;j<M;j++)
    {
      hs=(hs+j+j*j)%M;		//New index using quadratic probing technique
      if(table[hs]==s)		//Checking if the value at that index is same as the searched
      {
	printf("\n%d is present at index %d",s,hs);
	break;
      }
    }
    if(table[hs]!=s)	//If the element is not present in table	
    {
      printf("\nThe entered element is not present in the table.");
    }
  }
}

void display(int table[M])
{
  int i;
  printf("\n");
  for(i=0;i<M;i++)
  {
    printf("%d ",table[i]);
  }
}