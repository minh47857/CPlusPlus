#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;
ll n , h[N] , dp[N];
void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	cin >> n;
   for(int i = 1 ; i <= n ; i++) cin >> h[i] , dp[i] = inf;
   dp[1] = 0;
   for(int i = 1 ; i < n ; i++) {
   	dp[i + 1] = min(dp[i + 1] , dp[i] + abs(h[i + 1] - h[i]));
   	dp[i + 2] = min(dp[i + 2] , dp[i] + abs(h[i + 2] - h[i]));
   }
   cout << dp[n]; 
}

