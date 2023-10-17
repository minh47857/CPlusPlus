#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define pb push_back
const ll N = 2e5 + 5;
ll n, k, m;
priority_queue <ll> d[N];
vector < pi > adj[N];
 vector <ll> res;
int main() 
{
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
       ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back ({v, w});
    }
    priority_queue < pi, vector < pi >, greater <pi > > heap;
    d[1].push(0); heap.push({0, 1});
 
    while (heap.size()) {
        ll u = heap.top().second;
        ll du = heap.top().first;
        heap.pop();
        if (du > d[u].top()) continue;
        for (auto it : adj[u]) {
            ll v = it.first;
              ll w = it.second;
            ll newDist = w + du;
            if (d[v].size() < k) {
                d[v].push(newDist);
                heap.push({newDist, v});
            }
            else if (d[v].top() > newDist) {
                d[v].pop();
                d[v].push(newDist);
                heap.push({newDist, v});
            }
        }
    }
 
    while (d[n].size()) 
	{
        res.pb(d[n].top());
        d[n].pop();
    }
    for(int i = res.size() - 1; i >= 0; i--) cout<< res[i] << " ";
    return 0;
}
