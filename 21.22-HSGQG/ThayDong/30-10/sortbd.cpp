#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define ll long long
#define pi pair<int , int>
using namespace std;

const int N = 55 , M = 1e4 + 5;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m, n, s;
int a[M][N], id[M];
vector<int> col;

bool cmp(int x, int y) {
	for (auto i : col) {
		if ( a[x][i] < a[y][i] ) return true;
		else if ( a[x][i] > a[y][i] ) return false;
	}
    return ( x < y );
}

int main(){
     file();
    cin >> m >> n >> s;
    for (int i = 1; i <= m ; i++)
        for (int j = 1; j <= n ; j++)
            cin >> a[i][j];
    for (int i = 1 , x ; i <= s ; i++) cin >> x , col.pb(x);
    reverse(col.begin() , col.end());
    for (int i = 1; i <= m ; i++) id[i] = i;
    sort(id + 1, id + 1 + m, cmp);
    for (int i = 1; i <= m ; i++){
        for (int j = 1; j <= n ; j++)
            cout << a[id[i]][j] << ' ';
        cout << '\n';
    }
    return 0;
}
