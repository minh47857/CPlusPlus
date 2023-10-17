#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005 , MOD = 1e9 + 7 , inf = 1e15;
void file()
{
	freopen("GEN.inp" , "r" , stdin);
	freopen("GEN.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m[N] , d = 1 , c , g , kq = -1 , base = 37 ;
string s[N];

bool check(int x)
{
	map<ll , ll> dd;
	for(int i = 1 ; i <= n ; i++) 
	{
		ll Hash = 0;
		if(m[i] < x) continue;
		for(int j = 1 ; j <= x ; j++) Hash = (Hash * base + s[i][j] - 'a' + 1) % MOD;
		if(dd[Hash] != 0) 
		{
		//	if(x >= 30) cout << Hash << ' ' << i << ' ' << dd[Hash] << '\n';
			return false;
		}
		
		dd[Hash] = 1;
	}
	return true;
}

int main()
{
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> s[i] , c = max(int(s[i].size()) , c) , s[i] = ' ' + s[i] , m[i] = s[i].size() - 1 ;
 // sort(s + 1 , s + n + 1);
 // for(int i = 1 ; i <= n ; i++) cout << s[i] << '\n';
  while(d <= c)
  {
  	g = (d + c) / 2;
  	//cout << g << ' ';
  	if(check(g)) kq = g , c = g - 1;
  	else d = g + 1;
  }
 if(kq != -1) cout << kq;
 else cout << c + 1;
 return 0;
}

