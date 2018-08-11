//connected component of undirected graph


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
int visit[100];
struct node * arr[100];
void insert(struct node *arr[] , int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));

	temp->data = val;
        //temp->next = NULL;
	if(*arr==NULL)
	{
		*arr = temp;
		temp->next=NULL;
	}
	else{
		temp->next = *arr;
		*arr = temp;
	}
}

void print(int n)
{
	struct node * temp;

	int i ;
	for(i=1;i<=n;i++)
	{
		temp = arr[i];

		printf("%d -->",i);

		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}


void dfs(int v)
{
	visit[v] = 1;
        struct node* temp = arr[v];
	
       printf("%d ",v);

	while(temp!=NULL)
	{
		if(visit[temp->data]!=1)
			dfs(temp->data);

		temp = temp->next;

	}
}


int main()
{
	int i,j,k;
	int t,n,m;

	scanf("%d %d",&n,&m);

	for(k=1;k<=n;k++)
	{
		visit[k]=0;
		arr[k]=NULL;
	}
	
	
	
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&j,&k);

		insert(&arr[j],k);
		insert(&arr[k],j);

	}
         
	for(j=1;j<=n;j++)
	{

           if(visit[j]!=1)
	   {
		   dfs(j);

           printf("\n");
	   }
	}

	return 0;
}



       
