#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , inf = 1e9;

void file() {
    freopen("MINPRODUCT.inp" , "r" , stdin);
	freopen("MINPRODUCT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
ll a[N];
pi maxx , minn;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	maxx = {-inf , -inf};
	minn = {inf , inf};
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] >= maxx.fi) 
			maxx.se = maxx.fi , maxx.fi = a[i];
		else if(a[i] > maxx.se) maxx.se = a[i];
		if(a[i] <= minn.fi) 
			minn.se = minn.fi , minn.fi = a[i];
		else if(a[i] < minn.se) minn.se = a[i];
	}
	cout  << min({minn.fi * minn.se , minn.fi * maxx.fi ,  maxx.se * maxx.fi});
	return 0;
}



