#include<stdio.h>
#include<conio.h>

int in[100];	//array for input from user
int inc[100];	//array for sorted list

void read(int n);		//function for reading the list from user
void sel_sort(int n);		//function for performing selection sort
void ins_sort(int n);		//function for performing insertion sort

void main()
{
  int n,i,op;
  clrscr();
  do
  {
    printf("\n\nMAIN MENU");		//MENU DRIVEN PROGRAM
    printf("\n1.Read list \n2.Selection sort \n3.Insertion sort \n4.Display sorted list \n5.Exit");\
    printf("\nEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
      {
	printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	read(n);
	break;
      }
      case 2:
      {
	sel_sort(n);
	break;
      }
      case 3:
      {
	ins_sort(n);
	break;
      }
      case 4:
      {
	printf("\n\nSorted list is: ");
	for(i=0;i<n;i++)
	{
	  printf("%d ",inc[i]);
	}
      }
    }
  }while(op!=5);
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

void read(int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Enter element %d: ",i+1);
    scanf("%d",&in[i]);			//accepting the element of the list from user and storing in array for input
  }
  printf("\nThe entered list is: ");	//printing the list entered by the user
  for(i=0;i<n;i++)
  {
    printf("%d ",in[i]);
  }
}

void sel_sort(int n)
{
  int i,j,index,t,k;
  for(i=0;i<n;i++)	//copying elements of input list to sorted list
  {
    inc[i]=in[i];
  }
  for(i=0;i<n;i++)
  {
    index=i;
    for(j=i+1;j<n;j++)
    {
      if(inc[j]<inc[index])	//checking if value of current index is greater than any of the following indices
      {
	index=j;		//changing index to j
      }
    }
    t=inc[index];	//interchanging the element at index and ith position by using a temporary variable t
    inc[index]=inc[i];
    inc[i]=t;
    printf("\n%d and %d are swapped",inc[index],inc[i]);
    printf("\nPass %d: ",i+1);		//printing the list after that iteraion
    for(k=0;k<n;k++)
	{
	  printf("%d ",inc[k]);
	}
  }
}

void ins_sort(int n)
{
  int i,j=0,t,k,l;
  for(i=0;i<n;i++)	//copying elements of input list to sorted list
  {
    inc[i]=in[i];
  }
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j>0;j--)		//for loop from the element following current element to the start of the array
    {
      if(inc[j]<inc[j-1])	//checking if value of current index is lesser than any of the previous indices
      {
	t=inc[j-1];		//interchanging the element at index and ith position by using a temporary variable t
	inc[j-1]=inc[j];
	inc[j]=t;
	printf("\n%d and %d are swapped",inc[j-1],inc[j]);
      }
    }
    printf("\nPass %d: ",i+1);		//printing the list after that iteraion
    for(l=0;l<n;l++)
    {
      printf("%d ",inc[l]);
    }
  }
}