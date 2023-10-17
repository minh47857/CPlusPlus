#include<bits/stdc++.h>
using namespace std;
int n,q,vs[27],d[27][27];
string s[500005];
queue<int> Q;
int bfs(int u,int v)
{
	int kq=INT_MAX;
	memset(vs,0,sizeof(vs));
	for(int j=0;j<s[u].size();j++)	
	{
	  Q.push((s[u])[j]-96);
	  vs[(s[u])[j]-96]=1;	
	}
	while(!Q.empty())
	{
		int k=Q.front();
		Q.pop();
		for(int j=1;j<=26;j++)
		{
			if(vs[j]!=0||d[k][j]==0) continue;
			vs[j]=vs[k]+1;
			Q.push(j);
		}
	}
	for(int j=0;j<s[v].size();j++)	if(vs[(s[v])[j]-96]!=0) kq=min(kq,vs[(s[v])[j]-96]);
	if(kq==INT_MAX) return -1;
	return kq+1;
	
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i].size()-1;j++)
		{
			for(int k=j+1;k<s[i].size();k++)
			{
				d[(s[i])[j]-96][(s[i])[k]-96]=1;
				d[(s[i])[k]-96][(s[i])[j]-96]=1;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
	int x,y;	cin>>x>>y;
	   	cout<<bfs(x,y)<<endl;
	}
}
