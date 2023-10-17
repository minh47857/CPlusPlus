#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e6 + 5 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , MOD , a[N] , Prime[N] , pre[N] , ans = 1;

void sieve() {
	Prime[1] = 1 , pre[1] = 1;
	for(int i = 2 ; i <= sqrt(n) ; i++) {
		if(Prime[i] == 0) 
		   for(int j = i * i ; j <= n ; j += i) {
		   	   if(!pre[j]) pre[j] = i;
		   	   Prime[j] = 1;
		   }
	}
	
	for(int i = 2 ; i <= n ; i++) if(pre[i] == 0) pre[i] = i;
}

int factor(int x) {
	int t = 1 , dem = 1;
	vector<int> res;
	
	while(pre[x] != x) {
		res.pb(pre[x]);
		x = x / pre[x];
	}
	res.pb(x);
//	for(auto x : res) cout << x << ' ';
	//cout <<"|";
	for(int i = 1 ; i < res.size() ; i++) {
		if(res[i] != res[i - 1]) {
			if(dem % 2) t *= res[i - 1];
			dem = 1;
		}
		else dem++;
	}
//	cout << "?";
	if(dem % 2) t *= res[res.size() - 1];
	//cout << x << ' ' << t <<'\n';
	return t;
}
int main() {
	cin >> n >> MOD;
	sieve();
//	cout << "?";
  for(int i = 1 ; i <= n ; i++) a[factor(i)]++;
 // cout << "?";
  for(int i = 1 ; i <= n ; i++) ans = (ans * (a[i] + 1)) % MOD;
  cout << ans;
}

