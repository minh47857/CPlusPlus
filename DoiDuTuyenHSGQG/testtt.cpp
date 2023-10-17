#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define BIT(x , k) (((x) >> k) & 1)
const string FILE_NAME = "CONVEXHULL";
int n , m; 
ii p;
vector<ii> Node;
stack<ii> s , st;
void file()
{
	FASTio
	if (fopen((FILE_NAME + ".inp").c_str(),"r"))
	{
		freopen((FILE_NAME + ".inp").c_str() , "r" , stdin);
		freopen((FILE_NAME + ".out").c_str() , "w" , stdout);
	}
}
ii Nxt()
{
    ii tmp = s.top();
    s.pop();
    ii res = s.top();
    s.push(tmp);
    return res;
}
int calc(ii a, ii b)
{
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}
int ccw(ii a , ii b , ii c)
{
    int tmp = (b.se - a.se) * (c.fi - b.fi) - (b.fi - a.fi) * (c.se - b.se);
    if(!tmp) return 0;
    if(tmp < 0) return 2;
    else return 1;
}
bool cmp(ii a , ii b)
{
    int way = ccw(p , a , b);
    if(!way) return (calc(p , b) >= calc(p , a));
    return (way == 2);
}
void solve()
{
    Node.clear();
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> p.fi >> p.se;
        Node.push_back(p);
    }
    int MinY = Node[0].se , mi = 0;
    for(int i = 0 ; i < n ; i++)
        if((Node[i].se < MinY) || (Node[i].se == MinY) && (Node[i].fi < Node[mi].fi))
            MinY = Node[i].se, mi = i;

    swap(Node[0], Node[mi]);
    p = Node[0];
    sort(Node.begin() + 1 , Node.end() , cmp);
	int pos = 1 , m = 1;
    while(pos < n && Node[pos] == p) pos++;
    while(pos < n)
    {
        while(pos < n - 1 && ccw(p , Node[pos] , Node[pos + 1]) == 0) pos++;
        Node[m] = Node[pos];
        m++; 
		pos++;
    }
    if(m <= 3)
    {
        cout << m << '\n';
        for(int i = 0 ; i < m ; i++) 
			cout << Node[i].fi << ' ' << Node[i].se << '\n';
        return;
    }
    s.push(Node[0]);
    s.push(Node[1]);
    s.push(Node[2]);
    for(int i = 3 ; i < m ; i++)
    {
        while(ccw(Nxt() , s.top() , Node[i]) != 2) s.pop();
        s.push(Node[i]);
    }
    cout << s.size() << '\n';
    while(s.size())
    {
        p = s.top();
        st.push(p);
        s.pop();
    }
    while(st.size())
    {
        p = st.top();
        cout << p.fi << ' ' << p.se << '\n';
        st.pop();
    }
}
int main()
{	
	file();// NHO THEM TEN FILE NAME
    while(cin >> n)
    {
        if(!n) return 0;;
        solve();
    }
}
