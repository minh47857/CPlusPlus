#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7 , 
	  row[] = {0 , -1 , 1 , 0} , col[] = {1 , 0 , 0 , -1};

using namespace std;

void file() {
	freopen("gotoschool.inp" , "r" , stdin);
	freopen("gotoschool.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct school {
	int x , y , t;
};

int n , m , k , a[N][N] , dp[N][N][2];
pi s , f;
string str[N];
deque<school> dq;
school trace[N][N][2];
vector<school> res;

int Bit(int x , int k) {
	return (x >> k) & 1;
}

void Extract() {
	for(int i = 1 ; i <= n ; i++) {
		int id = 0;
		for(int j = 0 ; j < str[i].size() ; j++) {
			int num;
			if(str[i][j] == '#') num = 62;
			else if(str[i][j] == '$') num = 63;
			else if(str[i][j] <= '9') num = str[i][j] - '0';
			else if(str[i][j] <= 'Z') num = str[i][j] - 'A' + 10;
			else if(str[i][j] <= 'z') num = str[i][j] - 'a' + 36;
			for(int l = 0 ; l <= 5 ; l++) {
				if(id >= m) break;
				a[i][++id] = Bit(num , l);
			}
		}
	}
}

int main() {
	file();
	cin >> n >> m >> k;
	cin >> s.fi >> s.se >> f.fi >> f.se;
	for(int i = 1 ; i <= n ; i++) 
		cin >> str[i];
	Extract();
	memset(dp , 0x3f , sizeof(dp));
		dq.push_back({s.fi , s.se , 0});
		dq.push_back({s.fi , s.se , 1});
		dp[s.fi][s.se][0] = dp[s.fi][s.se][1] = 0;
		while(dq.size()) {
			int x = dq.front().x , y = dq.front().y , t = dq.front().t;
			dq.pop_front();
			for(int i = 0 ; i < 4 ; i++) {
				int nx = x + row[i] , ny = y + col[i] , nt;
				if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny]) continue;
				if(t == 0) 	nt = (nx != x);
				else nt = (ny == y);
				if(dp[nx][ny][nt] > dp[x][y][t] + (nt != t)) {
					trace[nx][ny][nt] = {x , y , t};
					dp[nx][ny][nt] = dp[x][y][t] + (nt != t);
					if(nt == t) dq.push_front({nx , ny , nt});
					else dq.push_back({nx , ny , nt});
				}	
			}
		}
	int ans , x = f.fi , y = f.se , t;
	t = (dp[f.fi][f.se][0] >= dp[f.fi][f.se][1]);
	ans = dp[f.fi][f.se][t];
	if(ans > k) {
		cout << -1;
		return 0;
	}
	cout << ans << '\n';
	while(x != s.fi || y != s.se) {
		res.pb({x , y , t});
		auto s = trace[x][y][t];
		x = s.x , y = s.y , t = s.t;
	}
	res.pb({x , y , t});
	reverse(res.begin() , res.end());
	cout << s.fi << ' ' << s.se << '\n';
	for(int i = 1 ; i < res.size() - 1; i++) {
		if(res[i].t != res[i + 1].t) cout << res[i].x << ' ' << res[i].y << '\n';
	}
	cout << f.fi << ' ' << f.se << '\n';
	return 0;
}
