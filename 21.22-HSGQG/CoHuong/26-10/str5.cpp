#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("str5.inp" , "r" , stdin);
	freopen("str5.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int ans , d , c = N , n;
ll Pow[N] , Hash1[10][N] , Hash2[10][N] , base = 31;
string s1[10] , s2[10];

ll Get(int l , int r , ll Hash[10][N] , int i) {
	return (Hash[i][r] - Hash[i][l - 1] * Pow[r - l + 1] + MOD * MOD) % MOD;
}

bool st(ll val , int id , int x) {
	for(int i = 1 ; i <= s1[id].size() - x; i++) 
	   if(Get(i , i + x - 1 , Hash1 , id) == val || Get(i , i + x - 1 , Hash2 , id) == val) return true;
    return false;
}

bool ok(ll val , int x) {
   for(int i = 2 ; i <= n ; i++) if(!st(val , i , x)) return false;
   return true;
}

bool check(int x) {
	for(int i = 1 ; i <= s1[1].size() - x; i++) 
	  if(ok(Get(i , i + x - 1 , Hash1 , 1) , x) || ok(Get(i , i + x - 1 , Hash2 , 1) , x)) return true;
	return false;
}

int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) {
  	cin >> s1[i];
  	c = min(int (s1[i].size()) , c);
	s1[i] = s1[i] + s1[i], 
	s2[i] = s1[i];
	reverse(s2[i].begin() , s2[i].end());
	s1[i] = ' ' + s1[i];
	s2[i] = ' ' + s2[i];
  }
  Pow[0] = 1;
  for(int i = 1 ; i <= 1000 ; i++) Pow[i] = (Pow[i - 1] * base) % MOD;
  for(int i = 1 ; i <= n ; i++) {
  	for(int j = 1 ; j < s1[i].size() ; j++) Hash1[i][j] = (Hash1[i][j - 1] * base + s1[i][j] - 'a' + 1) % MOD;
  	for(int j = 1 ; j < s2[i].size() ; j++) Hash2[i][j] = (Hash2[i][j - 1] * base + s2[i][j] - 'a' + 1) % MOD;
  }
  while(d <= c) {
  	int g = (d + c) / 2;
  	if(check(g)) d = g + 1 , ans = g;
  	else c = g - 1;
  }
  cout << ans;
}

