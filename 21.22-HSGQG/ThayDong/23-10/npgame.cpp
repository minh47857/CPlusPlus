#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 505;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n1 , n2 , m , vis[N] , t = 0 , r[N] , l[N] , ans = 0;
vector<int> G[N] , H[N];
string res1 , res2;

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
  cin >> n1 >> n2 >> m;
  for(int i = 1 , u , v ; i <= m ; i++) cin >> u >> v , G[u].pb(v) , H[v].pb(u);
  for(int i = 1 ; i <= n1 ; i++) {
  	t++;
  	ans += findMatch(i);
  }
  for(int i = 1 ; i <= n1 ; i++) {
  	t++;
  	if(!r[i] || visit1(r[i])) res1 += 'P';
  	else res1 += 'N';
  }
  for(int i = 1 ; i <= n2 ; i++) {
  	t++;
  	if(!l[i] || visit2(l[i])) res2 += 'P';
  	else res2 += 'N';
  }
  cout << res1 << '\n' << res2;
  return 0;
}

