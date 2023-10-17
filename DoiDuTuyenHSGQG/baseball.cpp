#include<bits/stdc++.h>
using namespace std;
long long dem=0,a[1005],t;
long long tknp1(long long l,long long r,long long k)
{
	long long d=l,c=r,g,kq=0;
	while(d<=c)
	{
		g=(d+c)/2;
		if(a[g]>=k)
		{
			kq=g;
			c=g-1;
		}
		else d=g+1;
	}
	return kq;
}
long long tknp2(long long l,long long r,long long k)
{
	long long d=l,c=r,g,kq=0;
	while(d<=c)
	{
		g=(d+c)/2;
		if(a[g]<=k)
		{
			kq=g;
			d=g+1;
		}
		else c=g-1;
	}
	return kq;
}

int main()
{
	freopen("baseball.inp","r",stdin);
	freopen("baseball.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(long long i=1;i<=t;i++) cin>>a[i];
	sort(a+1,a+t+1);
	for(long long i=2;i<t;i++)
	{
		for(long long j=1;j<i;j++)
		{
			long long x=a[i]-a[j];
			long long m=tknp1(i+1,t,a[i]+x);
			long long n=tknp2(i+1,t,a[i]+2*x);
			if(m==0||n==0) continue;
			dem+=(n-m+1);
		}
	}
	cout<<dem;
	
}
