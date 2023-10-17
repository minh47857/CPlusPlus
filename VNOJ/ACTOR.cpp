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
int r , t , a , b , c , n;
int main()
{
	cin >> r >> t;
   while (t--)
   {
   	cin >> n >> a >> b >> c;
   	if(r == 1) 
   	{
   	 int point = n - a + n - b + n - c;
		cout << max	(0 , n - point) << '\n';
	}
	else cout << min({a , b , c}) << '\n';
   }
}

