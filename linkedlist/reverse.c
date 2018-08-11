#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

int main()
{
    int i,j,k,p,q,r;
    int flag=1;
    struct node* p1,*p2,*p3;
    struct node* curr, *temp, *pre;
    head = NULL;
    scanf("%d",&p);

    for(i=1;i<=p;i++)
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
    pre = NULL;
    if(head!=NULL)
    {

        curr = head;
        while(curr!=NULL)//reversing list
        { 
            temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        head = pre;


        p3 = head;
        while(p3!=NULL)
        {
            printf("%d\t",p3->data);
            p3 = p3->next;
        }
        printf("\n");

    }

    else
        printf("Since list is empty we can't reverse it\n");


    return 0;
}
