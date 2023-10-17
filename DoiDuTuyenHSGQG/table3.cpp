#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll  MOD = 111539786 , inf = 1e15 ;
       
      
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll n , m ;


namespace sub2
{
    const int r[4] = {-1, 0, 0, 1};
    const int c[4] = {0, -1, 1, 0};
    const int N=33;

    int cnt , x , f[N*N][N*N], id[N][N], hs, ni, nj;
    ll tmp, ans; bool ok;

    void solve()
    {

        memset(id, 0, sizeof(0));
        cnt=0;
        for (int i = 1 ; i <= m ; i++)
        for (int j = 1 ; j <= n ; j++)
                id[i][j] = ++cnt;

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                cin >> x;

                for(int t = 0; t < 4; t++)
                {
                    ni = i+r[t]; nj = j+c[t];
                    f[ id[i][j] ][ id[ni][nj] ] = 1;
                }

                f[ id[i][j] ][ cnt+1 ] = x;
            }

        tmp = 0;
        for(int i = 1; i <=cnt ; i++)
        {
            ok = true;
            for(int j = 1; j <=cnt ; j++)
            {
                if( f[i][j] )
                {
                    for(int t = i + 1 ; t <=cnt ; t++)
                    {
                        if( f[t][j] )
                        {
                            if( f[i][j] == f[t][j] ) hs = 2;
                            else hs = 1;

                            for(int x = 1; x <= cnt + 1 ; x++) f[t][x] = ( f[t][x] + hs*f[i][x] )%3;
                        }
                    }
                    ok = false;
                    break;
                }
            }
            if( ok )
                {
                    if( f[i][cnt + 1]==0 ) tmp++;
                    else
                    {
                        cout << '0';
                        exit(0);
                    }
                }
        }

        ans = 1;

        for(int i = 1 ; i <= tmp ; i++) ans = ( ans*3 ) % MOD;
        cout << ans;
        exit(0);
    }
}
int main()
{
	file();
	cin >> m >> n;
 // if (n <= 3 && m <= 3) sub1::solve();
  sub2::solve();
  return 0;
}
