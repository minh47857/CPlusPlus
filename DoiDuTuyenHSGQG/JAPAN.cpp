#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
typedef pair<ll,ll> pa;
const long long N=1000001;
ll n,m,k,bit[N],t,ans;
pair<ll,ll> a[N];
void update(int x){
	for( ;x<=m;x+=(x&(-x))) bit[x]++;
}
void get(int x){
	
	for(   ;x>0 ;x-=(x&(-x))) ans+=bit[x];
}
int main(){
	 ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
   cin>>t;
  for(int j=1;j<=t;j++)
  {
  	memset(bit,0,sizeof(bit));
	cin>>n>>m>>k;
     ans=0;
	
	for(int i=1;i<=k;i++) cin>>a[i].fi>>a[i].se;
	sort(a+1,a+k+1);
	for(ll i=k;i>=1;i--)
	{
		get(a[i].se-1);
		update(a[i].se);
	}
	cout<<"Test case "<<j<<": "<<ans<<endl;
  }
  
   
   
}

