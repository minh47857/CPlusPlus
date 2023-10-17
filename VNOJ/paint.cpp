#include<bits/stdc++.h>
using namespace std;
const int nma=100005;
int colour[nma],name[nma],f[nma],g[nma],n,dkinh=0;
vector<int> child[nma],a[nma],b[nma];
void dfs(int s,int k)
{
	for(int i=0;i<a[s].size();i++)
	{
		if(a[s][i]==k) continue;
		if(colour[a[s][i]]==colour[s])  name[a[s][i]]=name[s];	 
		else 
		{
			b[name[s]].push_back(name[a[s][i]])  ;
			b[name[a[s][i]]].push_back(name[s])  ;	
		}
		dfs(a[s][i],s);
	}
}
void duongkinh(int u,int pa)
{
	for(int i=0;i<b[u].size();i++)
	{
		if(b[u][i]==pa) continue;
		duongkinh(b[u][i],u);
		child[u].push_back(f[b[u][i]]);
	}
	sort(child[u].begin(),child[u].end());
	f[u]=1;g[u]=1;
   if(child[u].size()!=0)	f[u]+=child[u].back();
   if(child[u].size()>=2)  g[u]+=(child[u].back()+child[u][child[u].size()-2]);
	 dkinh=max(dkinh,max(g[u],f[u]));
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>colour[i];
		name[i]=i;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	duongkinh(1,0);
	cout<<dkinh/2;
}
