#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 105 , M = 1e5 + 5 , inf = 1e9;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct matrix {
	int s[N][N];
};

int n , t , m , ans , a[N] , pos[M];
vector<int> v;

matrix newone(matrix x) {
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= m ; j++)
			x.s[i][j] = -inf; 
	return x;
}

matrix mul(matrix a , matrix b) {
	matrix c;
	c = newone(c);
	for(int i = 1 ; i <= m ; i++)
		for(int j = i ; j <= m ; j++) 
			for(int k = i ; k <= j ; k++)
				if(min(a.s[i][k] , b.s[k][j]) != -inf)
					c.s[i][j] = max(c.s[i][j] , a.s[i][k] + b.s[k][j]);
	return c;
}

matrix Pow(matrix x , int T) {
	if(T == 1) return x;
	matrix tmp = Pow(x , T / 2);
	tmp = mul(tmp , tmp);
	if(T % 2) return mul(tmp , x);
	else return tmp;
}

int main() {
	file();
	cin >> n >> t;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , v.pb(a[i]);
	sort(v.begin() , v.end());
	v.erase(unique(v.begin() , v.end()) , v.end());
	m = v.size();
	for(int i = 0 ; i < m ; i++) pos[v[i]] = i + 1;
	matrix f;
	f = newone(f);
	for(int i = 1 ; i <= n ; i++) {
		int p = pos[a[i]];
		for(int j = 1 ; j <= p ; j++) 
			for(int k = p ; k >= j ; k--)
				if(f.s[j][k] != -inf) f.s[j][p] = max(f.s[j][p] , f.s[j][k] + 1);
		f.s[p][p] = max(f.s[p][p] , 1);
	}
	for(int i = m - 1 ; i >= 1 ; i--)
		for(int j = i ; j <= m ; j++)	
			 f.s[i][j] = max(f.s[i][j] , f.s[i + 1][j]);
	f = Pow(f , t);
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= m ; j++)
			ans = max(ans , f.s[i][j]);
	cout << ans;
	return 0;
}

