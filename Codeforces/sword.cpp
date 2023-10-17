#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5, MIN = -2e9, MAX = 2e9;

struct seg {
	ll l;
	ll r;
	ll c;
	int index;
};

seg a[N];
ll t, n, ans[N];
pair<seg, seg> pre[N], suf[N];
 
bool cmp(seg a, seg b) {
	if(a.r < b.r) return true;
	else return false;
}

ll get(seg a, seg b) {
	if(a.c == b.c) return MAX;
	if(!cmp(a, b)) swap(a, b);
	if(b.l <= a.r) return 0;
	return b.l - a.r;
}

void calc() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r >> a[i].c;
		a[i].index = i;
	}
	//sorting
	sort(a + 1, a + n + 1, cmp);
	//prefix
	pre[0] = {{MIN,MIN,0,0}, {MIN,MIN,0,0}};
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		if(a[i].c != pre[i].first.c) 
			pre[i] = {a[i], pre[i].first};
		else
			pre[i] = {a[i], pre[i].second};
	}
	//suffix
	suf[n + 1] = {{MAX,MAX,0,0}, {MAX,MAX,0,0}};
	for(int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1];
		if(a[i].l < suf[i].first.l) {
			if(a[i].c != suf[i].first.c)
				suf[i] = {a[i], suf[i].first};
			else 
				suf[i] = {a[i], suf[i].second};

		}
		else if(a[i].l < suf[i].second.l && a[i].c != suf[i].first.c) {
			suf[i].second = a[i];
		}
	}
	//process
	for(int i = 1; i <= n; i++) {
		ans[a[i].index] = min({get(a[i], pre[i - 1].first), get(a[i], pre[i - 1].second), get(a[i], suf[i + 1].first), get(a[i], suf[i + 1].second)});
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}
int main() {
	cin >> t;
	while(t--) 
		calc();
	return 0;
}


