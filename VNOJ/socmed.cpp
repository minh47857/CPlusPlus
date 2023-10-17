#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 201 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pair<string , string> s[N];
int n , k , d[N];
int main()
{
	file();  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> s[i].fi >> s[i].se;
  cin >> k;
  for (int i = 1 ; i <= k ; i++)
  {
  	string x , y;
  	cin >> x >> y;
  	for (int j = 1 ; j <= n ; j++) if (s[j].fi == x && s[j].se == y) d[j]++;
  }
  for (int i = 1 ; i <= n ; i++) cout << d[i] << ' ';
  return 0;
}

