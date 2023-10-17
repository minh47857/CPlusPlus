#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define lb long double
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
    freopen("BAOLOI.inp" , "r" , stdin);
    freopen("BAOLOI.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct point{
    lb x , y;
};

int n ;
point pivot;
lb area = 0 , p = 0;
 
lb dist(point u , point v){
    return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}

int orientation(point a , point b , point c){
    int t = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    if(t == 0) return 0;
    if(t < 0) return -1;
    return 1;
} 

bool cmp1(point a , point b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

bool cmp2(point u , point v){
    int ccw = orientation(pivot , u , v);
    if(ccw == 0) return dist(pivot , u) < dist(pivot , v);
    return (ccw == -1);
}

vector<point> convexhull(vector<point> &q){
	vector<point> p;
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
    cin >> n;
    vector<point> q;
    
    
    for(int i = 1 ; i <= n ; i++){
    	lb x , y;
    	cin >> x >> y;
    	q.pb({x , y});
	}
	
	auto res = convexhull(q);
	cout << res.size() << '\n';
	
	res.pb(res[0]);
	for(int i = 0 ; i < res.size() - 1 ; i++) {
		area += (res[i].x * res[i + 1].y - res[i + 1].x * res[i].y);
		p += dist(res[i] , res[i + 1]);
	}
	area = abs(area);
	area = area * 1.0 / 2;
	cout << fixed << setprecision(3) << p << '\n' << area;
}

int main(){
    file();
  solve();
  return 0;
}
