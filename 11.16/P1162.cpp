#include<bits/stdc++.h>
using namespace std;
int n;
int s[33][33],f[33][33];
int dx[9]={0,-1,0,0,1};
int dy[9]={0,0,-1,1,0};
struct node{
	int x,y;
}a,t;
queue<node>q;
void bfs(int sx,int sy)
{
	a.x=sx; a.y=sy;
	q.push(a); f[sx][sy]=1;
	while(!q.empty())
	{
		a=q.front(); q.pop();
		for(int i=1;i<=4;i++)
		{
			t.x=a.x+dx[i];
			t.y=a.y+dy[i];
			if(t.x<1||t.x>n||t.y<1||t.y>n) continue;
			if(!f[t.x][t.y]&&s[t.x][t.y]==0)
			{
				q.push(t);
				f[t.x][t.y]=1;
			}
		}
	}
}
void Print(int m,int i,int j)
{
	if(m==0&&!f[i][j]) printf("2");
	else if(m==0&&f[i][j]) printf("0");
	else printf("1");
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&s[i][j]);
	for(int i=1;i<=n;i++)
	{
		if(s[1][i]==0&&!f[1][i]) bfs(1,i);
		if(s[i][1]==0&&!f[i][1]) bfs(i,1);
		if(s[i][n]==0&&!f[i][n]) bfs(i,n);
		if(s[n][i]==0&&!f[n][i]) bfs(n,i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
			Print(s[i][j],i,j),printf(" ");
		Print(s[i][n],i,n);
		printf("\n");
	}
	return 0;
}
