#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long N=1000005;
ll n,a[N],m,Max=-1;
void file()
{
	freopen("CATGO.inp","r",stdin);
	freopen("CATGO.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll tinh(ll x)
{
	ll s=0;
	for(int i=1;i<=n;i++) if(a[i]>x) s+=(a[i]-x);
	return s;
}
ll solve(ll d,ll c)
{
	ll g,kq;
	while(d<=c)
	{
		g=(d+c)/2;
	//	cout<<tinh(g)<<" ";
		if(tinh(g)>=m) 
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
	file();
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	cout<<solve(1,Max);
	return 0;
}

