//to detect cycle in directed graph//
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;};

struct node * arr[100];
int visit[100];
int count;
void insert(struct node * arr[], int val)
{
	struct node * temp=(struct node*)malloc(sizeof(struct node));

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

int dfs(int v,int track[])
{
	if(visit[v]!=1)
	{
		struct node * temp =arr[v];

		visit[v] = track[v]  = 1;
		
		while(temp!=NULL)
		{ 

			if(visit[temp->data]!=1)
			{
				if(dfs(temp->data,track)==1)
                                  return 1;
			}

			else if(track[temp->data]==1)
			{
				
				count++;
				return 1;
			}
	temp = temp->next;
		}
	}

	track[v] = 0;
	return 0;
}
                                   
int main()
{
	int i,j,k;
	int t,n,m,p,q,r;
	int track[100];

	scanf("%d %d",&n,&m);
count=0;
	for(i=1;i<=n;i++)
	{
		arr[i]= NULL;
		visit[i] = 0;
		track[i] = 0;
	}

	for(j=1;j<=m;j++)
	{
		scanf("%d %d",&p,&q);

		insert(&arr[p],q);

	}
r = 0;
        for(k=1;k<=n;k++)
	{
			if(dfs(k,track)==1)
                          r = 1;
	}

	if(r==1)
	{
		printf("cycle found\n");
		printf("number of cycles is -- %d\n",count);
	}

	else
		printf("cycle not found\n");

	return 0;
}







