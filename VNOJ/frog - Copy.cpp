#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N=1501;
pair < int, pair<int,int> > a[N*N];
multiset< pair < int, pair<int,int> >  > col[N],row[N];
int dp[N][N],in,ou,n,x,y,k;
void updatehang(int u)
{
	for (auto p: row[u] )
	{
		if(p.se.fi!=a[k].fi&&abs(p.se.se-y)>1)   dp[x][y]=max(dp[x][y],p.fi+1);
	}
}
void updatecot(int u)
{
  for(auto p: col[u])	
	{
		if(p.se.fi!=a[k].fi&&abs(p.se.se-x)>1) 	dp[x][y]=max(dp[x][y],p.fi+1);	
	}
}
void updatereal()
{
	        row[x].insert(make_pair(dp[x][y],make_pair(a[k].fi,y)));
			col[y].insert(make_pair(dp[x][y],make_pair(a[k].fi,x)));
		if(row[x].size()>4)	row[x].erase(row[x].begin());
		if(col[y].size()>4)	col[y].erase(col[y].begin());	
}
void solve()
{
	if(x-1>0)   updatehang(x-1);
	if(x+1<=n)  updatehang(x+1);
	if(y-1>0)   updatecot(y-1);
	if(y+1<=n)  updatecot(y+1);
	updatereal();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>in>>ou;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
          cin>> a[n*(i-1)+j].fi;
			a[n*(i-1)+j].se.fi=i;
			a[n*(i-1)+j].se.se=j;
			dp[i][j]=1;
		}
	}
	
	sort(a+1,a+n*n+1);
	
	for(int i=n*n;i>=1;i--)
	{
		x=a[i].se.fi,y=a[i].se.se,k=i;
		solve();
	}
	
	cout<<dp[in][ou];
	return 0;
	
}
