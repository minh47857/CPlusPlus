#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 3e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("bus.in" , "r" , stdin);
	freopen("bus.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct bus {
	int a , b , x , y;
	bool operator < (const bus&s) const {return y < s.y;}
};

int n , m , q , l[N];
bus s[N];
vector<pi> f[N];

int main() {
	file();
  cin >> n >> m;
  for(int i = 1 , a , b , x , y ; i <= m ; i++) {
  	 cin >> a >> b >> x >> y;
  	 s[i] = {a , b , x , y};
  }
  
  cin >> q;
  for(int i = 1 ; i <= q ; i++) cin >> l[i];
  sort(s + 1 , s + m + 1);
  
  for(int i = 1 ; i <= m ; i++) {
  	int res;
  	if(s[i].a != 1) {
  		int d = 0 , c = f[s[i].a].size() - 1 , g , kq = -1;
  		while(d <= c) {
  			g = (d + c) / 2;
  			if(f[s[i].a][g].fi <= s[i].x) kq = g , d = g + 1;
  			else c = g - 1;
		  }
		if(kq != -1)  res = f[s[i].a][kq].se;
		else res = -1;
	}
	else res = s[i].x;
	if(res != -1) {
		if(f[s[i].b].empty()) f[s[i].b].pb({s[i].y , res});
		else {
			int val = f[s[i].b].back().se;
		    f[s[i].b].pb({s[i].y , max(res , val)});
		}
    }
  }

  for(int i = 1 ; i <= q ; i++) {
  	int d = 0 , c = f[n].size() - 1 , g , kq = -1;
  		while(d <= c) {
  			g = (d + c) / 2;
  			if(f[n][g].fi <= l[i]) kq = g , d = g + 1;
  			else c = g - 1;
		  }
	    if(kq == -1) cout << -1 << '\n';
	      else cout << f[n][kq].se << '\n';
  }
}


