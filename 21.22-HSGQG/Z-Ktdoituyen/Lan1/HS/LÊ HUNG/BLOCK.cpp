#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first 
#define se second
#define FOR(i,x,y) for(int i=x;i<=y;i++)
#define FOD(i,x,y) for(int i=x;i>=y;i--)
const ll N=1e5+5;
const ll MOD=0;
const ll oo=1e15;

int n,k;
ll a[N],st[4*N],dp[N][105];
pair<ll,ll> dp2[N][105];

void build(int id,int l,int r){
	if(l==r){
		st[id]=a[l];
		return;
	}
	
	int mid=(l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	
	st[id]=max(st[2*id],st[2*id+1]);
}

ll get(int id,int l,int r,int u,int v){
	if(r<u || v<l) return -1;
	if(u<=l && r<=v) return st[id];
	
	int mid=(l+r)/2;
	
	return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}

void sub3(){
	
	build(1,1,n);
	
	FOR(i,0,n)
		FOR(j,0,k) dp[i][j]=oo;
	
	dp[0][1]=0;
	FOR(i,1,n)
		FOR(j,1,k){
			if(j==1){
//				cout<<i<<" "<<j<<": ";
//				cout<<dp[i-1][j]<<" "<<get(1,1,n,1,i-1)<<" "<<get(1,1,n,1,i)<<"\n";
				if(i!=1) dp[i][j]=dp[i-1][j]-get(1,1,n,1,i-1)+get(1,1,n,1,i);
				else dp[i][j]=a[1];
				continue;
			}
			FOR(t,j-1,i-1) 
				dp[i][j]=min(dp[t][j-1]+get(1,1,n,t+1,i),dp[i][j]);
		}
	
	cout<<dp[n][k];
}

void sub4(){
	
	FOR(i,0,n)
		FOR(j,0,k) 
			dp2[i][j].fi=oo, dp2[i][j].se=0;

	FOR(i,1,n)
		FOR(j,1,min(k,i)){
			if(j==1){
				if(i!=1){
					if(a[i]>dp2[i-1][j].se){
						dp2[i][j].fi=dp2[i-1][j].fi-dp2[i-1][j].se+a[i];
						dp2[i][j].se=a[i];
					}
					else dp2[i][j].fi=dp2[i-1][j].fi, dp2[i][j].se=dp2[i-1][j].se;
//					cerr<<i<<" "<<j<<": "<<dp2[i][j].fi<<"\n";
				}
				else dp2[i][j].fi=dp2[i][j].se=a[1];
//				cerr<<i<<" "<<j<<": "<<dp2[i][j].fi<<"\n";
				continue;
			}
			dp2[i][j].fi=min(dp2[i][j].fi,dp2[i-1][j-1].fi+a[i]);
			if(dp2[i][j].fi==dp2[i-1][j-1].fi+a[i]) dp2[i][j].se=a[i];
			
			if(a[i]>dp2[i-1][j].se){
				dp2[i][j].fi=min(dp2[i][j].fi,dp2[i-1][j].fi-dp2[i-1][j].se+a[i]);
				if(dp2[i][j].fi==dp2[i-1][j-1].fi+a[i]) dp2[i][j].se=a[i];
			}
			else{
				dp2[i][j].fi=min(dp2[i][j].fi,dp2[i-1][j].fi);
				if(dp2[i][j].fi==dp2[i-1][j-1].fi) dp2[i][j].se=dp2[i-1][j-1].se;
			}
		}
	
	cout<<dp2[n][k].fi<<"\n";
//	FOR(i,1,n){
//		FOR(j,1,min(k,i)) cout<<i<<" "<<j<<": "<<dp2[i][j].fi<<" "<<dp2[i][j].se<<"\n";
//		cout<<"\n";
//	}
}

int main(){
	freopen("BLOCK.inp","r",stdin);
	freopen("BLOCK.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>k;
	FOR(i,1,n) cin>>a[i];
	
	if(n<=100) sub3();
	else sub4();
	
//	cout<<"\n";
//	sub4();
	
	return 0;
}
