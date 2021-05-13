#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int n;

void create(int arr[]);
void build(int pos,int arr[]);
int delet(int arr[]);
void insert(int arr[]);
void display(int arr[]);

void main()
{
	int ch,heap[MAX],data,i;
	int k=0;
	clrscr();
	heap[0]=0;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("\nEnter the elements: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&heap[i]);
	}
	create(heap);
	do
	{
		printf("\n\nMain Menu");
		printf("\n1.Delete \n2.Insert \n3.Display \n4.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
			{
				k=delet(heap);
				printf("\nThe element deleted is %d",k);
				create(heap);
				break;
			}
			case 2 :
			{
				insert(heap);
				break;
			}
			case 3 :
			{
				display(heap);
				break;
			}
		}
	}while(ch!=4);
	printf("\n\nProgram by Mihir Gandhi B1 1611077");
	getch();
}

void create(int arr[])
{
	int i;
	for(i=(n/2);i>=1;i--)
		build(i,arr);
}

void build(int pos,int arr[])
{
	int val;
	int i;
	val=arr[pos];
	while(pos<=(n/2))
	{
		i=2*pos;
		if((i<n) && arr[i]<arr[i+1])
			i++;
		if(val >= arr[i])
			break;
		arr[pos]=arr[i];
		pos=i;
	}
	arr[pos]=val;
}

int delet(int arr[])
{
	int val;
	val=arr[1];
	arr[1]=arr[n];
	n--;
	build(1,arr);
	return val;
}

void insert(int arr[])
{
	int ele;
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&ele);
	n++;
	arr[n]=ele;
	create(arr);
}

void display(int arr[])
{
	int i;
	printf("\nThe sorted elements of the queue are: \n");
	for(i=1;i<=n;i++)
		printf("%d ",arr[i]);
}

