#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
typedef long double Real;

const int MOD = 2004010501; //MOD > 2e9

/*credit : https://codeforces.com/blog/entry/14378 */
/*An O(|V|^2 |E|^{1/2}) Implementation of Push-Relabel Maximum Flow Algorithm*/
template <class T> struct Edge {
    int from, to, index;
    T cap, flow;

    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
    int n, E = 0;
    vector <vector <Edge <T>>> adj;
    vector <T> excess;
    vector <int> dist, count;
    vector <bool> active;
    vector <vector <int>> B;
    int b;
    queue <int> Q;

    PushRelabel (int n): n(n), adj(n) {}

    void AddEdge (int from, int to, int cap) {
    	++E;
        adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
        if (from == to) {
            adj[from].back().index++;
        }
        adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));

    }

    void Enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < n) {
            active[v] = true;
            B[dist[v]].push_back(v);
            b = max(b, dist[v]);
        }
    }

    void Push (Edge <T> &e) {
        T amt = min(excess[e.from], e.cap - e.flow);
        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
            e.flow += amt;
            adj[e.to][e.index].flow -= amt;
            excess[e.to] += amt;    
            excess[e.from] -= amt;
            Enqueue(e.to);
        }
    }

    void Gap (int k) {
        for (int v = 0; v < n; v++) if (dist[v] >= k) {
            count[dist[v]]--;
            dist[v] = max(dist[v], n);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel (int v) {
        count[dist[v]]--;
        dist[v] = n;
        for (auto e: adj[v]) if (e.cap - e.flow > 0) {
            dist[v] = min(dist[v], dist[e.to] + 1);
        }
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (auto &e: adj[v]) {
            if (excess[v] > 0) {
                Push(e);
            } else {
                break;
            }
        }

        if (excess[v] > 0) {
            if (count[dist[v]] == 1) {
                Gap(dist[v]); 
            } else {
                Relabel(v);
            }
        }
    }

    T GetMaxFlow (int s, int t) {
        dist = vector <int>(n, 0), excess = vector<T>(n, 0), count = vector <int>(n + 1, 0), active = vector <bool>(n, false), B = vector <vector <int>>(n), b = 0;
        
        for (auto &e: adj[s]) {
            excess[s] += e.cap;
        }

        count[0] = n;
        Enqueue(s);
        active[t] = true;
        
        while (b >= 0) {
            if (!B[b].empty()) {
                int v = B[b].back();
                B[b].pop_back();
                active[v] = false;
                Discharge(v);
            } else {
                b--;
            }
        }
        return excess[t];
    }

    T GetMinCut (int s, int t, vector <int> &cut);
};
/*END OF COPY-PASTE */

const int INF = 1e9;
const int MAX = 55;
int id[MAX][MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//	freopen("debug.txt", "w", stderr);
	const int bound = 51; //[0..50] --> shifted to [1..51]
	int counter = 0;
	for (int x = 0; x <= bound+1; x++)
		for (int y = 0; y <= bound+1; y++)
			for (int z = 0; z <= bound+1; z++) id[x][y][z] = ++counter;
	int source = 0, sink = ++counter;
	
	PushRelabel<int> flow(sink);
	for (int x = 1; x <= bound; x++)
		for (int y = 1; y <= bound; y++)
			for (int z = 1; z <= bound; z++)
				flow.AddEdge(id[x][y][z], id[x+1][y][z], 1),
				flow.AddEdge(id[x][y][z], id[x][y+1][z], 1),
				flow.AddEdge(id[x][y][z], id[x][y][z+1], 1),
				flow.AddEdge(id[x][y][z], id[x-1][y][z], 1),
				flow.AddEdge(id[x][y][z], id[x][y-1][z], 1),
				flow.AddEdge(id[x][y][z], id[x][y][z-1], 1);
	for (int x = 0; x <= bound+1; x++)
		for (int y = 0; y <= bound+1; y++)
			for (int z = 0; z <= bound+1; z++)
				if (x == 0 or x == bound+1 or y == 0 or y == bound+1 or z == 0 or z == bound+1)
					flow.AddEdge(id[x][y][z], sink, 1); 
	
	int k;
	cin >> k;
	for (int x,y,z; k --> 0; ) {
		cin >> x >> y >> z;
		++x, ++y, ++z;
		flow.AddEdge(source, id[x][y][z], sink);
	}
	
	cerr << "There are " << flow.E << " edges in total\n";
	cout << flow.GetMaxFlow(source, sink) << '\n';
}