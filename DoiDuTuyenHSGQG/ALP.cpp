#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int,int>

const int N = 1002 , inf = 1e9;

int n , m , t , d[N][N]; 
ll s1 = 0 , s2 = 0;
string str;
vector<int> adj[N];
priority_queue< pi , vector<pi> , greater<pi> > Q;

void Dijkstra(int s) {
	d[s][s] = 0;
	Q.push({0 , s});
	while(!Q.empty()) {
		int u = Q.top().se , du = Q.top().fi;
		Q.pop();
		if(du != d[s][u]) continue;
		for(auto v : adj[u]) {
			int  w = 1 + ((str[v] == str[s]) ? 0 : t);
			if(d[s][v] > du + w) d[s][v] = du + w , Q.push({du + w , v});
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  cin >> n >> m >> t >> str;
  str = ' ' + str;
  for(int i = 1 , u , v ; i <= m ; i++) {
  	cin >> u >> v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
      d[i][j] = inf;
  for(int i = 1 ; i <= n ; i++) Dijkstra(i);
  for(int i = 1 ; i <= n ; i++)
   for(int j = i + 1 ; j <= n ; j++)
    if(str[i] == str[j]) {
    	if(str[i] == 'Y') s1 += d[i][j];
    	else s2 += d[i][j];
	}
	cout << s2 << ' ' << s1 ;
	return 0;
}

