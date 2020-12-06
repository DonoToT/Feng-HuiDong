//dfs，每添加一个用三个数组标记此行列斜不可用 
#include<bits/stdc++.h>
using namespace std;
int n,ans;
int l[20],zx[20],yx[20],a[5][20],t[20];
void dfs(int c)
{
	if(c==n+1)
	{
		ans++;
		if(ans<=3)
		{
			for(int i=1;i<=n;i++)
				a[ans][i]=t[i];
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int zx_n=c+i-1,yx_n=n-(i-c);
		if(!l[i]&&!zx[zx_n]&&!yx[yx_n])
		{
			l[i]=zx[zx_n]=yx[yx_n]=1;
			t[c]=i;
			dfs(c+1);
			l[i]=zx[zx_n]=yx[yx_n]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<n;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][n]);
	}
	printf("%d",ans);
	return 0;
}
