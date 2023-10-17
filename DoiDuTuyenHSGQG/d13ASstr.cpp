#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 111539786;
ll Next[10][5] , n , f[N][10] , ans = 0;
string s , p[10] ;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve ()
{
	memset(Next , 0 , sizeof(Next));
	memset(f , 0 , sizeof(f));
	ans = 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        p[i + 1] = p[i] + s[i];
    	for (int j = 0 ; j <= 1 ; j++)
    	{
    		string str = p[i] + char(j + 48);
    		while (s.substr( 0 , str.size() ) != str && str.size() ) str.erase(0 , 1);
    		Next[i][j] = str.size();
		}
	}
	Next[s.size()][0] = s.size();
	Next[s.size()][1] = s.size();
	f[0][0] = 1 ;
	for (int i = 0 ; i < n ; i++)
	{
		for (int d = 0 ; d <= s.size() ; d++)
		{
			for (int k = 0 ; k <= 1 ; k++)
			{
				f[i + 1][Next[d][k]] = (f[i + 1][Next[d][k]] + f[i][d]) % MOD ;
			}
		}
	}
	for (int i = 0 ; i < s.size() ; i++) ans = ( ans + f[n][i] ) % MOD ;
	cout << ans << '\n';
}
int main()
{
	file();
	while (cin >> n >> s)	solve();
	return 0;
}

