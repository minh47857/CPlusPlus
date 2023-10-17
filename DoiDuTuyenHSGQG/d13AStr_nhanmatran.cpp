#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 111539786;
ll Next[10][5] , n , f[N][10] ;
string s , p[10] ;
struct node
{
	ll v[6][6];
} A;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
node combine (node a , node b)
{
	node res ;
	for (int i = 0 ; i <= s.size() ; i++)
	{
		for (int j = 0 ; j <= s.size() ; j++)
		{
			res.v[i][j] = 0;
			for (int k = 0 ; k <= s.size() ; k++)
			{
				res.v[i][j] = (res.v[i][j] + a.v[i][k] * b.v[k][j]) % MOD;
			}
		}
	}
	return res ;
}
node poww ( node a , ll  k)
{
	if (k == 1) return a;
	node t = poww(a , k / 2);
	t = combine(t , t);
	if (k % 2 == 0) return t;
	return combine(a , t);
}
void solve ()
{
	memset(Next , 0 , sizeof(Next));
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
    for (int i = 0 ; i <= s.size() ; i++)
    {
    	
    	for (int j = 0 ; j <= s.size() ; j++)
    	{
    		A.v[i][j] = 0;
    		if (Next[j][0] == i) A.v[i][j] ++;
    		if (Next[j][1] == i) A.v[i][j] ++;
		}
	}

	node ans = poww(A , n);
	ll kq = 0 ;
	for (int i = 0 ; i < s.size() ; i++)	kq = (kq + ans.v[i][0]) % MOD;
	cout << kq << '\n';
}
int main()
{
	file();
	while (cin >> n >> s)	solve();
	return 0;
}

