#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , H = 150000;
ll a[N] , n , pmin[N] , check[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
    while ( cin >> n)
    {
  	for (int i = 1 ; i <= n ; i++) cin >> a[i];
  	deque <ll> dq1 ,dq2;
  	memset (check , 0 , sizeof (check));
  	
		for (int i = n ; i >= 1 ; i--)
  	{
  		ll Min = a[i] , pos;
  		while(dq2.size() != 0 && a[i] >= a[dq2.back()])  Min = min(pmin[dq2.back()] , Min) , dq2.pop_back() ;
  		if (dq2.size() == 0) pos = i;
  		else pos = dq2.back();
  		pmin[i] = a[i];
  	if (pos != i)	pmin[pos] = min (pmin[pos] , Min);
  		if (a[i] - pmin[pos] >= H || pos == i)  check[i] = 1 ;
  		dq2.push_back(i);
	}
	
	for (int i = 1 ; i <= n ; i++)
  	{
  		ll Min = a[i] , pos;
  		while(dq1.size() != 0 && a[i] >= a[dq1.back()])  Min = min(pmin[dq1.back()] , Min) , dq1.pop_back() ;
  		if (dq1.size() == 0) pos = i;
  		else pos = dq1.back();
  		pmin[i] = a[i];
  	if (pos != i)	pmin[pos] = min (pmin[pos] , Min);
  		if ((a[i] - pmin[pos] >= H || pos == i) && check[i] == 1) cout << i << ' ';
  		dq1.push_back(i);
	}
	
	cout << '\n';
	}
  	
  
  
}

