#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
  int data; 
  struct node *left;
  struct node *right;
};

struct node *tree;

struct node *insert(struct node *t);
void delete(int x);
void preorder(struct node *t);
void inorder(struct node *t);
void postorder(struct node *t);

void main()
{
  int option,val,x;
  struct node *ptr;
  clrscr();
  do
  {
    printf("\n\nMAIN MENU");
    printf("\n1.Insert a new node \n2.Delete a node \n3.Traverse in PreOrder and Display \n4.Traverse in InOrder and Display \n5.Traverse in PostOrder and Display \n6.Exit");
    printf("\nEnter your option : ");
    scanf("%d",&option);
    switch(option)
    {
	case 1:
	{
	  tree=insert(tree);
	  break;
	}
	case 2:
	{
	  printf("Enter the value to be deleted : ");
	  scanf("%d",&x);
	  delete(x);
	  break;
	}
	case 3:
	{
	  printf("\nThe elements of the tree in PreOrder form are : ");
	  preorder(tree);
	  break;
	}
	case 4:
	{
	  printf("\nThe elements of the tree in InOrder form are : ");
	  inorder(tree);
	  break;
	}
	case 5:
	{
	  printf("\nThe elements of the tree in PostOrder form are : ");
	  postorder(tree);
	  break;
	}
    }
  }while(option!=6);
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

struct node *insert(struct node *tree)
{
  int val;
  struct node *ptr,*nodeptr,*parentptr;
  printf("\nEnter the value of the new node : ");
  scanf("%d",&val);
  ptr=(struct node*)malloc(sizeof(struct node));
  ptr->data=val;
  ptr->left=NULL;
  ptr->right=NULL;
  if(tree==NULL)
  {
    tree=ptr;
    tree->left=NULL;
    tree->right=NULL;
  }
  else
  {
    parentptr=NULL;
    nodeptr=tree;
    while(nodeptr!=NULL)	//traversing to parent node after which new node is to be inserted
    {
      parentptr=nodeptr;
      if(val<nodeptr->data)
      {
	nodeptr=nodeptr->left;
      }
      else
      {
	nodeptr=nodeptr->right;
      }
    }
    if(val<parentptr->data)	//setting adress of parent to point to new node depending on values of both
    {
      parentptr->left=ptr;
    }
    else
    {
      parentptr->right=ptr;
    }
  }
  printf("\nElement inserted.");
  return tree;
}


void delete(int x)
{
   struct node *t1,*t2,*b,*bp;
   t1=(struct node*)malloc(sizeof(struct node));
   t2=(struct node*)malloc(sizeof(struct node));
   b=(struct node*)malloc(sizeof(struct node));
   bp=(struct node*)malloc(sizeof(struct node));
   if(tree==NULL)	//checking if tree is empty
   {
     printf("\nTree is empty.");
   }
   else
   {
     int c;
     t1=tree;
     t2=tree;
     while(t1!=NULL&&t1->data!=x)	//traversing to node
     {
	t2=t1;		//stores the root that came before t1 that is, t1's previous node
	if(x<t1->data)
	{
	   t1=t1->left;
	}
	else
	{
	   t1=t1->right;
	}

     }
     if(t1==NULL||!(t1!=NULL && t1->data==x))	//checking if entered element is present in tree
     {
	printf("\nNo Such Element Found.");
     }
     else
     {
	if(t1->left==NULL && t1->right==NULL)	//node with no child
	{
	   if(t2->data>t1->data)
	   {
		t2->left=NULL;
	   }
	   else
	   {
		t2->right=NULL;
	   }
	   free(t1);
	}
	else if(t1->right==NULL)	//node with no right child i.e. single child
	{
	   t2->left=t1->left;
	   free(t1);
	}
	else if(t1->left==NULL)		//node with no left child i.e. single child
	{
	   t2->right=t1->right;
	   free(t1);
	}
	else				//node with 2 children
	{
	   bp=t1->left;		//obtaining the greatest node in the left subtree
	   b=bp;
	   while(b->right!=NULL)
	   {
		bp=b;
		b=b->right;
	   }
	   t1->data=b->data;
	   t1->left=b->left;
	   bp->right=NULL;
	   free(b);
	}
	printf("\nElement has been deleted.");
     }
   }
}


void preorder(struct node *tree)
{
  if(tree!=NULL)
  {
    printf("%d ",tree->data);
    preorder(tree->left);
    preorder(tree->right);
  }
}

void inorder(struct node *tree)
{
  if(tree!=NULL)
  {
    inorder(tree->left);
    printf("%d ",tree->data);
    inorder(tree->right);
  }
}

void postorder(struct node *tree)
{
  if(tree!=NULL)
  {
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ",tree->data);
  }
}
