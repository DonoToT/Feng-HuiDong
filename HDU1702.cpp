#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int T,n,h,t;
int d[N];
string s;
void runA()
{
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s=="IN")
		{
			int x;
			scanf("%d",&x);
			d[++t]=x;
		}
		else
		{
			if(h<t) printf("%d\n",d[++h]);
			else printf("None\n");
		}
	}
}
void runB()
{
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s=="IN")
		{
			int x;
			scanf("%d",&x);
			d[++t]=x;
		}
		else
		{
			if(t>0) printf("%d\n",d[t--]);
			else printf("None\n");
		}
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cin>>s;
		h=t=0;
		if(s=="FIFO") runA();
		else runB();
	}
	return 0;
}
