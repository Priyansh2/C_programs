#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head;

void search(int data1)//:-O(n)
{
	int flag1=1;
	struct node* temp;

	temp = head;

	while(temp!=NULL)
	{
		if(temp->data == data1)
		{
			printf("found\n");
			flag1=0;
			break;
		}

		temp = temp->next;

	}

	if(flag1==1)
	{
		printf("not found\n");
	}

}
int main()
{
	struct node* p1,*p2,*p3;

	int flag=1;
	int i,j,k;
head=NULL;
	scanf("%d",&i);

	for(j=1;j<=i;j++)
	{
		p1=(struct node*)malloc(sizeof(struct node));

		if(flag==0)
			p2->next = p1;

		else if(flag==1)
		{

			head = p1;
			flag=0;

		}

		scanf("%d",&p1->data);

		p2 = p1;

	}

	p1->next = NULL;

	scanf("%d",&k);

	search(k);
	return 0;
}
