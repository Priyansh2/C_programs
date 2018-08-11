#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head;
//head->next = NULL;
//head->data = NULL;

void insert(int n , int input)//insert at particular position :- O(n)
{
	struct node* temp;
	struct node* temp1;
int i;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=input;
	temp1 = head;

	if(n==1)// if n==1 , we want to insert node at beginning
		{
			temp->next = head;
			head = temp;
			return;
		}
	else{
		for(i=1;i<=n-2;i++)
		{
                   temp1 = temp1->next;
		}

		if(temp1->next==NULL)
		{
			temp1->next = temp;
			temp->next = NULL;
			return;
		}
		else
		{
			temp->next = temp1->next;
			temp1->next = temp;
			return;
		}
	}
}

int main(){
   int i,j,k;
   struct node*p1;
int p,q,r,m;
head = NULL;
// from now we going to create linklist via using insertion fun
   scanf("%d",&i);

   for(j=1;j<=i;j++)
   {
	   scanf("%d",&k);
	   insert(j,k);
   }
// since linked list at this time is created.
// now we going to give r as input denoting no of times we want to insert elements in linked list
   scanf("%d",&r);
for(m=1;m<=r;m++)
{
        scanf("%d %d",&p,&q);// scan node no and data to be inputted at that node no
	insert(p,q);
}
   p1 = head;

   while(p1!=NULL)
   {
	   printf("%d\t",p1->data);
	   p1 = p1->next;
   }
   printf("\n");
 
   return 0;
}




