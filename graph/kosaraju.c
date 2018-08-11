//strongly conected component of graph
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node * arr[100];
struct node * brr[100];
//int visit[100];
int stack[100];
//int st[100];
int top;
int flag;

void push(int val)
{
	
	
	if(top==0)
	{
		top++;
		stack[top] = val;
	
	}

	else{
		top++;
		stack[top] = val;
	}

//	printf("%d ",stack[top]);
}

int pop()
{
  int k;        
 k = stack[top];	
	top--;
	return k;
}

int empty()
{
	if(top==0)
		return 0;
}

void insert1(struct node *arr[], int val)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));

	temp->data = val;

	if(*arr==NULL)
	{
		*arr = temp;
		temp->next = NULL;
	}

	else{
		temp->next = *arr;
		*arr = temp;
	}
}

void insert2(struct node *brr[] , int val)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));

	temp->data = val;

	if(*brr==NULL)
	{
		*brr = temp;
		temp->next = NULL;
	}

	else{
		temp->next = *brr;
		*brr = temp;
	}

}


void dfs(int v,int visit[])
{
	visit[v]=1;
 //       struct node* temp;
if(flag==1)
{
	printf("%d ",v);


//printf("yoyo\n");
	struct node* temp= brr[v];

	while(temp!=NULL)
	{
		if(visit[temp->data]!=1)
		{
			dfs(temp->data,visit);
		}

	temp = temp->next;
	}
}

else{  
	   
	struct node * temp = arr[v];
//printf("ypyp\n");	
	while(temp!=NULL)
	   {
		   if(visit[temp->data]!=1)
		   {
			   dfs(temp->data,visit);
		   }

		   temp = temp->next;

	   }


push(v);

}


}

void ssc(int visit[])
{
	//flag=1;
	int vertex;
	while(empty()!=0)
	{   
		vertex = pop();

		if(visit[vertex]!=1)
		{
			dfs(vertex,visit);
//			printf("yoyo2\n");

			printf("\n");
		}

	}

}

int main()
{
    int visit[100],i,j,k;
    int t,n,m,p,q,r;
 //   struct node *arr[100];
   // struct node *brr[100];

    scanf("%d %d",&n,&m);
top = 0;
    flag=0;
    for(i=1;i<=n;i++)
    {
	    visit[i]=0;
	    arr[i] = NULL;
	    brr[i]  = NULL;
    }

    for(j=1;j<=m;j++)
    {
	    scanf("%d %d",&p,&q);

	    insert1(&arr[p],q);
            insert2(&brr[q],p);

    }

    for(k=1;k<=n;k++)
   {
	   if(visit[k]!=1)
		  dfs(k,visit);
    }
     
    for(i=1;i<=n;i++)
    {
          printf("%d ",stack[i]);  
   }
    printf("\n");

    //printf("%d\n",top);
    
    flag=1;
     for(i=1;i<=n;i++)
     {
	     visit[i]=0;
     }
     
     
     ssc(visit);

return 0;
}
