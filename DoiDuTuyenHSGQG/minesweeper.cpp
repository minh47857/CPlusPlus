#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
 
using namespace std;
 
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define RESET(a, c) memset(a, c, sizeof(a))
#define MAXN 1000002
#define base 1000000007
 
string s;
int a[MAXN];
int f[MAXN][6], F[MAXN][6];
int n;
long long result;
 
int main()
{
    
    cin >> s;
 
    n = s.length();
    FOR(i, 1, n) {
        if (s[i - 1] != '?') {
            if (s[i - 1] == '*') a[i] = 3;
            else a[i] = int(s[i - 1]) - 48;
        }
        else a[i] = 4;
    }
 
    f[0][3] = 0; f[0][0] = 1;
    FOR(i, 1, n) {
        f[i][0] = (f[i - 1][1] + f[i - 1][0]) % base;
        f[i][1] = f[i - 1][3];
        if (i > 1) f[i][3] = f[i - 1][3]; else f[i][3] = 1;
        if ((a[i - 1] == 4) || (a[i - 1] == 1)) f[i][3] = (f[i][3] + F[i - 1][0]) % base;
        if ((a[i - 1] == 4) || (a[i - 1] == 2)) f[i][3] = (f[i][3] + F[i - 1][1]) % base;
        
        FOR(j, 0, 3) F[i][j] = f[i][j] , cout << f[i][j] << ' ';
        FOR(j, 0, 3) {
            if ((a[i] != 4) && (a[i] != j)) f[i][j] = 0;
        }
        cout << endl;
    }
 
    result = 0;
    FOR(i, 0, 3) {
        if ((a[n] == 4) || (a[n] == i)) result = (result + f[n][i]) % base;
    }
    result = (result + base) % base;
 
    cout << result << endl;
}
