#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 25 , MOD = 1e9 +7 , inf = 1e15;
ll n , a[N] , m ,  ans;
string st;

void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void check()
{
	int j;
    for(ll i = 1 ; i <= n - m + 1 ; i++)
    {
        for( j = 0 ; j < m ; j++)
        if(a[i + j] == 0 && st[j] == '1' ) break;
        if(j == m)
        {
            ans++;
            return;
        }
    }
}
void gen(int x)
{
	for (int i = 0 ; i <= 1 ; i++)
	{
	  a[x] = i;
      if(x < n) gen(x + 1);
      if(x == n) check();
   }
}
int main()
{
	file();
	cin >> n >> st;
    m = st.size();
    gen(1);
    cout << ans;
}
