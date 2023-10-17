#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define lb long double

const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t ;

int check(lb a , lb b , lb c , lb d , lb e, lb g)
{
//    cout << a << ' ' << b << ' ' << c << ' '
    if(a * e == b * d)
    {
        if(b * g == c * e) return 0;
        return 1;
    }
    return 2;
}
void solve()
{
    lb x1 , y1 , x2 , y2 , a , b , c , d , e , g;
    int ans;
    cin >> x1 >> y1 >> x2 >> y2;
    a = y1 - y2 , b = x2 - x1 , c = y1*x2 - x1*y2;
    cin >> x1 >> y1 >> x2 >> y2;
    d = y1 - y2 , e = x2 - x1 , g = y1*x2 - x1*y2;
    ans = check(a , b , c , d , e , g);
    if(ans == 0) cout << "LINE" << '\n';
    else if(ans == 1) cout << "NONE" << '\n';
    else
    {
        cout << "POINT" << ' ';
        lb x = (c * e - g * b) * 1.0 / (a * e - b * d);
        lb y = (c * d - a * g) * 1.0 / (b * d - a * e);
        cout << fixed << setprecision(2) << x << ' ' << y << '\n';
    }
}

int main()
{
	file();
  cin >> t;
  while(t--) solve();
}

