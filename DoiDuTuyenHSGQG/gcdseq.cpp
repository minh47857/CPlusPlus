#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2e5 + 5 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n, m , l[N] , r[N] , k[N] , f[N][16] , a[N] , st[4*N];



void build(int id, int l, int r)
{
    if ( l == r ){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2 , l , mid);
    build(id * 2 + 1 , mid + 1 , r);
    st[id] = __gcd(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v)
{
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = (l + r) / 2;
    return __gcd(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main()
{
   file();

    cin >> n >> m;

    for (int i = 1; i <= m ; i++)
	{
        cin >> l[i] >> r[i] >> k[i];
        f[l[i]][k[i]] ++;
        f[r[i]+1][k[i]] --;
    }

    for (int j = 1; j <= 16 ; j++)
        for (int i = 1; i <= n ; i++) f[i][j] += f[i-1][j];

    for (int i = 1; i <= n ; i++) a[i] = 1;

    for (int i = 1; i <= n ; i++)
        for (ll j = 1; j <= 16 ; j++) if ( f[i][j] > 0 ) a[i] = ( a[i] * j ) / __gcd(a[i], j);

    build(1, 1, n);

    for (int i = 1; i <= m ; i++)
        if ( get(1, 1, n, l[i], r[i]) != k[i] )
		{
            cout << -1;
            return 0;
        }

    for (int i = 1; i <= n ; i++)cout << a[i] << ' ';
    return 0;
}
