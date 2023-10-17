#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 5000005 , MOD = 1e9 + 7 , inf = 1e15;
vector <ll> bit;
char type;
ll n , cnt , x , num[N][5] , nx[N][5];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void insert_remove(ll p)
{
	ll cur = 0;
	for  (ll i = 0 ; i <= 30 ; i++)
	{
		if (nx[cur][bit[i]] == -1) nx[cur][bit[i]] = ++ cnt;
		num[cur][bit[i]] += p;
		ll newcur = cur;
		cur = nx[cur][bit[i]];
		if (num[newcur][bit[i]] == 0) nx[newcur][bit[i]] = -1;	
	}
}
ll Xor ()
{
	ll cur = 0 , ans = 0;
	for (ll i = 0 ; i <= 30 ; i++)
	{
		if (nx[cur][1 - bit[i]] != -1)
		{
			cur = nx[cur][1 - bit[i]];
			ans += (1 << (30 - i));
		}
		else	cur = nx[cur][bit[i]];
	}
	return ans;
}
int main()
{
	file();
  cin >> n ;
  cnt = 0;
  memset (nx , - 1 , sizeof (nx));
  for (int i = 30 ; i >= 0 ; i--) bit.pb(0);
  insert_remove(1);
  for (ll i = 1 ; i <= n ; i++)
  {
  	cin >> type >> x;
  	ll a = x;
  	bit.clear();
  	for (ll i = 30 ; i >= 0 ; i--)
	{
		if (x >= (1 << i)) 
		{
			x -= (1 << i);
			bit.pb(1);
		}
		else bit.pb(0);
	}
	//cout << x << endl;
//	for (ll i = 0 ; i <= 30 ; i++) cout << bit[i];
	//cout <<endl;
  	if (type == '+') insert_remove(1);
  	if (type == '-') insert_remove(-1);
  	if (type == '?') cout << Xor() << '\n';
  }
  non bo me doi code
  Non vcl
  Im lmang
  Non vcl
  Noonnnnnnnn
}

