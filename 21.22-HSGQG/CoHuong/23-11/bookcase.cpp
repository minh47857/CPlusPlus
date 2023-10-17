#include <bits/stdc++.h>
#define FOR(i, a, b)     for (int i = a; i <= b; ++i)
#define ii               pair <int, int>
#define fi               first
#define se               second
using namespace std;
const int N = 73, S = 70 * 30 + 3, oo = 1e9;
int TTest, n;
ii  book[N];
int f[2][S][S];

void mini(int &a, int b) { if (a > b) a = b; }

void sol() {
     cin >> n;
     FOR(i, 1, n) cin >> book[i].fi >> book[i].se;

     sort(book + 1, book + n + 1, greater<ii>());
     // FOR(i, 1, n) cerr << book[i].fi << ' ' << book[i].se << '\n';

     int sumT = 0;
     FOR(i, 1, n) sumT += book[i].se;

     FOR(i, 0, 1) FOR(d1, 0, sumT) FOR(d2, 0, sumT)
          f[i][d1][d2] = oo;

     f[1][0][0] = 0;           // book 1 use for 3rd shelf
     int x = 1, sum = 0;
     FOR(i, 2, n) {
          FOR(d1, 0, sum + book[i].se) FOR(d2, 0, sum + book[i].se)
               f[1 - x][d1][d2] = oo;
          FOR(d1, 0, sum) FOR(d2, 0, sum - d1) if (f[x][d1][d2] < oo) {
               mini(f[1 - x][d1 + book[i].se][d2], f[x][d1][d2] + (d1 == 0) * book[i].fi);
               mini(f[1 - x][d1][d2 + book[i].se], f[x][d1][d2] + (d2 == 0) * book[i].fi);
               mini(f[1 - x][d1][d2], f[x][d1][d2]);
          }
          x = 1 - x, sum += book[i].se;
     }

     int res = oo;
     FOR(d1, 1, sumT) FOR(d2, 1, sumT) if (d1 + d2 < sumT) {
          int d3 = sumT - d1 - d2;
          if (f[x][d1][d2] == oo) continue;
          int val = (f[x][d1][d2] + book[1].se) * max({ d1, d2, d3 });
          res = min(res, (f[x][d1][d2] + book[1].fi) * max({ d1, d2, d3 }));
     } else break;
     cout << res << '\n';
}

main() {
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     if (fopen("trash.inp", "r"))
          freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
     else 
          freopen("bookcase.inp", "r", stdin), freopen("bookcase.out", "w", stdout);

     cin >> TTest;
     while (TTest--) sol();
}