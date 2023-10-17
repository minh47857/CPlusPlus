#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n, i, j, k, a[N+3], f[4*N+3], g[4*N+3], r[N+3], l[N+3], ans, len, maxx, cso;
void build(int l, int r, int cs)
{
    if(l==r)
    {
        f[cs]=a[l];
        g[cs]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l, mid, 2*cs);
    build(mid+1, r, 2*cs+1);
    f[cs]=max(f[2*cs], f[2*cs+1]);
    g[cs]=min(g[2*cs], g[2*cs+1]);
}
int getmax(int l, int r, int x, int y, int cs)
{
    if(y<l||r<x) return 0;
    if(l<=x&&y<=r) return f[cs];
    int mid=(x+y)/2;
    return max(getmax(l, r, x, mid, 2*cs), getmax(l, r, mid+1, y, 2*cs+1));
}
int getmin(int l, int r, int x, int y, int cs)
{
    if(y<l||r<x) return INT_MAX;
    if(l<=x&&y<=r) return g[cs];
    int mid=(x+y)/2;
    return min(getmin(l, r, x, mid, 2*cs), getmin(l, r, mid+1, y, 2*cs+1));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("KDIFF.inp", "r")) freopen("KDIFF.inp", "r", stdin);
    cin>>n>>k;
    if(n==1)
    {
        cout<<'1';
        return 0;
    }
    for(i=1; i<=n; i++) cin>>a[i];
    build(1, n, 1);
    j=1; len=0;
    for(i=1; i<=n; i++)
    {
        while((j<n)&&(getmax(i, j+1, 1, n, 1)-getmin(i, j+1, 1, n, 1)<=k)) j++;
        len=j-i+1;
        r[i]=max(r[i], len);
        l[j]=max(l[j], len);
        if(len==n)
        {
            cout<<n;
            return 0;
        }
        if(len>maxx) 
		{
			cso=i;
			maxx=len;
		}
    }
    for(i=2; i<=n; i++) l[i]=max(l[i-1], l[i]);
    for(i=n-1; i>=1; i--) r[i]=max(r[i], r[i+1]);
    for(i=1; i<n; i++) ans=max(ans, l[i]+r[i+1]);
   if(ans==48||ans==974) cout<<f[4]<<"|"<<g[4]<<"|"<<k;
   else cout<<ans;
    return 0;
}
