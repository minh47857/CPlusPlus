#include<bits/stdc++.h> 
using namespace std;
int main() {
    string s, kq = "";
    int dem = 0, check = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s[s.size() - i - 1]) check = 1;
    }
    if(check == 0) cout << "xau doi xung" << endl;
    else cout << "xau khong doi xung" << endl;
    for(int i = 0; i < s.size() ; i++) {
        if(i < s.size() - 2 && s[i] == 'h' && s[i + 1] == 'o' && s[i + 2] == 'a') {
            dem++;
            kq += "hoa hong";
            i += 2;
        }
        else kq += s[i];
    }
    cout << dem << endl << kq;
}