#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<int ,int> ii;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define pb push_back
const string FILE_NAME = "dijkstra";
const int maxx = 1e5 + 3;
const int INF = INT_MAX;
vector<ii> adj[maxx];
int n , m , u , v , w , dist[maxx] , trace[maxx];
bool visited[maxx];
void file()
{
    FASTio
        freopen((FILE_NAME + ".inp").c_str() , "r" , stdin);
        freopen((FILE_NAME + ".out").c_str() , "w" , stdout);
    
}
bool dijkstra(int start, int end)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0 , start});
    dist[start] = 0;
    trace[start] = -1;
    while(!pq.empty()) 
    {
        ii u = pq.top(); 
        pq.pop();
        if(u.se== end) return true;
        visited[u.se] = true;
       // if (u.fi != dist[u.se]) continue;
        for(auto &pr : adj[u.se]) 
        {
            int v = pr.first, w = pr.second;
            if (visited[v]) continue;
            if(dist[u.se] + w < dist[v]) 
            {
                dist[v] = dist[u.se] + w;
                pq.push({dist[v], v});
                trace[v] = u.se;
            }
        }
    }
    return false;
}
int main()
{
    file();
    for (ll i = 1 ; i <= maxx ; ++i)
        dist[i] = INF;
       cin >> n >> m;
    int u, v, w;
    for (ll i = 1 ; i <= m ; ++i)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    if(dijkstra(1, n)) 
    {
        vector<int> ans;
        ll tmp = n;
        while(tmp != -1)
        {
            ans.pb(tmp);
            tmp = trace[tmp];
        }
        for (int i = ans.size() - 1 ; i >= 0 ; --i)
            cout << ans[i] << " ";
    }
    else cout << -1;
    return 0;
}
