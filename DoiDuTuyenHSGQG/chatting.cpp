#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
typedef  pair<ll,ll> pa;
const long long N=100005;
set<pa> s;
vector<pa> adj[N];
vector<ll> trace[N];
queue<int> q;
long long n,m,f,h[N],d[N],a,b,c,check1[N],check2[N],kq=0;
void file()
{
	freopen("chatting.inp","r",stdin);
	freopen("chatting.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dijkstra(int u)
{
	memset(d,0x3f3f3f3f,sizeof(d));
	d[u]=0;
	s.insert(make_pair(d[u],u));
	while(!s.empty())
	{
		pa t=*(s.begin());
		int k=t.second;
		s.erase(s.begin());
		for(auto x : adj[k])
		{
			int  ve=x.fi;
			int  kc=x.se;
			if(d[ve]==d[k]+kc)  trace[ve].pb(k);
			if(d[ve]>d[k]+kc) 
			{
				trace[ve].clear();
				trace[ve].pb(k);
				if(d[ve]!=0x3f3f3f3f) s.erase(make_pair(d[ve],ve));
				d[ve]=d[k]+kc;
				s.insert(make_pair(d[ve],ve));
			}		
		}
	}
}
void findd(ll y,ll kt[])
{
	q.push(y);
    kt[y]=1;
    while(q.size()!=0)
    {
        int t=q.front();
        q.pop();
        for(auto x:trace[t])
        {
            if(kt[x]==1) continue;
            kt[x]=1;
            q.push(x);
        }
    }
}
int main()
{
//	file();
    cin>>n>>m>>f;
    for(int i=1;i<=m;i++)
    {
    	cin>>a>>b>>c;
    	adj[a].pb(make_pair(b,c));
    	adj[b].pb(make_pair(a,c));
	}
	for(int i=0;i<=f;i++) cin>>h[i];
	dijkstra(0);
    findd(h[0],check1);
    for(int i=1;i<=f;i++) findd(h[i],check2);
    for(int i=1;i<n;i++) if(check1[i]==1&&check2[i]==1) kq=max(kq,d[i]);
    cout<<kq;
    return 0;
}
