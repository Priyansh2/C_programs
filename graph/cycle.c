//detecting whether there is as cycle of undirected graph or not
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;};

int visit[100];
struct node *arr[100];
int count;
void insert(struct node * arr[], int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));

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

int dfs(int v , int parent)
{
	struct node * temp = arr[v];

	visit[v] = 1;

	while(temp!=NULL)
	{
		if(visit[temp->data]!=1)
		{
			if(dfs(temp->data,v)==1)
				return 1;
		}

		else if(temp->data!=parent && parent!=-1)
		{
			
			count++;
			return 1;
		}

		temp =temp->next;
	}

	return 0;
}
int main()
{
	int i,j,k;
	int p,q,r;
	int m,n;
int flag;
	scanf("%d %d",&n,&m);
flag=1;
count = 0;	
for(i=1;i<=n;i++)
	{
		visit[i]=0;
		arr[i]=NULL;
	}

	for(j=1;j<=m;j++)
	{
		scanf("%d %d",&p,&q);

		insert(&arr[p],q);
		insert(&arr[q],p);

	}


	if(n<=2 && m<=2)
	{
		flag=0;
		
		if((n==1 && (m==1||m==2)) || (n==2 && m==2))
		{
			printf("cycle found\n");
		}
		else if(n==2 && m==1)
			printf("cycle not found\n");
	}


	r=0;
	for(k=1;k<=n;k++)
	{
		if(visit[k]!=1)
			r = dfs(k,-1);
	}

	if(r==1 && flag==1)
	{
		printf("cycle found\n");
		printf("%d\n",count);
	}

	else if(r==0 && flag==1){
		printf("cycle not found\n");
	}


	return 0;
}
