#include <stdio.h>
#include <conio.h>

#define MAX 10

int deque[MAX];
int l=-1,r=-1;

void input(void);
void output(void);
void insert_l(void);
void insert_r(void);
void delete_l(void);
void delete_r(void);
void display(void);

void main()
{
  int option;
  clrscr();
  printf("\n **** MAIN MENU ****");
  printf("\n 1.Input restricted deque");
  printf("\n 2.Output restricted deque");
  printf("\n Enter your option : ");
  scanf("%d",&option);
  switch(option)
  {
    case 1:
    {
      input();
      break;
    }
    case 2:
    {
      output();
      break;
    }
  }
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

void input()
{
  int option;
  do
  {
  printf("\n * INPUT RESTRICTED DEQUE *");
  printf("\n 1.Insert at right");
  printf("\n 2.Delete from left");
  printf("\n 3.Delete from right");
  printf("\n 4.Display");
  printf("\n 5.Quit");
  printf("\n Enter your option : ");
  scanf("%d",&option);
  switch(option)
  {
    case 1:
    {
      insert_r();
      break;
    }
    case 2:
    {
      delete_l();
      break;
    }
    case 3:
    {
      delete_r();
      break;
    }
    case 4:
    {
      display();
      break;
    }
  }
  }while(option!=5);
}

void output()
{
  int option;
  do
  {
  printf("\n * OUTPUT RESTRICTED DEQUE *");
  printf("\n 1.Insert at right");
  printf("\n 2.Insert at left");
  printf("\n 3.Delete from left");
  printf("\n 4.Display");
  printf("\n 5.Quit");
  printf("\n Enter your option : ");
  scanf("%d",&option);
  switch(option)
  {
    case 1:
    {
      insert_r();
      break;
    }
    case 2:
    {
      insert_l();
      break;
    }
    case 3:
    {
      delete_l();
      break;
    }
    case 4:
    {
      display();
      break;
    }
  }
  }while(option!=5);
}

void insert_r()
{
  int val;
  printf("\nEnter the value to be added:");
  scanf("%d", &val);
  if((l==0&&r==MAX-1)||(l==r+1))
  {
    printf("\nOverflow");
    return;
  }
  if (l==-1) //check for empty
  {
    l = 0;
    r = 0;
  }
  else
  {
    if(r==MAX-1) /*r is at last position of queue */
    {
      r = 0;
    }
    else
    {
      r=r+1;
    }
  }
  deque[r] = val ;
}

void insert_l()
{
  int val;
  printf("\n Enter the value to be added:");
  scanf("%d", &val);
  if((l == 0 && r == MAX-1) || (l == r+1))
  {
    printf("\nOverflow");
    return;
  }
  if (l == -1)//check for empty
  {
    l = 0;
    r = 0;
  }
  else
  {
    if(l == 0)
    {
      l=MAX-1;
    }
    else
    {
      l=l-1;
    }
  }
  deque[l] = val;
}

void delete_l()
{
  if (l == -1)
  {
    printf("\nUnderflow");
    return;
  }
  printf("\n The element deleted is : %d\n", deque[l]);
  if(l == r) //when Queue has only one element
  {
    l = -1;
    r = -1;
  }
  else
  {
  if(l == MAX-1)
    l = 0;
  else
    l = l+1;
  }
}

void delete_r()
{
  if (l == -1)
  {
    printf("\nUnderflow");
    return;
  }
  printf("\n The element deleted is : %d\n", deque[r]);
  if(l == r) //when queue has only one element
  {
    l = -1;
    r = -1;
  }
  else
  {
    if(r == 0)
      r=MAX-1;
    else
      r=r-1;
  }
}

void display()
{
  int front = l, rear = r;
  if(front == -1)
  {
    printf("\n QUEUE IS EMPTY");
    return;
  }
  printf("\n The elements of the queue are : ");
  if(front <= rear )
  {
    while(front <= rear)
    {
      printf("%d ",deque[front]);
      front++;
    }
  }
  else
  {
    while(front <= MAX-1)
    {
      printf("%d ",deque[front]);
      front++;
    }
    front = 0;
    while(front <= rear)
    {
      printf("%d ",deque[front]);
      front++;
    }
  }
  printf("\n");
}