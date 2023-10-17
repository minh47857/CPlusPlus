#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 2e5 , MOD = 1e9 + 7 , inf = 1e15;
ll n , h[N] , dp[N] , k;
void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	cin >> n >> k;
   for(int i = 1 ; i <= n ; i++) cin >> h[i] , dp[i] = inf;
   dp[1] = 0;
   for(int i = 1 ; i < n ; i++) {
   	for(int j = i + 1 ; j <= min(n , i + k) ; j++) 	dp[j] = min(dp[j] , dp[i] + abs(h[j] - h[i]));
   }
   cout << dp[n]; 
}

