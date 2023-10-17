#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int nx[N][3] , t , n , a[N] , cnt;
 
int Bit(int x , int k) {
	return (x >> k) & 1;
}

void Insert(int x) {
  int cur = 0;
  for(int i = 30 ; i >= 0 ; i--) {
  	if(nx[cur][Bit(x , i)] == -1) nx[cur][Bit(x , i)] = ++cnt;
  	cur = nx[cur][Bit(x , i)];
  }
}

int Get(int x) {
	int cur = 0 , res = 0;
	for(int i = 30 ; i >= 0 ; i--) {
		if(nx[cur][1 ^ (Bit(x , i))] != -1) res += (1 << i) , cur = nx[cur][1 ^ (Bit(x , i))] != -1;
		else cur = nx[cur][Bit(x , i)];
	}
	return res;
}

void solve() {
	int ans = 0;
	cnt = 0;
	memset(nx , -1 , sizeof(nx));
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		Insert(a[i]);
		ans = max(ans , Get(a[i]));
	}
	cout << ans << '\n';
}

int main() {
  cin >> t;
  while(t--) {
  	solve();
  }
}

