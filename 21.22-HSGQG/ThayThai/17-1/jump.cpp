#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , h[N];
pi p[2][N][35];
deque<int> dq;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> h[i];
	for(int i = 1 ; i <= n ; i++) {
		while(dq.size() && h[i] < h[dq.back()]) dq.pop_back();
		if(dq.size()) p[0][i][0] = {0 , dq.back()};
		else p[0][i][0] = {1 , i};
		dq.pb(i);
	}
	dq.clear();
	for(int i = n ; i >= 1 ; i--) {
		while(dq.size() && h[i] > h[dq.back()]) dq.pop_back();
		if(dq.size()) p[1][i][0] = {1 , dq.back()};
		else p[1][i][0] = {0 , i};
		dq.pb(i);
	}
	for(int l = 1 ; l <= 30 ; l++) {
		for(int i = 1 ; i <= n ; i++) {
			pi x = p[0][i][l - 1];
			p[0][i][l] = p[x.fi][x.se][l - 1];
			x = p[1][i][l - 1];
			p[1][i][l] = p[x.fi][x.se][l - 1];
		}
	}
	for(int i = 1 ; i <= m ; i++) {
		int u , len , v;
		cin >> u >> len;
		v = 1;
		for(int j = 31 ; j >= 0 ; j--) 
			if(len >= (1LL << j)) {
				len -= (1 << j);
				pi x = p[v][u][j];
				u = x.se , v = x.fi;
			}
		cout << u << '\n';	
	}
	return 0;
}


