#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 505 ;

void file() {
	freopen("AMN.inp" , "r" , stdin);
	freopen("AMN.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , x , y , a[N][N] , Max = -1 , t , c[N] , r[N];
vector<pair<int , int>> res;

int main() {
	file();
 cin >> n >> m >> x >> y;
 for(int i = 1 ; i <= n ; i++)
   for(int j = 1 ; j <= m ; j++)
   {
     cin >> a[i][j];
     if(a[i][j] > Max) Max = a[i][j] , t = i;
   }
 for(int i = 1 ; i <= m ; i++) res.pb({a[t][i] , i});
 sort(res.begin() , res.end() , greater<pair<int , int>>());
 for(int i = 1 ; i <= m ; i++) c[i] = res[i - 1].se;
 res.clear();
 
 t = c[1];
 for(int i = 1 ; i <= n ; i++) res.pb({a[i][t] , i});
 sort(res.begin() , res.end() , greater<pair<int , int>>());
 for(int i = 1 ; i <= n ; i++) r[i] = res[i - 1].se;
  cout << a[r[x]][c[y]];
}

