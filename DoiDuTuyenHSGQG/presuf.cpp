#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001, MOD = 1e9 + 7;
string s;
ll n, po[N], Hash[N], check[N], base = 257;
set<ll> res;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(int x,int y)
{
	return ( Hash[y] - Hash[x-1] * po[y - x + 1] + MOD * MOD ) % MOD;
}
int main()
{
	file();
    cin >> s;
    n = s.size();
    s = ' ' + s;
     po[0] = 1;
     for(int i = 1; i <= n; i++)   po[i] = ( po[i-1] * base ) % MOD;
     for(int i = 1; i <= n; i++)   Hash[i]= (Hash[i-1] * base + s[i] ) % MOD;
     for (int i = 1; i <= n ; i++)
     {
     	int d = 0, c = n - i, kq = -1, g;
     	while( d <= c )
     	{
     		g = ( d + c ) / 2;
     		if (get(i , i + g) == Hash[g + 1])   kq = g, d = g + 1;
     		else c = g - 1;
		}
		if (kq == -1) continue;
		if(kq == n - i) res.insert(kq + 1);
	    check[kq + 1]++;
	 }
	 for(int i = n ; i >= 1; i--)	check[i] =  check[i] + check[i + 1] ;
	 cout<< res.size()<< '\n';
	 for (auto x : res) cout << x << ' ' << check[x] << '\n';
    return 0;
}

