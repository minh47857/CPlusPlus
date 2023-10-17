#include <bits/stdc++.h>
using namespace std;
int n,m;
long long x,d[100002],h[100002],B[100002];
typedef pair <long long,int> pp;
vector <pp> A[100002];
void dijkstra()
{
    priority_queue <pp,vector <pp>,greater <pp> > q;
    for (int i=1;i<=n;i++)
        d[i]=1e18;
    d[1]=0;q.push({0,1});
    h[1]=x;
    while (!q.empty())
    {
        int u=q.top().second;
        long long du=q.top().first;

        q.pop();
        if (du!=d[u]) continue;
        //cout<<u<<' '<<du<<' '<<h[u]<<endl;
        for (int i=0;i<A[u].size();i++)
        {
            int v=A[u][i].second;
            long long w=A[u][i].first;
            if (B[u]-w<0) continue;
            long long cost=w;
            if (h[u]>B[v]+w) cost+=h[u]-w-B[v];
            if (h[u]-w<0) cost+=w-h[u];
            if (d[v]>d[u]+cost)
            {
                d[v]=d[u]+cost;
                h[v]=h[u]-w;
                if (h[v]<0) h[v]=0;if (h[v]>B[v]) h[v]=B[v];
                q.push({d[v],v});
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>x;
    for (int i=1;i<=n;i++)
        cin>>B[i];
    for (int i=1;i<=m;i++)
    {
        int a,b;long long w;cin>>a>>b>>w;
        A[a].push_back({w,b});
        A[b].push_back({w,a});
    }
    dijkstra();
    if (d[n]<1e18) cout<<d[n]+B[n]-h[n];
    else cout<<-1;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("robot.inp","r",stdin);
    freopen("robot.out","w",stdout);
    solve();
}
