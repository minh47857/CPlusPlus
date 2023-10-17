#include<bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N=33;
const int row[4]={-1, 0, 0, 1};
const int col[4]={0, -1, 1, 0};

int m, n, k, i, j, cnt, id[N][N], dp[N][N], ans, d, c, g, ni, nj, t, trace[N*N], cap[N*N], tmp;
ii s[N*N];
bool color[N][N];
char kt[N][N];
vector<int> a;

bool inside(int x, int y)
{
    if( x<1 || x>m ) return false;
    if( y<1 || y>n ) return false;
    if(kt[x][y]=='#') return false;
    return true;
}

bool outside(int x, int y, int u, int v, int mid)
{
    return !( u<=x && x<u+mid && v<=y && y<v+mid );
}

int get(int x, int y, int mid)
{
    return dp[x][y] - dp[x-mid][y] - dp[x][y-mid] + dp[x-mid][y-mid];
}

void ghep(int u, int x, int y, int mid)
{
    if(tmp) return;
    for(int v=0; v<4; v++)
    {
        int nu=s[u].fi+row[v], nv=s[u].se+col[v];

        if( !inside(nu, nv) || !outside(nu, nv, x, y, mid) || trace[ id[nu][nv] ]!=0 ) continue;
        trace[ id[nu][nv] ]=u;
        if(cap[ id[nu][nv] ]==0)
        {
            tmp=id[nu][nv];
            return;
        }
        else ghep(cap[ id[nu][nv] ], x, y, mid);
    }
}

void dao(int v)
{
    int u, nv;
    while(v>0)
    {
        u=trace[v];
        nv=cap[u];
        cap[u]=v;
        cap[v]=u;
        v=nv;
    }
}

bool able(int x, int y, int mid)
{
    if(k==0) return true;
    memset(cap, 0, sizeof(cap));
    cnt=0; a.clear();
    for(int u=1; u<=m; u++)
        for(int v=1; v<=n; v++)
            if( color[u][v] && outside(u, v, x, y, mid) && kt[u][v]!='#' )
            {
                for(t=0; t<4; t++)
                {
                    ni=u+row[t]; nj=v+col[t];
                    if( inside(ni, nj) && outside(ni, nj, x, y, mid) && cap[ id[ni][nj] ]==0 )
                    {
                       cap[ id[u][v] ] = id[ni][nj];
                       cap[ id[ni][nj] ] = id[u][v];
                       cnt++;
                       break;
                    }
                }
                if(cap[ id[u][v] ]==0) a.push_back(id[u][v]);
                if(cnt>=k) return true;
            }
    for(int u=0; u<a.size(); u++)
    {
        memset(trace, 0, sizeof(trace));
        tmp=0;
        ghep(a[u], x, y, mid);
        if(tmp) dao(tmp), cnt++;
        if(cnt>=k) return true;
    }
    return false;
}

bool check(int mid)
{
    for(i=1; i<=m-mid+1; i++)
        for(j=1; j<=n-mid+1; j++)
            if(get(i+mid-1, j+mid-1, mid)==0) if(able(i, j, mid)) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;

    cnt=0;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            cin>>kt[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (kt[i][j]=='#');
            id[i][j]=++cnt;
            s[ id[i][j] ]={i, j};
        }

    color[0][0]=false;
    for(i=1; i<=m; i++) color[i][0]=!color[i-1][0];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            color[i][j]=!color[i][j-1];

    d=1; c=min(m, n); ans=0;
    while(d<=c)
    {
        g=(d+c)/2;
        if(check(g))
        {
            ans=g;
            d=g+1;
        }
        else c=g-1;
    }
    cout<<ans;

    return 0;
}

