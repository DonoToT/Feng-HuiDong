#include<bits/stdc++.h>
using namespace std;
const int N=5555;
vector<int>a,b,c[N],d[N];
string s1,s2;
int f[N];
void easy_work()
{
	for(int i=a.size()-1;i>=0;i--)
	{
		int x=0;
		for(int j=b.size()-1;j>=0;j--)
		{
			int k=a.size()-i+b.size()-j-1;
			f[k]=a[i]*b[j]+x+f[k];
			x=f[k]/10;
			f[k]%=10;
		}
		f[b.size()-i+b.size()]=x;
	}
	int l=a.size()+b.size();
	while(f[l]==0&&l>1) l--;
	for(int i=l;i>=1;i--)
		cout<<f[i];
}
int main()
{
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++)
		a.push_back(s1[i]-'0');
	for(int i=0;i<s2.length();i++)
		b.push_back(s2[i]-'0');
	easy_work(); return 0;
	for(int i=b.size()-1;i>=0;i--)
	{
		int now=b.size()-i-1;
		for(int j=1;j<=now;j++)
			c[now].push_back(0);
		int x=0;
		for(int j=a.size()-1;j>=0;j--)
		{
			int cnt=a[j]*b[i]+x;
			c[now].push_back(cnt%10);
			x=cnt/10;
		}
		if(x) c[now].push_back(x);
	}
	for(int i=0;i<b.size();i++)
	{
		int x=0;
		for(int j=d[i].size();j<=c[i].size();j++)
			d[i].push_back(0);
		for(int j=0;j<c[i].size();j++)
		{
			int cnt=c[i][j]+d[i][j]+x;
			d[i+1].push_back(cnt%10);
			x=cnt/10;
		}
		if(x) d[i+1].push_back(x);
	}
	if(d[b.size()][d[b.size()].size()-1]==0)
	{
		printf("0");
		return 0;
	}
	for(int i=d[b.size()].size()-1;i>=0;i--)
		printf("%d",d[b.size()][i]);
	return 0;
}
