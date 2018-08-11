#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

void swap(struct node* p1, struct node* p2)
{
    int  temp;

    temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
}

void sort(struct node* head)
{
    struct node* pre,*curr;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{

        pre = head;
        curr = pre->next;

        while(pre->next!=NULL)
        {
            while(curr!=NULL)
            {
                if((pre->data) > (curr-> data))

                {
                    swap(pre,curr);

                }
                curr = curr->next;
            }

            pre = pre->next;
            curr = pre->next;

        }
    }

}

int main()
{
    int i,j,k;
    struct node* p1,*p2,*p3;
    int flag =1;
    int p,q,r;
    head=NULL;
    scanf("%d",&p);

    for(i=1;i<=p;i++)
    {
        p1=(struct node*)malloc(sizeof(struct node));

        if(flag==0)
        {
            p2->next = p1;
        }

        else if(flag==1)
        {
            head = p1;
            flag=0;
        }

        scanf("%d",&p1->data);

        p2  = p1;
    }
    p1->next = NULL;

    sort(head);

    p3 = head;

    while(p3!=NULL)
    {
        printf("%d\t",p3->data);
        p3 = p3->next;
    }
    printf("\n");

    return 0;
}

