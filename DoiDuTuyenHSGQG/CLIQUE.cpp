#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N=1000001;
ll n,m,k,a[N],kq=0,d[N];
vector<ll> adj[N];
queue<ll> s;
void file()
{
	//freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll bfs(int u)
{
	ll res=0;
	memset(d,-1,sizeof(d));
	d[u]=0;
	s.push(u);
	while(!s.empty())
	{
		int t=s.front();
		s.pop();	
		for(auto x: adj[t])
		{
			if(d[x]!=-1) continue;
			d[x]=d[t]+1;
			s.push(x);
		}	
	}
	for(int i=u;i<=n;i++) res+=d[i];
	return res;
	
}
int main()
{
	file();
	cin>>n>>m;
	for(int i=1;i<=m;i++) 
	{
		cin>>k;
		for(int j=1;j<=k;j++) 
		{
			cin>>a[j];
			adj[a[j]].pb(i+n);
			adj[i+n].pb(a[j]);
		}
	}
	for(int i=1;i<=n;i++)	kq+=bfs(i);
	cout<<kq/2;
}

