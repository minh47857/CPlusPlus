#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define ld long double
#define pb push_back
#define pi pair<ll , ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;

void file()
{
    freopen("CONVEX.inp" , "r" , stdin);
    freopen("CONVEX.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
struct Point{
    ld x , y;
    Point() {x = y = 0;}
     Point(ld x, ld y) : x(x), y(y) {}

    Point operator + (const Point &a) const {return Point(x + a.x, y + a.y);}
    Point operator - (const Point &a) const {return Point(x - a.x, y - a.y);}
    ld operator % (const Point &a) const {return x * a.y - y * a.x;} // cross product
};

int n ; 
Point pivot;

ld dist(Point u , Point v){
    return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}

ld orientation(Point a , Point b , Point c){
    ld t = (b - a) % (c - b);
    if(t == 0) return 0;
    if(t > 0) return -1;
    return 1;
} 

bool cmp1(Point a , Point b) {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(Point u , Point v) {
    ld ccw = orientation(pivot , u , v);
    if(ccw == 0) return dist(pivot , u) < dist(pivot , v);
    return (ccw == -1);
}

vector<Point> convexhull(vector<Point> &q) {
    vector<Point> p;
    sort(q.begin() , q.end() , cmp1);
    for(int i = 0 ; i < q.size() ; i++) {
        p.pb(q[i]);
        while(i + 1 < q.size() && q[i].x == q[i + 1].x && q[i].y == q[i + 1].y) i++;
    }
        
    pivot = p[0];
    sort(p.begin() + 1 , p.end() , cmp2);

    int m = 0;
    for(int i = 0 ; i < p.size() ; i++) {
        while(m >= 2 && orientation(p[m - 2] , p[m - 1] , p[i]) >= 0) m--;
        p[m++] = p[i];
    }
    
    p.resize(m);
    return p;
    
}

int main (){
	file();
    cin >> n;
    vector<Point> q;
    for(int i = 1 ; i <= n ; i++) {
        ld x , y;
        cin >> x >> y;
        q.pb({x , y});
    }
    auto res = convexhull(q);
    res.pb(res[0]);
    ld P = 0 , area = 0;
    for(int i = 0 ; i < res.size() - 1 ; i++) {
   		area = area + res[i] % res[i + 1];
   		P += __gcd((ll)abs(res[i].x - res[i + 1].x) , (ll)abs(res[i].y - res[i + 1].y));
   	}
   	area = abs(area * 1.0) / 2;
   	cout << (long long) (area + 1 - P / 2);
   	return 0;
}

