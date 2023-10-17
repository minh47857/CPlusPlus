#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 30 , MOD = 1e9 +7 , inf = 1e15;
ll n , a[N] , sum = 0;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub1
{
	ll dem = 0 , s[3] , d[N];
	void gen(int t)
    {
    	for (int i = 1 ; i <= n ; i++)
    	{
    		if (d[i] == 1) continue;
    		d[i] = 1;
    		for (int j = 1 ; j <= 2 ; j ++)
    	    {
    		  s[j] += a[i];
    		  if (s[1] > s[2]) 
    		  {
    		  	s[j] -= a[i];
    		  	continue;
			  }
			  if (t == n) dem++;
			  else gen(t + 1);
			  s[j] -= a[i];
		    }
    		d[i] = 0;
		}
	}
	void solve()
	{
		memset(d , 0 , sizeof (d));
		gen(1);
		cout << dem ;
	}
}
namespace sub2
{
    ll f[5000000];
    ll mu3[15];

    ll calc(int t, int t2, ll s1, ll s2)
	{
        if ( f[t] ) return f[t];
        if ( t2 == (1<<n)-1 ) return 1;
        ll cnt = 0;
        for (int i = 0; i < n; i ++)
		{
            if ( ( t2 & (1<<i) ) == 0 )
			{
                if ( s1 + a[i+1] <= s2 ) cnt += calc(t + mu3[i], t2|(1<<i), s1 + a[i+1], s2);
                cnt += calc(t + 2*mu3[i], t2|(1<<i), s1, s2 + a[i+1]);
            }
        }
        f[t] = cnt;
        return cnt;
    }

    void solve()
	{
        mu3[0] = 1;
        for (int i = 1; i <= 15; i ++) mu3[i] = mu3[i-1] * 3;
        cout << calc(0, 0, 0, 0) ;
    }
}
namespace sub3
{
	string add(string a, string b)
	{
        while (a.size() < b.size()) a='0'+a;
        while  (b.size() < a.size()) b='0'+b;

        int Lena = a.size(), Lenb = b.size();

        string c = "";
        int x, y, sum, du = 0;
        for (int i = Lena - 1; i >= 0; i--)
		{
            x = a[i]-'0';
            y = b[i]-'0';
            sum = x + y + du;
            du = sum / 10;
            c = char(sum % 10 +'0') + c ;
        }

        if ( du > 0 ) c='1'+c;
        return c;
    }

    string cal(string a, int b)
	{
		string res = a;
        for (int i = 1; i < b; i ++) res = add(res, a);
        return res;
    }
    void solve()
    {
    	string ans = "1";	
    	//cout << cal(ans , 19) << endl;
     for (int i = 1 , x = 1; i <= n ; x += 2 , i++) ans = cal(ans , x);
      cout << ans;
	}
}
int main()
{
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
  if (n <= 7) sub1::solve();
  if (n > 7 && n <= 14) sub2::solve();
 if (n >14) sub3 :: solve();
  return 0;
}

