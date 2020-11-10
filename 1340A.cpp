#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+100;
int t,n;
int a[N],mp[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]=i;
		}
		int now=1,flag=0;
		while(now<n)
		{
			int nx=mp[now];
			while(a[nx]+1==a[nx+1]&&nx+1<=n) nx++;
			if(nx==n) now=a[nx]+1;
			else if(a[nx]<a[nx+1])
			{
				printf("No\n");
				flag=1;
				break;
			}
			else now=a[nx]+1;
		}
		if(!flag) printf("Yes\n");
	}
	return 0;
}
