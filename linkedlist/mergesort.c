#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* merge(struct node* a ,struct node* b)
{
    struct node *result = NULL;
    if(a==NULL)//base case
        return b;
        else if(b==NULL)//base case
            return a;
            if(a->data <= b->data)//pick up smallest one and then recurr
            {
                result = a;
                result->next = merge(a->next,b);

            }
            else
            {
                result = b;
                result->next = merge(a,b->next);
            }
            return result;
}
//below is utility function:- split the nodes of given list into front and back
void frontback_split(struct node*source , struct node** frontref , struct node** backref)
{
    struct node * fast;
    struct node * slow;
    if(source==NULL || source->next==NULL)
    {
        *frontref = source;
        *backref = NULL;
    }
    else{
        slow = source;
        fast = source->next;

        while(fast!=NULL)
            {
                fast = fast->next;
                if(fast!=NULL)
                {
                    slow = slow->next;
                    fast= fast->next;
                }
            }

            *frontref = source;
            *backref = slow->next;
            slow->next=NULL;
    }
}

void mergesort(struct node **headref)
{
    struct node* head= *headref;
    struct node* a;
    struct node*b;

    if((head==NULL) || (head->next==NULL))//base case
    return ;

    frontback_split(head,&a,&b);//split head into 'a' and 'b' sublists
    mergesort(&a);//recurssively sort the sublist
    mergesort(&b);
    *headref = merge(a,b);//merge the two list together
}

void printlist(struct node *node)
{
    while(node->next!=NULL)
    {
        printf("%d->",node->data);
        node = node->next;
    }
    printf("%d\n",node->data);


}

void push(struct node**headref ,int value)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = (*headref);
    (*headref) = temp;
}

int main(){
    struct node* res = NULL;
    struct node*a = NULL;
    int n,j,k;
    int t;
    scanf("%d",&t);
    while(t--)
    {

    scanf("%d",&n);//no of nodes to insert 
    for(j=1;j<=n;j++)
    {
        scanf("%d",&k);
        push(&a,k);
    }
printf("\n before sorting linked list is: \n");
printlist(a);
    mergesort(&a);
    printf("\n after sorting linked list is: \n");
    printlist(a);
}
    return 0;
}


