#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string s;

string conv(ll x){
    string res = "";
    while ( x ) res += ((x%10) + '0'), x /= 10;
    reverse(res.begin(), res.end());
    return res;
}

namespace sub1{
    void solve(){
        string cur = "";
        ll i = 1, cnt = 0;
        while ( true ){
            ll x = i;
            string tmp = conv(i);
            for (int j = 0; j < tmp.size(); j ++){
                cnt ++; cur += tmp[j];
                if ( cnt >= n ){
                    bool ck = 1;
                    for (int t = 0; t < n; t ++)
                        if ( cur[cnt-n+t] != s[t] ){ ck = 0; break; }
                    if ( ck ){
                        cout << cnt;
                        return;
                    }
                }
            }
            i ++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);

    cin >> n >> s;
    //if ( n <= 6 )
        sub1::solve();
    return 0;
}
