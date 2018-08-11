// swapping datas fixing the node address
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

int swap(int m ,int n)//:-O(n)
{
    int i,j,temp;
    struct node *ptr,*ptr1;
    int flag;
    i=1;

    ptr=head;

    while(i<m && ptr!=NULL)
    {	
        ptr = ptr->next;
        i++;
    }


    j=1;

    ptr1=head;

    while(j<n && ptr1!=NULL)
    {	
        ptr1=ptr1->next;
        j++;
    }

    if(ptr!=NULL && ptr1!=NULL)
    {
        temp = ptr->data;
        ptr->data = ptr1->data;
        ptr1->data = temp;
        flag=1;
    }
    else
    {
        flag=0;
    }
    return flag;
}

int main()
{
    int i,j,k;
    int flag=1;
    int p,q,r;
    struct node* p1,*p2,*p3;
    head=NULL;
    scanf("%d",&i);

    for(j=1;j<=i;j++)
    {      
        p1 = (struct node*)malloc(sizeof(struct node));

        if(flag==0)
            p2 -> next = p1;

        else if(flag==1)
        {
            head = p1;
            flag=0;
        }
        scanf("%d",&p1->data);
        p2 = p1;
    }
    p1->next = NULL;
    scanf("%d %d",&p,&q);//p and q are values to be swapped
    r = swap(p,q);

    if(r==1)//if swap is successful then print list
    {
        p3 = head;

        while(p3!=NULL)
        {
            printf("%d %d ",p3->data,&p3->data);
            p3  = p3->next;
        }
        printf("\n");
    }

    else
        printf("Swapping couldn't possible\n");

    return 0;
}
