#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 205 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , s[5][N] , a[5][N];
vector<pair<int , pair<int , int>>> V;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= 2 ; i++)
	  for(int j = 1 ; j <= n ; j++)
	  	cin >> a[i][j] , V.pb({-a[i][j] , {i , j}});
	sort(V.begin() , V.end());
    if (n == 2) {
		int res = max({a[1][1] + a[1][2], a[1][2] + a[2][2], a[2][2] + a[2][1], a[2][1] + a[1][1]});
		if (a[1][1] + a[1][2] == res) cout << "0";
		else if (a[1][2] + a[2][2] == res) cout << "1\n1";
		else if (a[2][2] + a[2][1] == res) cout << "2\n1 1";
		else cout << "3	\n1 1 1";
		return 0;
	}
	for(int i = 0 ; i < n ; i++)
		s[V[i].se.fi][V[i].se.se] = 1;
	while(1) {
		int p1 = 0 , p2 = 0;
		for(int i = 1 ; i <= n ; i++) {
			if(!s[1][i]) p1 = i;
			if(s[2][i]) p2 = i;
		}
		if(!p1) break;
		if(p1 == p2) {
			int b1 , b2 , b3 , b4 , b5 , b6;
			if(p1 == 1) {
				ans.pb(2) , ans.pb(2) , ans.pb(2) , ans.pb(1) , ans.pb(2) , ans.pb(1) , ans.pb(2);
				b1 = s[1][1] , b2 = s[1][2] , b3 = s[1][3];
				b4 = s[2][1] , b5 = s[2][2] , b6 = s[2][3];
				s[1][1] = b2 , s[1][2] = b3 , s[1][3] = b4;
				s[2][1] = b5 , s[2][2] = b6 , s[2][3] = b1;
			}
			else if(p1 == n) {
				ans.pb(n - 2) , ans.pb(n - 1) , ans.pb(n - 2) , ans.pb(n - 2) , ans.pb(n - 2);
				b1 = s[1][n - 2] , b2 = s[1][n - 1] , b3 = s[1][n];
				b4 = s[2][n - 2] , b5 = s[2][n - 1] , b6 = s[2][n];
				s[1][n - 2] = b1 , s[1][n - 1] = b2 , s[1][n] = b6;
				s[2][n - 2] = b5 , s[2][n - 1] = b3 , s[2][n] = b4;
			}
			else {
				ans.pb(p1 - 1) , ans.pb(p1) , ans.pb(p1 - 1) , ans.pb(p1) , ans.pb(p1) , ans.pb(p1);
				b1 = s[1][p1 - 1] , b2 = s[1][p1] , b3 = s[1][p1 + 1];
				b4 = s[2][p1 - 1] , b5 = s[2][p1] , b6 = s[2][p1 + 1];
				s[1][p1 - 1] = b3 , s[1][p1] = b1 , s[1][p1 + 1] = b5;
				s[2][p1 - 1] = b2 , s[2][p1] = b4 , s[2][p1 + 1] = b6;
			}
		}
		if(p1 < p2) {
			for (int j = p2 - 1; j >= p1; --j) {
				ans.push_back(j);
				int tmp = s[2][j];
				s[2][j] = s[1][j];
				s[1][j] = s[1][j + 1];
				s[1][j + 1] = s[2][j + 1];
				s[2][j + 1] = tmp;
			}
		}
		if(p1 > p2) {
			for (int j = p2; j <= p1 - 1; ++j) {
				ans.push_back(j) ; ans.push_back(j) ; ans.push_back(j);
				int tmp = s[2][j];
				s[2][j] = s[2][j + 1];
				s[2][j + 1] = s[1][j + 1];
				s[1][j + 1] = s[1][j];
				s[1][j] = tmp;
			}
		}
	}
	cout << ans.size() << '\n';
	for(auto x : ans)
		cout << x << ' ';
	return 0;
}

