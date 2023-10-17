#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 105 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int n, m , k;
bool c[N][N];
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1 , x , y ; i <= m ; i++) {
        cin >> x >> y;
        c[x][y] = c[y][x] = 1;
	}
    for (int i = 1 ; i <= n ; i++) a[i] = i;
    int res = 0;
    do{
        bool ok = true;
        for (int i = 2 ; i <= n ; i++)
            if ( c[a[i]][a[i - 1]] ) ok = false;
        if (ok) res++;
        if (res == k) {
            for (int i = 1 ; i <= n ; i++) cout << a[i] << ' ';
            return 0;
        }
    }
    while (next_permutation(a + 1, a + n + 1));
    return 0;
}

