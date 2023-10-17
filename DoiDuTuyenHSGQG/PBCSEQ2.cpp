#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const long long N=1000001;
ll n,kq=-N,ma=-N,st[4*N];
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> a,pair<ll,ll>b)
{
    return (a.fi<b.fi) || (a.fi==b.fi&&a.se>b.se);
}
 void update(ll id,ll l,ll r,ll x,ll m)
 {
     if(l>x||r<x) return ;
     if(l==r) 
     {
         st[id]=m;
         return ;
     } 
     int mid=(l+r)/2;
     update(id*2,l,mid,x,m);
     update(id*2+1,mid+1,r,x,m);
     st[id]=max(st[id*2],st[id*2+1]);
 }
ll get(ll id,ll l,ll r,ll x)
 {
     if(r<x) return 0;
     if(l>=x) return st[id]+1;
     ll mid=(l+r)/2;
     return max(get(id*2,l,mid,x),get(id*2+1,mid+1,r,x));
 }

int main()
{
  cin>>n;
  for(ll i=1;i<=n;i++) 
  {
      cin>>a[i].fi>>a[i].se;
      ma=max(ma,a[i].se);
  }
  sort(a+1,a+n+1,cmp);
  for(ll i=1;i<=n;i++)
  {
  ll    res=get(1,1,ma,a[i].se);
      kq=max(res,kq);
      update(1,1,ma,a[i].se,res);    
  }
  cout<<kq;
}

