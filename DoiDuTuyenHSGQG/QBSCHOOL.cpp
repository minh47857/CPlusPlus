#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(d, i) memset(d, i, sizeof d)
#define LLI pair<long long, int>
#define ILL pair<int, long long>
#define II pair<int, int>
#define fs first
#define sc second
#define pb push_back

const int N = 5005;
const ll inf = 1e18 + 5;

int n, m, k, u, v, l;
vector<ILL> adj[N];
ll minDis[N];
ll f[N];

void dijkstra(int s)
{
    priority_queue< LLI, vector< LLI >, greater< LLI > > heap;
    for(int i = 1; i <= n; ++i) minDis[i] = inf;
    minDis[s] = 0; f[s] = 1; heap.push({0, s});
    while(!heap.empty())
    {
        int u = heap.top().sc;
        ll du = heap.top().fs;
        heap.pop();
        if(du != minDis[u]) continue;
        for(auto it : adj[u])
        {
            int v = it.fs; ll w = it.sc;
            if(minDis[v] > du + w) minDis[v] = du + w, heap.push({minDis[v], v}), f[v] = f[u];
            else if(minDis[v] == du + w) f[v] += f[u];
        }
    }
        cout << minDis[n] << ' ' << f[n];
}
void solve()
{
    dijkstra(1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> k >> u >> v >> l;
        if(k == 1) adj[u].pb({v, l});
        if(k == 2) adj[u].pb({v, l}), adj[v].pb({u, l});
    }
	solve();
	return 0;
}
