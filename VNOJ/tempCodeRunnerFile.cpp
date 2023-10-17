#include<bits/stdc++.h> 
using namespace std;
int t;
int main() {
    cin >> t;
    while(t--) {
        int n , a , b , tmp = 0;
        string s;
        cin >> n >> a >> b >> s;
        for(char c : s) {
            if(c == '0') tmp++;
        }
        if(tmp == 0 || a != n) cout << "YES\n";
        else cout << "NO\n";
    }
}