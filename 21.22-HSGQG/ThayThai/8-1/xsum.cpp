#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 105 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , m , a[N][N];

int main() {
	freopen("xsum.inp" , "r" , stdin);
	freopen("xsum.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			vector<int> v;
			for(int l = 1 ; l <= j - 1 ; l++) v.pb(a[i][l]);
			for(int l = 1 ; l <= i - 1 ; l++) v.pb(a[l][j]);
			v.pb(n + m);
			sort(v.begin() , v.end());
			if(v[0] != 0) a[i][j] = 0;
			else {
				for(int x = 0 ; x < v.size() - 1 ; x++) 
					if(v[x] != v[x + 1] - 1) {
						a[i][j] = v[x] + 1;
						break;
					}	
			}
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

