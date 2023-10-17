#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("height.inp" , "r" , stdin);
	freopen("height.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , a[N] , d[N] , q , e[N];
int main()
{
	file();
	cin >> q;
	while(q--)
	{
		deque<ll> dq;
		cin >> n;
  for (int i = 1 ; i <= n ; i++)
  {
  	 cin >> a[i] ;
  }
  for (int i = 1 ; i <= n ; i++)
  {
  	while (dq.size() && a[i] > a[dq.back()]) dq.pop_back();
  	if(dq.size()) 
  	{
  		if (a[dq.back()] == a[i]) d[i] = d[dq.back()] + 1;
  		else d[i] = 0;
	}
	else d[i] = 0;
	dq.pb(i);
  }
  dq.clear();
   for (int i = n ; i >= 1 ; i--)
  {
  	while (dq.size() && a[i] > a[dq.back()]) dq.pop_back();
  	if(dq.size()) 
  	{
  		if (a[dq.back()] == a[i]) e[i] = e[dq.back()] + 1;
  		else e[i] = 0;
	}
	else e[i] = 0;
	dq.pb(i);
  }
  for (int i = 1 ; i <= n ; i++) cout << d[i] + e[i]<< ' ';
  cout << '\n';
	}
  
  return  0;
}
