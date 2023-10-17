#include<bits/stdc++.h>
using namespace std;
long long n,k,dp[100005][105],kq=INT_MIN,a[100005];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(a[i]<0&&j!=0) dp[i][j]=dp[i-1][j-1]+a[i];
			if(a[i]>=0) dp[i][j]=dp[i-1][j]+a[i];
			kq=max(kq,dp[i][j]);
		}
	}
	cout<<kq;
    
}
