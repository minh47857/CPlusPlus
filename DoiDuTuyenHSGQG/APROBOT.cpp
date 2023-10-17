#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	freopen("APROBOT.inp" , "r" , stdin);
	freopen("APROBOT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

pi a[N];
int n , k , h , res , ans = 0 , bit[N];

void update(int p , int val) {
	for(int i = p ; i <= n ; i += (i & (-i))) bit[i] = max(val , bit[i]);
}

int get(int p) {
	int s = 0;
	for(int i = p ; i >= 1 ; i -= (i & (-i))) s = max(bit[i] , s);
	return s;
}

int main() {
	file();
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++) cin >> a[i].fi , a[i].se = i , a[i].fi = -a[i].fi;
  sort(a + 1 , a + n + 1);
  h = n / k;
  while(h) {
  	for(int i = h * k ; i > h*k - k ; i--) 	a[i].fi = h;
	h--;
  }
  sort(a + 1 , a + n + 1);
//  for(int i = 1 ; i <= n ; i++) cout << a[i].fi << ' ' << a[i].se << '\n';
   for(int i = 1 ; i <= n ; i++) {
   	res = get(a[i].se - 1) + 1;
   	update(a[i].se , res);
   	ans = max(res , ans);
   }
   cout << n - ans ;
  return 0;
}

