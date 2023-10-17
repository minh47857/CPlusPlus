#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 1000001 ;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
} 
  int f[2][5][5][N] , s[N] , m , MOD , n;
  string str;
int cv(int x)
{
	if (x == 3) return -1;
	if (x == 4) return -2;
	if (x == -1) return 3;
	if (x == -2) return 4;
	return x;
}
int calc(int id  , int ok , int Max , int Min)
{
	if (id > m) return 1;
	if(f[ok][Max][Min][id] != -1) return f[ok][Max][Min][id];
	int maxx , minn , cnt = 0; 
  maxx = cv(Max);
  minn = cv(Min);
  if (minn > -2)	cnt = ( cnt + calc(id + 1 , ok | (-1 != s[id]) , cv(max(maxx - 1 , -1)) , cv(min(minn - 1 , -1))) ) % MOD;
  if (maxx < 2 && (ok  || (s[id] == 1))) cnt = (cnt + calc(id + 1 , ok | (1 != s[id]) , cv(max(maxx + 1 , 1)) , cv(min(minn + 1 , 1)))) % MOD ;
   f[ok][Max][Min][id] = cnt;
   return cnt;
}
int main()
{
	file();
  cin >> n >> MOD >> str;
  m = str.size();
  for (int i = 1 ; i <= m ; i++) s[i] = (str[i - 1] == 'L') ? (-1) : 1 ;
  memset(f , -1 , sizeof(f));
  cout << calc(1 , 0 , 0 , 0);
  return 0;
}

