#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int check68() {
    for (int i = 0; i < n; ++i) {
        if (s[i] != '6' && s[i] != '8')
            return i;
    }
    return n;
}

void fill8(int pos) {
    for (int i = pos; i < n; ++i) {
        s[i] = '8';
    }
}

void fix_pre(int pos) {
    for (int i = pos; i >= 0; --i) {
        if (s[i] == '8') {
            s[i] = '6';
            return;
        }
        if (s[i] == '6') {
            if (i) {
                s[i] = '8';
            } else {
                s[i] = '*';
            }
        }
    }
}

int main() {

    // for (int t = 6; t < 2000; ++t)
    //     cout << t << endl;
    //     return 0;
    //for (int t = 6; t < 2000; ++t) {
    cin >> s;
    //cout << s << ' ';
    n = s.size();
    int i = check68();
    if (i == n) {
        cout << s << endl;
        //continue;
        return 0;
    }
    if (s[i] > '8') {
        fill8(i);
    } else if (s[i] > '6') {
        s[i] = '6';
        fill8(i + 1);
    } else {
        if (i == 0) s[i] = '*';
        else s[i] = '8';
        fix_pre(i - 1);
    }
    for (i = i + 1; i < n; ++i) {
        s[i] = '8';
    }
    for (char c: s) {
        if (c != '*')
            cout << c;
    }
    cout << endl;
    //}
}