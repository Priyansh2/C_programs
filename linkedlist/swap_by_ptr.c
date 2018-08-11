//this program swap two node's datas by swapping their node's pointers or their addresses

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node* head;

void swapNodes(struct node*x, struct node*y)
{
	struct node* temp,*pre1,*pre2,*curr1,*curr2;
	pre1 = pre2 = NULL;//prevX is pre1 and prevY is pre2
	curr1 = curr2 = head;//CurrX is curr1 and CurrY is curr2
	// Nothing to do if x and y are same
	if (x == y) return;

	// Search for x (keep track of prevX and CurrX)
	
	while (curr1!= x)
	{
		pre1 = curr1;
		curr1 = curr1->next;
	}

	// Search for y (keep track of prevY and CurrY)
	
	while (curr2!= y)
	{
		pre2 = curr2;
		curr2 = curr2->next;
	}

	// If either x or y is not present, nothing to do
	if (curr1 == NULL || curr2 == NULL)
		return;

	// If x is not head of linked list
	if (pre1 != NULL)
		pre1->next = curr2;
	// Else make y as new head
	else
		head = curr2; 

	// If y is not head of linked list
	if (pre2 != NULL)
		pre2->next = curr1;
	else // Else make x as new head
		head = curr1;

	// Swap next pointers
	temp = curr2->next;
	curr2->next = curr1->next;
	curr1->next = temp;
}

/* Function to add a node at the begining of List :-O(1) insertion*/
struct node* create(int data1)
{

	struct node* temp;
	
	temp = (struct node*) malloc(sizeof(struct node));
      temp->data = data1;

   // creating linked list in left to right direction
      temp->next = head;

     head = temp;
 return temp;    
}


void printList()
{
	 struct node * node1;
//head = NULL;
	 node1 = head;
while(node1!=NULL)
	{
		printf("%d\t",node1->data);
		node1 = node1->next;
	}
printf("\n");
}

int main()
{
     struct node* a,*b,*c,*d,*e;

     a = create(15);//5
     b = create(12);//4
     c = create(1);//3
     d = create(0);//2
     e = create(50);//1

	printf("\n Linked list before calling swapNodes() ");


	printList();

	swapNodes(d,c);

	printf("\n Linked list after calling swapNodes() ");
	printList();

	return 0;
}

