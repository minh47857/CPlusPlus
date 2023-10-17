#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define ldb long double
const ll N = 7, MOD = 1e9 +7 , inf = 1e15;
ll t , x[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool check(ll a, ll b, ll c)
{
    return (a + b > c) && (b + c > a) && (c + a > b);
}
ldb calc(ll u, ll U, ll v, ll V, ll w, ll W)
{
    ldb X = (w * w + u * u - V * V);
    ldb Y = (v * v + w * w - U * U);
    ldb Z = (u * u + v * v - W * W);
    ldb T = (u * v * w);
    return sqrt(X * Y * Z + 2 * 2 * T * T - u * u * Y * Y - v * v * X * X - w * w * Z * Z) / 12;
}

bool solve()
{
    for (int i = 0; i < 6; ++i) cin >> x[i];
    sort(x, x + 6);
    if (x[0] <= 0) return false;
    do
    {
        ll BC = x[0];
        ll CA = x[1];
        ll AB = x[2];
        ll OA = x[3];
        ll OB = x[4];
        ll OC = x[5];
        bool ABC = check(BC, CA, AB);
        bool OBC = check(BC, OB, OC);
        bool OCA = check(CA, OC, OA);
        bool OAB = check(AB, OA, OB);
        ldb V_OABC = calc(OA, BC, OB, CA, OC, AB);
        if (ABC && OBC && OCA && OAB && V_OABC > 0) return true;
    }
    while (next_permutation(x, x + 6));

    return false;
}
int main()
{
    cin >> t;
    while (t--) 
	{
		if (solve()) cout << "Yes" << '\n';
		else cout << "NO" << '\n';
	}
    return 0;
}
