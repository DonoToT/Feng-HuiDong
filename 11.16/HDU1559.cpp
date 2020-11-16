#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int T,n,m,x,y,a;
int f[N][N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a);
				f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a;
			}
		int ans=0;
		for(int i=x;i<=n;i++)
			for(int j=y;j<=m;j++)
				ans=max(ans,f[i][j]-f[i][j-y]-f[i-x][j]+f[i-x][j-y]);
		printf("%d\n",ans);
	}
	return 0;
}
