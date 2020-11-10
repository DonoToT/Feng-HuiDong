#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans,sx,sy,fx,fy;
int v[10][10];
int dx[6]={0,-1,0,0,1};
int dy[6]={0,0,-1,1,0};
void dfs(int x,int y)
{
	if(x==fx&&y==fy)
	{
		ans++;
		return;
	}
	for(int i=1;i<=4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m||v[nx][ny]) continue;
		v[nx][ny]=1;
		dfs(nx,ny);
		v[nx][ny]=0;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	for(int i=1;i<=t;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x][y]=1;
	}
	v[sx][sy]=1;
	dfs(sx,sy);
	printf("%d",ans);
	return 0;
}
