#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int a , b , c;
vector<pi> G , Ans;

int Bit(int x , int k) {
	return (x >> k) & 1;
}

void calc(vector<pi>& G) {
	for(int i = 0 ; (1 << i) <= G[1].fi ; i++) {
		if(Bit(G[1].fi , i)) 	G[1].fi -= G[0].fi , Ans.pb({G[1].se , G[0].se});
		else G[2].fi -= G[0].fi , Ans.pb({G[2].se , G[0].se});
		G[0].fi *= 2;
	}
}

void Solve() {
	sort(G.begin() , G.end());
	while(G[0].fi != 0) {
        a = G[0].fi;
        b = G[1].fi;
        c = G[2].fi;
		G[0].fi = a / a;
		G[1].fi = b / a;
		G[2].fi = c / a;
		calc(G);
		G[0].fi = a * G[0].fi;
		G[1].fi = a * G[1].fi + b % a;
		G[2].fi = a * G[2].fi + c % a;
		sort(G.begin() , G.end());
	}
}

void Print() {
	cout << Ans.size() << '\n';
	for(auto x : Ans) cout << x.fi << ' ' << x.se << '\n';
}

int main() {
	cin >> a >> b >> c;
	G.pb({a , 1}) , G.pb({b , 2}) , G.pb({c , 3});
	Solve();	
	Print();
	return 0;
}

