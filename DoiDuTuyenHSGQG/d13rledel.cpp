#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
string str;
ll k ;
vector<pair <char , ll> > a;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solvemax( vector<pair <char , ll> > st , ll x)
{
	for (int i = 0 ; i < st.size() - 1 && x != 0 ; i++)
	{
	//	cout << st[i].fi << ' ' << st[i + 1].fi << endl;
		if (st[i].fi < st[i + 1].fi) 
		{
		ll	p = min(x , st[i].se);
			st[i].se -= p;
			x -= p;
		  if (st[i].se == 0)	
		  {
		  	st.erase(st.begin() + i) ;
			if (i != 0) i -= 2;
		  }
		}
		else 
	{
			if (st[i].fi == st[i + 1].fi) 
		  {
		  //	cout << i << ' ';
     		st[i].se = st[i].se + st[i + 1].se;
			st.erase(st.begin() + i + 1);
			i--;
		  }
	}
	}
	for (int i = 0 ; i < st.size() - 1 ; i++)
	{
		if (st[i].fi == st[i + 1].fi) 
		  {
     		st[i].se = st[i].se + st[i + 1].se;
			st.erase(st.begin() + i + 1);
			i--;
		  }
	}
	for (int i = st.size() - 1 ; i >= 0 && x != 0; i--)
	{
			ll p = min(x , st[i].se);
			st[i].se -= p;
			x -= p ;
		  if (st[i].se == 0)		st.erase(st.begin() + i) ;
	}
	for (auto x : st) cout << x.fi << x.se;
	cout << '\n';
}
void solvemin( vector<pair <char , ll> > st , ll x)
{
//	cout << "?";
	for (int i = 0 ; i < st.size() - 1 && x != 0 ; i++)
	{
		if (st[i].fi > st[i + 1].fi) 
		{
		ll	p = min(x , st[i].se);
			st[i].se -= p;
			x -= p;
		  if (st[i].se == 0)	
		  {
		  	st.erase(st.begin() + i) ;
			if (i != 0) i -= 2;
		  }
		}
		else 
	{
			if (st[i].fi == st[i + 1].fi) 
		  {
     		st[i].se = st[i].se + st[i + 1].se;
			st.erase(st.begin() + i + 1);
			i--;
		  }
	}
	}
	for (int i = 0 ; i < st.size() - 1 ; i++)
	{
		if (st[i].fi == st[i + 1].fi) 
		  {
     		st[i].se = st[i].se + st[i + 1].se;
			st.erase(st.begin() + i + 1);
			i--;
		  }
	}
//	cout << st.size() << ' ' << x;
//	cout << "?";
	for (int i = st.size() - 1 ; i >= 0 && x != 0; i--)
	{
		ll p = min(x , st[i].se);
			st[i].se -= p;
			x -= p ;
		  if (st[i].se == 0)		st.erase(st.begin() + i) ;
		  //cout << x << ' ' << st.size() << endl;
	}
	//cout << st.size();
	for (auto x : st) cout << x.fi << x.se;
}
int main()
{
	file();
  cin >> k >> str;
   for (ll i = 0 ; i < str.size() ; i++) 
  {
  	char x = str[i];
  	ll res = 0;
  	while (str[i + 1] >= '0' && str[i + 1] <= '9' && i < str.size()) 
  	{
  		res = (res * 10 + (str[i + 1] - '0'));
  		i++;
	}
	a.pb({x , res});
  }
  solvemax(a , k);
  solvemin(a , k);
  return 0;
}

