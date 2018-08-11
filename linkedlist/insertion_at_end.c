#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head;

int main()
{
	int i,j,k,p;
	struct node* node,*temp,*temp1;
int flag =1;
head = NULL;
	scanf("%d",&p);//number of nodes in linked list

	for(i=1;i<=p;i++)//O(n) insertion
	{
                 node=(struct node*)malloc(sizeof(struct node));

		 if(flag==0)
			 temp->next = node;

		 else if(flag==1)
		 {
			 head = node;
		 flag=0;
		 }
		 scanf("%d",&node->data);//scanning data of each node
		 temp = node;//temp is now pointing to node
	}
	node->next = NULL;
temp1 = head;
             while(temp1!=NULL)
	     {
		     printf("%d ",temp1->data);
		     temp1 = temp1->next;
	     }

	     printf("\n");

	     return 0;
}
