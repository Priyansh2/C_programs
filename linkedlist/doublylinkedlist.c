#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node *next;
};
int len;
struct node *split(struct node* head)
{
    struct node*fast = head;
    struct node*slow = head;
    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct node* temp = slow->next;
    slow->next=NULL;
    return temp;
}


struct node *merge(struct node* first , struct node*second)
{//function to merge two doubly linked lists

    if(!first)//if first linked list is empty
        return second;
    if(!second)//if second list is empty
        return first;

    if(first->data < second->data)
    {//pick the smaller value
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }

    else{
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;

        return second;
    }

}

struct node *mergesort(struct node *head)
{//function to do merge sort

    if(!head || !head->next)
        return head;

    struct node * second  = split(head);

    head = mergesort(head); //recurse for first halve 

    second = mergesort(second); //recurse for second halve

    return merge(head,second); //merge the two sorted halves
}

void push(struct node**headref,int value)
{//insertion at beginning of head node of dll
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    len++;
    temp->next = *headref;
    temp->prev = NULL;
    struct node *ptr;
    ptr = *headref;
    if(ptr!=NULL)
    {
        ptr->prev = temp;
    }

    ptr = temp;
    *headref = ptr;

}

void insertafter(struct node*prev_node , int data1)
{//in this function we give node as prev. node and 
    //we insert a new node after this prev. node

    if(len==0 || prev_node==NULL)
    {
        printf("\n list is empty\n");
        return ;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data1;
    len++;
    temp->next = prev_node->next;
    prev_node->next = temp;
    temp->prev = prev_node;

    if(temp->next!=NULL)
        temp->next->prev = temp;
}

void append(struct node**headref , int data1)
{//insert a new node at end

    struct node*temp = (struct node*)malloc(sizeof(struct node));

    struct node*last = *headref;
    temp->data = data1;
    len++;
    temp->next=NULL;
    if(*headref==NULL)
    {
        temp->prev = NULL;
        *headref = temp;
        return ;
    }

    while(last->next!=NULL)
        last = last->next;

    last->next = temp;

    temp->prev = last;
    return ;
}

void delete(struct node**headref , struct node*del)
{//here del is node to be deleted


    if(len==0 || *headref==NULL || del==NULL)//base case
    {
        printf("\n list is empty\n");
        return;    
    }
    if(*headref==del)//if del is head node
    {
        len--;
        *headref = del->next;
    }
    if(del->next!=NULL)//if del is not last node
    {
        len--;
        del->next->prev =del->prev;
    }
    if(del->prev!=NULL)
    {
        len--;
        del->prev->next = del->next;
    }
    free(del);
    printf("\n delete sucessful\n");
    return ;
}


void printlist(struct node*node,int flag)
{
    struct node *last;
    struct node *first;
    if(len==0)
        printf("\n list is empty\n");
    else{

        if(flag==1)
        {
            printf("\n traversal in forward direction\n");
            while(node->next!=NULL)
            {
                printf("%d ",node->data);
                last = node;
                node = node->next;
                first = node;
            }

            printf("%d\n",node->data);
        }

        else
        {
            while(node->next!=NULL)
            {
                node = node->next;
                first = node;
            }
            printf("\n traversal in reverse direction\n");
            while(first->prev!=NULL)
            {
                printf("%d ",first->data);
                first=first->prev;
            }
            printf("%d\n",first->data);
        }
    }
}
struct node * isempty()
{


    int main()
    {
        int i,j,k;
        int temp,n;
        int c,c1,flag;
        struct node*head =NULL;
        struct node*search_node;
        struct node*delnode;

        printf("\n 1.insert at beginning\n");
        printf("\n 2.insert at end\n");
        printf("\n 3.insert after node\n");
        printf("\n 4.delete node\n");
        printf("\n 5.perform mergesort\n");
        printf("\n 6.forward traversing\n");
        printf("\n 7.reverse traversing\n");
        printf("\n");

        while(1)
        {

            printf("\n Enter your choice\n");
            scanf("%d",&temp);
            switch(temp)
            {
                case 1:
                    j=1;
                    while(j==1)
                    {
                        printf("enter data\n");
                        scanf("%d",&i);
                        push(&head,i);
                        printf("\n if u want to continue press 1 else press 0\n");
                        scanf("%d",&j);
                        if(j!=1 &&j!=0)
                        {
                            printf("please enter correct no: out of 1 and 0\n");
                            scanf("%d",&j);
                        }

                    }
                    break;
                case 2:
                    k=1;
                    while(k==1)
                    {
                        printf("enter data\n");
                        scanf("%d",&i);
                        append(&head,i);
                        printf("\n if u want to continue press 1 else press 0\n");
                        scanf("%d",&k);
                        if(k!=0 && k!=1)
                        {
                            printf("please enter correct no: out of 1 and 0\n");
                            scanf("%d",&k);
                        }
                    }
                    break;
                case 3:
                    search_node=head;
                    c=0;
                    printf("please enter the node no: after which u want data to be inserted\n");
                    scanf("%d",&i);
                    if(i>=len){

                        printf("\n given node no: is out of range\n");
                        printf("please give correct node no:\n");
                        scanf("%d",&i);
                    }
                    while(1)
                    {
                        c++;
                        if(c==i)
                        {
                            printf("enter the data\n");
                            scanf("%d",&n);
                            insertafter(search_node,n);
                            break;
                        }


                        search_node = search_node->next;

                    }
                    break;
                case 4:
                    c1=0;
                    delnode=head;
                    printf("please enter node no: which u want to delete\n");
                    scanf("%d",&i);
                    while(1)
                    {
                        c1++;
                        if(c1==i)
                        {
                            delete(&head,delnode);
                            break;
                        }
                        delnode = delnode->next;

                    }
                    break;
                case 5:
                    if(len!=0)
                    {
                    head = mergesort(head);
                    }
                    else
                        printf("\n list is empty\n");
                    break;
                case 6:
                    flag=1;
                    printlist(head,flag);
                    break;
                case 7:
                    flag=0;
                    printlist(head,flag);
                    break;
            }
        }
        return 0;
    }
