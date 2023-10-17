#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const long long N=1000001;
ll n,res[N],st[4*N],ma;
struct nod
{
	ll fi,se,cs;
}a[N];
bool cmp(nod a, nod b)
{
	return a.fi<b.fi||(a.fi==b.fi&&a.se<=b.se);
}
void file()
{
	//freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void update(int id,int l,int r,int x)
{
	if(l>x||r<x) return ;
	if(l==r) 
	{
		st[id]++;
	//	cout<<l<<" "<<st[id]<<endl;
		return ;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,x);
	update(id*2+1,mid+1,r,x);
	st[id]=st[id*2]+st[id*2+1];
//	cout<<l<<" "<<r<<" "<<st[id]<<endl;
}
int get(int id,int l,int r,int x)
{
	if(l>x) return 0;
	if(r<=x) return st[id];
	int mid=(l+r)/2;
  return get(id*2,l,mid,x)+get(id*2+1,mid+1,r,x);
}
int main()
{
	file();
  cin>>n;
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i].fi>>a[i].se;
  	a[i].cs=i;
  	ma=max(a[i].se,ma);
  }
  sort(a+1,a+n+1,cmp);
 // cout<<endl;
    //for(int i=1;i<=n;i++) cout<<a[i].fi<<" "<<a[i].se<<" "<<a[i].cs<<endl;
  for(int i=1;i<=n;i++) 
  {
  	if(a[i].fi==a[i-1].fi&&a[i].se==a[i-1].se) res[a[i].cs]=res[a[i-1].cs];
  else 	res[a[i].cs]=get(1,1,ma,a[i].se);
  	update(1,1,ma,a[i].se);
  //	cout<<endl;
   } 
  
  for(int i=1;i<=n;i++) cout<<res[i]<<'\n';
}
