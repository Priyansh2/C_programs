//this program gives (intersection , union , list after merging) : - two lists

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

node *create ()//insertion at head
{
    node *head, *p;
    int i, n;
    head = NULL;
    printf ("\n Enter no of data:");
    scanf ("%d", &n);
    printf ("\nEnter  data(in sorted sequence): ");
    for (i = 0; i < n; i++)
    {
        if (head == NULL)
            p = head = (node *) malloc (sizeof (node));
        else
        {
            p->next = (node *) malloc (sizeof (node));
            p = p->next;
        }
        p->next = NULL;
        scanf ("%d", &(p->data));
    }
    return (head);
}

void print (node * head)
{
    node *p;
    p = head;
    while (p != NULL)
    {
        printf ("%d\t", p->data);
        p = p->next;
    }
    printf ("\n");
}

node *insert (node * head, int x)	// insertion at end
{
    node *p, *q;
    p = (node *) malloc (sizeof (node));
    p->data = x;
    p->next = NULL;
    if (head == NULL)
    {
        return p;
    }
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;

        }

        q->next = p;

        return head;
    }
}

node *intersection (node * l1, node * l2)
{
    node *l6 = NULL, *p;
    p = l1;

    while (p != NULL)
    {
        if (search (l2, p->data) == 1)	// searching p->data in l2
        {
            l6 = insert (l6, p->data);
        }

        p = p->next;
    }
    return l6;
}

node *Union (node * l1, node * l2)
{
    node *l8, *p;
    l8 = NULL;
    if (l1->data > l2->data)
    {
        for (p = l2; p != NULL; p = p->next)
            l8 = insert (l8, p->data);
        for (p = l1; p != NULL; p = p->next)
            if (search (l2, p->data) == 0)
                l8 = insert (l8, p->data);
    }

    else
    {
        for (p = l1; p != NULL; p = p->next)
            l8 = insert (l8, p->data);
        for (p = l2; p != NULL; p = p->next)
            if (search (l1, p->data) == 0)
                l8 = insert (l8, p->data);
    }

    return l8;
}




node *merging (node * l1, node * l2)//O(n+m)
{
    node *l7 = NULL;

    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    else
    {
        if (l1->data < l2->data)
        {
            l7 = l1;
            l7->next = merging (l1->next, l2);
        }

        else
        {
            l7 = l2;
            l7->next = merging (l1, l2->next);
        }

        return l7;
    }
}


int search (node * head, int x)
{
    node *p;
    int flag = 0;
    p = head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }

    return flag;
}


int main ()
{
    node *l1, *l2, *l3, *l4, *l5;
    l1 = l2 = l3 = l4 = l5 = NULL;
head = NULL;
    l1 = create ();
    l2 = create ();

    l3 = intersection (l1, l2);
    printf ("The intersection is:\n");
    print (l3);

    l4 = merging (l1, l2);
    printf ("The merging is:\n");
    print (l4);

    l5 = Union (l1, l2);
    printf ("The union is:\n");
    print (l5);

    return 0;
}
