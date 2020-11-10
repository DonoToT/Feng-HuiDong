#include<bits/stdc++.h>
using namespace std;
int n,ans;
int v[1010],f[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(!v[x])
		{
			v[x]=1;
			f[++ans]=x;
		}
	}
	sort(f,f+ans+1);
	printf("%d\n%d",ans,f[1]);
	for(int i=2;i<=ans;i++)
		printf(" %d",f[i]);
	return 0;
}
