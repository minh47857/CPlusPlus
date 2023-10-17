#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
const ll N = 1e3 + 3 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int timein[N], low[N];
bool vs[N];
vector<int> adj[N];
stack<pi> S;
set<int> answer;

int n, m, s, t , Time;

void visit(int u) 
{
    vs[u] = true;
    for (int v : adj[u]) if (!vs[v]) visit(v);
}

bool Component() 
{
    visit(s);
    return vs[t];
}


void dfs(int u  , int pa) 
{
    timein[u] = ++Time; low[u] = N;
    for (int v : adj[u]) 
	if (v != pa) 
	{
        if (timein[v])  low[u] = min(low[u], timein[v]);
         else {
                S.push({u , v});
                 dfs(v , u);
                 low[u] = min(low[u], low[v]);
                 if (low[v] >= timein[u]) 
				 {
                   set<int> cur;
                   while (S.top() != make_pair(u, v))
				   {
                    cur.insert(S.top().se);
                    S.pop();
                   }
                cur.insert(u) ; cur.insert(v) ; S.pop();
                if (cur.count(s) && cur.count(t))   answer = cur;
            }
        }
    }
}
int main() 
{
	file();
    cin >> n >> m >> s >> t;
    bool check = false;
    for (int i = 1; i <= m; i++) 
	{
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
        check |= (u == s && v == t) || (u == t && v == s);
    }
    if (!Component()) return cout << 0, 0;
    if (!check) adj[s].push_back(t), adj[t].push_back(s);
    for (int i = 1; i <= n; i++) if (!timein[i]) dfs(i , 0);
    cout << answer.size() << endl;
    for (int u : answer) cout << u << '\n';
    return 0;
}


