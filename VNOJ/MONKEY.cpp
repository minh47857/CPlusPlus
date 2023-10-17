#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int row[4]={1,0,-1,0};
const int col[4]={0,1,0,-1};
long long d[N][N],a[N][N],m,n,u,v,Max=0;

void dfs(int x,int y)
{
	d[x][y]=1;Max++;
	for(int i=0;i<=3;i++) if(a[x+row[i]][y+col[i]]==1&&x+row[i]<=m&&y+col[i]<=n&&d[x+row[i]][y+col[i]]==0&&x+row[i]>=1&&y+col[i]>=1) dfs(x+row[i],y+col[i]);
	
}
int main()
{
	cin>>m>>n>>u>>v;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>a[i][j];
	}
	dfs(u,v);
	if(a[u][v]==0) cout<<0;
	else cout<<Max;
}
