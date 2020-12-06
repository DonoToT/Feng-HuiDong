//前缀和求w、b、r前i行个数，两层循环枚举分割线，求需涂色数，取最小值 
#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,ans=0x7fffffff;
int w[N],b[N],r[N];
string s;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j]=='W') w[i]++;
			if(s[j]=='B') b[i]++;
			if(s[j]=='R') r[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		w[i]+=w[i-1];
		b[i]+=b[i-1];
		r[i]+=r[i-1];
	}
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<=n-1;j++)
		{
			int tw=i*m-w[i];
			int tb=(j-i)*m-(b[j]-b[i]);
			int tr=(n-j)*m-(r[n]-r[j]);
			ans=min(ans,tw+tb+tr);
		}
	printf("%d",ans);
	return 0;
}
