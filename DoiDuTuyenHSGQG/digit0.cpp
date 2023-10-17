#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7;
string s ;
ll res2 = 0 , res5 = 0 , d[N] ;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(int n, int k)
{
    ll res = 0;
    ll t = 1;
    while ( t <= n )
	{
        t *= k;
        res += n / t;
    }
    return res;
}
int main()
{
	file();
   cin >> s;
   for (int i = 0 ; i < s.size() ; i++) d[s[i] - 'a']++;
   res5 = get(s.size() , 5);
   res2 = get(s.size() , 2);
   for (int i = 0 ; i <= ('z' -'a') ; i++) res2 -= get(d[i] , 2) , res5 = get(d[i] , 5);
   	  cout << min(res2 , res5);
}

