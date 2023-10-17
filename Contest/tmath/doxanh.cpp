#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7,
		  r[] = {0 , 1 , 0 , -1},
		  c[] = {1 , 0 , -1 , 0};

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct path {
	int u , v , d;
};

int n , m , a[N][N] , dist[N][N][2];
queue<path> Q;

int main() {
	memset(dist , -1 , sizeof(dist));
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			cin >> a[i][j] , a[i][j] = 1 - a[i][j];
	dist[1][1][0] = 0;
	Q.push({1 , 1 , 0});
	while(Q.size()) {
		int u = Q.front().u , v = Q.front().v , d = Q.front().d;
		Q.pop();
		if(dist[u][v][1 - d] == -1) 
				dist[u][v][1 - d] = dist[u][v][d] + 1 , Q.push({u , v , 1 - d});
		if((a[u][v] + d) % 2 == 1) continue;
		for(int i = 0 ; i < 4 ; i++) {
			int nxu = u + r[i] , nxv = v + c[i];
			if(nxu >= 1 & nxu <= n && nxv >= 1 && nxv <= m && dist[nxu][nxv][1 - d] == -1)
				dist[nxu][nxv][1 - d] = dist[u][v][d] + 1 , Q.push({nxu , nxv , 1 - d});
		}
	}
	cout << dist[n][m][a[n][m]];
	return 0;
}
