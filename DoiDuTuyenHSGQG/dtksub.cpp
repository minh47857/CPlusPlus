#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N = 5e4 + 5;
const ll MOD = 1e9 + 7;
ll n, m, po[N], has[N], base = 31;
string str;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(int x,int y)
{
	return ( has[y] - has[x-1] * po[y-x+1] + MOD * MOD )%MOD;
}
bool check(int k)
{
	unordered_map <ll,ll> d;
	for(int i = 1; i <= n - k + 1 ; i++)
	{
		ll a = get( i, i + k - 1 );
		d[a]++ ;
		if( d[a] >= m ) return true;
	}
	return false;
}
int main()
{
	file();
    cin>>n>>m>>str;
    str = ' '+ str;
    po[0] = 1;
    for(int i = 1; i <= n; i++) po[i] = ( po[i-1] * base ) % MOD;
    for(int i = 1; i <= n; i++) has[i] = (has[i-1] * base + str[i] - 'a' + 1 )  % MOD;
   ll d = 1, c = n, g, kq=0;
	while(  d <= c )
	{
		g= (d + c )/2;
		if( check(g) )
		{
			kq = g;
			d = g + 1;
		}
		else c = g - 1;
	}
	cout<< kq;
	return 0;
}
