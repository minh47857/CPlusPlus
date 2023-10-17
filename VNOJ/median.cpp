#include<bits/stdc++.h>
using namespace std;
int dem=0,n,k,d1[100005],d2[100005],a[100005],dp[100005],m;
int main()
{
	cin>>n>>k;
	d1[0]++;
	for(int i=1;i<=n;i++)
	{
		 cin>>a[i];
		 if(a[i]==k) m=i;
	 }
	for(int i=1;i<m;i++)
	{
		dp[i]=dp[i-1];
		if(a[i]>k) dp[i]+=1;
		if(a[i]<k) dp[i]-=1;
	    if(dp[i]>=0)	d1[dp[i]]++;	
	   else  d2[abs(dp[i])]++;
	}
	for(int i=m;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(a[i]>k) dp[i]+=1;
		if(a[i]<k) dp[i]-=1;
		if(dp[i]>=0) dem+=d1[dp[i]];
	   else  	dem+=d2[abs(dp[i])];
	   
	}
	cout<<dem;	
}
