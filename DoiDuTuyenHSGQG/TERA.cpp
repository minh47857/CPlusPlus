#include<bits/stdc++.h>
using namespace std;
const long long N=1005;
long long a[N],b[N],c[N],d[N],s=0,n,x;
map <long long,long long> sum;
int main()
{
	freopen("TERA.inp","r",stdin);
	freopen("TERA.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>d[i];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)	 sum[a[i]+b[j]]++;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		    if(c[i]+d[j]<=x)	 s+=sum[x-c[i]-d[j]];
				
		
		cout<<s;
		return 0;
}
