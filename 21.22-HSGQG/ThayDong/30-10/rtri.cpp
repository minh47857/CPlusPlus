#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pi pair<int , int>

const int N = 3e5 + 5;

void file() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
ll ans = 0;
pi a[N];
unordered_map<int , ll> x , y;

int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se , x[a[i].fi]++ , y[a[i].se]++;
  for(int i = 1 ; i <= n ; i++) ans = ans + (x[a[i].fi] - 1) * (y[a[i].se] - 1);
  cout << ans;
  return 0;
}

