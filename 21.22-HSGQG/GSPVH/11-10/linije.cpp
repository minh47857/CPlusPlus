#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 505;

void file() {
	freopen("linije.inp" , "r" , stdin);
	freopen("linije.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m , vis[N] , t = 0 , r[N] , l[N] , ans = 0 , d1[N] , d2[N];
vector<int> G[N] , H[N] , X , Y;
bool ok = false;

bool findMatch(int u) {
	if(vis[u] == t) return false;
	vis[u] = t;
	for(auto v : G[u]) 
		if(!l[v] || findMatch(l[v])) {
			l[v] = u , r[u] = v;
			return true;
		}
	return false;
}

bool visit1 (int u){
	if(vis[u] == t) return false;
	vis[u] = t;
	for(auto v : H[u]) 
		if(!r[v] || visit1(r[v])) 	return true;
	return false;
}

bool visit2 (int u){
	if(vis[u] == t) return false;
	vis[u] = t;
	for(auto v : G[u]) 
		if(!l[v] || visit2(l[v])) 	return true;
	return false;
}

int main() {
	file();
  cin >> m;
  for(int i = 1 , u , v ; i <= m ; i++) {
  	cin >> u >> v ;
    G[u].pb(v) , H[v].pb(u);
    if(!d1[u]) d1[u] = 1 , X.pb(u);
    if(!d2[v]) d2[v] = 1 , Y.pb(v);
  }
  for(auto i : X) {
  	t++;
  	ans += findMatch(i);
  }
  for(auto i : X) {
  	t++;
  	ok |= (!r[i] || visit1(r[i]));
  }
  for(auto i : Y) {
  	t++;
  	ok |= (!l[i] || visit2(l[i]));
  }
  cout << ((ok) ? "Tanya" : "Antonina");
  return 0;
}

