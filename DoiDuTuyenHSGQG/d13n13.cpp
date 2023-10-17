#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll x , y  , mu[20]; 
ll calc(ll n)
{
	string s;
	if (n < 12) return 0;
	if (n < 100 ) return 1;
	ll ans = 0 , res = 1;
	while (n) s = char(int(n % 10) + 48) + s , n = n / 10;
//	for (int i = 0 ; i < s.size() ; i++) cout << s[i] ;
	//cout << '\n';
	s = "0" + s;
	for (int i = 0 ; i < s.size() - 2; i++)
	{ 
	   int p = s[i] - '0';
	   //cout << p << ' ';
		res = res * 10 - (9 - p); 
	//	cout << res << endl;
		if (1 < (s[i + 1] - '0') ) ans += (res * mu[s.size() - i - 3]); 
		if (s[i + 1] - '0' == 0) ans += ((res - 1) * mu[s.size() - i - 3]);
		if (s[i + 1] - '0' == 1)
		{
			if (3 < s[i + 2] - '0') ans += (res * mu[s.size() - i - 3]); 
			if (3 > s[i + 2] - '0') ans += ((res - 1) * mu[s.size() - i - 3]);
			if (3 == s[i + 2] - '0') 
			{
				ans += ((res - 1) * mu[s.size() - i - 3]);
				ll val = 1;
				for (int j = i + 3 ; j < s.size() ; j++) val *= (s[j] - '0');
				ans += val;
			}
		
		}
	}
	return ans;
}
int main()
{
	file();
	mu[0] = 1;
	for (int i = 1 ; i <= 16 ; i++) mu[i] = mu[i - 1] * 10;
	cin >> x ;
	cout << calc(x);
//	while(cin >> x >> y)
//	cout << y - x + 1 - (calc(y) - calc(x - 1)) <<  '\n';
}

