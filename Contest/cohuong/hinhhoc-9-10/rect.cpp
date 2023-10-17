#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pb push_back
#define EPS 1e-6
using namespace std;
const int N = 1e3 + 5;

inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

void file() {
	freopen("rect.inp" , "r" , stdin);
	freopen("rect.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Point{
    int x, y;
    Point() { x = y = 0; }
    Point(int x, int y) : x(x), y(y) {}
    double operator % (const Point& a) const { return x*a.y - y*a.x; }
};

double stg(Point a, Point b, Point c){
    return abs(a%b + b%c + c%a) * 1.0 / 2;
}

double shcn(Point a, Point b, Point c, Point d){
    return abs(a%b + b%c + c%d + d%a) * 1.0 / 2;
}

struct hcn{
    Point ver[5];

    bool inside(Point& a){
        double s1, s2, s3, s4, s;
        s1 = stg(ver[1], ver[2], a);
        s2 = stg(ver[2], ver[3], a);
        s3 = stg(ver[3], ver[4], a);
        s4 = stg(ver[4], ver[1], a);
        s = shcn(ver[1], ver[2], ver[3], ver[4]);
        if ( cmp( s1 + s2 + s3 + s4, s) == 0 ) return true;
        return false;
    }
};

int n, ans = 1;
hcn rec[N];
int Par[N], Size[N];

bool cut(int u, int v){
    for (int i = 1; i <= 4; i ++)
        if ( rec[u].inside(rec[v].ver[i]) ) return true;
    return false;
}

int Find(int u){
    if ( u == Par[u] ) return u;
    return Par[u] = Find(Par[u]);
}

void merge(int u, int v){
    u = Find(u);
    v = Find(v);
    if ( u != v ){
        if ( Size[u] < Size[v] ) swap(u, v);
        Par[v] = u;
        Size[u] += Size[v];
        ans = max(ans, Size[u]);
    }
}

int main(){
    file();
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= 4; j ++)
            cin >> rec[i].ver[j].x >> rec[i].ver[j].y;
    for (int i = 1; i <= n; i ++)
        Par[i] = i, Size[i] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if ( cut(i, j) || cut(j, i) ) merge(i, j);
    cout << ans;

    return 0;
}
