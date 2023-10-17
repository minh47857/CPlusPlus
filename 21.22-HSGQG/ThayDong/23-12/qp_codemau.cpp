#include <bits/stdc++.h>
#define BIT(x, i) (((x)>>(i))&1)
#define MASK(i) (1LL<<(i))
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define TASK "test"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

template<typename T1, typename T2> bool mini(T1 &a, T2 b) {if(a>b) a=b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b) {if(a<b) a=b; else return 0; return 1;}
template<typename T1> T1 abs(T1 a) {if(a<0) a*=-1; return a;}

const int N = 1e3+7;
const ll oo = 1e18+7;

typedef array<int, 3> iii;
typedef vector<iii> viii;

iii s, x, u;
viii ans, tmp;

int dist(iii x, int a) {
    return min(abs(x[0] - a), min(abs(x[1] - a), abs(x[2] - a)));
}

void reduce(iii &x, viii &v) {
    sort(all(x));
    v.pb(x);
    if(x[2] - x[1] == x[1] - x[0]) return;
    x[2] = 2*x[1] - x[2];
    int dist1 = dist(x, 5e5);
    x[2] = 2*x[1] - x[2];
    x[0] = 2*x[1] - x[0];
    int dist2 = dist(x, 5e5);
    x[0] = 2*x[1] - x[0];
    if(dist1 < dist2) x[2] = 2*x[1] - x[2];
    else x[0] = 2*x[1] - x[0];
    reduce(x, v);
}

void go(iii x, iii u, viii &v) {
    sort(all(x));
    sort(all(u));
    if(x==u) return;

    if(x[0] < u[0]) {
        x[0] = 2*x[2] - x[0];
        v.push_back(x);
        x[1] = 2*x[2] - x[1];
        v.push_back(x);
    }
    else {
        x[1] = 2*x[0] - x[1];
        v.push_back(x);
        x[2] = 2*x[0] - x[2];
        v.push_back(x);
    }
    go(x, u, v);
}

int diff(iii a, iii b) {
    return (int) (a[0] != b[0]) + int(a[1] != b[1]) + int(a[2] != b[2]);
}

void modify(iii h) {
    sort(all(h));
    while(diff(s, h) > 1) next_permutation(all(h));
    s = h;
}

void proc() {
    cin>>x[0]>>x[1]>>x[2];
    cin>>u[0]>>u[1]>>u[2];
    s = x;
    reduce(x, ans);
    reduce(u, tmp);
    if(x[1] - x[0] == u[1] - u[0] && (u[0] - x[0]) % (2 * (x[1] - x[0])) == 0) {
        reverse(all(ans));
        ans.pop_back();
        reverse(all(ans));

        tmp.pop_back();
        reverse(all(tmp));

        go(x, u, ans);
        for(auto h: tmp) ans.push_back(h);
        cout<<ans.size()<<"\n";
        for(auto h : ans) {
            modify(h);
            cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<"\n";
        }
    }
    else cout<<-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--)
    {
        proc();
    }
    return 0;
}
