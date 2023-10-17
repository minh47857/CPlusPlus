#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define vc vector<pair <char , int>>  
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;

void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 string s;
 
vc inp(string str)
{
	vc ans;
	for (int i = 0 ; i < str.size() ; i++) 
  {
  	char x = str[i];
  	int res = 0;
  	while (str[i + 1] >= '0' && str[i + 1] <= '9' && i < str.size()) 
  	{
  		res = res * 10 + (str[i + 1] - '0');
  		i++;
	}
	ans.pb({x , res});
  }
  return ans;
}

vc Plus(vc a , vc b)
{
	if (!b.size()) return a;
	if (!a.size()) return b;
	vc res = a;
	res.pop_back();
	if (a[a.size() - 1].fi == b[0].fi) res.pb({b[0].fi , a[a.size() - 1].se + b[0].se});
	else res.pb(a[a.size() - 1]) , res.pb(b[0]);
	for (int i = 1 ; i < b.size() ; i++) res.pb(b[i]);
	return res;
}

vc Copy(vc a , ll l , ll r)
{
	vc ans;
	if (l > r) return ans;
	ll dem = 0;
	for (int i = 0 ; i < a.size() ; i++)
	{
		dem += a[i].se;
		if (ans.size() == 0 && dem >= l) 
		{
			if (dem < r) ans.pb({a[i].fi , dem - l + 1});
			else 
			{
				ans.pb({a[i].fi , r - l + 1});
				break;
			}
		}
		else 
		{
				if (dem >= l && ans.size() != 0)
		{
		 if (dem < r) ans.pb(a[i]);
		 else 
		 {
		 	ans.pb({a[i].fi , r - dem + a[i].se});
		 	break;
		 }
	    }
		}
	
	}
	return ans;
}

void solve1()
{
	string str1 , str2;
	vc a , b;
	cin >> str1 , a =  inp(str1);
	cin >> str2 , b =  inp(str2);
  	vc ans = Plus(a , b);
  	cout << "@1: ";
  	for (auto x : ans) cout << x.fi << x.se;
}

void solve2()
{
	ll p , c , num = 0;
	string str1;
	vc a , s1 , s2 , ans;
	cin >> str1 >> p >> c ;
	a = inp(str1);
	for (auto x : a) num += x.se;
	s1 = Copy(a , 1 , p - 1);
	s2 = Copy(a , p + c , num);
	ans = Plus(s1 , s2);
	cout << "@2: ";
	for (auto x : ans) cout << x.fi << x.se;
}

void solve3()
{
	ll p , c ;
	vc a;
	string str1;
	cin >> str1 >> p >> c;
	a = inp(str1);
	a = Copy(a , p , p + c - 1);
	cout << "@3: ";
	for (auto x : a) cout << x.fi << x.se;
}

void solve4()
{
	ll p , num = 0;
	string str1 , str2;
	vc a , s1 , s2 , ans , b;
	cin >> str1 >> str2 >> p ;
	a = inp(str1);
	b = inp(str2);
	for (auto x : a) num += x.se;
	s1 = Copy(a , 1 , p - 1);
	s2 = Copy(a , p  , num);
	ans = Plus(Plus(s1 , b) , s2);
	cout << "@4: ";
	for (auto x : ans) cout << x.fi << x.se;
}

int main()
{
  while(cin >> s)
  {
    if (s == "@1") solve1();
    if (s == "@2") solve2();
    if (s == "@3") solve3();
    if (s == "@4") solve4();
    cout << '\n';
  }
}

