#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

int tracker;
int flag_ptr;
struct node *head,*x,*y,*z;

void create();
void get_length(struct node*p);
void ins_at_beg();
void ins_at_pos();
void del_at_beg();
void del_at_pos();
void traverse();
void search();
void sort();
void update();
void rev_traverse(struct node*p);
void get_length(struct node*p)
{
    int count,i,j,k;
    if(tracker==0 || head==NULL)
        count =0;
    else{    
        count = 1;
        struct node* temp;
        temp = p;
        while(temp->next!=head)
        {
            count++;
            temp = temp->next;
        }
    }
    printf("\n current length of list is :- %d\n",count);

    tracker = count;
}
void create()
{
    int c;
    int count=1;
    x = (struct node*)malloc(sizeof(struct node));
    printf("\n enter the data: ");
    scanf("%d",&x->data);
    x->next = x;
    head = x;
    printf("\n if u wish to continue press 1 otherwise 0: ");
    scanf("%d",&c);
    while(c!=0)
    {
        y = (struct node*)malloc(sizeof(struct node));
        printf("\n enter the data:");
        scanf("%d",&y->data);
        count++;//determine length of list
        x->next = y;
        y->next = head;
        x = y;
        printf("\n if u wish to continue press 1 otherwise 0: ");
        scanf("%d",&c);
    }
    tracker = count;
}

void ins_at_beg()
{
    x=head;
    y = (struct node*)malloc(sizeof(struct node));
    printf("\n enter the data: ");
    scanf("%d",&y->data);
    while(x->next!=head)
    {
        x =x->next;
    }

    x->next = y;
    y->next = head;
    head = y;
    tracker++;
}

void ins_at_pos()
{
    struct node* ptr;
    int c = 1, pos , count =1;
    y = (struct node*)malloc(sizeof(struct node));
    if(tracker==0 || head==NULL)
    {
        printf("\n cannot enter an element at this place\n");
        return;
    }
    printf("\n enter the data: ");
    scanf("%d",&y->data);
    printf("\n enter the position to be inserted: ");
    scanf("%d",&pos);
    x = head;
    ptr = head;
    while(ptr->next!=head){
        count ++;
        ptr = ptr->next;
    }
    count++;
    if(pos>count)
    {
        printf("\n out of bound\n");

    }
    while(c<pos)
    {
        z = x;
        x = x->next;
        c++;
    }
    y->next = x;
    z->next = y;
    tracker++;
}

void del_at_beg()
{
    if(tracker==0 || head==NULL)
        printf("\n list is empty\n");

    else{
        tracker--; 
        x = head;
        y = head;
        while(x->next!=head)
        {
            x = x->next;
        }

        head = y->next;
        x->next = head;
        free(y);
    }
}

void del_at_pos()
{
    if(tracker==0 || head==NULL)
        printf("\n list is empty\n");
    else{
        tracker--;
        int c = 1,pos;
        printf("\n enter the position to be deleted: ");
        scanf("%d",&pos);
        x = head;
        while(c<pos)
        {
            y = x;
            x = x->next;
            c++;
        }
        y->next = x->next;
        free(x);
    }

}
void traverse()
{
    if(tracker==0 || head==NULL)
        printf("\n list is empty\n");
    else{
        x = head;
        while(x->next!=head)
        {
            printf("%d->",x->data);
            x = x->next;
        }
        printf("%d",x->data);
    }
}

void search()
{
    int search_val;
    int count = 0;
    int flag=0;
    printf("\n enter the element to search: ");
    scanf("%d",&search_val);
    if(tracker==0 || head==NULL)
        printf("\n list is empty nothing to search\n");
    else{
        x = head;
        while(x->next!=head)
        {
            if(x->data==search_val)
            {
                printf("\n the element is found at position: %d",count);
                flag = 1;
                break;
            }
            count++;
            x = x->next;
        }
        if(flag==0)
            printf("\n element not found\n");
    }
}

void sort()
{
    struct node *ptr ,*nxt;
    int temp;
    if(tracker==0 || head==NULL)
        printf("\n list is empty\n");
    else{
        ptr = head;
        while(ptr->next!=head)
        {
            nxt = ptr->next;
            while(nxt!=head)
            {
                if(ptr->data > nxt->data)
                {
                    temp = ptr->data;
                    ptr->data = nxt->data;
                    nxt->data = temp;
                }
                nxt=nxt->next;     
            }
            ptr = ptr->next;
        }
    }

    return ;
}


void update()

{
    struct node*ptr;
    int search_val;
    int replace_val;
    int flag = 0;
    if(tracker==0 || head==NULL)
        printf("\n list is empty\n");
    else{
        printf("\n enter the value to be edited: ");

        scanf("%d",&search_val);
        fflush(stdin);
        printf("\n enter the value to be replace: ");
        scanf("%d",&replace_val);
        ptr = head;

        while(ptr->next!=head)
        {
            if(ptr->data==search_val)
            {
                ptr->data = replace_val;
                flag=1;
                break;
            }
            ptr = ptr->next;
        }
        if(ptr->data==search_val)
        {
            ptr->data = replace_val;
            flag =1;
        }
        if(flag==1)
            printf("\n update sucessful\n");
        else
            printf("\n update not successful\n");
    }
}
void rev_traverse(struct node*p)
{
    int i=0;
    if(tracker==0 || head==NULL)
        printf("\n list is empty\n");
    else
    {
        if(p->next!=head)
        {
            i = p->data;
            rev_traverse(p->next);
                printf("->%d",i);
        }
        if(p->next==head)
            printf("%d",p->data);
    }
}

int main()
{
    int ch;
    printf("\n 1.creation");
    printf("\n 2.insertion at begnning");
    printf("\n 3.insertion at position");
    printf("\n 4.deletion at begnning");
    printf("\n 5.deletin at position");
    printf("\n 6.traversing list");
    printf("\n 7.searching list");
    printf("\n 8.sorting list");
    printf("\n 9.updating list");
    printf("\n 10.reverse traversing");
    printf("\n 11.get current length");
    printf("\n 12.exit");
    printf("\n");
    tracker=0;
    while(1)
    {
        printf("\n enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                ins_at_beg();
                break;
            case 3:
                ins_at_pos();
                break;
            case 4:
                del_at_beg();
                break;
            case 5:
                del_at_pos();
                break;
            case 6:
                traverse();
                break;
            case 7:
                search();
                break;
            case 8:
                sort();
                break;
            case 9:
                update();
                break;
            case 10:
                flag_ptr = tracker;
                rev_traverse(head);
                break;
            case 11:
                get_length(head);
                break;
            case 12:
                exit(0);
                break;

        }
    }
    return 0;
}
