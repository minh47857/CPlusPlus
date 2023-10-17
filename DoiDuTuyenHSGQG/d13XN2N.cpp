#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll n , dem = 0 , d[N] , nt[2000005] , match[N] , a[N] , check[N] , dem1 = 0;
vector <ll>  l , adj[N];
vector <pi> r , v;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void snt()
{
	for (int i = 2 ; i <= sqrt(2e6 + 5) ; i++)
	if (nt[i] == 0) for (int j = i * i ; j <= 2e6 + 5 ; j += i) nt[j] = 1;
}
bool ghep(int u)
{
	if (d[u] == 1) return false;
	else d[u] = 1;
	for (auto x : adj[u])
	{
		if (match[x] == 0 || ghep(match[x]))
		{
			match[x] = u;
			return true;
		}
	}
}
bool operator < (const pi&a , const pi&b)
{
	return a.fi < b.fi;
}
void solve()
{
	r.pb({inf , 0}) , l.pb(0);
  for (int i = 1 ; i <= n ; i++) 	
  {
  	 cin >> a[i] ;
	 if (a[i] % 2 == 1) r.pb({a[i] , i}) ;
	 else l.pb(i);
  }
  snt();
 sort(r.begin() , r.end() , greater<pi>()) ;
 
  for (int i = 1 ; i < r.size() ; i++)
  	for (int j = 1 ; j < l.size() ; j++)
  		if (nt[a[r[i].se] + a[l[j]]] == 0) adj[i].pb(j) ;
	
  
  for (int i = 1 ; i < r.size() ; i++)
  {
  	memset(d , 0 , sizeof(d));
  	dem += ghep(i);
  }
  for (int i = 1 ; i < l.size() ; i++) 	if (match[i])	  check[match[i]] = 1;
  for (int i = 1 ; i < r.size() ; i++) 	if(check[i] == 0 && a[r[i].se] == 1) dem1++;
  
  dem1 = dem1 - dem1 %2;
  dem += (dem1 / 2);
  cout << dem << '\n';
  for (int i = 1 ; i < l.size() ; i++)	if (match[i]) cout << r[match[i]].se << ' ' << l[i] << '\n';
 
  for (int i = r.size() - 1 ; i >= r.size() - dem1 + 1 ; i -= 2) cout << r[i].se<< ' ' << r[i - 1].se << '\n';
}
void sub3()
{
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	snt();
	n = n - n % 2;
	ll pos = n;
	cout << n / 2 << '\n';
	for (int i = n - 1 ; i >= 1 ; i--) 	if (nt [a[i] + a[pos]] == 0) v.pb({i , pos}) , pos = i - 1;
	for (auto x : v)
	{
	ll	pos1 = x.fi , pos2 = x.se;
	//cout << pos1 << ' ' << pos2 << endl;
	while(pos1 < pos2)
	{
	 cout << pos1 << ' ' << pos2 << '\n';
	 pos1 ++ , pos2 --;
	}
	}
}
int main()
{
	file();
  cin >> n ;
  if(n <= 1000) solve();
 else sub3();
  return 0;
}

