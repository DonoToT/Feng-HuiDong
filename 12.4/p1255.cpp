//f[i]=f[i-1]+f[i-2]£¬ÓÃ¸ß¾« 
#include<bits/stdc++.h>
using namespace std;
const int N=5555;
int n;
vector<int>f[N];
void gj_add(int x,int y,int z)
{
	int s=0,l=max(f[x].size(),f[y].size());
	for(int i=0;i<l;i++)
	{
		if(i<f[x].size()) s+=f[x][i];
		if(i<f[y].size()) s+=f[y][i];
		f[z].push_back(s%10);
		s/=10;
	}
	if(s) f[z].push_back(s);
}
int main()
{
	cin>>n;
	if(n==0)
	{
		printf("0");
		return 0;
	}
	f[0].push_back(1);
	f[1].push_back(1);
	for(int i=2;i<=n;i++)
		gj_add(i-1,i-2,i);
	for(int i=f[n].size()-1;i>=0;i--)
		printf("%d",f[n][i]);
	return 0;
}
