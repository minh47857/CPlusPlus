#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1002 , MOD = 1e9  , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , A , B ;
pair<int , int> x[15];
namespace sub12 {
	ll dp[15][N][N];
	void solve() {
		dp[0][0][0] = 1;
		for(int i = 1 ; i <= n ; i++) 
		  for(int t1 = 0 ; t1 <= A ; t1++)
		    for(int t2 = 0 ; t2 <= B ; t2++) {
		    	if(x[i].fi > t1 || x[i].se > t2) dp[i][t1][t2] = dp[i - 1][t1][t2];
		    	else dp[i][t1][t2] = (dp[i - 1][t1][t2] + dp[i][t1 - x[i].fi][t2 - x[i].se]) % MOD;
			}
	   cout << dp[n][A][B];
	}
}

namespace sub3 {
	
	ll f[35][55][55] , s1[15] , s2[15];
	
	int Bit(int x , int k) {
		return (x >> k) & 1;
	}
    void gen(int t , int id , int nho1 , int nho2) {
    	for(int i = 0 ; i <= 1 ; i++) {
    		s1[t] = s1[t - 1] + i * x[t].fi;
    		s2[t] = s2[t - 1] + i * x[t].se;
    		if(t == n) {
    		  if((s1[t] + nho1) % 2 == Bit(A , id) && (s2[t] + nho2) % 2 == Bit(B , id)) {
    		  	 (f[id + 1][(s1[t] + nho1) / 2][(s2[t] + nho2) / 2] += f[id][nho1][nho2]) %= MOD ;
			  }	  
			}
			else gen(t + 1 , id , nho1 , nho2);
		}
	}
	
	void solve() {
		f[0][0][0] = 1;
		for(int i = 0 ; i <= 30 ; i++) 
		for(int nho1 = 0 ; nho1 <= 50 ; nho1++)
		for(int nho2 = 0 ; nho2 <= 50 ; nho2++) {
			if(f[i][nho1][nho2]) gen(1 , i , nho1 , nho2 );
		}
		cout << f[31][0][0];
	}
}

int main() {
	file();
  cin >> n >> A >> B;
  for(int i = 1 ; i <= n ; i++) cin >> x[i].fi >> x[i].se;
  if(A <= 1000 && B <= 1000) sub12::solve() ;
   else sub3::solve();
}

