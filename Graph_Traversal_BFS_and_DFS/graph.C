#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int graph[26][26]={0};	//adjacency matrix
char vertices[26];	//for storing vertices
int x=0;
int status[26]={0};	//for storing if the node has been visited or not

void readgraph(int nodes);	//function for reading graph from user
void display(int nodes);	//function for displaying adjacent matrix
void bfs(int nodes,int start);	//function for BFS traversal of graph
void dfs(int nodes,int start);	//function for DFS traversal of graph

void main()
{
  int nodes,op,i;
  char v;
  clrscr();
  do
  {
    printf("\n\nMAIN MENU");
    printf("\n1.Read Graph \n2.Display adjacency matrix \n3.BFS Traversal \n4.DFS Traversal \n5.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
      {
	printf("\nEnter the number of nodes: ");
	scanf("%d",&nodes);
	readgraph(nodes);
	break;
      }
      case 2:
      {
	display(nodes);
	break;
      }
      case 3:
      {
	printf("\nEnter the starting vertex: ");
	scanf(" %c",&v);
	printf("\nBFS Traversal\n");
	bfs(nodes,v-'A');
	break;
      }
      case 4:
      {
	printf("\nEnter the starting vertex: ");
	scanf(" %c",&v);
	printf("\nDFS Traversal\n");
	dfs(nodes,v-'A');
	break;
      }
    }
  }while(op!=5);
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

void readgraph(int nodes)
{
  int i,j,k,neigh;
  char v,n;
  for(i=0;i<nodes;i++)
  {
    printf("\nEnter vertex %d: ",i+1);
    scanf(" %c",&v);
    vertices[x]=v;	//storing the vertices in a separate matrix
    x++;
    printf("Enter the number of neighbours of %c: ",v);
    scanf("%d",&neigh);
    for(j=0;j<neigh;j++)
    {
      printf("Enter neighbour vertex %d: ",j+1);	//accepting the neighbours of the vertex from user
      scanf(" %c",&n);
      k=n-'A';		//storing in matrix using ASCII value of character 
      graph[i][k]=1;
    }
  }
}

void display(int nodes)
{
  int i,j;
  printf("\nThe adjacency matrix is:\n");
  for(i=0;i<nodes;i++)
  {
    for(j=0;j<nodes;j++)
    {
      printf("%d ",graph[i][j]);
    }
    printf("\n");
  }
}

void bfs(int nodes,int start)
{
  int front=0;	//setting front and rear of queue to 0
  int rear=0;
  int i,j;
  char q[26];	//queue for storing vertices
  status[start]=1;		//changing status of starting vertex to 1 i.e. visited
  q[rear]=vertices[start];	//insering the vertex to queue
  rear++;			
  while(rear!=front)	//while the queue is not empty
  {
    j=q[front]-'A';	//setting j to the index of the character stored in vertices matrix using ASCII value
    printf("%c ",vertices[j]);
    front++;
    for(i=0;i<nodes;i++)
    {
      if(status[i]==0&&graph[j][i]==1)	//if the ith node has not been visited earlier and it is a neighbour of jth node
      {
	q[rear]=vertices[i];	//insering in queue
	rear++;
	status[i]=1;		//changing status of vertex to 1 i.e. visited
      }
    }
  }
}

void dfs(int nodes,int start)
{
  int j;
  printf("%c ",vertices[start]);
  status[start]=1;	//changing status of vertex to 1 i.e. visited
  for(j=0;j<nodes;j++)	
  {
     if(status[j]==0&&graph[start][j]==1)	//if the node has not been visited earlier and it is a neighbour of (start)th node
     {
       dfs(nodes,j);	//calling dfs recursively i.e. moving ahead from jth node performing all steps of dfs again
     }
  }
}

