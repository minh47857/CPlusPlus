#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 2e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("pawns.in" , "r" , stdin);
	freopen("pawns.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , Pow[20] , a  = 0 , f[N];
pair<int , int> pre[N];

bool check(vector<int> p) {
	int n1 = 0 , n2 = 0;
	for(auto x : p) {
		if(x == 1) n1++;
		if(x == 2) n2++;
	}
	for(int i = 0 ; i < n1 ; i++) if(p[i] != 1) return false;
	for(int i = n - 1 ; i >= n - n2 ; i--) if(p[i] != 2) return false;
	return true;
}

vector<int > get(int x) {
	vector<int> tmp;
	for(int i = 1 ; i <= n ; i++) tmp.pb(x%3) , x /= 3;
	//reverse(tmp.begin() , tmp.end());
	return tmp;
}

int calc(int x) {
	if(f[x] != -1) return f[x];
	vector<int> res = get(x);
	if(check(res)) return 0;
	int best = inf;
	for(int i = 0 ; i < n ; i++) {
		int tmp =inf , P = 0;
		
		if(res[i] == 1) {
			if(i > 0 && res[i - 1] == 0) P = x - res[i] * Pow[i] + res[i] * Pow[i - 1] , tmp = 1 + calc(P) ;
			if(i > 1 && res[i - 1] != 0 && res[i - 2] == 0)P = x - res[i] * Pow[i] + res[i] * Pow[i - 2] , tmp = 1 + calc(P) ;
		}
		
		if(res[i] == 2) {
			if(i < n - 1 && res[i + 1] == 0) P = x - res[i] * Pow[i] + res[i] * Pow[i + 1] , tmp = 1 + calc(P) ;
			if(i < n - 2 && res[i + 1] != 0 && res[i + 2] == 0) P = x - res[i] * Pow[i] + res[i] * Pow[i + 2] , tmp = 1 + calc(P) ;
		}
		
		if(res[i] != 0) {
			if(tmp < best) pre[x].fi = P , pre[x].se = i + 1 , best = tmp ;// cout << x << ' ' << pre[x].fi << ' ' << pre[x].se << '\n';
		}
	}
	f[x] = best;
	return best;
}

int main() {
	file();
	Pow[0] = 1;
    for(int i = 1 ; i <= 13 ; i++) Pow[i] = Pow[i - 1] * 3;
    memset(f , -1 , sizeof(f));
	cin >> n;
	for(int i = 0 , x ; i < n ; i++) cin >> x , a = a + Pow[i] * x;
    cout << calc(a) << '\n';
    while(pre[a].fi != 0) {
    	cout << pre[a].se << ' ';
    	a = pre[a].fi;
	}
}

