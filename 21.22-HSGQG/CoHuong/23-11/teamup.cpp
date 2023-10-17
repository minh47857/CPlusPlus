#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 105 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("teamup.inp" , "r" , stdin);
	freopen("teamup.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , d[N][N] , side[N] , f[N] , dp[N];
vector<int> A;
bool Check = true;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	for(int j = 1 ; j <= n ; j++) d[i][j] = 1;
	for(int i = 1 , x ; i <= n ; i++) {
		while(cin >> x) {
			if(x == 0) break;
			d[i][x] = 0;
		}
	}
	memset(side , -1 , sizeof(side));
	for(int i = 1 ; i <= n ; i++) {
		if(side[i] != -1) continue;
		queue<int> Q;
		vector<int> V;
		side[i] = 0 , Q.push(i);
		while(Q.size()) {
			int u = Q.front();
			V.pb(u);
			Q.pop();
			for(int v = 1 ; v <= n ; v++) if(u != v && d[u][v]) {
				if(side[v] == -1) {
					side[v] = side[u] ^ 1;
					Q.push(v);
				}
				else Check &= (side[u] != side[v]);
			}
		}
		int P1 = 0 , P2 = 0;
		for(auto u : V) {
			P1 += (side[u] == 0);
			P2 += (side[u] == 1);
		}
		A.pb(abs(P1 - P2));
	}
	if(!Check) {
		cout <<  "No solution";
		return 0;
	}
	dp[0] = 1;
	for(auto x : A) {
		for(int i = 0 ; i <= N ; i++) f[i] = dp[i] , dp[i] = 0;
		for(int i = 0 ; i <= N ; i++) 
		  if(f[i]) dp[i + x] = 1 , dp[abs(i - x)] = 1;
	}
	for(int i = 0 ; i <= N ; i++) if(dp[i]) {
		cout << i;
		return 0;
	}
}

