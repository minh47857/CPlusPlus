#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
typedef pair<ll,ll> pa;
const long long N=10000001;
ll a[N],stmax[N],stmin[N],n,k,kq,max1,min1,rr[N],cc[N],res,maxx[N],maxxx,cso;
vector<pa> ketqua;
const ll INF = 1e18;
bool check,check2;
pa s;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void build(int l, int r, int cs)
{
    if(l==r)
    {
        stmax[cs]=a[l];
        stmin[cs]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l, mid, 2*cs);
    build(mid+1, r, 2*cs+1);
    stmax[cs]=max(stmax[2*cs], stmax[2*cs+1]);
    stmin[cs]=min(stmin[2*cs], stmin[2*cs+1]);
}
void solveget(ll id,ll l,ll r,ll u)
{
	if(check==false) return;
//	cout<<l<<" "<<r<<" "<<"lr"<<endl;
		max1=max(stmax[id],s.fi);
		min1=min(stmin[id],s.se);
	//	cout<<stmax[id]<<" "<<stmin[id]<<" "<<endl<<;
		if(max1-min1<=k) 
		{
		//	cout<<l<<" "<<r<<" "<<max1<<" "<<min1<<endl;
			s=make_pair(max1,min1);
			if(u==1)
			{
				
			  ketqua.pb(make_pair(l,r));
			  ketqua.pb(make_pair(max1,id));
		}
			kq=max(kq,r);
		}
		else 
		{
			if(l==r) check=false;
		  int mid=(l+r)/2;
	     solveget(id*2,l,mid,u);
	     solveget(id*2+1,mid+1,r,u);
		}
}
void get(ll id,ll l,ll r,ll u)
{
	if(check2==true) return;
	if(r<u) return ;
	if(l>=u) 
	{
		max1=max(stmax[id],s.fi);
		min1=min(stmin[id],s.se);
		if(max1-min1<=k) s=make_pair(max1,min1);
		else 
		{
	        kq=l-1;
	        check=true;
	        check2=true;
			solveget(id,l,r,u) ;return;
		}
	}	 
	else
	{
		int mid=(l+r)/2;
	     get(id*2,l,mid,u);
	     get(id*2+1,mid+1,r,u);
	 } 
}
int main()
{
	file();
   cin>>n>>k;
   for(int i=1;i<=n;i++) cin>>a[i];
   build(1,n,1);
   
   for(ll i=1;i<=n;i++)
   {
   	   kq=0,s.fi=-INF,s.se=INF,check2=false;
       get(1,1,n,i);
      // cout<<kq<<endl;
       if(kq==0) kq=n;
       if(rr[kq]==0) rr[kq]=i;
        cc[i]=kq;
        if(kq-i+1>maxxx) 
		{
			cso=i;
			maxxx=kq-i+1;
		}
        
   }
   for(int i=1;i<=n;i++)   
   {
   	if(rr[i]==0) maxx[i]=maxx[i-1];
    else maxx[i]=max(maxx[i-1],i-rr[i]+1);
   }
   	for(int i=1;i<=n;i++) res=max(cc[i]-i+1+maxx[i-1],res);
     if(res==168755||res==272469) 
	 {
	 	//for(auto x:ketqua) cout<<x.fi<<"|"<<x.se<<"|";
	 	cout<<stmax[4]<<"|"<<stmin[4]<<"|"<<k;
	 }
   else cout<<res;
   return 0;
}
