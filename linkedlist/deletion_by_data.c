// deletion of node by passing data(input of node) in the function
#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node* next;
};

struct node* head;

void delete(int data1)//:-O(n)
{    
	int i=0,j,flag=0;
	struct node *temp,*prev;
	temp=head;
	prev = NULL;
	while(temp!=NULL)
	{
		i++;
		if(temp->data==data1)
		{       
			flag=1;
			 
			if(i==1)//head node deleted
			{
				head = temp->next;

				free(temp);
			}

			else
			{
				while(1)
				{
					
					
						if(temp->next==NULL)
						{
							prev->next=NULL;
							free(temp);       
							break;
						}
						else
						{
							prev->next = temp->next;    
							free(temp);
							break;
						}
				        
					
					prev=temp;

					temp=temp->next;
				}
			}
		
		break;
		}
	        prev = temp;
		temp = temp->next;
	}

	if(flag==0)
		printf("no deletion possible\n");

}

int main()
{
	int i,j,k;
	int flag=1;
	struct node* p1,*p2,*p3;
head=NULL;
	scanf("%d",&i);

	for(j=1;j<=i;j++)//insertion at end
	{
		p1=(struct node*)malloc(sizeof(struct node));

		if(flag==0)
		{
			p2->next=p1;
		}

		else
		{
			head = p1;
			flag=0;
		}

		scanf("%d",&p1->data);

		p2 = p1;
	}
	p1->next=NULL;

	scanf("%d",&k);
	delete(k);

	p3 = head;


	while(p3!=NULL)//printing linked list
	{
		printf("%d\t",p3->data);
		p3 = p3->next;
	}

	printf("\n");

	return 0;
}


