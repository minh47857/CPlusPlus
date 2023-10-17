#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("BITRANS.inp" , "r" , stdin);
	freopen("BITRANS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
string f[N] ;
ll x;

string Plus(string x, string y) 
{
    if(x.size() > y.size()) swap(x, y);
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    while(x.size() < y.size()) x += '0';
    string ans; int t = 0;
    for (int i = 0; i < x.size(); ++i) 
	{
        int add = (x[i] - '0') + (y[i] - '0') + t;
        ans += (add % 10 + '0');
        t = add / 10;
    }
    if(t > 0) ans += (t % 10 + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}


string Minus(string s)
{
    string res = s;
    ll i = res.size() - 1 , k = 1;
    while(k)
    {
        if(res[i] != '0')
        {
            res[i]--;
            k = 0;
        }
        else res[i] = '9';
        i--;
    }
    if(res[0] == '0') res.erase(0 , 1);
    return res;
}
void solve()
{
	f[1] = "0"; 
	for (int i = 2 ; i < N ; i++) 
	{
		f[i] = Plus(f[i - 1] , f[i - 1]) ;
		if(i % 2) f[i] = Minus(f[i]);
		else f[i] = Plus(f[i] , "1");
	}
}
int main()
{
	file();
	solve();
   while(cin >> x) cout << f[x] << '\n' ;
   return 0;
}

