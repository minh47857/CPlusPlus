#include<bits/stdc++.h>
using namespace std;
//dp1 chon dinh thu i
//dp2 khong chon dinh thu i
const long long nmax=100005;
long long ts[nmax],dp1[nmax],dp2[nmax],n;
vector <long long> a[nmax];
void dfs(int u,int pa)
{
	dp1[u]=ts[u];
	for(int i=0;i<a[u].size();i++)
	{
		int et=a[u][i];
		if(et==pa)  continue;
		dfs(et,u);
		dp2[u]+=max(dp1[et],dp2[et]);
		dp1[u]+=(dp2[et]);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ts[i];
	for(int i=1;i<n;i++)
	{
		long long x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	cout<<max(dp1[1],dp2[1]);
	
}
