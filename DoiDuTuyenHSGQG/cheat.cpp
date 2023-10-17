#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const ll N = 405 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
//    freopen(".inp" , "r" , stdin);
//    freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n , m , t;
string str[N];

bool ic(string a , string b) {
    for(int i = 0 ; i < a.size() ; i++) if(a[i] == 'Y' && b[i] == 'N') return false;
    return true;
}

bool check() {
    int res = 0;
    for(int i = 1 ; i <= n ; i++) cin >> str[i];
    
    for(int i = 2 ; i <= n ; i++) if(ic(str[1] , str[i])) res++;
    if(res > 1) return false;
    
    for(int i = 2 ; i <= n ; i++) {
        vector<int> same , non , diff;
        for(int j = 0 ; j < m ; j++) if(str[i][j] == 'Y' && str[1][j] == 'Y') same.pb(j); else if(str[i][j] == 'Y' && str[1][j] == 'N') diff.pb(j);
        
        for(int j = 2 ; j <= n ; j++) {
            if(j != i) {
                bool flag = true;
                for(auto x : same) if(str[j][x] == 'N') {flag = false ; break;}
                if(flag) non.pb(j);
              }
          }
        
        for(auto x : diff) {
            bool flag = true;
            for(auto j : non) if(str[j][x] == 'Y') {flag = false ; break;}    
            if(flag) return true;
            }
         
    }
    return false;
    
}

int main() {
    file();
 cin >> t;
 while(t--) {
     cin >> n >> m;
    if(check()) cout << 'Y' << '\n';
    else cout << 'N' << '\n';
 }
 return 0;
}


