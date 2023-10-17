#include<bits/stdc++.h>
using namespace std;
const long long N=1000005;
long long x,y,n,s,t,d[N];
queue <long long> Q;
void bfs(long long u)
{
	Q.push(u);
	memset(d,-1,sizeof(d));
	d[u]=0;
	while(Q.size()!=0)
	{
		int k=Q.front();
		cout<<k<<endl;
		Q.pop();
		if((x+k)<=n&&d[x+k]==-1)
		{
			Q.push(x+k);
			d[x+k]=d[k]+1;
		 } 
		 if((k-y)>=1&&d[abs(k-y)]==-1)
		 {
		 	Q.push(k-y);
		 	d[k-y]=d[k]+1;
		 }
	}
}
int main()
{
	cin>>n>>x>>y>>s>>t;
	bfs(s);
	cout<<d[t];
	return 0;
	
}
