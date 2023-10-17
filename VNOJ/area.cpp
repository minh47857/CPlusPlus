#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fi  first
#define se  second
#define LL  long long
#define uint unsigned int
#define pb  push_back
#define eb  emplace_back
#define bit(s,i) ((s >> i) & 1)
#define off(s,i) (s & (~ (1 << i)))
#define ii pair <int , int>
#define iii1 pair <ii , int>
#define iii2 pair <int , ii>
#define iiii pair < ii , ii >
#define TASK "AREA"
using   namespace   std;
const int maxn = 3e4 + 10;
ii IT[8 * maxn];
vector < iiii > event;
///--------------------------
void upl(int id,int l,int r,int i,int j,int val)
{
    if (r <= i || j <= l) return;
    if (i <= l && r <= j) IT[id].fi += val;
    else
    {
        int mid = l + r >> 1;
        upl(id << 1 , l , mid , i , j , val);
        upl(id << 1|1 , mid , r , i , j , val);
    }
    if (IT[id].fi == 0) IT[id].se = IT[id << 1].se + IT[id << 1|1].se;
    else IT[id].se = r - l;
}
///--------------------------
void readf()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
        int u , v , x , y;
        cin >> u >> v >> x >> y;
        event.pb(iiii(ii(u,1),ii(v,y)));
        event.pb(iiii(ii(x,-1),ii(v,y)));
    }
    sort(event.begin(),event.end());
}
///--------------------------
void solve()
{
    int res = 0;
    for (int i = 0 ; i < event.size() - 1 ; ++i)
    {
        upl(1, 0 , maxn , event[i].se.fi , event[i].se.se , event[i].fi.se);
        res += (event[i+1].fi.fi - event[i].fi.fi) * IT[1].se;
    }
    cout << res;
}
///--------------------------
int main()
{
   #ifdef BDP0509
       freopen(TASK".inp", "r", stdin);
       freopen(TASK".out", "w", stdout);
   #endif // ONLINE_JUDGE
   ios::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   readf();
   solve();
}
