#include<bits/stdc++.h>
using namespace std;
const int nma=1000000;
long long n,check[nma+1],d[nma+1],dp[nma+1],t,x,y;
void sang()
{
	check[1]=1,check[0]=1,d[0]=-1,d[1]=-1;
	for(int i=2;i<=nma/2;i++)
	{
		for(int j=i*2 ;j<nma;j+=i) 
		{
		    d[j]++;
			if(check[i]==0) check[j]=1	;
		}
	}
	for(int i=2;i<=nma;i++)
	{
		dp[i]=dp[i-1];
		if(check[d[i]+2]==0) dp[i]++;
	}
}
int main()
{
	freopen("cprime.inp","r",stdin);
	freopen("cprime.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	sang();
	for(int i=1;i<=t;i++)
	{
		cin>>y>>x;
		cout<<dp[x]-dp[y-1]<<endl;
	}
	return 0;
}
