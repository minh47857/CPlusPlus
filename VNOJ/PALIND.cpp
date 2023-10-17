#include<bits/stdc++.h>
using namespace std;
const long long MODD = 123456789;
char a[51][51];
long long dp[51][51][51][51],n,kq=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>a[i][j];
	if(a[1][1]!=a[n][n])
	{
		cout<<"0";return 0;
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=n;k>=1;k--)
	for(int l=n;l>=1;l--)
	{
		if(i==1&&j==1&&k==n&&l==n) dp[i][j][k][l]=1;
		else 
		{
		   if(a[i][j]==a[k][l])	dp[i][j][k][l]=(dp[i][j][k][l]+dp[i-1][j][k+1][l]+dp[i-1][j][k][l+1]+dp[i][j-1][k+1][l]+dp[i][j-1][k][l+1])%MODD;
		}
		
	}
	
	for(int i=1;i<=n;i++)	kq=(kq+dp[i][n-i+1][i][n-i+1])%MODD;
	
	cout<<kq;
	return 0;
	
	
}
