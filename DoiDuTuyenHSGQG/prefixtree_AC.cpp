#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6;
const ll mod=1e9+7;
ll n, k, i, cnt, cs, sm;
ll ans, gt[N+3], bit[N+3];
string st, t, s[N+3];
ll mu(ll x, ll y)
{
    if(y==0) return 1;
    ll res=mu(x, y/2);
    if(y%2) return (((res*res)%mod)*x)%mod;
    return (res*res)%mod;
}
ll calc(ll b, ll a)
{
    if(b==0) return 1;
    return (gt[a]*sm)%mod;
}
ll cnp(string x)
{
    ll d=1, c=n, g;
    while(d<=c)
    {
        g=(d+c)/2;
        if(s[g]==x) return g;
        if(s[g]>x) c=g-1;
        else d=g+1;
    }
    return 0;
}
void update(ll x)
{
    while(x<=N)
    {
        bit[x]++;
        x+=x&(-x);
    }
}
ll get(ll x)
{
    ll res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=x&(-x);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("prefixtree.inp", "r")) freopen("prefixtree.inp", "r", stdin);
    gt[1]=1; gt[0]=1;
    for(i=2; i<=N; i++) gt[i]=(gt[i-1]*i)%mod;
    cin>>n>>k;
    for(i=1; i<=n; i++) cin>>s[i];
    sort(s+1, s+n+1);
    sm=mu(gt[n-k], mod-2);
    cin>>st;
    for(i=0; i<st.size(); i++)
    {
        t+=st[i];
        cs=cnp(t);
        if(cs)
        {
            update(cs);
            cs-=get(cs);
            cnt++;
            ans=(ans+(cs*calc(k-cnt, n-cnt))%mod)%mod;
            t="";
        }
    }
    cout<<(ans+1)%mod;
    return 0;
}
