#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const long long N=100005;
long long d[N],n,q,x;
pair<long long ,long long> a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	if(a[i].fi!=a[i-1].fi) d[a[i].se]=i-1;
    	else d[a[i].se]=d[a[i-1].se];
	}
	cin>>q;
	for(int i=1;i<=q;i++) 
	{
		cin>>x;
		cout<<d[x]<<endl;;
	}
}
