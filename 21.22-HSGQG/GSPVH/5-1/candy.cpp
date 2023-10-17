#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e5 + 5;
const ll inf = LLONG_MAX / 2;

using namespace std;

void file() {
	freopen("candy.inp" , "r" , stdin);
	freopen("candy.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n;
ll m , A , B , sum[N] , st[4 * N] , pre[N] , dp[N];

void update(int id , int l , int r , int u , ll val) {
	if(l > u || r < u) return;
	if(l == r) {
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , val);
	update(id * 2 + 1 , mid + 1 , r , u , val);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
}

ll get(int id , int l , int r , int u , int v) {
	if(r < u || l > v) return inf;
	if(l >= u && r <= v) return st[id];
	int mid = (l + r) / 2;
	return min(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
}

int main() {
	file();
	cin >> n >> m >> A >> B;
	for(int i = 1 , x ; i <= n ; i++) 
		cin >> x , sum[i] = sum[i - 1] + x;
	for(int i = 1 ; i <= 4 * n ; i++) st[i] = inf;
	int j = 0;
	for(int i = 1 ; i <= n ; i++) {
		while(sum[i] - sum[j + 1] >= m) j++;
		if(sum[i] - sum[j] < m) dp[i] = (m - sum[i]) * B;
		else dp[i] = min(pre[j] + (sum[i] - m) * A , get(1 , 1 , n , j + 1 , i - 1) + (m - sum[i]) * B); 
		update(1 , 1 , n , i , dp[i] + sum[i] * B);
		pre[i] = min(pre[i - 1] , dp[i] - sum[i] * A);
	}
	cout << dp[n];
	return 0;
}
