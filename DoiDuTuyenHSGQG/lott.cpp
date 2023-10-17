#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
string s ;
ll n , res1 , res2;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(ll x , ll k)
{
	ll ans = 1;
	for (int i = x ; i > x - k ; i--) ans *= i;
	for (int i = k ; i >= 1 ; i--) ans /= i;
	return ans;
}
int main()
{
	file();
   while (true)
   {
   	cin >> s;
   	if (s == "[END]") return 0;
   	cin >> n;
   	if (n <= 2) 
   	{
   		cout << "1.0" << '\n' ;
   		continue;
	}
   	res1 = get (n * 5 , 5);
   	res2 = 10 * n * get((n - 1) * 5 , 2) + 5 * n * (n - 1) * 5 + n ; 
     cout << float (res2) / res1 << '\n';
   }
   return 0;
}

