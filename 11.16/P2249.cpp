#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m,l,r;
int a[N];
int rec(int q)
{
	l=0; r=n+1;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(a[mid]<q) l=mid;
		else r=mid-1;
	}
	if(a[l+1]==q) return l+1;
	else return -1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int q;
		scanf("%d",&q);
		printf("%d ",rec(q));
	}
	return 0;
}
