#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001 , inf = 1e9;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
string str ;
int n  , s[N] , t;
pair<int , int> d[30];
void solve()
{
	vector<int> s1 , s2 , a[30];
	cin >> str;
	n = str.size();
	str = ' ' + str;
	for(int i = 0 ; i <= 27 ; i++) d[i] = {0 , i};
	for(int i = 1 ; i <= n ; i++)
	{
		a[str[i] - 'a'].pb(i);
		d[str[i] - 'a'].fi++;
	}
	sort(d , d + 28 , greater<pair<int , int>>());
	if(a[d[0].se].size() > n / 2) 
     {
     	cout << "Impossible" << '\n';
     	return ;
	 }
	for(int i = 0 ; i <= 27 ; i++) 
	for(auto x : a[d[i].se]) 
	{
		s1.pb(x) ;
		if(i != 0) s2.pb(x);
	}
	for(auto x : a[d[0].se]) s2.pb(x);
/*	for(auto x : s1) cout << x << ' ';
	cout << endl;
	for(auto x : s2) cout << x << ' ';
	cout << endl;*/
	for(int i = 0 ; i < n ; i++) s[s1[i]] = s2[i];
	for(int i = 1 ; i <= n ; i++) cout << str[s[i]];
	cout << '\n';
}

int main()
{
	file();
  cin >> t;
  while(t--) solve();
  
  return 0;
}

