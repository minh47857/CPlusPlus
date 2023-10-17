#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const long long N=500009;
long long n,d2[N],d1[N],sum=0;
pair<long long,long long> a[N];
int main()
{
	freopen("POPUST.inp","r",stdin);
	freopen("POPUST.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].se>>a[i].fi;
	sort(a+1,a+n+1);
	d1[0]=LLONG_MAX,d2[n+1]=LLONG_MAX;
	for(int i=1;i<=n;i++)    d1[i]=min(d1[i-1],a[i].se-a[i].fi);
	for(int i=n;i>=1;i--)	d2[i]=min(a[i].se,d2[i+1]);
	for(int k=1;k<=n;k++)  
	{
		sum+=a[k].fi;
		cout<<min(sum+d1[k],sum-a[k].fi+d2[k])<<endl;
	  }  
	return 0;
	
}
