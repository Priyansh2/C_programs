// deletion at particular position
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;

int insertion()
{
    struct node* p1;
    struct node* p2;
    int data1;
    int flag=1;
    int j,k;

    scanf("%d",&j);

    if(j==0)
    {
        printf("linked list is empty, so you can't delete any node\n");
        return j;
    }

    else
    {
        for(k=1;k<=j;k++)
        {      
            p1 =(struct node*)malloc(sizeof(struct node));

            if(flag==0)
            {

                p2->next=p1;
            }

            if(flag ==1)
            {
                head = p1;
                flag=0;
            }
            scanf("%d",&data1);
            p1->data = data1;
            p2 = p1;	


        }

        p1->next=NULL;

        return 1;
    }

}
void delete(int n)
{
    struct node* temp;
    struct node* pre;
    struct node* forw;
    int i;
    temp = head;


    if(n==1)
    {
        head = temp->next;
        free(temp);
        return;

    }

    else{
        for(i=1;i<=n-1;i++)
        {    
            pre = temp;
            temp = temp->next;
        }

        if(temp->next==NULL)
        {  
            pre->next = NULL;
            free(temp);
            return;
        }
        else{
            pre->next = temp->next;
            free(temp);
            return;
        }
    }


}

int main()
{
    int n,pass;
    struct node* p3;
    pass =  insertion();

    if(pass!=0)//if list is not empty then only do
    {
        scanf("%d",&n);// scan node no which we want to delete

        delete(n);

        p3 = head;

        while(p3!=NULL)//printing rest of linked list
        {
            printf("%d\t",p3->data);
            p3 = p3->next;
        }

        printf("\n");
    }
    return 0;

}
