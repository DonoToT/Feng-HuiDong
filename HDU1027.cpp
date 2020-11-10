#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[10101],v[10101],a[10101];

int main()
{
	memset(f,0X7F,sizeof(f));
	f[0]=1;
	for(int i=1;i<=8;i++)
		f[i]=f[i-1]*i;
	while(~scanf("%d%d",&n,&m)) //~:use ctrl Z to stop
	{
		memset(v,0,sizeof(v));
		m--;
		/* È«ÅÅÁÐº¯Êý 
		for(int i=1;i<=n;i++) a[i]=i;
		while(m--) next_permutation(a+1,a+n+1);
		*/
		for(int i=1;i<=n;i++)
		{
			int mi,cnt=0,j;
			mi=m/f[n-i]+1;
			for(j=1;j<=n;j++)
			{
				if(!v[j]) cnt++;
				if(cnt==mi) break;
			}
			v[j]=1; a[i]=j;
			m=m%f[n-i];
		}
		for(int i=1;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}
