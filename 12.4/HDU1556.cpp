//Ç°×ººÍ°å×Ó 
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100000+100;
int n;
int d[N];
int main()
{
	while(scanf("%d",&n))
	{
		if(!n) break;
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			d[a]+=1; d[b+1]-=1;
		}
		for(int i=1;i<=n;i++)
			d[i]+=d[i-1];
		for(int i=1;i<n;i++)
			printf("%d ",d[i]);
		printf("%d\n",d[n]);
	}
	return 0;
}
