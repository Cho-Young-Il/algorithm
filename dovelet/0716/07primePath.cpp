#include <stdio.h>

int Q[100000];
int front=0,rear=0;
int len[10000];
bool visit[10000]={false,};

bool isPrime(int value)
{
	if(value==2)					return true;

	if(value%2==0)					return false;
	
	for(int i=3;i*i<=value;i+=2)
		if(value%i==0)				return false;

	return true;
}

void bfs(int x)
{
	for(int i=1;i<10;i++)
	{
		int value=x%1000+i*1000;
		if((!visit[value])&&(isPrime(value)))
		{
			Q[rear++]=value;
			visit[value]=true;
			len[value]=len[x]+1;
		}
	}
	for(int i=0;i<10;i++)
	{
		int value=(x%100)+(x/1000)*1000+i*100;
		if((!visit[value])&&(isPrime(value)))
		{
			Q[rear++]=value;
			visit[value]=true;
			len[value]=len[x]+1;
		}
	}
	for(int i=0;i<10;i++)
	{
		int value=x%10+(x/100)*100+i*10;
		if((!visit[value])&&(isPrime(value)))
		{
			Q[rear++]=value;
			visit[value]=true;
			len[value]=len[x]+1;
		}
	}
	for(int i=0;i<10;i++)
	{
		int value=(x/10)*10+i;
		if((!visit[value])&&(isPrime(value)))
		{
			Q[rear++]=value;
			visit[value]=true;
			len[value]=len[x]+1;
		}
	}
}

int main()
{
	int src,dst;
	scanf("%d %d",&src,&dst);

	len[src]=0;
	Q[rear++]=src;
	visit[src]=true;
	while(front<rear)
	{
		int pop=Q[front++];		
		if(pop==dst)
			break;
		bfs(pop);		
	}
	printf("%d\n",len[dst]);

	return 0;
}