#include <bits/stdc++.h>

using namespace std;

vector <pair <char, long long> > a, b, ans;
long long p, c;
string o, s, t;

long long num(string &str, int index) {
    long long res = 0;
    while (index < (int)str.size() && isdigit(str[index])) {
        res = res * 10 + str[index] - '0';
        ++index;
    }
    return res;
}

void conv(vector <pair <char, long long> > &dest, string &src) {
    for (int i = 0; i < (int)src.size(); ++i) {
        if (islower(src[i])) {
            dest.push_back({src[i], num(src, i + 1)});
        }
    }
}

void solve1() {
    cin >> s >> t;
    conv(a, s);
    conv(b, t);
    if (a.back().first == b[0].first) {
        a.back().second += b[0].second;
    } else {
        a.push_back(b[0]);
    }

    for (pair <char, long long> e: a) {
        cout << e.first << e.second;
    }
    for (int i = 1; i < (int)b.size(); ++i) {
        cout << b[i].first << b[i].second;
    }
}

void solve2() {
    cin >> s >> p >> c;
    --p;
    conv(a, s);
    int idx = 0;
    for (; idx < (int)a.size(); ++idx) {
        if (p < a[idx].second) break;
        p -= a[idx].second;
    }
    int idx_bak = idx;
    a[idx_bak].second -= p;
    for (; idx < (int)a.size(); ++idx) {
        if (c == 0) break;
        long long foo = min(a[idx].second, c);
        a[idx].second -= foo;
        c -= foo;
    }
    a[idx_bak].second += p;
    for (pair <char, long long> e: a) {
        if (e.second) {
            ans.push_back(e);
        }
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (ans[i].second == 0) continue;
        if (ans.size() - i == 1 || ans[i].first != ans[i + 1].first)
            cout << ans[i].first << ans[i].second;
        else {
            ans[i + 1].second += ans[i].second;
        }
    }
}

void solve3() {
    cin >> s >> p >> c;
    --p;
    conv(a, s);
    int idx = 0;
    for (; idx < (int)a.size(); ++idx) {
        if (p < a[idx].second) break;
        p -= a[idx].second;
    }
    ans.push_back(a[idx]);
    ans[0].second -= p;
    if (c <= ans[0].second)
        ans[0].second = c;
    else {
        c -= ans[0].second;
        for (++idx; idx < (int)a.size(); ++idx) {
            if (c == 0) break;
            ans.push_back(a[idx]);
            ans.back().second = min(ans.back().second, c);
            c -= ans.back().second;
        }
    }
    for (pair <char, long long> e: ans) {
        if (e.second)
            cout << e.first << e.second;
    }
}

void solve4() {
    cin >> s >> t >> p;
    --p;
    conv(a, s);
    conv(b, t);
    int idx = 0;
    for (; idx < (int)a.size(); ++idx) {
        if (p < a[idx].second) break;
        p -= a[idx].second;
        ans.push_back(a[idx]);
    }
    pair <char, long long> as = a[idx], af = a[idx];
    as.second = p;
    af.second = a[idx].second - p;
    if (as.second != 0) ans.push_back(as);
    for (pair <char, long long> e: b) {
        ans.push_back(e);
    }
    if (af.second != 0) ans.push_back(af);
    for (++idx; idx < (int)a.size(); ++idx)
        ans.push_back(a[idx]);
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (ans[i].second == 0) continue;
        if (ans.size() - i == 1 || ans[i].first != ans[i + 1].first)
            cout << ans[i].first << ans[i].second;
        else {
            ans[i + 1].second += ans[i].second;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    while (cin >> o) {
        a.clear();
        b.clear();
        ans.clear();
        cout << o << ": ";
        switch (o[1]) {
            case '1': solve1(); break;
            case '2': solve2(); break;
            case '3': solve3(); break;
            default: solve4();
        }
        cout << endl;
    }
}