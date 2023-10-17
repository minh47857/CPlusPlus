#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node {
	int x , y , id;
	bool operator < (const node&s) const {return x < s.x;}
};

int n , l[N] , r[N] , res[N];
node a[N];
deque<int> dq;

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y , a[i].id = i;
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		for(int j = i - 1 ; j >= 1 ; j--) {
			if(Max <= a[i].y || Max <= a[j].y) 
			Max = max(a[i].y , Max);
		}
	}
	for(int i = 1 ; i <= n ; i++) cout << res[i] << '\n';
	return 0;
}

