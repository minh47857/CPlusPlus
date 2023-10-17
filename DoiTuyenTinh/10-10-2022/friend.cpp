#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("friend.inp" , "r" , stdin);
	freopen("friend.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , B , a[N];
map<int , int> d;
ll ans;

int main() {
	file();
	cin >> n >> B;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) ans += d[B - a[i]] , d[a[i]]++;
	cout << ans;
	return 0;
}

