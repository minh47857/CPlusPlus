#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000005 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	freopen("conference.in" , "r" , stdin);
	freopen("conference.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , k , dem = 0, d[N] , v[N] , a[N] , b[N] , ans[N];
set<int> s[N];


void Solve1() {
	memset(v , -1 , sizeof(v));
	for(int i = m ; i >= 1 ; i--) {
		if(a[i] <= k) {
			if(b[i] <= k) {
				if(v[b[i]] != -1 && v[a[i]] == -1) v[a[i]] = i;
				if(v[a[i]] != -1 && v[b[i]] == -1) v[b[i]] = i;
			}
			else {
				if(v[a[i]] == -1) v[a[i]] = i;
			}
		}
	}
	for(int i = 1 ; i <= k ; i++) cout << v[i] << ' ';
	cout << '\n';
}

void Solve2() {
	for(int i = 1 ; i <= m ; i++) {
		if(a[i] <= k) {
			if(i >= v[a[i]]) d[a[i]] = 1;
			if(b[i] > k) 
			{
			  if(d[b[i]] == 0 && d[a[i]])	d[b[i]] = 1 , dem++;
			  if(d[b[i]]) d[a[i]] = 1;
			}
			if(b[i] <= k) {
				if(i >= v[b[i]]) d[b[i]] = 1;
				if(d[a[i]] == 1) d[b[i]] = 1;
				if(d[b[i]] == 1) d[a[i]] = 1;
			}
		}
		
		else {
			if(d[b[i]] && d[a[i]] == 0) d[a[i]] = 1 , dem++;
			if(d[a[i]] && d[b[i]] == 0) d[b[i]] = 1 , dem++;
		}
	}
	cout << dem << ' ';
	for(int i = k + 1 ; i <= n ; i++) if(d[i]) cout << i << ' ';
	cout << '\n';
}

void Solve3() {
	memset(ans , -1 , sizeof(ans));
   for(int i = 1 ; i <= m ; i++) {
   
   	if(a[i] <= k) {
   	if(v[a[i]] == i || v[a[i]] == -1) s[a[i]].insert(a[i]);
   		if(b[i] > k) {
   			for(auto x : s[a[i]]) if(ans[x] == -1) ans[x] = b[i];
   		    s[a[i]].clear();
		   }
		 else {
		 	if(v[b[i]] == i || v[b[i]] == -1) s[b[i]].insert(b[i]);
		 	for(auto x : s[b[i]]) s[a[i]].insert(x);
		 	for(auto x : s[a[i]]) s[b[i]].insert(x);
		 }
	   }
   }
   for(int i = 1 ; i <= k ; i++) cout << ans[i] << ' ';
}

int main() {
	file();
  cin >> n >> m >> k;
  for(int i = 1 ; i <= m ; i++) {
  	cin >> a[i] >> b[i] ;
    if(a[i] > b[i]) swap(a[i] , b[i]);
  }
  Solve1();
  Solve2();
  Solve3();
  return 0;
}

