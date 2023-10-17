#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const long long N=305;
int t ;
void file()
{
	freopen("dweight.inp","r",stdin);
	freopen("dweight.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
  cin>>t;
  while(t--)
  {
  	ll n;
	pair<ll,ll> a[N];
	set<pair<ll,ll>> s;
  	cin>>n;
  	for(int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
  	for(int i=1;i<=n;i++)
  	{
  		for(int j=i+1;j<=n;j++)
  		{
  			ll x1,x2,uoc;
  			if(a[i].fi==a[j].fi) continue;
  			x1=(a[i].se - a[j].se) ;
			x2 = (a[j].fi - a[i].fi);
		    uoc = __gcd(x1,x2);
		    x1/= uoc;
		    x2/= uoc;
  			if((x1>0&&x2>0)||(x1<0&&x2<0) ) s.insert({x1,x2});
		  }
	  }
	  cout<<s.size()+1<<endl;
  }
}

