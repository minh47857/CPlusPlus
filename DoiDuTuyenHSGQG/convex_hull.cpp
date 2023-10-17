#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
struct Point{
    int x , y;
   Point() {x = y = 0;}
     Point(int x, int y) : x(x), y(y) {}

    Point operator + (const Point &a) const {return Point(x + a.x, y + a.y);}
    Point operator - (const Point &a) const {return Point(x - a.x, y - a.y);}
    int operator % (const Point &a) const {return x * a.y - y * a.x;} // cross product
   // bool operator == (const Point &a) const {return (!cmp(x, a.x) && !cmp(y, a.y));}
};

int n ;
Point pivot;

int dist(Point u , Point v){
    return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}

int orientation(Point a , Point b , Point c){
   // int t = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
   int t = (b - a) % (c - b);
    if(t == 0) return 0;
    if(t > 0) return -1;
    return 1;
} 

bool cmp1(Point a , Point b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

bool cmp2(Point u , Point v){
    int ccw = orientation(pivot , u , v);
    if(ccw == 0) return dist(pivot , u) < dist(pivot , v);
    return (ccw == -1);
}

vector<Point> convexhull(vector<Point> &q){
	vector<Point> p;
	sort(q.begin() , q.end() , cmp1);
	for(int i = 0 ; i < q.size() ; i++){
		p.pb(q[i]);
		while(i + 1 < q.size() && q[i].x == q[i + 1].x && q[i].y == q[i + 1].y) i++;
	}
		
	pivot = p[0];
	sort(p.begin() + 1 , p.end() , cmp2);

	int m = 0;
	for(int i = 0 ; i < p.size() ; i++){
		while(m >= 2 && orientation(p[m - 2] , p[m - 1] , p[i]) >= 0) m--;
	    p[m++] = p[i];
	}
	
	p.resize(m);
	return p;
	
}
void solve(){
    if(n == 0) exit(0);
    vector<Point> q;
    
    
    for(int i = 1 ; i <= n ; i++){
    	int x , y;
    	cin >> x >> y;
    	q.pb({x , y});
	}
	
	auto res = convexhull(q);
	cout << res.size() << '\n';
	for(auto i : res) cout << i.x << ' ' << i.y << '\n';
}

int main(){
    file();
  while(cin >> n) solve();
  return 0;
}
